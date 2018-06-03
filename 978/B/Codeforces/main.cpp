//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/978/problem/B)
 **题目大意：**
 小明电脑上有一个文件，文件名是一串小写字母；
 小明很不喜欢'xxx'这个字符串，所以他想对文件名进行修改，去掉某些字符；
 问，最少去掉几个字符，文件名会不出现'xxx'。
 
 输入：
 第一行n，表示文件名长度；n ( 3 ≤ n ≤ 100 )
 第二行str，表示文件名；
 
 输出：
 最少去掉的字符数量。
 
 **Examples**
 **input**
 6
 xxxiii
 **output**
 1
 
 样例解释：
 xxxiii去掉第一个字符'x'，之后剩下xxiii，满足要求，所以最少只需要去掉1个字符。
 
 
 **题目解析：**
 题目的要求，'xxx'是一个不允许出现的字符串，那么当出现'xxx'的时候就要删除字符；
 可以知道，'xxx'不管删除哪一个字符串都是一样的，那么可以这么做：
 每次出现'xxx'就删掉一个字符，重新对整个字符串进行检查，直到检查之后没有'xxx'。
 
 **思考🤔：**
 或者'xx...x'的长度是指定长度m呢？（同时1 <= m,n <= 1e5)
 那么可以对字符进行聚合，相邻的同样字符进行合并，比如说aabbbc这的字符串就变成(a2,b3,c1)，再对x进行处理；
 
 
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
    
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    int ans = 0;
    while (1) {
        int ok = 1;
        for (int i = 2; i < n; ++i) {
            if (str[i] == 'x' && str[i - 1] == str[i] && str[i - 2] == str[i]) {
                str.erase(str.begin() + i, str.begin() + i + 1);
                ok = 0;
                ++ans;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}
