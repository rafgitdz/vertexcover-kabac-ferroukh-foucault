#!/bin/bash

echo "" > bench/gen.simpleGraph
echo "" > bench/gen.smallCover
echo "" > bench/gen.bipartite
echo "" > bench/gen.tree
echo "" > bench/gen.treeStat
for vertexCount in `seq 0 100 10000`
do
	echo "$vertexCount"
	echo "$vertexCount `./VertexCover -g 0 $vertexCount 0.4 | cut -d" " -f4`" >> bench/gen.simpleGraph
	let "cover = vertexCount / 2"
	echo "$vertexCount `./VertexCover -g 1 $vertexCount 0.4 $cover | cut -d" " -f4`" >> bench/gen.smallCover
	echo "$vertexCount `./VertexCover -g 2 $vertexCount 0.4 0.6 | cut -d" " -f4`" >> bench/gen.bipartite
	echo "$vertexCount `./VertexCover -g 3 $vertexCount | cut -d" " -f4`" >> bench/gen.tree
	echo "$vertexCount `./VertexCover -g 3 $vertexCount 10 | cut -d" " -f4`" >> bench/gen.treeStat
	gnuplot gnuplot_generation
	for algo in `seq 0 3`
	do
		echo "algo : $algo"
		echo "$vertexCount `./VertexCover -g 0 $vertexCount 0.4 -a $algo | cut -d" " -f9`" >> bench/cover_simpleGraph_vCount.$algo
	done
	for cover
	gnuplot gnuplot_vc_simpleGraph
done
