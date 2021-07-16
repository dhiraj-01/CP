### Problem
```
Given a tree with N nodes and N-1 edges. Each edge has some weight(W).
For every pair of vertices i and j (i != j) there exists a unique path.

A special prime factor of any given path is the largest prime factor of all the edges in the path.
Find the sum of special prime factors of all the possible tree paths.

In other word, special prime factor of the path a to b = max prime factor is
(weight of edge (a-c), weight of edge(c-d), ... , x-b (consider all weights which are in given path)

Sample Input:
N = 6 (Total nodes)
1 2 5 (Edge between node 1 and 2 having weight 5)
2 3 10
2 4 21
1 5 15
5 6 26

Sample Output:
246

Explanations:

special prime factor of the path (1,2) = 5
special prime factor of the path (1,3) = {(1->2) and (2->3)} = {5,10} = {5,2} = 5 (max prime factor from all the edges which are in the path)
special prime factor of the path (1,4) = {(1->2) and (2->4)} = {5,21} = {5,3,7} = 7
special prime factor of the path (1,5) = {(1->5)} = {15} = {3,5} = 5
special prime factor of the path (1,6) = {(1->5) and (5->6)} = {15,26} = {3,5,2,13} = 13
special prime factor of the path (2,1) = 5
special prime factor of the path (2,3) = 5
special prime factor of the path (2,4) = 7
special prime factor of the path (2,5) = 5
special prime factor of the path (2,6) = 13
and so on for all pairs of vertices i and j , where (i!=j).

Constraint:
2 <= N <= 100000
2 <= weight <= 1000000
```

### Solution
```
:(
```