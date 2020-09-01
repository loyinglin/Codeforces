//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/reverse-integer/)
 **题目大意：**
 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

 示例 1:

 输入: 123
 输出: 321
  示例 2:

 输入: -123
 输出: -321
 示例 3:

 输入: 120
 输出: 21
 注意:

 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

 **题目解析：**
 将负号单独拿出来考虑，只考虑整数的翻转。
 
 因为最终结果可能超过int范围，那么可以用long long来处理。


 ```
 
 ```
 
 **注意：**
 1在位移的时候，是按int来处理的，需要改成1LL；
 
 
 
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
    int reverse(int x) {
        lld ret = 0, flag = x < 0 ? -1 : 1;
        lld tmp = abs(x), sz = 1;
        while (tmp) {
            ret = tmp % 10 + ret * 10;
            tmp /= 10;
        }
        lld intLeft = -(1LL << 31), intRight = (1LL << 31) - 1;
        if (ret < intLeft || ret > intRight) {
            ret = 0;
        }
        return (int)ret * flag;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    while (1) {
        lld t;
        cin >> t;
        cout << leetcode.reverse(t) << endl;
    }
    
    return 0;
}
