/**
 * Copyright (C) 2019 Dean De Leo, email: dleo[at]cwi.nl
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <cinttypes>
#include <memory>
#include <unordered_map>

#include "common/error.hpp"
#include "library/interface.hpp"

// Forward declarations
namespace gapbs { class Bitmap; }
namespace gapbs { template <typename T> class SlidingQueue; }
namespace gapbs { template <typename T> class pvector; }
namespace gfe::utility { class TimeoutService; }

namespace gfe::library {

class CSR : public virtual LoaderInterface, public virtual GraphalyticsInterface  {
protected:
    const bool m_is_directed; // whether the graph is directed
    uint64_t m_num_vertices; // total number of vertices
    uint64_t m_num_edges; // total number of edges
    std::unordered_map<uint64_t, uint64_t> m_ext2log; // dictionary external vertex id -> logical vertex id
    uint64_t* m_log2ext {nullptr}; // dictionary logical vertex id -> external vertex id
    uint64_t* m_out_v {nullptr}; // vertex array for the outgoing edges
    uint64_t* m_out_e {nullptr}; // edge array for the outgoing edges
    double* m_out_w {nullptr}; // weights associated to the outgoing edges
    uint64_t* m_in_v {nullptr}; // vertex array for the incoming edges (only in directed graphs)
    uint64_t* m_in_e {nullptr}; // edge array for the incoming edges (only in directed graphs)
    double* m_in_w {nullptr}; // weights associated to the incoming edges
    uint64_t m_timeout = 0; // max time to complete a kernel of the graphalytics suite, in seconds

    // Retrieve the [start, end) interval for the outgoing edges associated to the given logical vertex
    std::pair<uint64_t, uint64_t> get_out_interval(uint64_t logical_vertex_id) const;

    // Retrieve the [start, end) interval for the incoming edges associated to the given logical vertex
    std::pair<uint64_t, uint64_t> get_in_interval(uint64_t logical_vertex_id) const;

    // Retrieve the [start, end) interval for the edges associated to the given logical vertex
    std::pair<uint64_t, uint64_t> get_interval_impl(const uint64_t* __restrict vertex_array, uint64_t logical_vertex_id) const;

    // Retrieve the number of outgoing edges for the given vertex
    uint64_t get_out_degree(uint64_t logical_vertex_id) const;

    // Retrieve the number of incoming edges for the given vertex
    uint64_t get_in_degree(uint64_t logical_vertex_id) const;

private:
    // Load an undirected graph
    void load_undirected(const std::string& path);
    void load_directed(const std::string& path);

    // BFS implementation
    std::unique_ptr<int64_t[]> do_bfs(uint64_t root, utility::TimeoutService& timer, int alpha = 15, int beta = 18) const;
    std::unique_ptr<int64_t[]> do_bfs_init_distances() const;
    void do_bfs_QueueToBitmap(const gapbs::SlidingQueue<int64_t>& queue, gapbs::Bitmap& bm) const;
    void do_bfs_BitmapToQueue(const gapbs::Bitmap& bm, gapbs::SlidingQueue<int64_t>& queue) const;
    int64_t do_bfs_TDStep(int64_t* distances, int64_t distance, gapbs::SlidingQueue<int64_t>& queue) const;
    int64_t do_bfs_BUStep(int64_t* distances, int64_t distance, gapbs::Bitmap &front, gapbs::Bitmap &next) const;

    // PageRank implementation
    std::unique_ptr<double[]> do_pagerank(uint64_t num_iterations, double damping_factor, utility::TimeoutService& timer) const;

    // WCC implementation
    std::unique_ptr<uint64_t[]> do_wcc(utility::TimeoutService& timer) const;

    // CDLP implementation
    std::unique_ptr<uint64_t[]> do_cdlp(uint64_t max_iterations, utility::TimeoutService& timer) const;

    // LCC implementation
    std::unique_ptr<double[]> do_lcc(utility::TimeoutService& timer) const;

    // SSSP implementation
    gapbs::pvector<double> do_sssp(uint64_t source, double delta, utility::TimeoutService& timer) const;

public:
    /**
     * Constructor
     * @param is_directed: true if the graph is directed, false otherwise
     */
    CSR(bool is_directed);

    /**
     * Destructor
     */
    ~CSR();

    /**
     * Get the number of edges contained in the graph
     */
    uint64_t num_edges() const;

    /**
     * Get the number of nodes stored in the graph
     */
    uint64_t num_vertices() const;

    /**
     * Returns true if the given vertex is present, false otherwise
     */
    bool has_vertex(uint64_t vertex_id) const;

    /**
     * Returns the weight of the given edge is the edge is present, or NaN otherwise
     */
    double get_weight(uint64_t source, uint64_t destination) const;

    /**
     * Check whether the graph is directed
     */
    bool is_directed() const;

    /**
     * Load the whole graph representation from the given path
     */
    void load(const std::string& path);

    /**
     * Set the timeout for the Graphalytics kernels
     */
    void set_timeout(uint64_t seconds);

    /**
     * Perform a BFS from source_vertex_id to all the other vertices in the graph.
     * @param source_vertex_id the vertex where to start the search
     * @param dump2file if not null, dump the result in the given path, following the format expected by the benchmark specification
     */
    void bfs(uint64_t source_vertex_id, const char* dump2file = nullptr);

    /**
     * Execute the PageRank algorithm for the specified number of iterations.
     *
     * @param num_iterations the number of iterations to execute the algorithm
     * @param damping_factor weight for the PageRank algorithm, it affects the score associated to the sink nodes in the graphs
     * @param dump2file if not null, dump the result in the given path, following the format expected by the benchmark specification
     */
    void pagerank(uint64_t num_iterations, double damping_factor = 0.85, const char* dump2file = nullptr);

    /**
     * Weakly connected components (WCC), associate each node to a connected component of the graph
     * @param dump2file if not null, dump the result in the given path, following the format expected by the benchmark specification
     */
    void wcc(const char* dump2file = nullptr);

    /**
     * Community Detection using Label-Propagation. Associate a label to each vertex of the graph, according to its neighbours.
     * @param max_iterations max number of iterations to perform
     * @param dump2file if not null, dump the result in the given path, following the format expected by the benchmark specification
     */
    void cdlp(uint64_t max_iterations, const char* dump2file = nullptr);

    /**
     * Local clustering coefficient. Associate to each vertex the ratio between the number of its outgoing edges and the number of
     * possible remaining edges.
     * @param dump2file if not null, dump the result in the given path, following the format expected by the benchmark specification
     */
    void lcc(const char* dump2file = nullptr);

    /**
     * Single-source shortest paths. Compute the weight related to the shortest path from the source to any other vertex in the graph.
     * @param source_vertex_id the vertex where to start the search
     * @param dump2file if not null, dump the result in the given path, following the format expected by the benchmark specification
     */
    void sssp(uint64_t source_vertex_id, const char* dump2file = nullptr);

    /**
     * Dump the content of the graph to given stream
     */
    void dump_ostream(std::ostream& out) const;
};

} // namespace
