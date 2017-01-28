//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/number-of-digit-one/
 题目大意：
 给出一个数字n，求出在区间[1, n]中所有数字中，1的数量。
 
 For example:
 Given n = 13,
 Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 
 
 题目解析：
 数位dp的思想。
 先预处理出1, 10, 100, 1000 ... 这些数字以下的1的数量；
 再从左到右遍历n，求出1的数量。
 
 但是，
 这个题有更简单的解法。因为数字n比较小，考虑直接通过数学方式来解决。
 例如数字315，可以分割成个十百三个位数上1的数量来分别统计；
 个位数：315个1;
 十位数：31个10；
 百位数：3个100；
 每个位数上可能有0、1、大于1的情况，(x+8)/10可以过滤出大于1的情况；
 
 在特别考虑每个位数为1的情况，比如315中的十位数；
 上面的统计方式还漏掉了310~315的三种情况，这种情况可以用x%i + 1来过滤出来。
 
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



class Solution {
public:
    int countDigitOne(int n) {
        int ret = 0;
        for (long long i = 1; i <= n; i *= 10) {
            ret += (n / i + 8) / 10 * i; // 对应位数上1的数量；
            if (n / i % 10 == 1) {
                ret += n % i + 1;
            }
        }
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
