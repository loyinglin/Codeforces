//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1328/problem/B)
 **题目大意：**
 有一个长度为n的字符串，有n-2个字符a，有2个字符b；
 把这个字符串重新排列，可以若干个字符串，然后按字典序排列，比如说n=5的时候：
 aaabb
 aabab
 aabba
 abaab
 ababa
 abbaa
 baaab
 baaba
 babaa
 bbaaa
 
 现在想知道长度为n的字符串重新排列后，第k个字符串是什么；
 
 **输入：**
 第一行整数t，表示样例个数；  (1≤𝑡≤10000)
 接下来t个样例，每个样例一行，有两个整数 𝑛 and 𝑘 (3≤𝑛≤10^5,1≤𝑘≤min(2⋅10^9, 𝑛⋅(𝑛−1)/2)
 
 **输出：**
 最少操作次数；
 
 **Examples**
 input
 7
 5 1
 5 2
 5 8
 5 10
 3 1
 3 2
 20 100
 
 output
 aaabb
 aabab
 baaba
 bbaaa
 abb
 bab
 aaaaabaaaaabaaaaaaaa
 
 **题目解析：**
 从n=5样例，我们只看字符b，会从最后面开始，逐渐往前面排；
 可以总结出规律，第1个b往前面挪动位置时，分别有：1、2、3、...、n-1种可能；
 那么累计这个数字和sum，直到数字sum大于k，此时找到b的第1个位置；
 接下来用sum和k的差值，就可以计算第2个b的位置，剩下的字符就全部是a了；

 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
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

bool cmp(int a, int b) {
    return a > b;
}

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            if (k > i) {
                k -= i;
            }
            else {
                int x = n - i - 1, y = n - k;
                for (int j = 0; j < n; ++j) {
                    if (j == x || j == y) {
                        putchar('b');
                    }
                    else {
                        putchar('a');
                    }
                }
                puts("");
                
                break;
            }
        }
    }
    
    return 0;
}


/**
 
 aaabb
 aabab
 baaba
 bbaaa
 abb
 bab
 aaaaabaaaaabaaaaaaaa

 
 */
