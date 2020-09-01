//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/group-anagrams/)
 **题目大意：**
 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

 示例:

 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 输出:
 [
   ["ate","eat","tea"],
   ["nat","tan"],
   ["bat"]
 ]
 说明：

 所有输入均为小写字母。
 不考虑答案输出的顺序。


 **题目解析：**
 字母异位词相当于每个字符出现的次数一致，那么字符串中位置信息是无用的，可以统计每个字符串中字母的数量，每个字符可以转为长度为26的数组；
 接下来用排序的方式，将所有的数组进行排序，这样数组一样的就会变得相邻，最后遍历数组即可。

 ```
 
 ```
 
 **思考：**
 hash的做法，将每个字符串排序，从小到大，然后用hash的方法将字符串映射为整数；（unorder_map + string）
 
 
 
 
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

struct Node {
    int cnt[26], index;
    Node(){}
    bool operator < (const Node tmp) const {
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != tmp.cnt[i]) {
                return cnt[i] < tmp.cnt[i];
            }
        }
        return false;
    }
    bool isEqual(Node tmp) {
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != tmp.cnt[i]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        Node dot[n];
        for (int i = 0; i < n; ++i) {
            memset(dot[i].cnt, 0, sizeof(dot[i].cnt));
            for (int j = 0; j < strs[i].length(); ++j) {
                dot[i].cnt[strs[i][j] - 'a']++;
            }
            dot[i].index = i;
        }
        sort(dot, dot + n);
        vector<vector<string>> ret;
        vector<string> tmp;
        tmp.push_back(strs[dot[0].index]);
        for (int i = 1; i < n; ++i) {
            if (!dot[i].isEqual(dot[i - 1])) {
                ret.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(strs[dot[i].index]);
        }
        ret.push_back(tmp);
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
