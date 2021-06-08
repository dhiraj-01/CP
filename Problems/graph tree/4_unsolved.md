### Problem
```
You are given a rooted binary tree with weights on edges.
The distance between two nodes in this tree is the sum of the edge weights on
the path between the two nodes. SUM[u] is the sum of the distances between 
u and all the other nodes in the tree.

task1 : Calculate Sum[root]
task2 : Calculate the array SUM for all nodes 1 to N.

Example :
Input
n = total nodes
(u v w) edge u to v with weight w

9
1 2 50
1 3 10
2 6 10
2 7 10
7 8 3
7 9 4
3 4 30
3 5 20

Output
Sum[1] = 377
Sum[2] = 327
Sum[3] = 407
Sum[4] = 617
Sum[5] = 547
Sum[6] = 397
Sum[7] = 357
Sum[8] = 378
Sum[9] = 385 

Expected time complexity = O(N).
N = Number of node in given tree.
```

easy version https://cses.fi/problemset/task/1133/ 

### Solution
```
first try to calculate answer for root then we can easily calculate answer for it childs
sum[root] = sum[1] = find contribution for each edge = each edge (u, v) * subtree size of v (u is parent of v)
```

<details>
  <summary>Code c++</summary>
  
```cpp
ll n, m;
using edge = pair<ll, ll>;
vector<vector<edge>> g;
vector<ll> subtree_sz;
vector<ll> ans;

void clearAll(ll nn)
{
    nn += 1;
    g.assign(nn, vector<edge>());
    subtree_sz.assign(nn, 0);
    ans.assign(nn, 0);
}

void dfs1(ll u, ll p)
{
    subtree_sz[u] = 1;
    for(auto [v, w] : g[u])
    {
        if(v != p)
        {
            dfs1(v, u);
            ans[1] += w * subtree_sz[v];
            subtree_sz[u] += subtree_sz[v];
        }
    }
}

void dfs2(ll u, ll p)
{
    for(auto [v, w] : g[u])
    {
        if(v != p)
        {
            ans[v] = ans[u] - w * subtree_sz[v] + w * (n - subtree_sz[v]);
            dfs2(v, u);
        }
    }
}

void solve(ll &tc)
{
    cin >> n;
    clearAll(n);

    m = n - 1;    
    for(ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs1(1, 0);
    dfs2(1, 0);
    for(ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
```
</details>
