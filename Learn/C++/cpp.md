# C++

https://devdocs.io/cpp/

### Hello World
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    return 0;
}
```

### Data Types
```cpp
int a = 1; 
// 32 bit => -2^31 to (2^31)-1 => ~ -1e9 to 1e9
int MX = INT_MAX;
int MN = INT_MIN;

unsigned int x = 10;
// only positive numbers
// 0 to (2^32)-1

long long int b = 1e17;
// 64 bit => -2^64 to 2^64 => ~ -1e18 to 1e18
long long int MX = LLONG_MAX;
long long int MN = LLONG_MIN;

char c = 'a';
// single character
// 'a' = 97 (ASCII value), 'b' = 98 ..

string s = "hello";
// string is not a data type, but a class
// s.length(), s.size(), s.empty() ...

double PI = 3.14;
long double d = 1.23;
float f = 2.1;

auto any = "string";
any = "you can change it to other string";
any = 10; // not possible
// you can assign any data type at initialization time

auto x;
x = 10; // error
// The variable declared with auto keyword should be 
// initialized at the time of its declaration only or else 
// there will be a compile-time error

// Tip: Always use long long int and long double (for cp)
```

### Array
```cpp
int a[10];
// 10 integers

int a[10][10];
// a[i] is array of 10 integer

string a[10];
// array of string

int a; 
// single integer

int arr[5];
// array of integers of size 5
// we can access each integer by index arr[index] => int

vector<int> v(10);
// vector of integers of size 10
// we can access each integer by index v[index] => int

vector<int> v[10];
// array of vectors of integer of size 10
// we can access each vector by index v[index] => vector of int

vector<vector<int>> v(10);
// vector of vector of integers of size 10
// we can access each vector by index v[index] => vector of int
```

### Pair
```cpp
pair<type1, type2> p;

pair<int, string> p{1, "ok"};
p.first = 10;
p.second = "update";

// destructuring
auto [x, s] = p;
x = 10, s = "update";
```

### Vector
```cpp
vector<int> v;
v.push_back(1);
// O(1)
// add new element (append)

v.pop_back();
// O(1)
// remove last element

v.front();
// O(1)
// v[0] = first element

v.back(); 
// O(1)
// v[v.size() - 1] = last element

v.empty(); 
// O(1)
// return true if empty

v.size();
// O(1)
// return size

v.clear();
// O(1)
// clear the vector

v.resize(new_size, value = default value);
// O(new_size)
// v.resize(10) => new size of vector is 10
// if new size < size, extra elements will be removed (value will not be set here)
// else new elements will be added with default values

v.assign(new_size, value); 
// O(new_size)
// resize to new size and set given value

/*  
   begin()                 end()
    |                       |
_ [ _ _ _ _ _ _ _ _ _ _ _ ] _ 
|                       |
rend()                 rbegin()

        container
*/

v.begin();
// O(1)
// iterator to first element
// dereference to get value
// v[0] == *v.begin();

v.end();
// O(1)
// iterator to the element after the last element 
// v = [1, 2] v.end() point to next memory location after 2
// v.back() == *(--v.end());

v.rend();
// O(1)
// iterator to element before first element

v.rbegin();
// O(1)
// iterator to last element.

v.erase(pos); // iterator to the element to remove
// O(n)
// remove element pointed by iterator
// v.erase(v.begin()) remove first ele
// v.erase(v.begin() + 1) remove 2nd ele

v.erase(first, last) // range of elements to remove

v.begin() + x
// iterator to v[x]

v.end() - x
// iterator to v[v.size() - x]

vector<int> v(size);
// O(size)
// vector<int> v(10);
// vector of int size 10
// default values 0

vector<int> v(size, value);
// O(size)
// vector<int> v(10, 5);
// default values 5, size 10

vector<int> v = {1, 3, 4, 2};
// list assignment

vector<int> new_v = v;
// O(size of v)

v[index]
// O(1)
// value at given index

// comparition possible, inbuilt default
// (vector1 == vector2) is correct C++ syntax. 
// There is an == operator for vectors.
if(new_v == v) {
    cout << "both are same" << endl;
}
if(new_v < v) {
    // new_v is lexicographically smaller than v
}

// print
// for each loop
for(int x : v) {
    cout << x << endl;
}
// using index
for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
// using iterator
for(auto it = a.begin(); it != a.end(); it++) {
    cout << *it << endl;
}
// reverse order
for(auto it = a.rbegin(); it != a.rend(); it++) {
    cout << *it << endl;
}

// *(v.begin() + x) = v[x]
cout << (*(v.begin() + 2) == v[2]) << endl;
```

### Stack
```cpp
// last in first out (LIFO)
// push => add element at the end of stack
// pop => remove last element

stack<int> s;
s.push(10);
// O(1)
// add new element to stack 

s.top();
// O(1)
// get top (last) element

s.pop();
// O(1)
// remove top element (last element)

s.empty();
// O(1)

s.size();
// O(1)

s.clear(); 
// error, not possible in stack

// print
while(!s.empty()) {
    cout << s.top() << endl;
    s.pop();
}
```

### Queue
```cpp
// first in first out (FIFO)
// push => add element at the end of queue
// pop => remove first element

queue<int> q;
q.push(10);
// O(1)
// add new element to queue

q.front(); 
// O(1)
// get front element

q.pop(); 
// O(1)
// remove front element

q.empty();
// O(1)

q.size();
// O(1)

q.clear(); 
// error, not possible in queue 

// print
while(!q.empty()) {
    cout << q.front() << endl;
    q.pop();
}
```

### Deque
```cpp
// double ended queue
// add front, add back
// pop front, pop back

deque<int> q;
q.push_front(10);
// O(1)
// add new ele. at front

q.push_back(11);
// O(1)
// add new ele. at end

q.pop_front();
// O(1)
// remove first ele

q.pop_back();
// O(1)
// remove last ele

q.front();
// O(1)
// get front ele.

q.back();
// O(1)
// get back ele.

q.empty();
// O(1)

q.size();
// O(1)

q.clear();
// O(1)
// clear dequeue

q[index]
// O(1)
// value at index

// print
- for each loop
- using index
- using iterator
```

### Priority queue
```cpp
Priority Queue (push, top, pop)
Higher value at the top

priority_queue<int> pq;
pq.push(value);
// O(log(size of pq))
// add value to pq

pq.top()
// O(1)
// return top element (higher value)

pq.pop();
// O(log(size of pq))
// remove top element

pq.size();
pq.empty();
// O(1)

priority_queue<int> pq;
pq.push(10);
pq.push(30);
// pq = {30, 10}

pq.top() = 30
pq.pop() remove 30
pq.top() = 10

// min priority queue
priority_queue<type, vector<type>, greater<type>> pq;
pq.push(10);
pq.push(30);
// pq = {10, 30}

pq.clear(); // error, not possible
pq.begin(), pq.end() .. // error, not possible

// print
while(!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
}
```

### String
```cpp
string s = "Dhiraj";
s += '.'; // add char at the end
s += " Govindvira"; // concat string at the end
// s = "Dhiraj.Govindvira";

string s = "one";
string t = "two";
string p = s + "#" + t;
// p = "one#two";

s.size();
// O(1)

s.length();
// O(1)
// same as size()

s.front();
// O(1)
// first character

s.back();
// O(1)
// last character

s.push_back(char);
// O(1)
// add char. at the end

s.pop_back();
// O(1)
// remove last char.

s.empty();
s.size();
s.clear();
s[index]
// all operations O(1)

// print
- cout << s << endl;
- for each
- using index
- using iterator
```

### Set
```cpp
Store unique values in sorted orders

set<int> s;

s.insert(value);
// O(log(size of set))
// insert value 

s.erase(value);
// O(log(size of set))
// removes the element (if one exists)

s.erase(iterator);
// O(log(size of set))
// remove element pointed by iterator

s.find(value);
// O(log(size of set))
// return iterator
{
    std::set<int> example = {1, 2, 3, 4};
    auto search = example.find(2);
    if (search != example.end()) {
        std::cout << "Found " << (*search) << '\n';
    } else {
        std::cout << "Not found\n";
    }
}

s.count(value);
// O(log(size of set))
// count number of values in set
// you can use to check value exist or not

s.lower_bound(value);
// O(log(size of set))
// Returns an iterator pointing to the first element that is not less than key. 

s.upper_bound();
// O(log(size of set))
// Returns an iterator pointing to the first element that is greater than key.

s.clear();
s.size();
s.empty();
s.begin(); s.end(); s.rbegin(); s.rend();
// O(1)

// print
- for loop
- using iterator
```

### Multiset
```
Same as set but you can store multiple values
```

### Unordered set
```
Not sorted (unordered)
Average time comp of operations is O(1)
worst case O(n)
```

### Map
```cpp
map<key, value> m;

m.insert({key, value});
// O(log(size of map))

m[key] = value;
// O(log(size of map))
// set key to value
// if not exist create key

m.size();
m.empty();
m.clear();
m.begin(); m.end(); m.rbegin(); m.rend();
// O(1)

m.find(key);
// O(log(size of map))
// if != m.end() key exist else not exist

m.count(key);
// O(log(size of map))
// count keys

// print
for(auto [key, value] : map) {
    cout << key << ": " << value << endl;
}
for(pair<key, value> p : map) {
    cout << p.first << ": " << p.second << endl;
}
for(auto it : map) {
    cout << (*it).first << endl;
    cout << (*it).second << endl;
}
// using iterator
```

### Multimap
```
Same as map but you can store multiple keys
operator [] not possible because we don't know which key to update (:
```
```cpp
multimap<int, string> m;
m[1] = "hi"; 
// error :|

m.insert({1, "hi"});
m.insert({1, "hello"});
```

### Unordered map
```cpp
Average time comp of operations is O(1)
worst case O(n)
```

### Pbds
```cpp
// In the set we can't get value at particular index but with pbds we can (:

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class key, class Comp = std::less<key>>
using pbds = tree<key, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key(k)    : number of elements strictly smaller than k
// find_by_order(ind) : iterator to set[ind]

int main()
{
    pbds<int> A;

    //Add elements in any random order
    A.insert(11);
    A.insert(1);
    A.insert(5);
    A.insert(3);
    A.insert(7);
    A.insert(9);

    // Total contents
    for(int x : A) {
        cout << x << " ";
    }
    cout << "\n";

    // K-th smallest
    int k = 3;
    cout << k << "rd smallest: " << *A.find_by_order(k - 1) << endl;

    k = 5;
    cout << k << "th smallest: " << *A.find_by_order(k - 1) << endl;

    // No of elements < X
    int X = 9;
    cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

    // Delete elements
    cout << "Deleted 3" << endl;
    A.erase(3);

    // Total contents
    for(int x : A) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

    // Next Bigger / Smaller element than X
    X = 8;
    cout << "Next greater element than " << X << " is " << *A.upper_bound(X) << endl;

    return 0;
}
/* for custom comparator
auto comp = [](const int &lhs, const int &rhs) {
    return lhs > rhs;
};
pbds<int, decltype(comp)> p(comp);
*/
```

### Bitset
https://devdocs.io/cpp/utility/bitset

```cpp
The class template bitset represents a fixed-size sequence of N bits. 
Bitsets can be manipulated by standard logic operators and converted to and from strings and integers.

#define setbit(pos,n)       n |= (1LL << pos)
#define resetbit(pos,n)     n &= (~(1LL << pos))
#define toogle(pos,n)       n ^= (1LL << pos)
#define atpos(pos,n)        ((n & (1LL << pos)) != 0)
#define bits(n)             (floor(log2(n)) + 1)
#define rightone(n)         (__builtin_ffs(n) - 1)
#define countone(n)         (__builtin_popcountll(n))
#define parity(n)           (__builtin_parity(n))
#define counttz(n)          (__builtin_ctzll(n))
#define countlz(n)          (__builtin_clzll(n))
```

### Lambda function
```cpp
[pass by value | reference](parameters) -> return type {
    // code logic
};

auto sum = [](int a, int b) {
    return a + b;
};

int c = 10;
auto sum = [c](int a, int b) {
    // you can access c here (pass by value)
    return a + b + c;
};
auto sum = [&c](int a, int b) {
    // you can access c here (pass by reference)
    c = 1;
    return a + b + c;
};
// c = 1 here

[&] => you can access all varaible pass by reference
[=] => ...                         pass by value

int x = 10;
auto add = [&](int y) {
    x += y;
};
add(5);
// x = 15 here

// Note:
// recursion not possible
```

### Function
```cpp
function<return type(parameter)> name = lambda function;

function<int(int)> fact = [&](int n) {
    if(n == 0) return 1;
    return n * fact(n - 1);
};
cout << fact(5);

// Note:
// [&] needed to capture fact
// recursion possible
```

### Algorithms
```cpp
lower_bound();
upper_bound();
sort();
reverse();
unique();
is_sorted();
binary_search();
min_element();
max_element();
next_permutation();
prev_permutation();
count();
rotate();
swap(x, y);
...
```