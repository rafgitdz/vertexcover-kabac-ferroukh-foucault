#!/bin/bash

# Compare the sizes of the covers obtained, and the time to obtain it 
# with different algorithms on randomly generated graphs with a small cover


vertexCount=3000
coverSize=300
for algo in 0 1 2 3
do
	echo "" > bench/vc_smallCover_eProb_size_$algo
	echo "" > bench/vc_smallCover_eProb_time_$algo
done


for proba in `seq 5 5 100`
do
	../VertexCover -g 1 $vertexCount $proba $coverSize -out graph.txt
	for algo in `seq 0 3`
	do
		echo $proba
		echo "algo : $algo"
		echo "$proba `../VertexCover -in graph.txt -a $algo | grep "^cover size" | cut -d" " -f4`" >> bench/vc_smallCover_eProb_size_$algo
		echo "$proba `../VertexCover -in graph.txt -a $algo | grep "^cover found" | cut -d" " -f4`" >> bench/vc_smallCover_eProb_time_$algo
	done
	gnuplot gnuplot_scripts/vc_smallCover_eProb
done


edgeProba=40
coverSize=100
for algo in 0 1 2 3
do
	echo "" > bench/vc_smallCover_vCount_size_$algo
	echo "" > bench/vc_smallCover_vCount_time_$algo
done
for vertexCount in `seq 100 100 3000`
do
	echo $vertexCount
	../VertexCover -g 1 $vertexCount $edgeProba $coverSize -out graph.txt
	for algo in `seq 0 3`
	do
		echo "algo : $algo"
		echo "$vertexCount `../VertexCover -in graph.txt -a $algo | grep "^cover size" | cut -d" " -f4`" >> bench/vc_smallCover_vCount_size_$algo
		echo "$vertexCount `../VertexCover -in graph.txt -a $algo | grep "^cover found" | cut -d" " -f4`" >> bench/vc_smallCover_vCount_time_$algo
	done
	gnuplot gnuplot_scripts/vc_smallCover_vCount
done

vertexCount=3000
edgeProba=40
for algo in 0 1 2 3
do
	echo "" > bench/vc_smallCover_cSize_size_$algo
	echo "" > bench/vc_smallCover_cSize_time_$algo
done


for coverSize in `seq 100 100 3000`
do
	echo "$coverSize"
	../VertexCover -g 1 $vertexCount $edgeProba $coverSize -out graph.txt
	for algo in `seq 0 3`
	do
		echo "algo : $algo"
		echo "$coverSize `../VertexCover -in graph.txt -a $algo | grep "^cover size" | cut -d" " -f4`" >> bench/vc_smallCover_cSize_size_$algo
		echo "$coverSize `../VertexCover -in graph.txt -a $algo | grep "^cover found" | cut -d" " -f4`" >> bench/vc_smallCover_cSize_time_$algo
	done
	gnuplot gnuplot_scripts/vc_smallCover_cSize
done



