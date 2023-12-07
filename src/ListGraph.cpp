#include <iostream>
#include <list>
#include <IGraph.h>

class ListGraph: public IGraph{
    int numVertices;
    std::list<int> *adjLists;
 
public:
    ListGraph(int vertices){
        numVertices = vertices;
        adjLists = new std::list<int>[vertices];
    }

    ~ListGraph(){
        delete adjLists;
    }

    ListGraph(IGraph *oth){};

    void AddEdge(int src, int dest){
        adjLists[src].push_front(dest);
    } // Метод принимает вершины начала и конца ребра и добавляет ребро

    int VerticesCount() const{

    }; // Метод должен считать текущее количество вершин

    // Для конкретной вершины метод выводит в вектор «вершины» все вершины, в которые можно дойти по ребру из данной
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const {

    };

    // Для конкретной вершины метод выводит в вектор «вершины» все вершины, из которых можно дойти по ребру в данную 
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const{

    }; 

    void toString() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << adjLists << " ";//доделать
        }
    }
};


 /*
ListGraph::ListGraph(int vertices)
{
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
}
 
void ListGraph::AddEdge(int src, int dest)
{
    adjLists[src].push_front(dest);
}

ListGraph::~ListGraph(){
    delete adjLists;
}
 */