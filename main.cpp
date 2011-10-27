<<<<<<< HEAD
#include <iostream>
#include "Graph.h"
#include "SmallCoverGraph.h"

using namespace std;

int main()
{
    Graph g;
    int v = g.addVertex();
    int v2 = g.addVertex();
    g.addEdge(v,v2);
    cout << g << endl;

    SmallCoverGraph g1(10, 0.25, 3);
    cout << g1;

    return 0;
}
=======
#include <iostream>
#include "TreeDynamicComplete.h"
#include "TreeDynamicSons.h"
#include "TreeStaticSons.h"

using namespace std;

int main() {
   // TreeStaticSonsAndRoots t2(10,2);
    TreeStaticSonsAndRoots t(15,2);
    cout << t << endl;
    return 0;
}
>>>>>>> MyRepository/master
