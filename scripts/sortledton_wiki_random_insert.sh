#!/bin/sh
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 64 --block_size 512
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 56 --block_size 512
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 48 --block_size 512
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 40 --block_size 512
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 32 --block_size 512
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 24 --block_size 512
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 16 --block_size 512
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 8 --block_size 512
numactl -N 0 -l /home/zhou822/gfe_driver_bigdata/build/gfe_driver -G /home/zhou822/gfe_experiment_data/edit-enwiki/out.edit-enwiki.el -u -l sortledton.4 -w 4 --block_size 512