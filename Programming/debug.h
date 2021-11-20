#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

template <typename A>
string to_string(queue<A> q);

template <typename T, typename Container, typename Compare>
string to_string(priority_queue<T, Container, Compare> pq);

template <typename A>
string to_string(stack<A> s);

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B>
string to_string(tuple<A, B> t);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t);

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
string to_string(T_container any);


string to_string(char c) {
    string res(3, '\'');
    res[1] = c;
    return res;
}
string to_string(string a) {
    return "\"" + a + "\"";
}
string to_string(const char* s) {
    return to_string((string) s);
}
string to_string(bool a) {
    // return (a ? "true" : "false");
    return (a ? "1" : "0");
}

// bitset
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for(size_t i = 0; i < N; i++) {
        res += (v[i] ? '1' : '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

// boolean can't access direclty in for each loop
string to_string(vector<bool> v) {
    string res = "";
    res += "{";
    bool first = true;
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) res += ", ";
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

// queue
template <typename A>
string to_string(queue<A> q) {
    string res = "";
    res += "{";
    bool first = true;
    while (!q.empty()) {
        if (!first) res += ", ";
        first = false;
        res += to_string(q.front());
        q.pop();
    }
    res += "}";
    return res;
}

// priority_queue
template <typename T, typename Container, typename Compare>
string to_string(priority_queue<T, Container, Compare> pq) {
    string res = "";
    res += "{";
    bool first = true;
    while (!pq.empty()) {
        if (!first) res += ", ";
        first = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += "}";
    return res;
}

// stack
template <typename A>
string to_string(stack<A> s) {
    stack<A> rev;
    while (!s.empty()) {
        rev.emplace(s.top());
        s.pop();
    }

    string res = "";
    res += "{";
    bool first = true;
    while (!rev.empty()) {
        if (!first) res += ", ";
        first = false;
        res += to_string(rev.top());
        rev.pop();
    }
    res += "}";
    return res;
}

// pair
template <typename A, typename B>
string to_string(pair<A, B> p) {
    string res = "";
    res += "(";
    res += to_string(p.first) + ", ";
    res += to_string(p.second);
    res += ")";
    return res;
}

// tuple
template <typename A, typename B>
string to_string(tuple<A, B> t) {
    string res = "";
    res += "(";
    res += to_string(get<0>(t)) + ", ";
    res += to_string(get<1>(t));
    res += ")";
    return res;
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    string res = "";
    res += "(";
    res += to_string(get<0>(t)) + ", ";
    res += to_string(get<1>(t)) + ", ";
    res += to_string(get<2>(t));
    res += ")";
    return res;
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    string res = "";
    res += "(";
    res += to_string(get<0>(t)) + ", ";
    res += to_string(get<1>(t)) + ", ";
    res += to_string(get<2>(t)) + ", ";
    res += to_string(get<3>(t));
    res += ")";
    return res;
}

// vector deque list set map
// template <typename T_container>
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
string to_string(T_container any) {
    string res = "";
    res += "{";
    bool first = true;
    for (auto x : any) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

// -------------------------------------------------------------------------

#define LINE_NO cerr << __LINE__ << "\t|"
#define exit(x) cerr << "Time elapsed : " << fixed << setprecision(3) << 1.0 * clock() / (CLOCKS_PER_SEC * 60.0) << " min.\n"; \
                exit(x)

void adjust_spaces(string& s) {
    if(s.empty()) return;
    if(s.front() != ' ') s = ' ' + s;
    if(s.back() != ' ') s += ' ';
}

#define dbg(...) LINE_NO, _debug1(#__VA_ARGS__), _debug2(__VA_ARGS__), 0

vector<string> all_variables{};
void _debug1(const string &s)
{
    if(s.empty()) return;
    string variable = "";
    int bracket = 0, start = all_variables.size();
    for(char c : s)
    {
        if (c == '(') bracket++;
        else if (c == ')') bracket--;
        else if (c == ',' and bracket == 0) {
            adjust_spaces(variable);
            all_variables.emplace_back(variable);
            variable = "";
            continue;
        }
        variable += c;
    }
    adjust_spaces(variable);
    all_variables.emplace_back(variable);
    reverse(all_variables.begin() + start, all_variables.end());
}

void _debug2() {
    cerr << '\n';
}
template<typename Head>
void _debug2(Head H) {
    cerr << all_variables.back() << "= " << to_string(H) << '\n';
    all_variables.pop_back();
}
template<typename Head, typename... Tail>
void _debug2(Head H, Tail ... T) {
    cerr << all_variables.back() << "= " << to_string(H) << ",";
    all_variables.pop_back();
    _debug2(T...);
}

// #define d(...) LINE_NO << " [" << #__VA_ARGS__ << "] : ", _debug(__VA_ARGS__)
// void _debug() {
//     cerr << '\n';
// }
// template<typename Head, typename... Tail>
// void _debug(Head H, Tail ... T) {
//     cerr << to_string(H) << " ";
//     _debug(T...);
// }

#endif