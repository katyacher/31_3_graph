#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(){
    std::cout << "MatrixGraph() is constructed" << std::endl;
};

MatrixGraph::MatrixGraph(int numVertices){

    adjMatrix.resize(numVertices);

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
    }

    std::cout << "MatrixGraph() is constructed" << std::endl;
}
    
MatrixGraph::~MatrixGraph() {
    std::cout << "~MatrixGraph()" << std::endl;
}

MatrixGraph::MatrixGraph(IGraph *oth){
    ListGraph* list = dynamic_cast<ListGraph*>(oth);
    if(list){
        int size = list->VerticesCount();
        for(int i = 0; i < size; ++i){
            std::vector<int> next_vertices;
            list->GetNextVertices(i, next_vertices);
            for(auto &vertex: next_vertices){
                this->AddEdge(i, vertex);
            }
        }

        std::cout << "Convert List to Matrix" << std::endl;
    } else {
        std::cout << "No convert matrix to matrix" << std::endl;
    }
};

void MatrixGraph::AddEdge(int from, int to) {
    if(from < 0 || to < 0) {
        std::cout << "Incorrect value for new vertex." << std::endl;
        return;
    }

    int max = std::max(from, to);

    if(adjMatrix.size() <= max){
        //увеличить размер матрицы и проинициализировать новые поля значением false
        adjMatrix.resize(max+1);
        for(int i = 0; i <= max; ++i){
            adjMatrix[i].resize(max+1, false);
        }
    }

    adjMatrix[from][to] = true;

} 
 
int MatrixGraph::VerticesCount() const{
    return adjMatrix.size();
} 

   
void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if(vertex >= adjMatrix.size()){
        std::cout<< "Incorect vertex" << std::endl;
        return;
    }

    for (int j = 0; j < adjMatrix.size(); ++j){
        if (adjMatrix[vertex][j] == true){
            vertices.push_back(j);
        }
    }
};

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const{
    if(vertex >= adjMatrix.size()){
        std::cout<< "Incorect vertex" << std::endl;
        return;
    }

    for (int i = 0; i < adjMatrix.size(); ++i){
        if (adjMatrix[i][vertex] == true){
            vertices.push_back(i);
        }
    }
}; 

void MatrixGraph::ShowGraph() {

    std::cout<<"__";

    for(int top = 0; top < adjMatrix.size(); ++top)
        std::cout << top;

    std::cout << std::endl;

    for (int i = 0; i < adjMatrix.size(); i++) {
        std::cout << i << " | ";
        for (int j = 0; j < adjMatrix.size(); j++)
            std::cout << "\u001b;4;" << adjMatrix[i][j];
        std::cout << std::endl;
    }
};



