//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/940/problem/C)
 **题目大意：**
 给出一个字符串str，字符串由小写字母拼成；
 现需要拼一个新字符串，要求：
 1、长度为k，全部为小写字母，且字母都在str中出现过；
 2、strNew的字典序大于str，且尽可能小；
 
 **输入数据：**
 n and k (1 ≤ n, k ≤ 100 000)
 
 >**Examples**
 **input**
 3 3
 abc
 **output**
 aca
 样例解释：
 aaa, aab, aac, aba, abb, abc, aca, acb, .... 都是满足条件1；
 其中字典序大于abc，且尽可能小的是aca；
 
 **题目解析：**
 题目分俩种情况讨论：
 1、k > n，那么只需要用str中最小的字符填满(strNew-str)后面的字符；
 2、k <= n，从右往左遍历，寻找某一位i，strNew[i]>str[i]，之后的字符全部用str中最小的字符填满。
 
  **思考🤔：**
 也可以借用模拟加法的方式来思考，比如说abc的下一个字符串是abc+a=abd，d进位变成aca。
 
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
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
int vis[3333];

int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    cin >> str;
    for (int i = 0; i < n; ++i) {
        vis[str[i]] = 1;
    }
    if (k > n) {
        cout << str;
        for (int i = 0; i < 26; ++i) {
            int index = 'a' + i;
            if (vis[index]) {
                for (int j = 0; j + n < k; ++j) {
                    putchar(index);
                }
                break;
            }
        }
        cout << endl;
    }
    else {
        for (int i = k - 1; i >= 0; --i) {
            int bigger = 0;
            for (int j = str[i] + 1; j < 'a' + 26; ++j) {
                if (vis[j]) {
                    bigger = j;
                    break;
                }
            }
            if (bigger) {
                str[i] = bigger;
                
                for (int j = 0; j < 26; ++j) {
                    int index = 'a' + j;
                    if (vis[index]) {
                        for (int t = i + 1; t < k; ++t) {
                            str[t] = index;
                        }
                        break;
                    }
                }
                break;
            }
        }
        str[k] = 0;
        cout << str << endl;
    }
    return 0;
}
