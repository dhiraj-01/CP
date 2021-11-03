```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct Point
{
    ll x, y;
    Point(ll _x = 0, ll _y = 0) {
        x = _x;
        y = _y;
    }
    friend Point operator - (Point lhs, Point rhs) {
        return Point(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend ll operator * (Point lhs, Point rhs) {
        return (lhs.x * rhs.y - lhs.y * rhs.x);
    }
    friend bool operator == (Point lhs, Point rhs) {
        return (lhs.x == rhs.y && lhs.y == rhs.x);
    }
};

// = 0 - colinear
// > 0 - right
// < 0 - left

// p1 to p2 then p2 to p3 then p3 to p1 = which direction ?
ll direction(Point p1, Point p2, Point p3) {
    return (p3 - p1) * (p2 - p1);
}
ll dist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// ConvexHull - Grahamscan Algo
namespace ConvexHull
{
    vector<Point> Grahamscan(vector<Point> p)
    {
        ll n = p.size();
        Point p0 = p[0];
        for(ll i = 0; i < n; i++) {
            if(p[i].y < p0.y || (p[i].y == p0.y and p[i].x < p0.x)) {
                p0 = p[i];
            }
        }

        auto comp = [&p0](const Point &lhs, const Point &rhs)
        {
            ll dir = direction(p0, lhs, rhs);
            if(dir == 0) return dist(p0, lhs) < dist(p0, rhs);
            return dir < 0;
        };
        sort(p.begin(), p.end(), comp);

        vector<Point> s;
        s.push_back(p[0]);
        s.push_back(p[1]);
        s.push_back(p[2]);

        for(ll i = 3; i < n; i++)
        {
            ll len = s.size();
            while(len >= 2 and direction(s[len - 2], s[len - 1], p[i]) > 0) {
                s.pop_back();
                len--;
            }
            s.push_back(p[i]);
        }
        return s;
    }
}; 

void solve(ll& tc)
{
    ll n;
    cin >> n;

    vector<Point> p(n);
    for(ll i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    vector<Point> hull = ConvexHull::Grahamscan(p);
    for(ll i = 0; i < hull.size(); i++) {
        cout << hull[i].x << " " << hull[i].y << endl;
    }
}

int main() {
    ll tc = 1;
    for(ll i = 1; i <= tc; i++) {
        solve(i);
    }
    return 0;
}

/*
Input1
8
0 0
6 1
3 1
7 3
4 2
5 3
5 5
3 4

Output1
0 0
6 1
7 3
5 5
3 4
*/
```