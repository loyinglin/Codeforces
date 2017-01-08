//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/longest-palindromic-substring/
 题目大意：
 
 
 题目解析：
 
 复杂度解析：
 时间复杂度
 O(N+M) N、M是两个数组的长度；
 空间复杂度
 O(1)；
 代码量
 从两个数组返回最小值，并指向下一个可以用函数getNext封装；
 
 其他解法：
 直接合并两个数组，然后排序，取中位数；
 优劣：代码量更小，但时间较长。
 
 
 http://blog.csdn.net/hopeztm/article/details/7932245
 
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
