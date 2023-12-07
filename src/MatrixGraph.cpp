#include <iostream>
#include <IGraph.h>

class MatrixGraph: public IGraph {
private:
    bool** adjMatrix;
    int numVertices;
public:
    MatrixGraph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new bool*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
        }
    }
 
    void AddEdge(int i, int j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }
 
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }
 
    bool isEdge(int i, int j) {
        return adjMatrix[i][j];
    }

    void toString() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                std::cout << adjMatrix[i][j] << " ";
            std::cout << "\n";
        }
    }

 
    ~MatrixGraph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};
