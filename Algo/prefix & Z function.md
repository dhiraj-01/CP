### Prefix function
```cpp
vector<ll> prefix_function(const string &p)
{
    ll m = p.size();
    vector<ll> lps(m, 0); // longest prefix suffix
    /*
    lps[i] = max j such that prefix(0, j - 1) = suffix(i - j, i) in pattern
    j point to first mismatch index

    ex.
    p = "abcxyabc"
         01234567 (index)
    lps[7] = 3, prefix(0, 3 - 1) = prefix(0, 2) = "abc"
               suffix(7 - 3, 7) = suffix(5, 7) = "abc"

    ex. 
    p = "abcabcxabcabc"
         01234567...... (index)
    lps[12] = 6

    ex.
    p = "acabacacd"
      p =  a  c  a  b  a  c  a  c  d
    lps = [0, 0, 1, 0, 1, 2, 3, 2, 0]
    */

    ll i = 1, j = 0;
    // i = current index in pattern
    // j = first mismatch index, such that prefix(0, m - 1) = suffix(i - m, i - 1) in given pattern
    while(i < m)
    {
        if(p[i] == p[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else if(j > 0) {
            // note that we do not increment i here.
            j = lps[j - 1];
        }
        else {
            // j = 0, we move to the next letter,
            // there was no any prefix found which 
            // is equal to the suffix for index i
            lps[i] = 0;
            i++;
        }
    }
    return lps;
}
```

### Z function
```cpp
vector<ll> z_function(const string &p)
{
    ll m = p.size();
    vector<ll> lps(m, 0);
    // lps[i] = max j such that
    // string(0, j) == string(i, i + j - 1)

    /*
    maintain (l, r) ends rightmost
    l = i
    r = i + j - 1
    

            (r - l)
                |
    0................l....x.....r.......
    [....x......] ...[....x......].......

    lps[x] = lps[x - l]
    */

    for(ll i = 1, l = 0, r = 0; i < m; i++)
    {
        // we maintain (l, r) such that s(l, r) = s(0, r - l + 1)
        // so that we don't need to calculate for i, l <= i <= r
        // lps[i] = lps[i - l], l <= i <= r
        if(i <= r) {
            lps[i] = min(r - i + 1, lps[i - l]);
        }
        // check for more matching
        while(i + lps[i] < m and p[lps[i]] == p[i + lps[i]]) {
            lps[i]++;
        }
        // update (l, r) such that i <= r
        if(i + lps[i] - 1 > r) {
            l = i;
            r = i + lps[i] - 1;
        }
    }
    return lps;
}

/*
# prefix_funtion
lps[i] is the length of the longest common prefix between string s and the suffix of string s ending at i. 

# z_function
lps[i] is the length of the longest common prefix between string s and the suffix of string s starting at i.
*/
```