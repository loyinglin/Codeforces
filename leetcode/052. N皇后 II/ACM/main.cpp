//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 2022年03月27日.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode-cn.com/problems/n-queens-ii
 题目大意：
 n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。

  
 
 题目解析：
 按照题目去dfs即可，为了更好实现，这里使用了深度优先搜索；
 一个小的优化点，就是在计算某个点是否可行时，使用x和y的相对距离来快速匹配。
 
 
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
#include<unordered_set>
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    else {
        return b.end < a.end;
    }
}
class Solution {
    int ans;
    bool check(int x, int y, vector<pair<int, int>> &vec) {
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i].first == x || vec[i].second == y || (abs(vec[i].first - x) == abs(vec[i].second - y))) {
                return false;
            }
        }
        return true;
    }
    void dfs(int k, int n, vector<pair<int, int>> &vec) { // 第k行，vec存放k-1行的皇后位置
        if (k >= n) {
            ++ans;
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (check(k, i, vec)) {
                vec.push_back(make_pair(k, i));
                dfs(k + 1, n, vec);
                vec.pop_back();
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        ans = 0;
        vector<pair<int, int> > vec;
        dfs(0, n, vec);
        return ans;
    }
    
}leetcode;


int main(int argc, const char * argv[]) {
    vector<Interval> vec;
    vec.push_back(Interval(1, 3));
    vec.push_back(Interval(2, 6));
    vec.push_back(Interval(10, 11));
    vec.push_back(Interval(8, 9));
    leetcode.merge(vec);
    
    return 0;
}
