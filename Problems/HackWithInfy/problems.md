## HackWithInfy problems

### (1)
```
given array of size n
each element of array a[i] can be expressed as (2 ^ x) * (5 ^ y), (x >= 0, y >= 0)
find any subset such that their product of element is 10 ^ z, return z
maximize z

constraints:
1 <= n <= 1e5
a[i] <= 1e9

testcase:
n = 5
array = {2, 5, 125, 16, 5}
answer = 5
subset = {2, 5, 125, 16, 5} => product = 10 ^ 5

n = 5
array = {2, 5, 5, 125, 20}
answer = 3
subset = {2, 5, 5, 20} => product = 10 ^ 3
```
tag: `dp`

### (2)
```
given n and array of 2 * n element
0 <= a[i] <= 1 (a[i] is 0 or 1)
in one operation you can select (i, j) 0 <= i, j <= n
remove first i elements from array and last j elements from array
after doing operations(0 or more time) remaining array should contain equal 1's and 0's
find minimum number elements you need to remove

constraints:
1 <= n <= 1e5
0 <= a[i] <= 1

testcase:
n = 3
array = {0, 0, 1, 0, 1, 1}
answer = 0 (no need to remove any element because no. of 1's = no. of 0's)

n = 3
array = {0, 1, 1, 1, 0, 1}
answer = 4
select (i, j) => (3, 1) => remove first 3 and last 1 element => array = {x, x, x, 1, 0, x} (x = removed element)
```
tag: `greedy`

### (3)
```
given n node, m
and 2 arrays a and b
you are on node 2
their is an direct edge(x, y) if x < y and y % x != 0 and x >= y - a[y]
cost between direct edge (x, y) = b[x]

ans = 0
for(ll i = 1; i <= n; i++) {
    if(shortest_dist(2, i) <= m) {
        ans++;
    }
}
print(ans)

constraints:
1 <= n <= 1e5
0 <= m <= 1e9
1 <= a[i] <= 1e4
1 <= b[i] <= 1e3
```
tag : `graph`, `dijkstra`


### (4)
```
Given an array of integers of length N and an integer K
find length of the smallest subarray  with number of good pairs in it is atleast K ( >= K)
We define good pair as pair of indices i, j such that i < j ans a[i] is even and a[j] is odd.

constraints:
2 <= N <= 1e5
```