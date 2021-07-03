### Problem
```
given array of N length and variable k.
Count the minimum number of elements need to change for make all k size subarrays xor is 0. 
1 <= N <= 1e4
0 <= A[i] <= 1024

ex.
4
1 2 3 1
3
ans : 0

4
1 2 3 1
2 
Ans : 2
```

### Solution

Observation 1
```
N < 1e4, A[i] <= 1024
so expected time / space = O(N * 1024)
```
Observations 2
```
all a[i % k] elements are same 
a[i] = a[i + k] = a[i + 2 * k] ...

After this solutions is very straight forward using n * 1024 dp with 1024 extra iterations for each step.
dp[id][curXor] = minimum number of changes required in 0 to id where curXor of 0 to id = curXor
time comp. = O(k * 1024 * 1024)
ending conditions => curXor == 0 && id == k
```
Observation 3
```
here, we can optimise 1024 iterations per step..
here, for some id i we need to iterate only j such that j % k = i.
and we will skip 1 elements as black after iteration for subarray we will put this 
elements as remaining xor. it will gives always optimal answer.

dp state dp[id][curXor][skip or not (0 / 1)].
time comp. = O(n * 1024 * 2)
```

### Bonus
easy version https://www.codechef.com/COOK129B/problems/CSUBS
