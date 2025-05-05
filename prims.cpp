#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

void prim(int n, vector<pii> g[]) {
    vector<bool> vis(n, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); // cost, node
    int cost = 0;
    
    while(!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        cost += w;
        cout << "Include: " << u << " (cost: " << w << ")\n";
        for(auto [v, wt] : g[u])
            if(!vis[v]) pq.push({wt, v});
    }
    cout << "Total cost: " << cost << "\n";
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<pii> g[n];
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    prim(n, g);
}
