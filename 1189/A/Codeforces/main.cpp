//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1189/problem/A)
 **题目大意：**
 有一个由数字0、1组成的字符串，长度为n；
 现在需要将其切分成若干段，要求每一段0和1的数量是不相同的。
 比如说1, 101, 0000是不一样的，01, 1001, 111000是相同的。
 
 问最少需要分成几段？
 
 输入：
 第一行，𝑛 (1≤𝑛≤100)
 第二行，数字0、1组成的字符串；
 
 输出：
 第一行，数字m，表示分成m段。
 接下来m行，每行包括一个切分出来的字符；（按照原字符串从左到右的顺序输出）
 
 Examples
 input
 1
 1
 output
 1
 1
 input
 2
 10
 output
 2
 1 0
 
 **题目解析：**
 
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    char str[1111];
    cin >> n;
    cin >> str;
    int x = 0, y = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == '0') {
            ++x;
        }
        else {
            ++y;
        }
    }
    
    if (x != y) {
        cout << 1 << endl;
        cout << str << endl;
    }
    else {
        cout << 2 << endl;
        cout << str[0] << " " << str + 1 << endl;
    }
    return 0;
}
