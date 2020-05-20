//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/822/problem/B)
 **题目大意：**
 给出两个长度为n和m的字符串a和b，有一个操作是把字符串a任意位置的字符变成字符?，字符?表示通配符，可以匹配任意字符；
 问最少需要变多少次，才能把字符串a变成字符串b的子串？
 输出最少变的数量和位置；
 
 输入数据
 第一行，整数 n and m (1 ≤ n ≤ m ≤ 1000)
 接下来是两行字符串a、b；
 
 输出数据
 最少变化的数量和位置；
  
 **Examples**
 input
 3 5
 abc
 xaybz
 output
 2
 2 3
 样例解释：可以把abc变成a??（适配ayb），这样需要变第2、3个字符；
 先输出最少变的次数，再输出具体的位置。
 
 
 **题目解析：**
 因为题目数据范围比较下，可以直接枚举字符串a与字符串b的匹配起始位置；
 再计算每次需要修改的字符个数，求出最小值。
 
 复杂度O（N^2）；
 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    
    
    vector<int> ans(n + 1);
    for (int i = 0; i + n <= m; ++i) {
        vector<int> tmp;
        for (int j = 0; j < n; ++j) {
            if (a[j] != b[i + j]) {
                tmp.push_back(j + 1);
            }
        }
        if (tmp.size() < ans.size()) {
            ans = tmp;
        }
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    
    
    return 0;
}
