//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 题目大意：
 给出一个字符串str，求出str中最长子串的长度，要求子串里没有重复的字符。
 
 Example 1:
 Input: "abcabcbb"
 Output: 3
 最长子串是abc，长度是3；

 Example 2:
 Input: "bbbbb"
 Output: 1
 最长子串是b，长度是1；（bb的话出现重复的b）
 
 
 题目解析：
 如果没有重复字符的要求，那么str的最长子串就是自己；
 基于此要求，我们考虑从左到右遍历字符串求subStr的时候，如果遇到某个字符subStr不存在，那么便把它加入subStr；
 如果遇到某个字符是subStr已经有的，那么便把subStr已出现的字符的位置开始，左边的字符全部不要即可。
 比如说对于题目的样例1，当我们枚举a/b/c的时候，都是直接加入subStr，得到abc；
 当遇到第四个字符a时，把a去掉得到bc，再加入a，得到bca；
 重复这个过程到字符串末尾，记录期间每个字符加入后的长度，可以得到满足要求的最长子串长度。
 
 复杂度解析：
 时间复杂度是O(N)
 空间复杂度是O(N)
 
 
 
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
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1


struct Node {
    int first, second;
    Node(){}
    Node(int f, int s) {
        first = f;
        second = s;
    }
    bool operator < (const Node tmp) const {
        if (first != tmp.first) {
            return first > tmp.first;
        }
        else {
            return second > tmp.second;
        }
    }
};

typedef long long lld;
const int N = 50000;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int vis[257] = {0};
        int maxLen = 0, cur = 0;
        for (int i = 0; i < s.length(); ++i) {
            while (vis[s[i]]) {
                vis[s[cur]] = 0;
                ++cur;
            }
            vis[s[i]] = 1;
            maxLen = max(maxLen, i - cur + 1);
        }
        return maxLen;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
