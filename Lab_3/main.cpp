#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 12;

struct edge {
    int to, w;
    edge(int _to, int _w) : to(_to), w(_w) {}
};

vector<edge> adj[MAXN];
bool vis[MAXN];
int dist[MAXN];
int parent[MAXN];

int prim(int s, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        vis[i] = false;
        parent[i] = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) {
            continue;
        }

        vis[u] = true;

        for (auto e : adj[u]) {
            int v = e.to;
            int w = e.w;

            if (!vis[v] && dist[v] > w) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    int total_weight = 0;
    for (int i = 2; i <= n; i++) {
        total_weight += dist[i];
    }
    return total_weight;
}

int main() {
    int n = 11, m = 18;

    cout << "Enter " << m << " edges in the format 'u v w':\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Minimum spanning tree edges:\n";
    int weight = prim(1, n);
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << " " << i << " " << dist[i] << endl;
    }

    cout << "Total weight of the minimum spanning tree: " << weight << endl;

    return 0;
}