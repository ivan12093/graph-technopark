#ifndef GRAPH_TECHNOPARK_GRAPH_LIST_H
#define GRAPH_TECHNOPARK_GRAPH_LIST_H

#include <vector>

#include "graph.h"

struct ListGraph : public IGraph {
    ListGraph(int _vertices_count);
    ListGraph(const IGraph& other);
    virtual ~ListGraph() {}

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> inv_graph;
    int vertices_count;
};

#endif //GRAPH_TECHNOPARK_GRAPH_LIST_H
