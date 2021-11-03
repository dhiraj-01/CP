### Sparce table

```cpp
// 1 based index
// min, max, gcd, lcm in range O(1) query, O(nlogn) preprocessing

const ll N = 1e5 + 5;
vector<ll> LOG2(N, 0);
void init() {
    LOG2[1] = 0;
    for(ll i = 2; i < N; i++) {
        LOG2[i] = LOG2[i / 2] + 1;
    }
}

template <typename T>
struct Sparce
{
    vector<vector<T>> dp; // dp[i][j] = answer for range (i, i + 2 ^ j - 1)
    function<T(const T&, const T&)> join;

    // O(nlogn)
    Sparce(const vector<T>& a, ll n, function<T(const T&, const T&)> _join) {
        join = _join;
        dp.assign(n + 1, vector<ll>(LOG2[n] + 1, -1));

        for(ll j = 0; j < LOG2[n] + 1; j++) {
            for(ll i = 1; (i + (1ll << j) - 1) <= n; i++) {
                if(j == 0) {
                    dp[i][j] = a[i];
                }
                else {
                    dp[i][j] = join(dp[i][j - 1], dp[i + (1ll << (j - 1))][j - 1]);
                }
            }
        }
    }
    // O(1)
    ll query(ll l, ll r) {
        ll j = LOG2[r - l + 1];
        return join(dp[l][j], dp[r - (1ll << j) + 1][j]);
    }
};
```