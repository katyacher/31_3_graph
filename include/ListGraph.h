#include <iostream>
#include <map>
#include <IGraph.h>

class ListGraph: public IGraph{

    std::map<int, std::vector<int>> adjList; //список смежности
 
public:
    ListGraph(){};

    ~ListGraph(){};
      
    ListGraph(IGraph *oth){};

    // Метод принимает вершины начала и конца ребра и добавляет ребро
    void AddEdge(int from, int to) override;

    // Метод должен считать текущее количество вершин
    int VerticesCount() const  override;

    // Для конкретной вершины метод выводит в вектор «вершины» все вершины, в которые можно дойти по ребру из данной
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    // Для конкретной вершины метод выводит в вектор «вершины» все вершины, из которых можно дойти по ребру в данную 
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const  override;

    // Вывод графа в консоль 
    void ShowGraph() const;

    //Получить список вершин
    void GetVertices(std::vector<int> &vertices);

};