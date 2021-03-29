## one loop for everything


> _Personally i don't recommend to use macro, but for speed it's your choice :octocat:_

```c++
#define FOR(i, a, b, s)     for(ll i = (a); i < (b); i += (s))
#define ROF(i, a, b, s)     for(ll i = (a); i > (b); i += (s))
#define FOR1(n)             FOR(_, 0, n, 1)
#define FOR2(i, n)          FOR(i, 0, n, 1)
#define FOR3(i, a, b)       FOR(i, a, b, 1)
#define FOR4(i, a, b, s)    FOR(i, a, b, s)
#define ROF1(i, n)          ROF(i, n, -1, -1)
#define ROF2(i, a, b)       ROF(i, a, b, -1)
#define ROF3(i, a, b, s)    ROF(i, a, b, s)
#define GETC(a, b, c, d, e, ...) e
#define FORC(...)           GETC(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)
#define ROFC(...)           GETC(__VA_ARGS__, ROF3, ROF2, ROF1)
#define loop(...)           FORC(__VA_ARGS__)(__VA_ARGS__)
#define rloop(...)          ROFC(__VA_ARGS__)(__VA_ARGS__)

void solve(int &T)
{
    // for(ll _ = 0; _ < 5; _++)
    loop(5) {
        cout << _ << " ";
    }
    cout << endl;

    // for(ll j = 0; j < 5; j++)
    loop(j, 5) {
        cout << j << " ";
    }
    cout << endl;
    
    // for(ll j = 5; j < 10; j++)
    loop(j, 5, 10) {
        cout << j << " ";
    }
    cout << endl;

    // for(ll j = 5; j < 10; j += 2)
    loop(j, 5, 10, 2) {
        cout << j << " ";
    }
    cout << endl;

    // for(ll k = 5; k > -1; k--)
    rloop(k, 5, -1) {
        cout << k << " ";
    }
    cout << endl;

    // for(ll k = 10; k > -1; k += (-3))
    rloop(k, 10, -1, -3) {
        cout << k << " ";
    }
    cout << endl;

    // for(ll i = 10; i < 5; i++)
    loop(i, 10, 5) {
        assert(0);
    }

    // for(ll i = 10; i > 10; i--)
    rloop(i, 10, 10) {
        assert(0);
    }

    // for(ll i = 4; i < 10;)
    loop(i, 4, 10, 0) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // for(ll i = 10; i > 4;)
    rloop(i, 10, 4, 0) {
        cout << i << " ";
        i--;
    }
    cout << endl;

    // for(ll i = 10; i > -1; i--)
    rloop(i, 10) {
        cout << i << " ";
    }
    cout << endl;
}
```

<details>
  <summary>complete code</summary>
  
```c++
#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
#define endl '\n'

#define FOR(i, a, b, s)     for(ll i = (a); i < (b); i += (s))
#define ROF(i, a, b, s)     for(ll i = (a); i > (b); i += (s))
#define FOR1(n)             FOR(_, 0, n, 1)
#define FOR2(i, n)          FOR(i, 0, n, 1)
#define FOR3(i, a, b)       FOR(i, a, b, 1)
#define FOR4(i, a, b, s)    FOR(i, a, b, s)
#define ROF1(i, n)          ROF(i, n, -1, -1)
#define ROF2(i, a, b)       ROF(i, a, b, -1)
#define ROF3(i, a, b, s)    ROF(i, a, b, s)
#define GETC(a, b, c, d, e, ...) e
#define FORC(...)           GETC(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)
#define ROFC(...)           GETC(__VA_ARGS__, ROF3, ROF2, ROF1)
#define loop(...)           FORC(__VA_ARGS__)(__VA_ARGS__)
#define rloop(...)          ROFC(__VA_ARGS__)(__VA_ARGS__)

void solve(ll &tc)
{
    // for(ll _ = 0; _ < 5; _++)
    loop(5) {
        cout << _ << " ";
    }
    cout << endl;

    // for(ll j = 0; j < 5; j++)
    loop(j, 5) {
        cout << j << " ";
    }
    cout << endl;
    
    // for(ll j = 5; j < 10; j++)
    loop(j, 5, 10) {
        cout << j << " ";
    }
    cout << endl;

    // for(ll j = 5; j < 10; j += 2)
    loop(j, 5, 10, 2) {
        cout << j << " ";
    }
    cout << endl;

    // for(ll k = 5; k > -1; k--)
    rloop(k, 5, -1) {
        cout << k << " ";
    }
    cout << endl;

    // for(ll k = 10; k > -1; k += (-3))
    rloop(k, 10, -1, -3) {
        cout << k << " ";
    }
    cout << endl;

    // for(ll i = 10; i < 5; i++)
    loop(i, 10, 5) {
        assert(0);
    }

    // for(ll i = 10; i > 10; i--)
    rloop(i, 10, 10) {
        assert(0);
    }

    // for(ll i = 4; i < 10;)
    loop(i, 4, 10, 0) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // for(ll i = 10; i > 4;)
    rloop(i, 10, 4, 0) {
        cout << i << " ";
        i--;
    }
    cout << endl;

    // for(ll i = 10; i > -1; i--)
    rloop(i, 10) {
        cout << i << " ";
    }
    cout << endl;
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
