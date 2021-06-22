//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/979/problem/B)
 **题目大意：**
 "Kuro", "Shiro" ， "Katie"三个人在玩游戏；
 每个人一个字符串，长度相同；
 游戏有n轮，每轮每个人都必须修改其中一个字符为任意字符；
 字符串中的任意子串subStr，在字符串重复出现的次数，就是每个人的得分。
 问游戏结束后，谁的分数最高；
 
 输入：
 第一行：n，游戏轮数 ( 0 ≤ n ≤ 1e9 )
 接下来3行字符串，分别表示"Kuro", "Shiro" ， "Katie"的字符串；
 输出：
 输出最高分的人，"Kuro", "Shiro" ， "Katie"；
 如果有两个最高分，则输出'Draw'；
 
 **Examples**
 **input**
 3
 Kuroo
 Shiro
 Katie
 **output**
 Kuro
 
 **题目解析：**
 任意子串的最大重复次数，其实就是某个字符的最大出现次数，因为：
 如果ab是最大重复次数的子串，那么a出现的次数不会比ab少；
 
 那么游戏转换为对字符串进行最多n次操作，使得某个字符出现最大次数。
 容易知道，假如已经出现字符次数最大的字符是x，那么相当于把非x的字符改成x。
 那么有sum=min(len, count+n)； sum是字符串的最大重复子串出现次数，len是字符串长度，count是相同字符出现最大次数；
 接着分别判断三个人的得分即可。
 
 **思考🤔：**
 trick：字符串是全部相同的字符，且n=1的时候！ 此时最多是len-1
 
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
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    string str[3];
    cin >> str[0] >> str[1] >> str[2];
    int sum[3];
    for (int i = 0; i < 3; ++i) {
        sum[i] = 0;
        int count[1000]={0};
        for (int j = 0; j < str[i].length(); ++j) {
            count[str[i][j]]++;
            sum[i] = max(sum[i], count[str[i][j]]);
        }
        if (sum[i] == str[i].length() && n == 1) {
            sum[i] = str[i].length() - 1;
        }
        else {
            sum[i] = min((int)str[i].length(), sum[i] + n);
        }
    }
    
    int totalMax = max(sum[0], max(sum[1], sum[2]));
    int size = 0, ans = 0;
    for (int i = 0; i < 3; ++i) {
        if (sum[i] == totalMax) {
            ++size;
            ans = i;
        }
    }
    
    if (size > 1) {
        cout << "Draw" << endl;
    }
    else {
        if (ans == 0) {
            cout << "Kuro" << endl;
        }
        else if (ans == 1) {
            cout << "Shiro" << endl;
        }
        else {
            cout << "Katie" << endl;
        }
    }
    
    return 0;
}
