//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/add-binary/)
 **题目大意：**
 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

  

 示例 1：

 输入:a = "11", b = "1"
 输出："100"
 示例 2：

 输入：a = "1010", b = "1011"
 输出："10101"

 

 **题目解析：**
 大数加法的简化版本。
 注意事项：
 1、逆序，从右到左操作；
 2、不等长处理，长度上 a>b、a=b、a<b三种情况的考虑；
 3、字符和整数转化；
 4、进位考虑，累加过程，以及最后进位处理；
 5、输出再重新逆序；

 
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
public:
    string addBinary(string a, string b) {
        string ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int x = 0, y = 0, add = 0;
        while (x < a.length() || y < b.length()) {
            int temp = add;
            if (x < a.length()) {
                temp += a[x] - '0';
            }
            if (y < b.length()) {
                temp += b[y] - '0';
            }
            ret.push_back('0' + temp % 2);
            add = temp / 2;
            ++x, ++y;
        }
        if (add) {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
}leetcode;


int main(int argc, const char * argv[]) {
    cout << leetcode.addBinary("1010", "1011") << endl;
    
    
    return 0;
}
