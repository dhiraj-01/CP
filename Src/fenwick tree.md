### Fenwick tree
```cpp
// O(1)
inline ll lsb(ll x) { // Least Significant Bit
    return (x & -x);
}

// 1 based index
struct Fenwick
{
    ll n;
    vector<ll> bit;

    Fenwick(ll _n = 1e5) {
        n = _n;
        bit.assign(n + 5, 0);
    }
    // O(logn) - arr[ind] += val;
    void add(ll ind, ll val) 
    {
        for(ll i = ind; i <= n; i += lsb(i)) {
            bit[i] += val;
        }
    }
    // O(logn) - range add
    void add(ll l, ll r, ll val) 
    { 
        add(l, val);
        add(r + 1, -val);
    }
    // O(logn) - arr[ind] = val;
    void replace(ll ind, ll val) {
        add(ind, val - sum(ind, ind));
    }
    // O(logn) - prefix sum
    ll sum(ll ind) 
    {
        ll ans = 0;
        for(ll i = ind; i > 0; i -= lsb(i)) {
            ans += bit[i];
        }
        return ans;
    }
    // O(logn) - range sum
    ll sum(ll l, ll r) { 
        return sum(r) - sum(l - 1);
    }
    friend string to_string(Fenwick f)
    {
        string res = "";
        #ifdef DHIRAJ
        {
            res += "BIT(" + to_string(f.n) + ") : ";
            res += "{";
            for(ll i = 1; i <= f.n; i++) {
                if(i > 1) res += ", ";
                res += to_string(f.sum(i, i));
            }
            res += "}";
        }
        #endif
        return res;
    }
};
```

### Fenwick tree - 2D array
```cpp
inline ll lsb(ll x) { // Least Significant Bit
    return (x & -x);
}

// 1 based index
struct Fenwick
{
    ll n, m;
    vector<vector<ll>> bit;

    Fenwick(ll _n = 1e5, ll _m = 1e5)    
    {
        n = _n, m = _m;
        bit.assign(n + 5, vector<ll>(m + 5, 0));
    }
    void add(ll x, ll y, ll val)
    {
        for(ll i = x; i <= n; i += lsb(i)) {
            for(ll j = y; j <= m; j += lsb(j)) {
                bit[i][j] += val;
            }
        }
    }
    ll sum(ll x, ll y)
    {
        ll ans = 0;
        for(ll i = x; i > 0; i -= lsb(i)) {
            for(ll j = y; j > 0; j -= lsb(j)) {
                ans += bit[i][j];
            }
        }
        return ans;
    }
    ll sum(ll x1, ll y1, ll x2, ll y2)
    {
        ll a = sum(x2, y2);
        ll b = sum(x2, y1 - 1);
        ll c = sum(x1 - 1, y2);
        ll d = sum(x1 - 1, y1 - 1);
        return (a - b - c + d);
    }
    friend string to_string(Fenwick f)
    {
        string res;
        #ifdef DHIRAJ
        {
            res += "BIT[" + to_string(f.n) + "][" + to_string(f.m) + "]\n";
            res += "{";
            for(ll i = 1; i <= f.n; i++) {
                res += "\n\t";
                for(ll j = 1; j <= f.m; j++) {
                    res += to_string(f.sum(i, j, i, j)) + " ";
                }
            }
            res += "\n}";
        }
        #endif
        return res;
    }
};
```

### Range update, Range query
```cpp
inline ll lsb(ll x) { // Least Significant Bit
    return (x & -x);
}

// 1 based index
class Fenwick
{
private:
    void add(vector<ll>& f, ll ind, ll val)
    {
        for(ll i = ind; i <= n; i += lsb(i)) {
            f[i] += val;
        }
    }
    ll sum(vector<ll> &f, ll ind)
    {
        ll ans = 0;
        for(ll i = ind; i > 0; i -= lsb(i)) {
            ans += f[i];
        }
        return ans;
    }

public:
    ll n;
    vector<ll> f1, f2;
    Fenwick(ll _n = 1e5)
    {
        n = _n;
        f1.assign(n + 5, 0);
        f2.assign(n + 5, 0);
    }
    void range_add(ll l, ll r, ll x)
    {
        add(f1, l, x);
        add(f1, r + 1, -x);
        add(f2, l, x * (l - 1));
        add(f2, r + 1, -x * r);
    }
    ll prefix_sum(ll ind) {
        return sum(f1, ind) * ind - sum(f2, ind);
    }
    ll range_sum(ll l, ll r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};
```