#!/bin/bash

Usage() {
	echo "$0 : prog_name"
}

if [ $# -ne 1 ]
then
	Usage
	exit 1
fi

echo "" > bench/cover_bGraph.optimal
echo "test algos on bipartite graphs"
for vertexCount in `seq 0 100 5000`
do
	r1 = `$1 -g 2 $vertexCount 0.5 0.5 -a 4`
	r2 = `$1 -g 2 $vertexCount 0.5 0.5 -a 4`
	r3 = `$1 -g 2 $vertexCount 0.5 0.5 -a 4`
	r4 = `$1 -g 2 $vertexCount 0.5 0.5 -a 4`
	for result in r1, r2, r3, r4
	do
		echo "$vertexCount `grep -E "^cover found" $result | cut -d " " -f4`" >> bench/cover_bGraph.optimal
	done
done


echo "" > bench/gen.simpleGraph
echo "" > bench/gen.smallCover
echo "" > bench/gen.bipartite
echo "" > bench/gen.tree
echo "" > bench/gen.treeStat
for vertexCount in `seq 0 100 10000`
do
	echo "$vertexCount `$1 -g 3 $vertexCount | cut -d" " -f4`" >> bench/gen.tree
	echo "$vertexCount `$1 -g 3 $vertexCount 10 | cut -d" " -f4`" >> bench/gen.treeStat
	gnuplot gnuplot_generation_tree
done

for vertexCount in `seq 0 100 10000`
do
	echo "$vertexCount"
	echo "$vertexCount `$1 -g 0 $vertexCount 0.4 | cut -d" " -f4`" >> bench/gen.simpleGraph
	let "cover = vertexCount / 2"
	echo "$vertexCount `$1 -g 1 $vertexCount 0.4 $cover | cut -d" " -f4`" >> bench/gen.smallCover
	echo "$vertexCount `$1 -g 2 $vertexCount 0.4 0.6 | cut -d" " -f4`" >> bench/gen.bipartite
	gnuplot gnuplot_generation
	for algo in `seq 0 3`
	do
		echo "algo : $algo"
		echo "$vertexCount `./VertexCover -g 0 $vertexCount 0.4 -a $algo | grep -E "^cover" | cut -d" " -f4`" >> bench/cover_simpleGraph_vCount.$algo
	done
	for cover
	gnuplot gnuplot_vc_simpleGraph
done


