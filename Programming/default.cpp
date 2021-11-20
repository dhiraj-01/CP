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

void solve(ll &);

int main()
{
    #ifdef DHIRAJ
        freopen("D:/dhiraj/Programming/i1.txt", "r", stdin);
        freopen("D:/dhiraj/Programming/o1.txt", "w", stdout);
        freopen("D:/dhiraj/Programming/e1.txt", "w", stderr);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll tc = 1;
    solve(tc);
    return 0;
}