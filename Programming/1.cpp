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
inline istream& operator >> (istream& in, pair<T, U>& p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
inline istream& operator >> (istream& in, vector<T>& v) {
    for(T& x : v) in >> x;
    return in;
}

void solve(ll &tc) {
    cout << "Hello World" << endl;
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
        cin >> tc;
        for(ll i = 1; i <= tc; i++) {
            // cout << "Case #" << i << ": ";
            cerr << "Case #" << i << "\n";
            solve(i);
        }
        if(dbg()) break;
    }
    return 0;
}