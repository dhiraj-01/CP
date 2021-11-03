### Articulation Point
A vertex v is an articulation point (also called cut vertex) if removing v increases the number of connected components.

### Bridge
An edge in an undirected connected graph is a bridge iff removing it disconnects the graph (increases the number of connected components).

### Learn
- http://www.cs.kent.edu/~aleitert/iga/slides/04ArtPointsBridges.pdf
- https://www.youtube.com/watch?v=aZXi1unBdJA
- https://codeforces.com/blog/entry/71146

### Problems
- https://www.spoj.com/problems/SUBMERGE/
- https://leetcode.com/problems/critical-connections-in-a-network/

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll n, m;
using edge = ll;
vector<vector<edge>> g;
vector<bool> vis;

vector<ll> lvl; 
// level of node in dfs tree
// level[node] = 1 + level[parent[node]]

vector<ll> low; 
// low[u] = min level node we can reach by atmost 1 back edge in dfs tree

vector<bool> ap; 
// is articulation point?

vector<pair<ll, ll>> bridges;

void clearAll(ll nn)
{
    nn += 1;
    g.assign(nn, vector<edge>());
    vis.assign(nn, 0);
    lvl.assign(nn, 0);
    low.assign(nn, -1);
    ap.assign(nn, 0);
    bridges.clear();
}

void dfs(ll u, ll p)
{
    vis[u] = 1;
    lvl[u] = low[u] = 1 + lvl[p];
    ll child = 0;
    for(ll v : g[u])
    {
        if(v == p) continue;
        if(!vis[v])
        {
            // forward edge (u, v)
            child++;
            dfs(v, u);
            if(u == 1) {
                // The root is an articulation point if and only if 
                // it has at least two children in the DFS-tree
                ap[u] = (child > 1);
            }
            else if(low[v] >= lvl[u]) {
                // u is articulation point
                ap[u] = 1; 
            }

            if(low[v] > lvl[u]) {
                // (u, v) is bridge
                bridges.push_back({u, v});
            }
            low[u] = min(low[u], low[v]);
        }
        else
        {
            /*
            back edge (u, v)
            update with lvl[v], not low[v] because we can use only 1 back edge.
            only 1 back edge because (we can't go through multiple subtree)
            
                root
                |
                |
            --- w (p, w) is back edge
            |   .
            |   .
            |   (we are here)
            |   u----------
            |  / \        | (r, u) is back edge 
            | /   \       |
            |/     \      |
            p       q     |
                     \    |
                      \   |
                       r --

            here we can't use 2 back edges
            (r, u) and (p, w) to reach w from r or q
            path: r - u - p - w or q - r - u - p - w
            
            because if we remove u, both subtree will be disconnect.
            that's why only 1 back edge.

            back edge is not a bridge
            */
            low[u] = min(low[u], lvl[v]);   
        }
    }
}

void solve(ll& tc)
{
    cin >> n >> m;
    clearAll(n);
    
    for(ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1, 0);

    // print all ap
    for(ll i = 1; i <= n; i++) {
        if(ap[i]) {
            cout << i << " is articulation point\n";
        }
    }

    // print bridges
    for(auto [u, v] : bridges) {
        cout << "bridge: [" << u << ", " << v << "]" << endl;
    }
}

int main() {
    ll tc = 1;
    for(ll i = 1; i <= tc; i++) {
        solve(i);
    }
    return 0;
}
```