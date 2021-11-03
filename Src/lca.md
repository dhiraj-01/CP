### LCA (Binary Lifting)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

using edge = ll;

ll n, m;
ll logn, timer;
vector<ll> lvl;
vector<ll> in, out;
vector<vector<edge>> g;
vector<vector<ll>> par;

void clearAll(ll nn)
{
    nn += 2;
    logn = log2(nn);
    lvl.assign(nn, 0);
    in.assign(nn, 0);
    out.assign(nn, 0);
    g.assign(nn, vector<edge>());
    par.assign(nn, vector<ll>(logn + 1, -1));
}

void dfs(ll u, ll p = -1)
{
    in[u] = timer++;
    for(ll& v : g[u])
    {
        if(v == p) continue;
        par[v][0] = u;
        lvl[v] = lvl[u] + 1;
        dfs(v, u);
    }
    out[u] = timer++;
}

// O(nlogn)
void lca_init()
{
    timer = 1;
    dfs(1);
    for(ll l = 1; l <= logn; l++)
    {
        for(ll i = 1; i <= n; i++)
        {
            ll p = par[i][l - 1];
            if(p != -1) {
                par[i][l] = par[p][l - 1];
            }
        }
    }
}

// O(logn)
ll lca1(ll a, ll b)
{
    if(lvl[a] > lvl[b]) {
        swap(a, b);
    }
    ll d = lvl[b] - lvl[a];
    for(ll i = 0; d > 0; i++) {
        if(d & 1) {
            b = par[b][i];
        }
        d /= 2;
    }

    if(a == b) return a;
    for(ll i = logn; i >= 0; i--)
    {
        if(par[a][i] != -1 and par[a][i] != par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

bool is_ancestor(ll u, ll v) {
    return in[u] <= in[v] and out[u] >= out[v];
}
ll lca2(ll u, ll v)
{
    if(is_ancestor(u, v)) {
        return u;
    }
    if(is_ancestor(v, u)) {
        return v;
    }
    for(ll i = logn; i >= 0; --i) {
        if(par[u][i] != -1 and !is_ancestor(par[u][i], v)) {
            u = par[u][i];
        }
    }
    return par[u][0];
}

ll lca3(ll root, ll u, ll v)
{
    ll a = lca1(u, v);
    ll b = lca1(u, root);
    ll c = lca1(v, root);

    if(b == c) return a;
    else if(a == b) return c;
    else if(a == c) return b;
    else return -1;
}

ll dist(ll a, ll b)
{
    ll lca_ab = lca1(a, b);
    return lvl[a] + lvl[b] - 2 * lvl[lca_ab];
}

// kth node from path (a, b)
// a is 1st node
ll kth_node(ll a, ll b, ll k)
{
    k--;
    ll lca_ab = lca1(a, b);
    if(k > lvl[a] - lvl[lca_ab])
    {
        k -= (lvl[a] - lvl[lca_ab]);
        k = lvl[b] - lvl[lca_ab] - k;
        a = b;
    }
    for(ll i = 0; k > 0; i++) {
        if(k & 1) {
            a = par[a][i];
        }
        k /= 2;
    }
    return a;
}

int main()
{
    cin >> n;
    clearAll(n);

    m = n - 1; // tree
    for(int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    lca_init();

    ll q;
    cin >> q;
    while(q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << lca1(x, y) << " " << lca2(x, y) << "\n";
    }
}

/*
Required time for various technique using fast I/O:

                                           preprocess  Query      Time

1. Naive Approach                          O(N)        O(N^2)     0.23s
2. using Square Root Decomposition         O(N)        O(sqrt(N)) 0.04s
3. using Segment Tree                      O(NlogN)    O(logN)    0.02s
4. using Sparse Table                      O(NlogN)    O(1)       0.04s
5. Binary Lifting                          O(Nlogn)    O(logN)    0.03s
6. Farach Colton and Bender Algorithm      O(N)        O(1)       0.03s
7. Tarjan's Offline Algorithm              O(N)        O(1)       0.03s

* brute force
ll LCA(a, b)
{
    if(lvl[a] > lvl[b]) {
        swap(a, b);
    }

    ll dis = lvl[b] - lvl[a];
    while(dis > 0) {
        b = par[b];
        dis--;
    }

    while(a != b) {
        a = par[a];
        b = par[b];
    }
    return a;
}
*/
```