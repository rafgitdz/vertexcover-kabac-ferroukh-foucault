#!/bin/bash

# This scripts launches a serie of graph generations, to monitor their 
# generation time, and the impact of various parameters on this time
# We use gnuplot to draw performance graphs


# We monitor the impact of the part ratio on the generation time of a bipartite graph
# TODO : verify the correctness of this test
echo "" > bench/gen_bipart_ratio
vertexCount=3000
for partRatio in `seq 5 5 95`
do
	echo "$partRatio `../VertexCover -g 2 $vertexCount 50 $partRatio | grep "^graph" | cut -d" " -f4`" >> bench/gen_bipart_ratio
	gnuplot gnuplot_scripts/gen_bipart_ratio
done



# We monitor the generation time of a tree, with a satic depth
echo "" > bench/gen_tree_vCount
for vertexCount in `seq 0 100 30000`
do
	let "numSons =  vertexCount / 10"
	echo "$vertexCount `../VertexCover -g 3 $vertexCount $numSons $numSons | grep "^graph" | cut -d" " -f4`" >> bench/gen_tree_vCount
	gnuplot gnuplot_scripts/gen_tree_vCount
done


# We monitor the generation time of the simple, small cover, and bipartite graph,
# for a number of vertices from 0 to 10000
echo "" > bench/gen_simple_vCount
echo "" > bench/gen_smallCover_vCount
echo "" > bench/gen_bipart_vCount
for vertexCount in `seq 0 100 10000`
do
	echo "vertex count: $vertexCount"
	echo "$vertexCount `../VertexCover -g 0 $vertexCount 40 | grep "^graph" | cut -d" " -f4`" >> bench/gen_simple_vCount
	let "cover = vertexCount / 2"
	echo "$vertexCount `../VertexCover -g 1 $vertexCount 40 $cover | grep "^graph" | cut -d" " -f4`" >> bench/gen_smallCover_vCount
	echo "$vertexCount `../VertexCover -g 2 $vertexCount 40 50 | grep "^graph" | cut -d" " -f4`" >> bench/gen_bipart_vCount
	gnuplot gnuplot_scripts/gen_all_vCount
done

# We monitor the impact of the size of the cover on the generation time of a small cover graph
echo "" > bench/gen_smallCover_cSize
vertexCount=3000
for coverSize in `seq 10 10 $vertexCount`
do
	echo "cover size: $coverSize"
	echo "$coverSize `../VertexCover -g 1 $vertexCount 10 $coverSize | grep "^graph" | cut -d" " -f4`" >> bench/gen_smallCover_cSize
	gnuplot gnuplot_scripts/gen_smallCover_cSize
done







echo "done!"
