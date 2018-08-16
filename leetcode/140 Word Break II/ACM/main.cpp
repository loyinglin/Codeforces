//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/word-break-ii/
 题目大意：
 https://leetcode.com/problems/word-break
 在前文的基础上，输出所有的解。
 
 Input:
 s = "catsanddog"
 wordDict = ["cat", "cats", "and", "sand", "dog"]
 Output:
 [
 "cats and dog",
 "cat sand dog"
 ]
 
 题目解析：
 用vector来存可能的解，然后用dfs来输出即可。
 
 
 
 其他解法：
 
 
 
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
const int N = 5000;
class Solution {
public:
    vector<int> g[N];
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        unordered_set<string> wordSet;
        for (int i = 0; i < wordDict.size(); ++i) {
            wordSet.insert(wordDict[i]);
        }
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    string substr = string(s.begin() + j, s.begin() + i);
                    if (wordSet.find(substr) != wordSet.end()) {
                        //                        cout << i << " " << j << " " << substr << endl;
                        dp[i] = true;
                        g[i].push_back(j);
                    }
                }
            }
        }
        vector<string> cur;
        if (dp[s.length()]) {
            dfs(s, ret, cur, s.length());
        }
        return ret;
    }
    
    void dfs(string &s, vector<string> &ret, vector<string> &cur, long n) {
        for (int i = 0; i < g[n].size(); ++i) {
            string str = string(s.begin() + g[n][i], s.begin() + n);
            cur.push_back(str);
            dfs(s, ret, cur, g[n][i]);
            cur.pop_back();
        }
        if (n == 0) {
            string str = cur.back();
            for (int i = cur.size() - 2; i >= 0; --i) {
                str += string(" ");
                str += cur[i];
            }
//            cout << str << endl;
            ret.push_back(str);
        }
    }
}leetcode;




int main(int argc, const char * argv[]) {
    string str = "aaaaaa";
    vector<string> vec;
    vec.push_back(string("aaaa"));
    //    vec.push_back(string("sand"));
    vec.push_back(string("aa"));
    leetcode.wordBreak(str, vec);
    
    return 0;
}
