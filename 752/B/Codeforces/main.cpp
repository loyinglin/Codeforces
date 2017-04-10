//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/752/problem/B
 题目大意：
 小明把键盘的键都卸下来清洗，在装回去后，发现有些键装错了。
 他看着键盘，打出一个字符串str，在屏幕显示出来一个字符串str';
 现在他可以选择任意两个键，交换它们的位置，但是每个键只能交换一次；
 
 问，小明是否能复原正确的键盘？
 如果可以，先输出交换次数，接下来每行输出每次交换的字母；（顺序无关）
 如果不可以，直接输出-1。
 
 题目样例：
 Examples
 input
 helloworld
 ehoolwlroz
 output
 3
 h e
 l o
 d z
 
 input
 merrychristmas
 christmasmerry
 output
 -1
 
 
 
 题目解析：
 题目有个很重要的条件，每个键只能使用一次。
 那么每次当遇到字符不同的时候，这两个字符就必须交换；如果这个字符已经交换过，那么无解。
 
 实现逻辑，可以用一个简单字符hash来实现，对str的字符，每次先判断是有hash字符，如果有则转成hash后的符；
 如果没有，添加hash[c]=c; 保证下次再遇到不会出错；
 然后进行判断，如果hash后的字符和str'上的不对应，则无解；
 
 
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
        if (first != second) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, ans = 0;
    char str[1111], strHash[1111];
    cin >> str;
    cin >> strHash;
    n = strlen(str);
    for (int i = 0; i < n; ++i) {
        int c = 0;
        if (a[str[i]] == strHash[i] && a[strHash[i]] == str[i]) { // 先看看转换后是否匹配
            c = a[str[i]];
        }
        if (c == strHash[i]) {
            continue;
        }
        else {
            if (a[str[i]] == 0 && a[strHash[i]] == 0) { // 双方都还没开始转换过
                a[str[i]] = strHash[i];
                a[strHash[i]] = str[i];
                if (str[i] != strHash[i]) {
                    node[ans++] = Node(str[i], strHash[i]);
                }
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < ans ; ++i) {
        cout << (char)node[i].first << " " << (char)node[i].second << endl;
    }
    
    return 0;
}
