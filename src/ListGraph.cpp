#include <iostream>
#include <map>
#include <vector>
#include "ListGraph.h"
#include "MatrixGraph.h"



ListGraph::ListGraph(){
    std::cout << "ListGraph() is constructed" << std::endl;
};

ListGraph::~ListGraph(){
    std::cout << "~ListGraph()" << std::endl;
};


ListGraph::ListGraph(IGraph *oth){
    MatrixGraph *matrix = dynamic_cast<MatrixGraph *>(oth);
    if (matrix){
        if(matrix->VerticesCount() != 0){
            for (int i = 0;  i < matrix->VerticesCount(); ++i){
                std::vector<int> next_vertices;
                matrix->GetNextVertices(i, next_vertices);

                if(next_vertices.size() != 0){
                    adjList[i] = next_vertices;
                } else {
                    std::vector<int> prev_vertices;
                    matrix->GetPrevVertices(i, prev_vertices);
                    if (prev_vertices.size() != 0){
                        adjList[i] = std::vector<int>();
                    }
                }
            }
        }
    }else {
        std::cout << "No convert list to list" << std::endl;
    }

};

void ListGraph::AddEdge(int from, int to){
    if(from < 0 || to < 0){
        std::cout << "Incrrect value" << std::endl;
        return;
    }

    std::vector<int> vertices{to};
    auto it = adjList.insert(std::make_pair(from, vertices));

    //если вершина уже есть, то добавляем смежную вершину в вектор
    if (!it.second){
        it.first->second.push_back(to);
    }

    //adjList[from].push_back(to); то же самое, что выше

    //если добавляется новая вершина
    if(adjList.find(to) == adjList.end()){
        adjList[to] = std::vector<int>();
    }        
}; 

int ListGraph::VerticesCount() const{
    return adjList.size();
}; 

   
void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {

    auto it = adjList.find(vertex);

    if(it != adjList.end()){
        vertices.clear();
        for(auto &adj_vertex : it->second)
            vertices.push_back(adj_vertex);
    }else{
        std::cout<< "Incorect vertex" << std::endl;
    }
};

   
void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const{

    auto it = adjList.find(vertex);

    if(it != adjList.end()){
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

void  ListGraph::ShowGraph() const{
    for(auto &vertex: adjList){
        std::cout << vertex.first << "-> (";

        for(auto &adj_vertex : vertex.second)
            std::cout << adj_vertex << ",";
        
        std::cout <<")" << std::endl;
    }
};
