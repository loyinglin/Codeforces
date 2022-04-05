//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 2022年03月27日.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode-cn.com/problems/spiral-matrix
 题目大意：
 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 示例 1：
 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 输出：[1,2,3,6,9,8,7,4,5]
 示例 2：

 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 输出：[1,2,3,4,8,12,11,10,9,5,6,7]

 
 题目解析：
 按照题目去遍历即可，为了更好实现，可以先把方向用数组描述出来；
 
 
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
    int dir[4][2] = {
        0, 1,
        1, 0,
        0, -1,
        -1, 0
    };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = 0, index = 0;
        map<pair<int, int>, bool> vis;
        while (ret.size() < n * m) {
            ret.push_back(matrix[x][y]);
            vis[make_pair(x, y)] = true;
            if (x + dir[index][0] < 0 || x + dir[index][0] >= n || y + dir[index][1] < 0 || y +dir[index][1] >= m) {
                index = (index + 1) % 4;
            }
            else if (vis[make_pair(x + dir[index][0], y + dir[index][1])]) {
                index = (index + 1) % 4;
            }
            x += dir[index][0];
            y += dir[index][1];
        }
        return ret;
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
