//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/955/problem/B)
 **题目大意：**
 我们认为一个字符串是好看，如果它满足：
 1、由两种字符组成；
 2、调整字符的顺序，可以使得相同字符是连续的；
 比如说：ab、aba、abb、aaabbbb这样的字符是好看的，但abc、aa这样的字符是不好看的；
 现在给出字符串s，问能否把s分成两个子序列，使得子序列都可以组成好看的字符串；
 
 输入：
 第一行，字符串s (1 ≤ |s| ≤ 1e5)
 输出：
 如果可以，输出Yes；否则输出No；
 
 **Examples**
 **input**
 ababa
 **output**
 Yes
  **input**
 yeee
 **output**
 No
 
 **题目解析：**
 好看的字符串，其实就是要求字符串有且只有两种字符串。
 题目的意思是把字符串s分成两个字符串，并且每个都有两种字符。
 那么先统计字符串s中各个字符的数量，得到字符种数num，如果：
 num>4，无解；
 num=4，有解，直接分为2+2；
 num=3，必须有一个字符的数量>=2；
 num=2，两个字符数量都满足>=2；
 num=1，无解；
 
 **思考🤔：**
 用a[i]表示字符串i的数量，然后对a进行从大到小的排序，可以一行代码写完上面的判断
 if ((count == 4) || (count == 3 && a[0] >= 2) || (count == 2 && a[1] >= 2)) cout << "Yes" << endl;
 
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

char str[N];
int a[N];

bool cmp(int a, int b) {
    return a > b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> str;
    long n = strlen(str);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[str[i] - 'a'] == 0) ++count;
        a[str[i] - 'a']++;
    }
    
    sort(a, a + 26, cmp);
    if ((count == 4) || (count == 3 && a[0] >= 2) || (count == 2 && a[1] >= 2)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    
    return 0;
}
