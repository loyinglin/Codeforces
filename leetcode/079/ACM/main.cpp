//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 2022年03月27日.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 链接：https://leetcode.cn/problems/word-search
 题目大意：
 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 示例 ：
 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 输出：true

 题目解析：
 题目给出的条件非常明确，就是按照格子进行搜索；
 搜索有广度/深度优先搜索，从题目的要求来看，采用深度优先搜索能够更加方便去匹配结果和剪枝；
 剪枝：
 1、如果某个字符不相同，不进行搜索；
 2、如果下一个字符不相同，则停止搜索；
 
 
 
 
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
        0, -1,
        1, 0,
        -1, 0
    };
    bool dfs(vector<vector<char>>& board, vector<vector<char>>& vis, int x, int y, int index, string &word) {
        if (board[x][y] != word[index]) {
            return false;
        }
        if (index + 1 == word.size()) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int nextX = dir[i][0] + x, nextY = dir[i][1] + y;
            if (nextX < 0 || nextX >= board.size() || nextY < 0 || nextY >= board[0].size() || vis[nextX][nextY]) continue;;
            
            vis[nextX][nextY] = 1;
            if (dfs(board, vis, nextX, nextY, index + 1, word)) {
                return true;
            }
            vis[nextX][nextY] = 0;
            
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ret = 0;
        vector<vector<char>> vis;
        for (int i = 0; i < board.size(); ++i) {
            vector<char> tmp(board[0].size());
            vis.push_back(tmp);
        }
        for (int i = 0; i < board.size() && !ret; ++i) {
            for (int j = 0; j < board[0].size() && !ret; ++j) {
                vis[i][j] = 1;
                ret = dfs(board, vis, i, j, 0, word);
                vis[i][j] = 0;
            }
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<char> a = {'A', 'A'};//, 'B', 'C', 'E'};
//    vector<char> b = {'S', 'F', 'C', 'S'};
//    vector<char> c = {'A', 'D', 'E', 'E'};
    vector<vector<char> > vec = {a};
    string word("AAA");
    cout << leetcode.exist(vec, word) << endl;
    
    return 0;
}
