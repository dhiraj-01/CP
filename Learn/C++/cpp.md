# C++

### Data type
```cpp
int a = 1; // 32 bit => 2^32 => ~ -1e9 to 1e9
long long int b = 1e17; // 64 bit => ~ -1e18 to 1e18
char c = 'a';
string s = "hello";
double PI = 3.14;
long double d = 1.23;
float f = 2.1;
auto any = "string"; // you can assign any data type

// Tip: Always use long long int and long double (for coding)
```

### STL | Methods

#### Vector
```cpp
vector<int> v;
v.push_back(1);         // add new ele. (append)
v.pop_back();           // remove last ele.
v.front();              // v[0]
v.back();               // v[v.size() - 1]
v.empty();              // true if empty
v.size();               // return size
v.clear();              // clear the vector
v.resize(size);         // v.resize(10) => new size is 10
v.assign(size, value);  // resize to size and set given value

v.begin();              // iterator to first ele.
v.end();                // iterator to after end ele. v = [1, 2] 
                        // v.end() point to next memory location after 2

v.rend();               // iterator to last ele.
v.rbegin();             // iterator to before first ele.

for(ll i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
for(auto it = a.begin(); it != a.end(); it++) {
    cout << *it << endl;
}
```

#### Stack
```
last in first out (LIFO)
add back
pop back

stack<int> s;
s.push(10); // add new ele. to stack 
s.top(); // get top (last) ele.
s.pop(); // remove top ele.

s.empty();
s.size();
s.clear(); // error, not possible in stack 
```

#### Queue
```
first in first out (FIFO)
add back
pop front

queue<int> q;
q.push(10); // add new ele. to queue
q.front(); // get front ele.
q.pop(); // remove front ele.

q.empty();
q.size();
q.clear(); // error, not possible in queue 
```

#### Deque
```
double ended queue
add front, add back
pop front, pop back

deque<int> q;
q.push_front(10); // add new ele. at front
q.push_back(11); // add new ele. at end
q.pop_front(); // remove first ele
q.pop_back(); // remove last ele
q.front(); // get front ele.
q.back(); // get back ele.

q.empty();
q.size();
q.clear(); // error, not possible in queue 
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
```
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
[=] => ...                         pass by value

int x = 10;
auto add = [&](int y) {
    x += y;
};
add(5);
// x = 15 here

Note:
recursion not possible
```

### Function
```
function<return type(parameter)> name = lambda function;

function<int(int)> fact = [&](int n) {
    if(n == 0) return 1;
    return n * fact(n - 1);
};
fact(5);

Note:
[&] needed to capture fact
recursion possible
```