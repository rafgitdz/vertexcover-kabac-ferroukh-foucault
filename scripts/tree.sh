#!/bin/bash

# Compare the sizes of the covers obtained, and the time to obtain it 
# with different algorithms on randomly generated tree graphs



#Monitor the performance of the algorithms on a tree when we increase its width
vertexCount=10000
for algo in `seq 0 3` 5
do
	echo "" > bench/vc_tree_numSons_size_$algo
	echo "" > bench/vc_tree_numSons_time_$algo
done
for min in `seq 2 100`
do
	let "max = min*2"
	echo "$min $max"
	echo "$min `../VertexCover -g 3 $vertexCount $min $max -out graph.txt -a 5| grep "^cover size" | cut -d" " -f4`" >> bench/vc_tree_numSons_size_5
	echo "$min `../VertexCover -g 3 $vertexCount $min $max -a 5 | grep "^cover found" | cut -d" " -f4`" >> bench/vc_tree_numSons_time_5
	for algo in `seq 0 3`
	do
		echo "algo : $algo"
		echo "$min `../VertexCover -in graph.txt -a $algo | grep "^cover size" | cut -d" " -f4`" >> bench/vc_tree_numSons_size_$algo
		echo "$min `../VertexCover -in graph.txt -a $algo | grep "^cover found" | cut -d" " -f4`" >> bench/vc_tree_numSons_time_$algo
	done
	gnuplot gnuplot_scripts/vc_tree_numSons
done



#Monitor the performance of the algorithms on a tree when we increase its depth
min=2
max=4
for algo in `seq 0 3` 5
do
	echo "" > bench/vc_tree_vCount_size_$algo
	echo "" > bench/vc_tree_vCount_time_$algo
done
for vertexCount in `seq 10 200 10010`
do
	echo $vertexCount
	echo "$vertexCount `../VertexCover -g 3 $vertexCount $min $max -out graph.txt -a 5| grep "^cover size" | cut -d" " -f4`" >> bench/vc_tree_vCount_size_5
	echo "$vertexCount `../VertexCover -g 3 $vertexCount $min $max -a 5 | grep "^cover found" | cut -d" " -f4`" >> bench/vc_tree_vCount_time_5
	for algo in `seq 0 3`
	do
		echo "algo : $algo"
		echo "$vertexCount `../VertexCover -in graph.txt -a $algo | grep "^cover size" | cut -d" " -f4`" >> bench/vc_tree_vCount_size_$algo
		echo "$vertexCount `../VertexCover -in graph.txt -a $algo | grep "^cover found" | cut -d" " -f4`" >> bench/vc_tree_vCount_time_$algo
	done
	gnuplot gnuplot_scripts/vc_tree_vCount
done
