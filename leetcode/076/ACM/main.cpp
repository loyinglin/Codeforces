//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/minimum-window-substring/
 题目大意：
 给出两个字符串S和T，在S中寻找一个子串s，要求：
 1、s包括T出现过的所有字符；
 2、s的字符串长度最小；
 
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 
 如果没有，返回空串；
 题目保证只有一个答案。
 
 
 题目解析：
 题目要求s出现T中所有的字符，但是没有顺序要求，那么对于一段字符串：
 字符串的位置是无意义的。
 假设已经选择一段字符串str，再选新的一个字符c；
 如果字符c没有出现过，那么c应该并入str中；
 如果字符c已经出现过，那么新出现的c比原来的c更优；
 在匹配过程中，当出现所有T的字符之后，一直保存最小的字符串长度。
 
 
 这里可以用反证法来证明。
 假设按照这一规则，选出包括所有T字符的子串s=(l, r)，最右边的字符是c;
 如果在(l, r)的位置k,k∈(l, r)，存在字符c，并且(l, k)出现过所有T的字符；
 那么按照之前的过程(l, k)会是最小值。
 
 
 复杂度解析：
 时间复杂度
 O(N) N是字符S的长度；
 空间复杂度
 O(M) M是T的长度；
 代码量
 
 
 收获一枚WA，没想到题目还有这种数据：
 Input:
 "a"
 "aa"
 Output:
 "a"
 Expected:
 ""
 
 改改即可。记录下每个字符的数量。
 
 
 其他解法：
 没发现。
 
 
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
const int N = 200;
class Solution {
    int flag[N];
public:
    string minWindow(string s, string t) {
        memset(flag, 0, sizeof(flag));
        vector<int> words;
        queue<int> pos[N];
        for (int i = 0; i < t.size(); ++i) {
            if (!flag[t[i]]) {
                words.push_back(t[i]);
            }
            ++flag[t[i]];
        }
        int x = 0, y = 0, minLen = s.length() + 1;
        for (int i = 0; i < s.length(); ++i) {
            if (flag[s[i]]) { // in t
                pos[s[i]].push(i);
                if (pos[s[i]].size() > flag[s[i]]) { // full
                    pos[s[i]].pop();
                }
                
                int ok = 1, left = s.length() + 1, right = 0;
                for (int j = 0; j < words.size(); ++j) {
                    if (pos[words[j]].size() < flag[words[j]]) {
                        ok = 0;
                    }
                    else {
                        left = min(left, pos[words[j]].front());
                        right = max(right, pos[words[j]].back());
                    }
                }
                if (ok && right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    x = left;
                    y = right + 1;
                }
            }
        }
        return string(s.begin() + x, s.begin() + y);
    }
}leetcode;


int main(int argc, const char * argv[]) {
    string a="a";
    string b="a";
    cout << leetcode.minWindow(a, b) << endl;
    
    return 0;
}
