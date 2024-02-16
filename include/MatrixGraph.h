#pragma once
#include <iostream>
#include <IGraph.h>

class MatrixGraph: public IGraph {
    private:
        bool** adjMatrix;
        int numVertices;
    public:
        MatrixGraph(int numVert): numVertices(numVert){};

        ~MatrixGraph();

        MatrixGraph(IGraph *oth);

        // Метод принимает вершины начала и конца ребра и добавляет ребро
        void AddEdge(int from, int to) override;

        // Метод должен считать текущее количество вершин
        int VerticesCount() const override;

        // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
        void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

        // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
        void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

        void ShowGraph() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                std::cout << adjMatrix[i][j] << " ";
            std::cout << "\n";
        }
    }

};
