#include <cassert>
#include "graph_arc.h"

ArcGraph::ArcGraph(int _vertices_count) : graph(), vertices_count(_vertices_count) {}

ArcGraph::ArcGraph(const IGraph &other) : graph(), vertices_count(other.VerticesCount()) {
    for (int from = 0; from < vertices_count; ++from)
        for (int to : other.GetNextVertices(from))
            graph.push_back(std::make_pair(from, to));
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices_count);
    assert(to >= 0 && to < vertices_count);

    graph.push_back(std::make_pair(from, to));
}

int ArcGraph::VerticesCount() const {
    return vertices_count;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    std::vector<int> result;
    for (auto [from, to] : graph)
        if (from == vertex)
            result.push_back(to);
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    std::vector<int> result;
    for (auto [from, to] : graph)
        if (to == vertex)
            result.push_back(from);
    return result;
}
