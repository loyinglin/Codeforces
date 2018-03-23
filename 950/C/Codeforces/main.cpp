//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 Numbers Exchange
 [题目链接](http://codeforces.com/contest/950/problem/C)
 **题目大意：**
 小明喜欢一种字符串Zebras，Zebras的定义是以0开头，以0结束，中间0/1交替出现，比如说：0, 010, 01010；
 类似1, 0110, 0101这种就不是Zebras；
 现在给出一串长度为n的字符串（全部是01组成）；
 小明希望把字符串分成若干个子序列，并且每个子序列都是Zebras；（每个字符存在子序列中，且只在一个）
 如果不能，则输出-1；
 
 **输入数据：**
 一串字符串，长度不超过20w；
 
 >**Examples**
 **input**
 0010100
 **output**
 3
 3 1 3 4
 3 2 5 6
 1 7
 样例解释：
 分3个子序列010，010，0；
 
 **题目解析：**
 由贪心知道，01010..的序列越长越好；（0的利用率提升）
 题目的要求是每个字符都要放到子序列里去，那么有一种简单的做法：
 每次从左到右扫描，在未选择的字符中，寻找最长的Zebras，比如说对样例0010100处理：
 第一次扫描，扫出01010；（1，3，4，5，6）
 第二次扫描，扫出0；（2）
 第三次扫描，扫出0；（7）
 
 但是这样的代价比较高，是N^2级别复杂度；（对于00001111000这样的数据）
 考虑这样一种优化方案：
 有两个队列，一个队列x放0结束的子序列，一个队列y放1结束的子序列；
 当遇到0时，从队列y取一个子序列，末尾拼0然后放入队列x；如果队列y没有数据，则新建一个序列；
 当遇到1时，从队列x取一个子序列，末尾拼1然后放入队列y；如果队列x没有数据，则无解；
 
 这样每次都是O(1)的操作，总体的复杂度是O(N)；
 
  **思考🤔：**
 trick: long long。
 
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
vector<int> ans[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cin >> str;
    size_t n = strlen(str);
    
    queue<int> q[2];
    int id = 0;
    int ok = 1;
    for (int i = 0; i < n && (ok>0); ++i) {
        if (str[i] == '0') {
            if (q[1].empty()) {
                ans[id].push_back(i);
                q[0].push(id++);
            }
            else {
                int x = q[1].front();
                q[1].pop();
                ans[x].push_back(i);
                q[0].push(x);
            }
        }
        else {
            if (q[0].empty()) {
                ok = -1;
            }
            else {
                int x = q[0].front();
                q[0].pop();
                ans[x].push_back(i);
                q[1].push(x);
            }
        }
    }
    if (ok > 0 && q[1].size() == 0) {
        cout << id << endl;
        for (int i = 0; i < id; ++i) {
            cout << ans[i].size() << " ";
            for (int j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] + 1 << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
