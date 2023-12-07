#include <iostream>
#include <list>

class ListGraph{
    int numVertices;
    std::list<int> *adjLists;
 
public:
    ListGraph(int V);
    void addEdge(int src, int dest);
};
 
ListGraph::ListGraph(int vertices)
{
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
}
 
void ListGraph::addEdge(int src, int dest)
{
    adjLists[src].push_front(dest);
}

ListGraph::~ListGraph(){
    delete adjLists;
}
 