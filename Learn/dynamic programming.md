# Dynamic Programming  

**Steps to solve dp problems**
- Identify it's dp problem (keys: count total ways, minimize or maximize answer type problems)
- Identify dimention and states
- State transition
- Recustion + memorization
- Done :)

```
Top Down = Recursive
Bottom Up = Iterative
```

### Fibonacci Number
```cpp
fib(0) = 0
fib(1) = 1
fib(n) = fib(n - 1) + fib(n - 2), n >= 2
```

### Staircase problem
```
Given a distance dist, count total number of ways to cover the distance with 1, 2 and 3 steps.
dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
```

### Longest Common Subsequence
```cpp
dp[i][j] = length of lcs of substring(0, i) of s1, substring(0, j) of s2

dp[i][j] = {
    if(s1[i] == s2[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
    }
    else {
        max(dp[i][j - 1], dp[i - 1][j]);
    }
}

answer = dp[s1.size()][s2.size()]
```

### Longest Common Substring
```cpp
dp[i][j] = length of lcs ending at i in s1, at j in s2

dp[i][j] = {
    if(s1[i] == s2[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
    }
    else {
        // s1[i] != s2[j] so length of lcs ending at i, j is 0
        dp[i][j] = 0;
    }
}

ans = 0;
for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
        ans = max(ans, dp[i][j]);
    }
}
```

### Longest Palindromic Subsequence
```cpp
- solution(1)
LPS of string s = Longest Common Subsequence(s, reverse(s))

- solution(2)
dp[i][j] = lps of substring(i, j) of s

dp[i][j] = {
    if(s[i] == s[j]) {
        dp[i][j] = 1 + dp[i + 1][j - 1];
    }
    else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    }
}
answer = dp[1][s.size()]
```

### Longest Palindromic Substring 
```cpp
- solution(1)
consider each index as center of palindrome, expand till palindrome and maximize answer
O(n ^ 2) worst case

for(int c = 0; c < n; c++)
{
    // odd length
    {
        int len = 1;
        int i = c - 1, j = c + 1;
        while(s[i] == s[j]) {
            i--, j++;
            len += 2;
        }
    }
    // even length
    {
        int len = 0;
        int i = c - 1, j = c;
        while(s[i] == s[j]) {
            i--, j++;
            len += 2;
        }
    }
}

- solution(2)
https://cp-algorithms.com/string/manacher.html
```

### Longest Repeated Subsequence
```
find longest subsequnce of string that occures at least twice.
any ith character in the two subsequences shouldn’t have the same index in 
the original string. (The occurrences should not overlap)

similar to longest common subsequence, just ignore when i = j and s[i] = s[j]
modified lcs(s, s)
```
```cpp
dp[i][j] = {
    if(s[i] == s[j] and i != j) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
    }
    else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
}
answer = dp[s.size()][s.size()];
```

### Minimum edit distance
```
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert str1 into str2.

- Insert
- Remove
- Replace

All of the above operations are of equal cost.
```
```cpp
dp[i][j] = min cost to convert substring(0, i) of s1 to substring(0, j) of s2

dp[i][j] = {
    if(s1[i] == s2[j]) {
        dp[i][j] = dp[i - 1][j - 1];
    }
    else {
        dp[i][j] = min(
            1 + dp[i][j - 1], // insert s2[j] between (i, i + 1) in s1
            1 + dp[i - 1][j]  // delete s1[i]
            1 + dp[i - 1][j - 1] // replace s1[i] = s2[j]
        );
    }
}
answer = dp[s1.size()][s2.size()]
```

### Shortest Common Supersequence
```
Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.
```
```cpp
- solution(1)
Length of the shortest supersequence 
= (Sum of lengths of given two strings) - (Length of LCS of two given strings) 
= s1.size() + s2.size() - LCS(s1, s2)

- solution(2)
dp[i][j] = length of scs of substring(0, i) of s1 and substring(0, j) of s2

dp[i][j] = {
    if(s1[i] == s1[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1] // insert s1[i]
    }
    else {
        dp[i][j] = min(
            1 + dp[i - 1][j], // insert s1[i]
            1 + dp[i][j - 1]  // insert s2[j]
        );
    }
}
answer = dp[s1.size()][s2.size()]
```

### Longest Increasing Subsequence
```
The Longest Increasing Subsequence (LIS) problem is to find the length of the
longest subsequence of a given sequence such that all elements of the subsequence 
are sorted in increasing order. For example, the length of LIS for 
{10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 
```
```cpp
- solution(1) O(n ^ 2)
dp[i] = lis ending at index i

dp[1] = 1;
for(ll i = 2; i <= n; i++) {
    for(ll j = 1; j < i; j++) {
        if(a[j] < a[i]) {
            dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
}

ans = 0;
for(ll i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
}

- solution(2) O(n * logn)
dp[i] = min value for lis of length i
ex. ar = {5, 2, 1, 4}
dp[1] = {1},
dp[2] = {4}

ll lengthOfLIS(vector<ll> &a) 
{
    const ll INF = 1e9;
    ll n = a.size();
    
    // dp[i] = minimum last element for LIS of length i
    vector<ll> dp(n + 1, INF);
    dp[0] = -INF;

    for(ll i = 0; i < n; i++)
    {
        ll id = upper_bound(dp.begin(), dp.begin() + i + 1, a[i]) - dp.begin();
        // if(dp[id - 1] <= a[i]) { // LIS
        if(dp[id - 1] < a[i]) { // LSIS
            dp[id] = a[i];
        }
    }
    for(ll len = n; len >= 1; len--) {
        if(dp[len] < INF) {
            return len;
        }
    }
    return 0;
}
```

### Longest Bitonic Subsequence
```
a subsequence of array is called Bitonic if it is first increasing, then decreasing

answer is S[i] + E[i] - 1
S[i] = longest increasing subsequence starting from i
E[i] = longest increasing subsequence ending at i
```

### Maximum Sum Increasing Subsequence
```cpp
For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100)

dp[i] = maximum sum of incresing subsequence ending at index i

dp[1] = a[1];
for(ll i = 2; i <= n; i++) {
    dp[i] = a[i];
    for(ll j = 1; j < i; j++) {
        if(a[j] < a[i]) {
            dp[i] = max(dp[i], a[i] + dp[j]);
        }
    }
}
```

### Find the size of the largest square submatrix of 1’s present in a binary matrix
```cpp
[
    [0   0   1   0   1   1]
    [0   1   1   1   0   0]
    [0   0   1   1   1   1]
    [1   1   0   1   1   1]
    [1   1   1   1   1   1]
    [1   1   0   1   1   1]
    [1   0   1   1   1   1]
    [1   1   1   0   1   1]
]
answer = 3

dp[i][j] = largest square matrix ending at cell(i, j)

dp[i][j] = {
    if(a[i][j] == 0) {
        dp[i][j] = 0;
    }
    else {
        dp[i][j] = 1 + min(
            dp[i - 1][j - 1],
            dp[i][j - 1],
            dp[i - 1][j]
        );
    }
}

answer = max in dp
```

### Matrix Chain Multiplication
```
Given a sequence of matrices, find the most efficient way to multiply these 
matrices together. The problem is not actually to perform the multiplications, 
but merely to decide in which order to perform the multiplications.

For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 
5 × 60 matrix. Then,  

(AB)C = (10 × 30 × 5) + (10 × 5 × 60) = 1500 + 3000 = 4500 operations
A(BC) = (30 × 5 × 60) + (10 × 30 × 60) = 9000 + 18000 = 27000 operations.
```
```cpp
total matrix n
given array a of size n + 1
dimention of matrix i = a[i] x a[i + 1]

dp[i][j] = minimum multiplications to multiply matrix i to j

for(ll k = i; k < j; k++) {
    // multiply i to k, k + 1 to j
    // then multiply resulting matrix (a[i] * a[k + 1]) x (a[k + 1] * a[j])
    dp[i][j] = dp[i][k] + dp[k + 1][j] + (a[i] * a[k + 1] * a[j]);
}
answer = dp[1][n]
```

### Find total ways to reach the last cell of a matrix from its first cell
```
dp[i][j] = total ways to reach cell(i, j)
dp[i][j] += dp[x][y], (x, y => direction)
```

### Find minimum cost to reach the last cell of a matrix from its first cell
```cpp
dp[i][j] = min cost to reach cell(i, j)
dp[i][j] = cost[i][j] + min(dp[x][y]), (x, y => direction)
```

### Count the number of paths in a matrix with a given cost to reach the destination cell
```
given cost, count total paths
dp[i][j][k] = total ways to reach cell(i, j) with cost k
dp[i][j][k] += dp[x][y][k - cost[i][j]], (x, y => direction)
```

### Find the longest sequence formed by adjacent numbers in the matrix
```
dp[i][j] = longest sequence ending at cell (i, j)

dp[i][j] = 1 + dp[x][y], if(a[x][y] == a[i][j] - 1), (x, y => direction)
(x, y) = {(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)}
```

### 01 - Knapsack
### Fractional knapsack
### Unbounded knapsack
### Coin Change

### Subset Sum
- exist subset with given sum
- count total subset with given sum
- equal sum partition
- mimimum sum partition

### Rod cutting
```cpp
dp[i] = max value by cutting rod of length i

for(ll j = 1; j <= n; j++) {
    if(i >= j) {
        dp[i] = max(dp[i], price[j] + dp[i - j]);
    }
}
```

### Maximum Product Rod Cutting
```cpp
// find max product
ex. n = 4, 
1 * 1 * 1 * 1 = 1
2 * 2 = 4
1 * 3 = 3

dp[i] = i;
for(ll j = 1; j < i; j++) {
    dp[i] = max(dp[i], j * dp[i - j]);
}
```

### Deque Game 
https://atcoder.jp/contests/dp/tasks/dp_l
```
dp[i][j] = optimal answer = maximum diff (x - y)
x = first player score
y = second player score

dp[i][j] = max(
    a[i] - dp[i + 1][j],
    a[j] - dp[i][j - 1]
);
```
https://codeforces.com/contest/859/problem/C  
https://atcoder.jp/contests/abc201/tasks/abc201_d  

### Jump Game

### Find all N-digit binary strings without any consecutive 1's
```
Input:  N = 2
Output: 3
The 3 strings are 00, 01, 10

Input: N = 3
Output: 5
The 5 strings are 000, 001, 010, 100, 101
```
```cpp
dp[i][j] = total ith digit strings, ending at char j

dp[i][j] = {
    if(j == '0') {
        dp[i][j] = dp[i - 1]['0'] + dp[i - 1]['1'];
    }
    else {
        dp[i][j] = dp[i - 1]['0'];
    }
}
```
