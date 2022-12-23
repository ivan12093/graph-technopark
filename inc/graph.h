#ifndef GRAPH_TECHNOPARK_GRAPH_H
#define GRAPH_TECHNOPARK_GRAPH_H

#include <vector>

struct IGraph {
    virtual ~IGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

void BFS(const IGraph& graph, int vertex, void (*visit)(int));

#endif //GRAPH_TECHNOPARK_GRAPH_H
