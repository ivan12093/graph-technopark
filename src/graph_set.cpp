#include <cassert>
#include "graph_set.h"

SetGraph::SetGraph(int _vertices_count) : graph(_vertices_count), vertices_count(_vertices_count) {}

SetGraph::SetGraph(const IGraph &other) : SetGraph(other.VerticesCount()) {
    for (int from = 0; from < vertices_count; ++from)
        for (int to : other.GetNextVertices(from))
            graph[from].insert(to);
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices_count);
    assert(to >= 0 && to < vertices_count);

    graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return vertices_count;
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    std::vector<int> result;
    for (int v : graph[vertex])
        result.push_back(v);
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    std::vector<int> result;
    for (int i = 0; i < vertices_count; ++i)
        if (graph[i].find(vertex) != graph[i].end())
            result.push_back(i);
    return result;
}
