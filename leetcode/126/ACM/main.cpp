//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/word-ladder-ii/
 题目大意：
 Given:
 beginWord = "hit"
 endWord = "cog"
 wordList = ["hot","dot","dog","lot","log"]
 
 从beginWord变成endWord，要求：
 1、每次只能变一个单词；
 2、每次变出来的单词必须在wordList列表；
 所有单词同等长度，都是小写；
 找出所有的最少变化次数。
 
 题目解析：
 非常明显的最短路；
 beginWord、wordlist、endWord两两连边（根据是否可变），求最短路；
 记录最短路的路径即可。
 记录几次TLE：
 建图用的是n^2，导致边数较多。
 当前做法的复杂度：
 建图是O(N^2),bfs是O(N^2)，dfs不确定，视答案而定。
 
 加了一个简单的优化：
 在compare处，如果不同数量大于1，立即返回；
 
 还可能加的优化：基数排序。这样可以极快的判断x、y是否可以trans；
 
 
 看了下其他人做法，大多数是len*26的可能，然后用set可以O(logN)来判断是否存在key；确实更快
 
 
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
class Solution {
public:
    vector<int> g[N];
    int vis[N];
    vector<string> wordVec;
    string begin, end;
    vector<int> ans[N];
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> ret;
        begin = beginWord;
        end = endWord;
        // 建图
        int src = (int)wordList.size() + 1, dest = (int)wordList.size() + 2;
        
        for (unordered_set<string>::iterator it = wordList.begin(); it != wordList.end(); ++it) {
            wordVec.push_back(*it);
        }
        for (int i = 0; i < wordVec.size(); ++i) {
            if (isConnect(beginWord, wordVec[i])) {
                addEdge(src, i);
            }
            if (isConnect(endWord, wordVec[i])) {
                addEdge(dest, i);
            }
            for (int j = i + 1; j < wordVec.size(); ++j) {
                if (isConnect(wordVec[i], wordVec[j])) {
                    addEdge(i, j);
                }
            }
        }
        if (isConnect(beginWord, endWord)) {
            addEdge(src, dest);
        }
        
        // BFS
        memset(vis, -1, sizeof(vis));
        queue<pair<int, int> > q; // 一个存遍历深度，一个存当前位置
        q.push(make_pair(src, 0));
        vis[src] = 0;
        while (!q.empty()) {
            pair<int, int> u = q.front();
            //            cout << "bfs " << getStr(u.first) << " Id " << u.first << " dep " << u.second << endl;
            q.pop();
            if (u.first == dest) {
                break;
            }
            for (int i = 0; i < g[u.first].size(); ++i) {
                int v = g[u.first][i];
                if (vis[v] < 0) {
                    vis[v] = u.second + 1;
                    q.push(make_pair(v, vis[v]));
                }
                if (vis[v] == u.second + 1) {
                    //                    cout << "add " << u.first << " TO " << v << endl;
                    ans[v].push_back(u.first); //记录可以从u到v
                }
            }
        }
        
        vector<string> cur;
        dfs(ret, cur, dest);
        
        return ret;
    }
    
    void dfs(vector<vector<string> > &ret, vector<string> &cur, int u) {
        cur.push_back(getStr(u));
        for (int i = 0; i < ans[u].size(); ++i) {
            int v = ans[u][i];
            dfs(ret, cur, v);
        }
        if (u == wordVec.size() + 1) {
            vector<string> ansVec;
            for (int i = cur.size() - 1; i >= 0; --i) {
                ansVec.push_back(cur[i]);
            }
            ret.push_back(ansVec);
#ifdef LYTEST
            cout << "ans " << " " << endl;
            for (vector<string>::iterator it = ansVec.begin(); it != ansVec.end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
#endif
        }
        
        cur.pop_back();
    }
    
    string getStr(int u) {
        string ret;
        if (u < wordVec.size()) {
            ret = wordVec[u];
        }
        else {
            if (wordVec.size() + 1 == u) {
                ret = begin;
            }
            else {
                ret = end;
            }
        }
        return ret;
    }
    
    
    void addEdge(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    bool isConnect (string a, string b) {
        int sum = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                ++sum;
                if (sum > 1) {
                    return 0;
                }
            }
        }
        return sum == 1;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    unordered_set<string> set;
    set.insert(string("hot"));
    set.insert(string("cog"));
    set.insert(string("dog"));
    set.insert(string("tot"));
    set.insert(string("hog"));
    set.insert(string("hop"));
    set.insert(string("pot"));
    set.insert(string("dot"));
    
    leetcode.findLadders("hot", "dog", set);
    
    
    return 0;
}
