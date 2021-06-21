### Hackerrank

- https://www.hackerrank.com/challenges/counting-valleys/problem
- https://www.hackerrank.com/challenges/sherlock-and-cost/problem
<details>
    <summary>Code in c++</summary>

```cpp
void solve()
{
    int n;
    cin >> n;

    int b[n];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int dp[n][2]; 
    // dp[i][0] => max answer if a[i] = 1
    // dp[i][1] => max answer if a[i] = b[i]
    dp[0][0] = dp[0][1] = 0;

    for(int i = 1; i < n; i++) {
        dp[i][0] = max(
            dp[i - 1][0] + abs(1 - 1),
            dp[i - 1][1] + abs(1 - b[i - 1])
        );
        dp[i][1] = max(
            dp[i - 1][0] + abs(b[i] - 1),
            dp[i - 1][1] + abs(b[i] - b[i - 1])
        );
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}
```
</details>

- https://www.hackerrank.com/challenges/construct-the-array/problem