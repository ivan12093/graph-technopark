#ifndef GRAPH_TECHNOPARK_GRAPH_ARC_H
#define GRAPH_TECHNOPARK_GRAPH_ARC_H

#include <vector>

#include "graph.h"

struct ArcGraph : public IGraph {
    ArcGraph(int _vertices_count);
    ArcGraph(const IGraph& other);
    virtual ~ArcGraph() {}

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::pair<int, int>> graph;
    int vertices_count;
};


#endif //GRAPH_TECHNOPARK_GRAPH_ARC_H
