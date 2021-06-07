### Problem
```
A tournament was played and score of all players is reported in a sequence,
considering 2^n players. comparison is made between 2 consicutive scores on
every level, highest one is declared as winner among 2. This keeps iterating
until we get the final winner of tournament.

Example :
initial array : 10, 76, 12, 13, 45, 46, 80, 64
level 1       : 76, 13, 46, 80
level 2       : 76, 80
level 3       : 80

We will get tree below.

            80             (level 3)
           / \
         /     \  
       /         \
      76          80       (level 2)
    /   \        /  \
   76     13    46   80    (level 1)
  / \    / \   / \   / \
 10 76 12 13 45 46 80 64   (level 0)

tree node structure : 

Node {
    int val;
    Node *right, *left;
}
```

### Solution
```
:(
```