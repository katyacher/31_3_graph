#include <iostream>
#include <memory>
#include <vector>
#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"


int main(int, char**){
    std::cout << "Hello, from 31_1_graph!\n";

    std::shared_ptr<IGraph> ptr_mtrx = std::make_shared<MatrixGraph>();
    ptr_mtrx->AddEdge(0, 5);
    ptr_mtrx->AddEdge(1, 2);
    ptr_mtrx->AddEdge(1, 3);
    ptr_mtrx->AddEdge(2, 4);
    ptr_mtrx->AddEdge(2, 0);
    ptr_mtrx->AddEdge(4, 5);

    ptr_mtrx->ShowGraph();

    std::shared_ptr<IGraph> ptr_list = std::make_shared<ListGraph>(ptr_mtrx.get());
    ptr_list->ShowGraph();

    std::shared_ptr<IGraph> ptr_list2 = std::make_shared<ListGraph>();

    ptr_list2 = ptr_list;

    ptr_list2->ShowGraph();

    std::shared_ptr<IGraph> ptr_mtrx2 = std::make_shared<MatrixGraph>(ptr_list2.get());
    ptr_mtrx2->ShowGraph();
    
    return 0; 
}
