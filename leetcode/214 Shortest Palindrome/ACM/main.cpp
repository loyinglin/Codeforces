//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/shortest-palindrome/
 题目大意：
 给出一个字符串s，在s的左边添加字符串，使得s变成一个回文串；
 要求s的字符串长度尽可能短，返回最后的s串。
 
 example:
 Given "aacecaaa", return "aaacecaaa".
 Given "abcd", return "dcbabcd".
 
 题目解析：
 本质还是找回文串，先考虑暴力的做法。
 对于每个位置，判断成为最后s串回文串中心点的可能性。
 如果位置能覆盖到最左边，那么右边剩下的字符串翻转后贴在最左边。
 
 优化：
 用manachar找出每个位置的回文串长度。
 
 复杂度解析：
 时间复杂度
 O(N);
 
 空间复杂度
 O(N);
 
 代码量
 
 
 其他解法：
 用kmp，s + "#" + reverse(s)；
 
 
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
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
class Solution {
public:
    string shortestPalindrome(string s) {
        vector<char> str(s.length() * 2 + 5);
        vector<int> p(str.size());
        str[0] = '@';
        int i, j;
        for(i = 0, j = 1; s[i]; i++){
            str[j++] = '#';
            str[j++] = s[i];
        }
        str[j++] = '#';
        int n = j;
        manachar(str, p, n);
        int ans = 0, pos = 0;
        for(i = 1; i < n; i++) { // @#a#b#a#a#
            if (p[i] == i) { // 能覆盖到最左边
                pos = i;
                ans = p[i] - 1; // 回文串长度
            }
        }
        string add = string(s.begin() + ans, s.end());
        reverse(add.begin(), add.end());
        return  add + s;
    }
    
    void manachar(vector<char> &str, vector<int> &p, int n){
        int id = 0, mx = 0;
        for(int i = 1; i < n; i++){
            if(mx > i) p[i] = min(p[2 * id - i], mx - i);
            else p[i] = 1;
            while(str[i + p[i]] == str[i - p[i]]) p[i]++;
            if(p[i] + i > mx) mx = p[i] + i, id = i;
        }
    }
}leetcode;


int main(int argc, const char * argv[]) {
    string str = "aaceca";
    cout << leetcode.shortestPalindrome(str) << endl;
    
    return 0;
}
