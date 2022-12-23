#include <cassert>
#include "graph_list.h"

ListGraph::ListGraph(int _vertices_count) : graph(_vertices_count), inv_graph(_vertices_count),
                                            vertices_count(_vertices_count) {}

ListGraph::ListGraph(const IGraph &other) : ListGraph(other.VerticesCount()) {
    for (int from = 0; from < vertices_count; ++from)
        for (int to : other.GetNextVertices(from)) {
            graph[from].push_back(to);
            inv_graph[to].push_back(from);
        }
}

void ListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices_count);
    assert(to >= 0 && to < vertices_count);

    graph[from].push_back(to);
    inv_graph[to].push_back(from);
}

int ListGraph::VerticesCount() const {
    return vertices_count;
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    return graph[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    return inv_graph[vertex];
}
