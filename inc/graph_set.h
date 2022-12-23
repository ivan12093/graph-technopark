#ifndef GRAPH_TECHNOPARK_GRAPH_SET_HPP
#define GRAPH_TECHNOPARK_GRAPH_SET_HPP

#include <unordered_set>
#include <vector>

#include "graph.h"

struct SetGraph : public IGraph {
    SetGraph(int _vertices_count);
    SetGraph(const IGraph& other);
    virtual ~SetGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> graph;
    int vertices_count;
};


#endif //GRAPH_TECHNOPARK_GRAPH_SET_HPP
