//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/count-and-say)
 **题目大意：**
 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 1 被读作  "one 1"  ("一个一") , 即 11。
 11 被读作 "two 1s" ("两个一"）, 即 21。
 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

 注意：整数序列中的每一项将表示为一个字符串。

  

 示例 1:

 输入: 1
 输出: "1"
 解释：这是一个基本样例。
 示例 2:

 输入: 4
 输出: "1211"
 解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 = 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。

 **题目解析：**
 按照题目的要求，统计连续的数字数量，然后用sprintf转成字符串，再记录下来。


 ```
 
 ```
 
 **思考：**
 
 
 
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
    vector<string> ans;
public:
    string countAndSay(int n) {
        if (!ans.size()) {
            string s = "1";
            ans.push_back(s);
            for (int i = 1; i < 30; ++i) {
                int cnt = 1;
                string strNew;
                for (int j = 1; j < s.length(); ++j) {
                    if (s[j] == s[j - 1]) {
                        ++cnt;
                    }
                    else {
                        char tmp[11];
                        sprintf(tmp, "%d%c", cnt, s[j - 1]);
                        cnt = 1;
                        strNew.append(tmp, strlen(tmp));
                    }
                }
                char tmp[11];
                sprintf(tmp, "%d%c", cnt, s.back());
                strNew.append(tmp, strlen(tmp));
                s = strNew;
                ans.push_back(s);
            }
        }
        return ans[n-1];
    }
}lt;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
