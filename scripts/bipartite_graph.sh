#!/bin/bash

# Compare the sizes of the covers obtained, and the time to obtain it 
# with different algorithms on randomly generated bipartite graphs


vertexCount=1000
edgeProba=10
for algo in `seq 0 4`
do
	echo "" > bench/vc_bGraph_ratio_size_$algo
	echo "" > bench/vc_bGraph_ratio_time_$algo
done


for partRatio in `seq 5 5 95`
do
	echo "$partRatio"
	echo "$partRatio `../VertexCover -g 2 $vertexCount $edgeProba $partRatio -out graph.txt -a 4 | grep "^cover size" | cut -d" " -f4`" >> bench/vc_bGraph_ratio_size_4 
	echo "$partRatio `../VertexCover -g 2 $vertexCount $edgeProba $partRatio -a 4 | grep "^cover found" | cut -d" " -f4`" >> bench/vc_bGraph_ratio_time_4
	for algo in `seq 0 3`
	do
		echo "algo : $algo"
		echo "$partRatio `../VertexCover -in graph.txt -a $algo | grep "^cover size" | cut -d" " -f4`" >> bench/vc_bGraph_ratio_size_$algo
		echo "$partRatio `../VertexCover -in graph.txt -a $algo | grep "^cover found" | cut -d" " -f4`" >> bench/vc_bGraph_ratio_time_$algo
	done
	gnuplot gnuplot_scripts/vc_bGraph_ratio
done

vertexCount=1000
partRatio=40
for algo in `seq 0 4`
do
	echo "" > bench/vc_bGraph_eProb_size_$algo
	echo "" > bench/vc_bGraph_eProb_time_$algo
done


for proba in `seq 5 5 100`
do
	echo "$proba `../VertexCover -g 2 $vertexCount $proba $partRatio -out graph.txt -a 4 | grep "^cover size" | cut -d" " -f4`" >> bench/vc_bGraph_eProb_size_4 
	echo "$proba `../VertexCover -g 2 $vertexCount $proba $partRatio -a 4 | grep "^cover found" | cut -d" " -f4`" >> bench/vc_bGraph_eProb_time_4
	for algo in `seq 0 3`
	do
		echo $proba
		echo "algo : $algo"
		echo "$proba `../VertexCover -in graph.txt -a $algo | grep "^cover size" | cut -d" " -f4`" >> bench/vc_bGraph_eProb_size_$algo
		echo "$proba `../VertexCover -in graph.txt -a $algo | grep "^cover found" | cut -d" " -f4`" >> bench/vc_bGraph_eProb_time_$algo
	done
	gnuplot gnuplot_scripts/vc_bGraph_eProb
done

edgeProba=10
partRatio=40
for algo in `seq 0 4`
do
	echo "" > bench/vc_bGraph_vCount_size_$algo
	echo "" > bench/vc_bGraph_vCount_time_$algo
done
for vertexCount in `seq 100 100 3000`
do
	echo $vertexCount
	echo "$vertexCount `../VertexCover -g 2 $vertexCount $edgeProba $partRatio -out graph.txt -a 4 | grep "^cover size" | cut -d" " -f4`" >> bench/vc_bGraph_vCount_size_4 
	echo "$vertexCount `../VertexCover -g 2 $vertexCount $edgeProba $partRatio -a 4 | grep "^cover found" | cut -d" " -f4`" >> bench/vc_bGraph_vCount_time_4
	for algo in `seq 0 3`
	do
		echo "algo : $algo"
		echo "$vertexCount `../VertexCover -in graph.txt -a $algo | grep "^cover size" | cut -d" " -f4`" >> bench/vc_bGraph_vCount_size_$algo
		echo "$vertexCount `../VertexCover -in graph.txt -a $algo | grep "^cover found" | cut -d" " -f4`" >> bench/vc_bGraph_vCount_time_$algo
	done
	gnuplot gnuplot_scripts/vc_bGraph_vCount
done
