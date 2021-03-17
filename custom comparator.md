### custom comparator

### 1. operator <
```c++
struct node
{
    ll a, b;
    node(ll x, ll y)
    {
        a = x;
        b = y;
    }
    friend bool operator < (const node &lhs, const node &rhs) {
        return lhs.a > rhs.a;
    }
    /*
    bool operator < (const node &rhs) const {
        return a > rhs.a;
    }
    */
};

priority_queue<node> pq;
pq.push(node(1, 2));
pq.push(node(3, 2));

set<node> s;
s.insert(node(1, 2));
s.insert(node(3, 2));

vector<node> v;
v.push_back(node(3, 2));
v.push_back(node(1, 2));
sort(v.begin(), v.end());
```

<details>
  <summary>complete code</summary>
  
  ```c++
  #include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class key, class Comp = less<key>>
using pbds = tree<key, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long int;
#define endl '\n'

struct node
{
    ll a, b;
    node(ll x = 0, ll y = 0) {
        a = x;
        b = y;
    }
    friend bool operator < (const node &lhs, const node &rhs) {
        return lhs.a > rhs.a;
    }
};

void solve(ll &tc)
{
    priority_queue<node> pq;
    pq.push(node(1, 2));
    pq.push(node(3, 2));
    // pq = {[1,2], [3,2]}

    set<node> s;
    s.insert(node(1, 2));
    s.insert(node(3, 2));
    // s = {[3,2], [1,2]}

    vector<node> v;
    v.push_back(node(3, 2));
    v.push_back(node(1, 2));
    sort(v.begin(), v.end());
    // v = {[3,2], [1,2]}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll tc = 1;
    for(ll i = 1; i <= tc; i++) {
        solve(i);
    }
    return 0;
}
  ```
  
</details>


### 2. lambda expression
```c++
auto comp = [](const node &lhs, const node &rhs) {
    return lhs.a > rhs.a;
};

priority_queue<node, vector<node>, decltype(comp)> pq(comp);
pq.push(node(1, 2));
pq.push(node(3, 2));

set<node, decltype(comp)> s(comp);
s.insert(node(1, 2));
s.insert(node(3, 2));

map<node, int, decltype(comp)> m(comp);
m[node(1, 2)] = 1;
m[node(1, 3)] = 5;

pbds<int, decltype(comp)> p(comp);

vector<node> v;
v.push_back(node(3, 2));
v.push_back(node(1, 2));
sort(v.begin(), v.end(), comp);
```

<details>
  <summary>complete code</summary>
  
  ```c++
  #include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class key, class Comp = less<key>>
using pbds = tree<key, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long int;
#define endl '\n'

struct node
{
    ll a, b;
    node(ll x = 0, ll y = 0) {
        a = x;
        b = y;
    }
};

void solve(ll &tc)
{
    auto comp = [](const node &lhs, const node &rhs) {
        return lhs.a > rhs.a;
    };

    priority_queue<node, vector<node>, decltype(comp)> pq(comp);
    pq.push(node(1, 2));
    pq.push(node(3, 2));

    set<node, decltype(comp)> s(comp);
    s.insert(node(1, 2));
    s.insert(node(3, 2));

    map<node, int, decltype(comp)> m(comp);
    m[node(1, 2)] = 1;
    m[node(1, 3)] = 5;

    pbds<int, decltype(comp)> p(comp);
    p.insert(3);
    p.insert(2);

    vector<node> v;
    v.push_back(node(3, 2));
    v.push_back(node(1, 2));
    sort(v.begin(), v.end(), comp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll tc = 1;
    for(ll i = 1; i <= tc; i++) {
        solve(i);
    }
    return 0;
}
  ```
</details>
