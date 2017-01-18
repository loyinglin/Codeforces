//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/longest-palindromic-substring/
 题目大意：
 输入一个回文串，输出长度最长的回文子串；
 如果有多个答案，输出任意一个。
 
 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 
 
 题目解析：
 模板题，有现成的解法。
 求回文串有O(N)的算法，详见[manacher解析](http://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html)。

 
 复杂度解析：
 时间复杂度
 O(N) N是字符串的长度；
 空间复杂度
 O(N) N是字符串的长度；
 
 
 其他解法：
 暴力，从每个点开始枚举，判断最长的回文子串，O(N^2);
 kmp，回文串s和s的转置是一样的，那么可以把原串s和s'进行匹配，判断区间是否合法；（有可能存在匹配，但是区间不重叠的情况）
 
 
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
const int N = 2200;
class Solution {
public:
    char s[N], str[N];
    int p[N];
    string longestPalindrome(string s) {
        str[0] = '@';
        int i, j;
        for(i = 0, j = 1; s[i]; i++){
            str[j++] = '#';
            str[j++] = s[i];
        }
        str[j++] = '#';
        int n = j;
        manachar(n);
        int ans = 0, pos = 0;
        for(i = 1; i < n; i++)
            if (ans < p[i] - 1) {
                ans = max(ans, p[i] - 1);
                pos = i;
            }
        
        return  string(s.begin() + pos/2 - (ans + 1) / 2, s.begin() + pos/2 + ans / 2);
    }
    
    void manachar(int n){
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
    string str = "babbab";
    cout << leetcode.longestPalindrome(str) << endl;
    
    return 0;
}
