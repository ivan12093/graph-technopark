#include <iostream>

#include "graph.h"
#include "graph_arc.h"
#include "graph_list.h"
#include "graph_set.h"
#include "graph_matrix.h"

int main() {
    ListGraph list_graph(6);
    list_graph.AddEdge(1, 3);
    list_graph.AddEdge(2, 1);
    list_graph.AddEdge(2, 4);
    list_graph.AddEdge(3, 4);
    list_graph.AddEdge(4, 5);
    list_graph.AddEdge(5, 3);
    list_graph.AddEdge(5, 4);

    IGraph& graph = list_graph;

    std::cout << "LIST GRAPH BFS: ";
    BFS(graph, 2, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n";

    MatrixGraph matrix_graph(graph);
    graph = matrix_graph;

    std::cout << "MATRIX GRAPH BFS: ";
    BFS(graph, 2, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n";

    ArcGraph arc_graph(graph);
    graph = arc_graph;

    std::cout << "ARC GRAPH BFS: ";
    BFS(graph, 2, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n";

    SetGraph set_graph(graph);
    graph = set_graph;

    std::cout << "SET GRAPH BFS: ";
    BFS(graph, 2, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n";

    return 0;
}
