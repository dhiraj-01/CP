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

string s = "hello";
// string is not a data type, but a class
// s.length(), s.size(), s.empty()

double PI = 3.14;
long double d = 1.23;
float f = 2.1;

auto any = "string";
any = "you can change it to other string";
any = 10; // not possible
// you can assign any data type at initialization type

auto x;
x = 10; // error
// The variable declared with auto keyword should be 
// initialized at the time of its declaration only or else 
// there will be a compile-time error

// Tip: Always use long long int and long double (for coding)
```

### Array
```cpp
int a[10];
// 10 integers
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

v.resize(new_size);
// O(new_size)
// v.resize(10) => new size of vector is 10
// if new size < size, extra elements will be removed
// else new elements will be added with default values

v.assign(new_size, value); 
// O(new_size)
// resize to new size and set given value

v.begin();
// O(1)
// iterator to first element
// dereference to get value
// v[0] == *v.begin();

v.end();
// O(1)
// iterator to after end element v = [1, 2]
// v.end() point to next memory location after 2
// v.back() == *(--v.end());

v.rend();
// O(1)
// iterator to last element

v.rbegin();
// O(1)
// iterator to before first ele.

v.erase(iterrator);
// O(n)
// remove element pointed by iterator
// v.erase(v.begin()) remove first ele
// v.erase(v.begin() + 1) remove 2nd ele

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
// (vector1 == vector2) is correct C++ syntax. There is an == operator for vectors.
if(new_v == v) {
    cout << "both are same" << endl;
}
if(new_v < v) {
    // new_v is lexicographically smaller than v
}

// print
for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
for(auto it = a.begin(); it != a.end(); it++) {
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
    cout << s.top();
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
    cout << q.front();
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
// value at index
```

### Set
### Multiset
### Unordered set
### Map
### Multimap
### Unordered map
### Priority queue
### Pbds
### String

### Lambda function
```cpp
[pass by value | reference](parameter) -> return type {
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
[=] => ... pass by value

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