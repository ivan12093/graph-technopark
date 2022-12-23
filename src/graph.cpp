#include <vector>
#include <queue>

#include "graph.h"

void BFS(const IGraph& graph, int vertex, void (*visit)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> queue;
    queue.push(vertex);
    visited[vertex] = true;
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        visit(current);
        for (int next : graph.GetNextVertices(current))
            if (!visited[next]) {
                queue.push(next);
                visited[next] = true;
            }
    }
}
