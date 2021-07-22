//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************

 [题目链接](http://codeforces.com/contest/982/problem/B)
 **题目大意：**
 有一辆公共汽车上面有n排座位，每排有两个座位，已知第i排的座位宽度是w[i]；
 有2n个乘客会逐个上车，这些乘客会分为两类：
 1、性格内向的，会优先选择一排座位都是空的，并且座位宽度最小的一排；
 2、性格外向的，会优先选择一排座位不为空的，并且座位宽度最大的一排；
 现在想知道这2n个乘客，会分别选中第几排。
 
 
 **输入数据：**
 第一行 𝑛 (1≤𝑛≤200000)
 第二行𝑤1,𝑤2,…,𝑤𝑛  (1≤𝑤𝑖≤1e9)
 第三行2n长度的01字符串，1表示乘客是外向的，题目保证外向的乘客上车时，一定能找到一排座位不为空的位置，并且性格外向和性格内向的数量相同。
 
 Examples
 input
 2
 3 1
 0011
 output
 2 1 1 2

 input
 6
 10 8 9 11 13 5
 010010011101
 output
 6 6 2 3 3 1 4 4 1 2 5 5

 
 **题目解析：**
 题目的意思比较直接，如果不考虑复杂度，可以直接模拟这个选择的过程，在每个乘客上车的时候，根据类型遍历剩下的位置。这样总体的复杂度是O(N^2)，由于N比较大会超时。
 可以知道，性格内向的乘客，永远只会挑选宽度最小的一排，那么可以使用优先队列来处理，把所有排按照宽度排序，每次选择宽度最小的出来，然后从队列剔除，放入另外一个按照宽度从大到小排序的优先队列；
 性格外向的乘客，每次都从第二个优先队列选择一个位置宽度最大的即可，题目会保证数据合法。
 
 **思考🤔：**
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 401000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first > tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

struct cmp
{
    bool operator()(Node a,Node b) { return  a.first < b.first; }
};


char str[N];
int a[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    priority_queue<Node> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        q.push(Node(a[i], i));
    }
    cin >> str;
    
    priority_queue<Node, vector<Node>, cmp> qBig;
    
    for (int i = 0; i < n * 2; ++i) {
        if (str[i] == '0') {
            Node top = q.top();
            q.pop();
            cout << top.second << endl;
            qBig.push(top);
        }
        else {
            Node top = qBig.top();
            qBig.pop();
            cout << top.second << endl;
        }
    }
    

    return 0;
}
