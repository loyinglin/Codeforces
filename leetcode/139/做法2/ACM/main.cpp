//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/word-break/
 题目大意：
 给出原串s，字符串数组dict，要求：
 1、把s分成多个连续的子串；
 2、每个子串都在dict里面；
 问，是否有解。
 
 s = "leetcode",
 dict = ["leet", "code"].
 
 Return true because "leetcode" can be segmented as "leet code".
 
 题目解析：
 把一个串分成2个串的可能性有n种可能，n是字符串长度。
 那么对于串[l, r] 如果[l, k] 和 [k+1, r]是合法的，那么[l, r]也是合法的。
 故而用动态规划：
 dp[i][j] 表示字符串[i, j]是否为合法的子串；
 枚举k∈[i, j] 来判断分割字符串的位置；
 转移转移是O（N），因为需要判断区间[i, k]和[k+1, j]是否合法（用字典数配合）；
 最后判断dp[1, n]是否合法。
 
 复杂度解析：
 时间复杂度
 O(N^3) N^2的状态* N的字典数判断。
 空间复杂度
 O(N^2+M) N^2是状态数量，M是字典数；
 
 优化方案：
 1、dp用1维表示；dp[i] 表示前i个是否合理，转移的时候dp[i]=dp[k] && substr(k+1, i) 
 2、判断substr是否存在时，可以用字典数；
 
 
 
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

struct Node {
    Node *ch[26];
    bool word;
};

class Solution {
public:
    bool dp[N];
    bool wordBreak(string s, vector<string>& wordDict) {
        reset();
        for (int i = 0; i < wordDict.size(); ++i) {
            insertTree(wordDict[i].c_str());
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    string substr = string(s.begin() + j, s.begin() + i);
                    if (look(substr.c_str())) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    struct Node node[N];
    int cnt;
    Node *head;
    Node* need(int t){
        memset(node + t, 0, sizeof(Node)); // 注意大小写！！
        return &node[t];
    }
    void reset() {
        cnt = 0;
        head = need(cnt);
    }
    void insertTree(const char *s){				//字典树建树
        Node *p = head;
        for(int i = 0; s[i]; i++){
            int id = s[i] - 'a';
            if(!p->ch[id]) p->ch[id] = need(++cnt);
            p = p->ch[id];
        }
        p->word = true;
    }
    bool look(const char * str) {
        Node *p = head;
        for(int i = 0; str[i]; i++){
            int id = str[i] - 'a';
            p = p->ch[id];
            if (p == NULL) return false;
        }
        return p->word;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    string str = "aaaaaaa";
    vector<string> vec;
    vec.push_back(string("aaaa"));
//    vec.push_back(string("sand"));
    vec.push_back(string("aa"));
    cout << leetcode.wordBreak(str, vec) << endl;
    
    return 0;
}
