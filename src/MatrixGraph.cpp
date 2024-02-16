#include <iostream>
#include <IGraph.h>

class MatrixGraph: public IGraph {
private:
    bool** adjMatrix;
    int numVertices;
public:
     MatrixGraph(int numVert): numVertices(numVert){
        adjMatrix = new bool*[numVert];
        for (int i = 0; i < numVert; i++) {
            adjMatrix[i] = new bool[numVert];
            for (int j = 0; j < numVert; j++)
                adjMatrix[i][j] = false;
        }
    }
    
    ~MatrixGraph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }

    MatrixGraph(IGraph *oth){};

    void AddEdge(int i, int j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
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
            std::cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                std::cout << adjMatrix[i][j] << " ";
            std::cout << "\n";
        }
    }
};
