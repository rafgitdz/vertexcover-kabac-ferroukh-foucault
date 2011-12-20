#!/bin/bash

echo "" > bench/parametric_cs
echo "" > bench/parametricbis_cs
vertexCount=100
for coverSize in `seq 5 20`
do
	../VertexCover -g 1 $vertexCount 40 $coverSize -out smallCover.txt
	echo "$coverSize `../VertexCover -in smallCover.txt -a 6 $coverSize | grep "^cover found" | cut -d" " -f4`" >> bench/parametric_cs
	echo "$coverSize `../VertexCover -in smallCover.txt -a 7 $coverSize | grep "^cover found" | cut -d" " -f4`" >> bench/parametricbis_cs
	gnuplot gnuplot_scripts/vc_parametric_cSize
done
