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
 但是，
 这样的复杂度会很高，因为回溯之后又要从原来的位置的下一个开始匹配。
 有一种优化方案：假设len为words字符串的统一长度；
 从0,1,2...到len-1，分别匹配一次即可。
 这样可以采取一种策略，当(l, r)的字符串最后len个字符匹配失败后，直接从r+1的位置匹配；因为(r-len,r)的字符不存在words中；
 如果(r-len, r)在之前已经在k出现过，则可以把左边界移到k+1，直到遇到右边界；
 可以在len次枚举后得到结果。
 
 
 复杂度解析：
 时间复杂度
 O(N*len) len为words中单词的长度。
 空间复杂度
 O(M*len) hash的空间复杂度较高；

 
 其他解法：
 有稍微慢一点，但是代码量很小的做法。
 仅需20行。
 详见[这里](https://discuss.leetcode.com/topic/17943/naive-c-solution-using-two-unordered_map-about-20-lines)
 
 
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

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> strNum;
        for (string word : words) {
            ++strNum[word];
        }
        int n = (int)s.length(), len = (int)words[0].length();
        for (int i = 0; i < len; ++i) { //枚举可能开始的位置
            int pos = i, curSize = 0;
            unordered_map<string, queue<int>> strHash;
            while (pos + len <= n) {
                string substr = s.substr(pos, len);
                if (strNum.find(substr) != strNum.end()) { // 存在子串
                    strHash[substr].push(pos);
                    ++curSize;
                    if (strHash[substr].size() > strNum[substr]) { //超过大小，在最左边元素的左边的值都不要
                        int leftPos = strHash[substr].front();
                        strHash[substr].pop();
                        --curSize;
                        for (auto iter = strHash.begin(); iter != strHash.end(); ++iter) {
                            while (!iter->second.empty() && iter->second.front() < leftPos) {
                                iter->second.pop();
                                --curSize;
                            }
                        }
                    }
                    if (curSize == words.size()) { //刚好n个
                        int ans = n;
                        for (auto iter = strHash.begin(); iter != strHash.end(); ++iter) {
                            queue<int> q = iter->second;
                            ans = min(ans, q.front());
                        }
//                        cout << "ans " << ans << endl;
                        ret.push_back(ans);
                    }
                }
                else {
                    curSize = 0;
                    while (!strHash.empty()) {
                        strHash.erase(strHash.begin());
                    }
                }
                pos += len;
            }
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
//    string str = "wordgoodgoodgoodbestword";
//    vector<string> words;
//    words.push_back(string("word"));
//    words.push_back(string("good"));
//    words.push_back(string("best"));
//    words.push_back(string("good"));
    
    string str = "a";
    vector<string> words;
    words.push_back(string("a"));
//    words.push_back(string("foo"));
//    words.push_back(string("the"));
    
    vector<int> ans = leetcode.findSubstring(str, words);
 
    
    
    return 0;
}
