//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1673/problem/B)
 **题目大意：**
 给出一个字符串，由小写字母组成；
 如果这个字符串的所有子串都满足，构成字符串的字符数相差不超过1，则称这个字符串为完美字符串，比如说：
 
 现在给出一个字符串，询问是否为完美字符串；
 
  **输入：**
 第一行，整数𝑡 表示t个样例  𝑡 (1≤𝑡≤2⋅1e4)
 每个样例一行，字符串𝑠  (1≤|𝑠|≤2⋅1e5)
  
 **输出：**
 每个样例一行，如果是完美字符串则输出YES；如果不是完美字符串则输出NO；
 
 **Examples**
 **input**
 5
 aba
 abb
 abc
 aaaaa
 abcba
 codeforces
 **output**
 YES
 NO
 YES
 YES
 NO
 
 **题目解析：**
 根据题目的要求，任意子串的字符数相差要在1以内，假设一共有k个不同字符；
 那么从字符串中任意截取k长度的字符串，必然会由不同的字符组成，否则就会出现重复字符数>1，然后没出现的字符数位0，那么就不符合题目的要求；
 并且由于可以任取，我们在[1, k]是由k个不同的字符构成，[2, k+1]也是k个不同的字符构成，由此可以推导出str[k+1] = str[1]，并由此类推，完美字符串必然是abcd abcd abc 这样的重复构成；
 这样只需要检测字符串是否满足这个特性即可。
  
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
            cin >> str;
            int sum = 0, v[26] = {0};
            for (int i = 0; i < str.length(); ++i) {
                int index = str[i] - 'a';
                if (!v[index]) {
                    v[index] = 1;
                    ++sum;
                }
            }
            bool ans = true;
            memset(v, 0, sizeof(v));
            for (int i = 0; i < sum; ++i) {
                int index = str[i] - 'a';
                if (!v[index]) {
                    v[index] = 1;
                }
                else {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                int pos = sum;
                while (pos < str.length() && ans) {
                    for (int i = pos; i < str.length() && i < (pos + sum); ++i) {
                        if (str[i] != str[i - sum]) {
                            ans = 0;
                            break;
                        }
                    }
                    pos += sum;
                }
                if (ans) {
                    cout << "YES" << endl;
                }
            }
            if (!ans) {
                cout << "NO" << endl;
            }
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
