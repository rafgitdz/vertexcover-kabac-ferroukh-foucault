#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph g;
    int v = g.addVertex();
    int v2 = g.addVertex();
    g.addEdge(v,v2);
    cout << g << endl;
    return 0;
}
