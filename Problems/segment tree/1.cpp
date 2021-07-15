// https://www.hackerearth.com/challenges/competitive/pycon-2020/algorithm/jumbo-and-array-1-69b5c314-2b740e3b/

#include <bits/stdc++.h>
using namespace std;

#ifdef DHIRAJ
    #include "D:/dhiraj/Programming/debug.h"
#else
    #define dbg(...) 1
    #define cerr if(0) cerr
#endif

using ll = long long int;
#define endl '\n'

template <typename T, typename U>
inline istream & operator >> (istream &in, pair<T, U> &p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
inline istream & operator >> (istream &in, vector<T> &v) {
    for(T &x : v) in >> x;
    return in;
}

struct node {
    ll sm, smsq, ans;
    node(ll x = 0) {
        sm = x;
        smsq = x * x;
        ans = (sm * sm - smsq) / 2;
    };
    friend string to_string(node n)
    {
        string res = "";
        #ifdef DHIRAJ
        {
            res += "[";
            res += to_string(n.sm) + ",";
            res += to_string(n.smsq) + ",";
            res += to_string(n.ans);
            res += "]";
        }
        #endif
        return res;
    }
};

#define left(n) (n << 1LL)
#define right(n) ((n << 1LL) | 1LL)

template <typename T>
struct SegmentTree
{
    ll n; T e;
    vector<T> tree;
    function<T(const T&, const T&)> combine;

    SegmentTree(const vector<T> &arr, ll _n, T _e, function<T(const T&, const T&)> _combine) {
        n = _n, e = _e;
        combine = _combine;
        tree.resize(n << 2ll);
        build(1, 1, n, arr);
    }

    void build(ll i, ll l, ll r, const vector<T> &arr) {
        if(l == r) { // leaf node of segment tree
            tree[i] = arr[l];
            return;
        }
        ll m = (l + r) >> 1ll;
        build(left(i), l, m, arr);
        build(right(i), m + 1, r, arr);
        tree[i] = combine(tree[left(i)], tree[right(i)]);
    }

    void update(ll i, ll l, ll r, ll ind, T val) {
        if(l == r) {
            tree[i] = val;
            return;
        }
        ll m = (l + r) >> 1ll;
        if(ind <= m) {
            update(left(i), l, m, ind, val);
        }
        else {
            update(right(i), m + 1, r, ind, val);
        }
        tree[i] = combine(tree[left(i)], tree[right(i)]);
    }

    T query(ll i, ll l, ll r, ll ql, ll qr) {
        if(l > r or r < ql or l > qr) { // (l, r) outside (ql, qr)
            return e;
        }
        if(ql <= l and r <= qr) { // (l, r) inside (ql, qr)
            return tree[i];
        }
        ll m = (l + r) >> 1ll;
        T L = query(left(i), l, m, ql, qr);
        T R = query(right(i), m + 1, r, ql, qr);
        return combine(L, R);
    }

    void update(ll ind, T val) {
        update(1, 1, n, ind, val);
    }
    T query(ll l, ll r) {
        return query(1, 1, n, l, r);
    }
};

template <typename T>
string to_string(SegmentTree<T> s) {
    string res = "Segment Tree\n";
    #ifdef DHIRAJ
    {
        res += "arr = {";
        for(ll i = 1; i <= s.n; i++) {
            if(i > 1) res += ", ";
            res += to_string(s.query(i, i));
        }
        res += "}\n";
        res += "{\n";
        res += "\tid\trange\tdata\n";

        auto add_info = [&res](ll id, ll l, ll r, T info) {
            pair<ll, ll> range = {l, r};
            res += "\t" + to_string(id);
            res += "\t" + to_string(range);
            res += "\t" + to_string(info);
            res += "\n";
        };
        function<void(ll, ll, ll)> F = [&](ll id, ll l, ll r) {
            if(l == r) {
                add_info(id, l, r, s.tree[id]);
                return;
            }
            ll m = (l + r) / 2;
            F(left(id), l, m);
            F(right(id), m + 1, r);
            add_info(id, l, r, s.tree[id]);
        };
        F(1, 1, s.n);
        res += "}\n";
    }
    #endif
    return res;
}

void solve(ll &tc)
{
    ll n, q;
    cin >> n >> q;

    vector<node> a(n + 1);
    for(ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[i] = node(x);
    }

    // node {
    //     sm => sum of element [l, r]
    //     smsq => sum of square of element [l, r]
    //     ans = (sm * sm - smsq) / 2 => ans of [l, r]
    // }


    SegmentTree<node> s(a, n, node(), 
    [](const node& l, const node& r) {
        node res;
        res.sm = l.sm + r.sm;
        res.smsq = l.smsq + r.smsq;
        res.ans = (res.sm * res.sm - res.smsq) / 2;
        return res;
    });

    while(q--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 0) {
            cout << s.query(x, y).ans << endl;
        }
        else {
            s.update(x, y);
        }
    }
}

int main()
{
    #ifdef DHIRAJ
        freopen("D:/dhiraj/Programming/i1.txt", "r", stdin);
        freopen("D:/dhiraj/Programming/o1.txt", "w", stdout);
        freopen("D:/dhiraj/Programming/e1.txt", "w", stderr);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll rep = 1;
    while(rep--) {
        ll tc = 1;
        for(ll i = 1; i <= tc; i++) {
            // cout << "Case #" << i << ": ";
            cerr << "Case #" << i << "\n";
            solve(i);
        }
        if(dbg()) break;
    }
    return 0;
}