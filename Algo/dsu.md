### DSU

```cpp
// 1 based index
struct Dsu
{
    ll cc, n;
    vector<ll> par, sz;
    set<pair<ll,ll>> sp;

    // O(n)
    Dsu(ll _n = 1e5)
    {
        cc = n = _n;
        par.resize(n + 5);
        sz.resize(n + 5);
        for(ll i = 1; i <= n; i++)
        {
            sz[i] = 1;
            par[i] = i;
            // sp.emplace(1, i);
        }
    }
    // O(~ logn)
    ll find(ll x) // find parent of x
    {
        if(par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }
    // O(~ logn)
    bool join(ll x, ll y)
    {
        // assert(x >= 1 and x <= n and y >= 1 and y <= n);
        ll xp = find(x);
        ll yp = find(y);
        if(xp == yp) {
            return false;
        }
        cc--;
        // sp.erase({sz[xp], xp});
        // sp.erase({sz[yp], yp});

        if(sz[xp] > sz[yp]) {
            swap(xp, yp);
        }
        // yp is root
        par[xp] = yp;
        sz[yp] += sz[xp];
        
        // sp.emplace(sz[yp], yp);
        return true;
    }
    // O(~ logn)
    ll size(ll x) {
        return sz[find(x)];
    }
    map<ll, vector<ll>> groups()
    {
        map<ll, vector<ll>> ans;
        for(ll i = 1; i <= n; i++) {
            ans[find(i)].push_back(i);
        }
        return ans;
    }
    friend string to_string(Dsu dsu)
    {
        string res = "DSU\n";
        #ifdef DHIRAJ
        {
            res += "{\n";
            res += "\tN = " + to_string(dsu.n) + ", ";
            res += "\tCC = " + to_string(dsu.cc) + "\n";
            res += "\tGroups : " + to_string(dsu.groups()) + "\n";
            res += "\tSize-Parent : " + to_string(dsu.sp);
            res += "\n}";
        }
        #endif
        return res;
    }
};
```