numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l sortledton.4 -w 64 -r 64 -R 10 --blacklist sssp,cdlp,wcc,lcc --block_size 512
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l sortledton.4 -w 64 -r 56 -R 10 --blacklist sssp,cdlp,wcc,lcc --block_size 512
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l sortledton.4 -w 64 -r 48 -R 10 --blacklist sssp,cdlp,wcc,lcc --block_size 512
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l sortledton.4 -w 64 -r 40 -R 10 --blacklist sssp,cdlp,wcc,lcc --block_size 512
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l sortledton.4 -w 64 -r 32 -R 10 --blacklist sssp,cdlp,wcc,lcc --block_size 512
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l sortledton.4 -w 64 -r 24 -R 10 --blacklist sssp,cdlp,wcc,lcc --block_size 512
numactl -N 1 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/graph_source/graph500-24.properties -u -l sortledton.4 -w 64 -r 16 -R 10 --blacklist sssp,cdlp,wcc,lcc --block_size 512