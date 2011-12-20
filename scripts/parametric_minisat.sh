#!/bin/bash

edgeProba=0.4
for algo in 6 7 8 9
do
	echo "" > bench/param_minisat_size.$algo
	echo "" > bench/param_minisat_time.$algo
done

for vertexCount in `seq 2 50`
do
	let "coverSize = vertexCount/2"
	for algo in 6 7 9
	do
		echo "algo : $algo"
		./VertexCover -g 1 $vertexCount $edgeProba $coverSize -out graph.txt
		echo "$vertexCount `./VertexCover -in graph.txt -a $algo $coverSize | grep -E "^cover size" | cut -d" " -f4`" >> bench/param_minisat_size.$algo
		echo "$vertexCount `./VertexCover -in graph.txt -a $algo $coverSize | grep -E "^cover found" | cut -d" " -f4`" >> bench/param_minisat_time.$algo		
	done
	gnuplot gnuplot_param_minisat_time
	gnuplot gnuplot_param_minisat_size
done 
