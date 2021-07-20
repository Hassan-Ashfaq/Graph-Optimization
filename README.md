# Graph-Optimization
In this project, I implemented an Algorithm that Optimizes the input Bipartite Graph and minimizes the no. of cuts and crosses among each node in Bipartite Graph.

Command to Run this Project : "g++ Graph-Optimization.cpp"

Enter Filename to make Graph: Graph-I.txt

Iteration 1
Bipartite Graph

Layer 1
Node 1: [ 2 3 ]
Node 2: [ 2 4 ]
Node 3: [ 1 3 4 5 ]
Node 4: [ 1 2 3 ]
Node 5: [ 3 ]

Layer 2
Node 1: [ 3 4 ]
Node 2: [ 1 2 4 ]
Node 3: [ 1 3 4 5 ]
Node 4: [ 2 3 ]
Node 5: [ 3 ]

Node Id Layer 1 : [ 1 3 5 9 12 ]
Node Id Layer 2 : [ 5 1 2 4 8 ]
Cuts: [ 4 5 7 2 ]
Total Cuts: 18
Crossing: 19

--------------------------------

Iteration 2
Bipartite Graph

Layer 1
Node 1: [ 2 3 ]
Node 2: [ 2 4 ]
Node 3: [ 1 3 4 5 ]
Node 4: [ 1 2 3 ]
Node 5: [ 3 ]

Layer 2
Node 2: [ 1 2 4 ]
Node 3: [ 1 3 4 5 ]
Node 4: [ 2 3 ]
Node 1: [ 3 4 ]
Node 5: [ 3 ]

Node Id Layer 1 : [ 1 2 5 3 7 ]
Node Id Layer 2 : [ 1 4 8 10 12 ]
Cuts: [ 3 5 4 3 ]
Total Cuts: 15
Crossing: 14

--------------------------------

Iteration 3
Bipartite Graph

Layer 1
Node 1: [ 2 3 ]
Node 2: [ 2 4 ]
Node 4: [ 1 2 3 ]
Node 3: [ 1 3 4 5 ]
Node 5: [ 3 ]

Layer 2
Node 2: [ 1 2 4 ]
Node 3: [ 1 3 4 5 ]
Node 4: [ 2 3 ]
Node 1: [ 3 4 ]
Node 5: [ 3 ]

Node Id Layer 1 : [ 1 3 5 8 12 ]
Node Id Layer 2 : [ 1 2 4 7 11 ]
Cuts: [ 3 5 2 4 ]
Total Cuts: 14
Crossing: 11

--------------------------------

Iteration 4
Bipartite Graph

Layer 1
Node 1: [ 2 3 ]
Node 2: [ 2 4 ]
Node 4: [ 1 2 3 ]
Node 3: [ 1 3 4 5 ]
Node 5: [ 3 ]

Layer 2
Node 2: [ 1 2 4 ]
Node 3: [ 1 3 4 5 ]
Node 4: [ 2 3 ]
Node 1: [ 3 4 ]
Node 5: [ 3 ]

Node Id Layer 1 : [ 1 2 3 6 7 ]
Node Id Layer 2 : [ 1 4 8 10 12 ]
Cuts: [ 3 5 2 4 ]
Total Cuts: 14
Crossing: 11

--------------------------------
