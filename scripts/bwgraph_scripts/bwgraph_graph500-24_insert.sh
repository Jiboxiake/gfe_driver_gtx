LD_LIBRARY_PATH=/usr/local/lib
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/zhou822/BwGraph_Mono/build/
export LD_LIBRARY_PATH
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 64
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 56
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 48
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 40
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 32
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 24
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 16
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 8
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l bwgraph_rw -w 4