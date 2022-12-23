#include <cassert>
#include "graph_matrix.h"

MatrixGraph::MatrixGraph(int _vertices_count) : matrix(_vertices_count), vertices_count(_vertices_count) {
    for (int i = 0; i < vertices_count; ++i)
        matrix[i].assign(vertices_count, false);
}

MatrixGraph::MatrixGraph(const IGraph &other) : MatrixGraph(other.VerticesCount()) {
    vertices_count = other.VerticesCount();
    for (int from = 0; from < vertices_count; ++from)
        for (int to : other.GetNextVertices(from))
            matrix[from][to] = true;
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices_count);
    assert(to >= 0 && to < vertices_count);

    matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return vertices_count;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    std::vector<int> result;
    for (int i = 0; i < vertices_count; ++i)
        if (matrix[vertex][i])
            result.push_back(i);
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count);
    std::vector<int> result;
    for (int i = 0; i < vertices_count; ++i)
        if (matrix[i][vertex])
            result.push_back(i);
    return result;
}
