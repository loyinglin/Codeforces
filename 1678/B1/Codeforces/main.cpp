//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1678/problem/B1)
 **题目大意：**
 给出一个偶数长度的字符串，由0和1组成；
 将字符串中相同字符组成的子串切分出来，比如说11001111可以切成 11、00 和 1111；
 如果切出来的子串长度都是偶数，这个字符串就是good；
 
 现在可以修改字符串中的字符，每次可以将某个位置的字符从0变成1，或者从1变成0；
 问最少修改几次，才能将字符串修改成good；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤10000)
 每个样例俩行，第一行 整数 𝑛表示字符串长度 (2≤𝑛≤1e5)
 第二行字符串s；
  
 **输出：**
 每个样例一行，最少的操作次数；
 
 
 **Examples**
 **input**
 5
 10
 1110011000
 8
 11001111
 2
 00
 2
 11
 6
 100110
 **output**
 3
 0
 0
 0
 3
 
 **题目解析：**
 good字符串，就是由多个长度为偶数的字符串组成；
 那么对于字符串中的第1、2个元素，只要保证两个元素是相同，那么不管后面的3、4号元素是什么字符，都不会对good字符串的定义产生影响：
 因为偶数+偶数=偶数；
 
 于是题目简化为，将字符串两两切分，要保证所有子串的字符相同；
 那么01和10需要修改1次，00和11不需要修改；
 
  
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
#include<algorithm>
using namespace std;

typedef long long lld;

class Solution {
    static const int N = 201010;
    string str;

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cin >> str;
            int ans = 0;
            for (int i = 0; i < n; i += 2) {
                if (str[i] != str[i + 1]) {
                    ++ans;
                }
            }
            cout << ans << endl;
        }
    }
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 */
