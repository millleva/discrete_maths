#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

#define V 13

int algorithm(int graph[V][V], int source, int dest) {
  int residualGraph[V][V];
  for (int u = 0; u < V; u++){
    for (int v = 0; v < V; v++) residualGraph[u][v] = graph[u][v];
  }

  int parent[V];
  int maxFlow = 0;

  while (true){
    queue<int> q;
    q.push(source);
    fill(parent, parent + V, -1);
    parent[source] = -2;
    while (!q.empty()){
      int u = q.front();
      q.pop();

      for (int v = 0; v < V; v++){
        if (parent[v] == -1 && residualGraph[u][v] > 0){
          parent[v] = u;
          q.push(v);
        }
      }
    }
    if (parent[dest] == -1) break;

    int pathFlow = INT_MAX;
    for (int v = dest; v != source; v = parent[v]){
      int u = parent[v];
      pathFlow = min(pathFlow, residualGraph[u][v]);
    }

    for (int v = dest; v != source; v = parent[v]) {
      int u = parent[v];
      residualGraph[u][v] -= pathFlow;
      residualGraph[v][u] += pathFlow;
    }

    maxFlow += pathFlow;
  }

  return maxFlow;
}

int main() {
    int graph[V][V] = {
        {0, 3, 5, 4, 6, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0},
        {0, 3, 2, 3, 0, 0, 0, 0, 2, 1, 4, 0, 0},
        {0, 0, 3, 0, 3, 0, 0, 0, 0, 1, 0, 5, 0},
        {0, 3, 0, 1, 2, 0, 0, 0, 3, 0, 5, 4, 0},
        {0, 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 4, 0, 5, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 0, 0, 5, 2, 9, 9, 0}
    };

    int source = 0;
    int dest = 12;
    int maxFlow = algorithm(graph, source, dest);

    cout << "Maximal flow: " << maxFlow << endl;

    return 0;
}