//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 题目大意：
 给出一个字符串s，一个字符列表words，words内的单词都是同一长度，找到一个区间，要求：
 1、区间内的字符串，可以切分成若干个连续的子串，每个子串都是words的单词；
 2、每个单词只出现一次；
 
 输出所有可能的区间的起点。
 
 For example, given:
 s: "barfoothefoobarman"
 words: ["foo", "bar"]
 You should return the indices: [0,9].
 
 
 
 题目解析：
 题目提供了一个了一个不可忽视的限制，所有的words是同一长度，这样就避免了fool和foo的情况；
 并且在判断s的子串是否出现时，可以直接截取长度为m的字符串；
 这样流程就变成：
 初始位置s，截取m个字符str，查询str是否在words中，如果在则判断下m个字符；
 如果不在words中，则回溯到最初的位置s，从s+1开始判断；
 
 这样的复杂度会很高，因为回溯之后又要从原来的位置的下一个开始匹配。
 有一种优化方案：假设len为words字符串的统一长度；
 从0,1,2...到len-1，分别匹配一次即可。
 这样可以采取一种策略，当(l, r)的字符串最后len个字符匹配失败后，直接从r+1的位置匹配；因为(r-len,r)的字符不存在words中；
 如果(r-len, r)在之前已经在k出现过，则可以把左边界移到k+1；
 
 
 
 复杂度解析：
 时间复杂度
 空间复杂度

 
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



typedef long long lld;
const int N = 50000;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> strNum;
        unordered_map<string, vector<int>> strHash;
        for (string word : words) {
            ++strNum[word];
            if (strHash.find(word) == strHash.end()) {
                vector<int> tmp;
                strHash[word] = tmp;
            }
        }
        int num = (int)words.size(), len = (int)words[0].length();
        for (int i = 0; i < len - 1; ++i) { //枚举可能开始的位置
            int pos = i;
            
        }
        
        
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
