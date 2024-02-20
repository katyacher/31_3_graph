#pragma once
#include "IGraph.h"

class MatrixGraph: public IGraph {
    private:

        std::vector<std::vector<bool>> adjMatrix;

    public:
        MatrixGraph();

        MatrixGraph(int numVert);

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

        void ShowGraph() const override;

};
