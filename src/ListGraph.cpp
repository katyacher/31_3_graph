#include <iostream>
#include <map>
#include <IGraph.h>

class ListGraph: public IGraph{
    std::map<int, std::vector<int>> adjList; //adjacency
 
public:
    ListGraph(){
        std::cout << "ListGraph constructor";
    }

    ~ListGraph(){
        std::cout << "ListGraph destructor";
    }

    ListGraph(IGraph *oth){};// конструктор копирования

    void AddEdge(int from, int to){
        if(from < 0 || to < 0){
            std::cout << "Incrrect value" << std::endl;
            return;
        }

        adjList[from].push_back(to);

        if(adjList.find(to) == adjList.end()){
            adjList[to] = std::vector<int>();
        }        
    }; // Метод принимает вершины начала и конца ребра и добавляет ребро

    int VerticesCount() const{
        return adjList.size();
    }; // Метод должен считать текущее количество вершин

    // Для конкретной вершины метод выводит в вектор «вершины» все вершины, в которые можно дойти по ребру из данной
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const {
        auto it = adjList.find(vertex);

        if(it != adjList.end()){
            vertices.clear();
            for(auto &vert : it->second)
                vertices.push_back(vert);
            }
        else
        {
            std::cout<< "Incorect vertex" << std::endl;
        }
    };

    // Для конкретной вершины метод выводит в вектор «вершины» все вершины, из которых можно дойти по ребру в данную 
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const{
        auto it_check = adjList.find(vertex);
        if(it_check != adjList.end()){
            vertices.clear();
            for(auto &adj: adjList){
               for(int i = 0; i < adj.second.size(); i++){
                    if(vertex == adj.second[i]){
                        vertices.push_back(adj.first);
                    }
                }   
            }
        }
    }; 
};