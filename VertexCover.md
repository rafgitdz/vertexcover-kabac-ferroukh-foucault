

&lt;H1&gt;

FIX Me!

&lt;/H1&gt;





&lt;H2&gt;

NAME

&lt;/H2&gt;



VertexCover - Gets a vertex cover from a randomly generated graph, or from a formatted entry


&lt;H2&gt;

SYNOPSIS

&lt;/H2&gt;





&lt;B&gt;

VertexCover {[

&lt;/B&gt;




&lt;I&gt;

inputFile

&lt;/I&gt;




&lt;B&gt;

] | [ -g

&lt;/B&gt;




&lt;I&gt;

graphType 

&lt;args&gt;



Unknown end tag for &lt;/I&gt;



&lt;B&gt;

]} [ -a

&lt;/B&gt;



&lt;I&gt;

algorithm 

&lt;args&gt;



Unknown end tag for &lt;/I&gt;




&lt;B&gt;

]

&lt;/B&gt;





&lt;H2&gt;

DESCRIPTION

&lt;/H2&gt;



This program, developed during an academic project at the university of bordeaux, returns a vertex cover of a generated (or given as input) graph, using one of the algorithms described below



&lt;H2&gt;

OPTIONS

&lt;/H2&gt;



<DL COMPACT>


&lt;DT&gt;

-g, --generate-graph

&lt;DD&gt;


Randomly generates a graph, using one of the algorithms, according to the first parameter:


&lt;BR&gt;





&lt;BR&gt;





&lt;B&gt;

0 n p

&lt;/B&gt;



: Generates a graph with n vertices, and a probability  p to draw an edge between two vertices (p must be between 0 an 1)


&lt;BR&gt;





&lt;B&gt;

1 n p c

&lt;/B&gt;



: Generates a graph with n vertices, a probability p to draw an edge between two vertices (p must be between 0 an 1), and with a vertex cover with c vertices


&lt;BR&gt;





&lt;B&gt;

2 n p r

&lt;/B&gt;



: Generates a bipartite graph with n vertices,a probability p to draw an edge between two vertices, and a ratio r between the two parts of a graph (p and r must be between 0 an 1)


&lt;BR&gt;





&lt;B&gt;

3 n

&lt;/B&gt;



: Generates a tree with n vertices


&lt;BR&gt;





&lt;B&gt;

4 n s

&lt;/B&gt;



: Generates a tree with n vertices, where each vertex has s sons


&lt;DT&gt;

-a, --algorithm

&lt;DD&gt;


Launches an algorithm for the generated graph or input graph,according to the first parameter


&lt;BR&gt;





&lt;BR&gt;





&lt;B&gt;

0 

&lt;/B&gt;



: Uses the greedy algorithm


&lt;BR&gt;





&lt;B&gt;

1

&lt;/B&gt;



: Uses the greedy simple algorithm


&lt;BR&gt;





&lt;B&gt;

2

&lt;/B&gt;



: Uses the 2-approached &quot;cover edges&quot; algorithm


&lt;BR&gt;





&lt;B&gt;

3

&lt;/B&gt;



: Uses the 2-approached algorithm based on a deep search tree


&lt;BR&gt;





&lt;B&gt;

4

&lt;/B&gt;



: Uses the optimal algorithm for bipartite graphs (for now, it can only be used with a generated graph)


&lt;BR&gt;





&lt;B&gt;

5

&lt;/B&gt;



: Uses the optimal algorithm for trees (for now, it can only be used with a generated tree)


&lt;BR&gt;





&lt;B&gt;

{ 6 | 7 } s

&lt;/B&gt;



: Uses the first | second recursive algoritm, which will try to find a cover with at most s vertices (you should avoid the use of this algorithm for large covers)


&lt;BR&gt;





&lt;B&gt;

8

&lt;/B&gt;



: Uses minisat to find a cover


&lt;BR&gt;





&lt;B&gt;

9 s

&lt;/B&gt;



: Uses minisat to try to find a cover with at most s vertices (you should avoid the use of this algorithm for large covers)


&lt;DT&gt;

-dot

&lt;DD&gt;


Generates a visual result of the vertex cover, as a png file (generated with dot)


&lt;DT&gt;

-h, --help

&lt;DD&gt;


prints usage and exits


&lt;DT&gt;

-t, --test

&lt;DD&gt;


Launches a serie of tests to ensure that each algorithm returns a vertex cover


Unknown end tag for &lt;/DL&gt;




&lt;A NAME="lbAF"&gt;

&nbsp;

&lt;/A&gt;




&lt;H2&gt;

AUTHOR

&lt;/H2&gt;





&lt;P&gt;



Written by Milan Kabac, Rafik Ferroukh and Matthieu Foucault


&lt;BR&gt;



Masters Degrees at University of Bordeaux


&lt;A NAME="lbAG"&gt;

&nbsp;

&lt;/A&gt;




&lt;H2&gt;

COPYRIGHT

&lt;/H2&gt;



Copyright (C) 2011  Milan Kabac, Rafik Ferroukh and Matthieu Foucault


&lt;P&gt;




&lt;P&gt;


This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.


&lt;P&gt;


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.


&lt;P&gt;


You should have received a copy of the GNU General Public License
along with this program.  If not, see &lt;

&lt;A HREF="http://www.gnu.org/licenses/"&gt;

http://www.gnu.org/licenses/

&lt;/A&gt;

&gt;.