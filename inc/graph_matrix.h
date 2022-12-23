#ifndef GRAPH_TECHNOPARK_GRAPH_MATRIX_H
#define GRAPH_TECHNOPARK_GRAPH_MATRIX_H

#include <vector>

#include "graph.h"

struct MatrixGraph : public IGraph {
    MatrixGraph(int _vertices_count);
    MatrixGraph(const IGraph& other);
    virtual ~MatrixGraph() {}

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<bool>> matrix;
    int vertices_count;
};

#endif //GRAPH_TECHNOPARK_GRAPH_MATRIX_H
