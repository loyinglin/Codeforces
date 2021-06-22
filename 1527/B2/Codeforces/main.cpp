//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1527/problem/B2)
 **题目大意：**
 
 
 
 
 **输入：**
 第一行是整数t，表示有t个样例(1≤𝑡≤1e4).
 每个样例一行，第一行是整数n(1≤𝑛≤1e9).
 **输出：**
 每个样例一行，输出1到n的整数中，有多少个由相同数字组成的数。

 
 **Examples**
 **input**
 6
 1
 2
 3
 4
 5
 100

 **output**
 1
 2
 3
 4
 5
 18

 
 
 **题目解析：**
 这里有一个简单策略：对于一个回文串（最中间的数字不为0），那么可以采取A填哪个位置，B就填回文串对应的位置；
 直到剩下2个0的时候，A填任何一个位置，B选择reverse；此时A只能再填一次0，B必胜；
 先手者，除非回文串中间是0（当有空格的部分大于1时），否则必输。
 
 注意这个题目中，先手者是可以reverse操作的，这是一个比较大的优势；
 如果起手是回文串，那么可以用上面的逻辑。（这里有一个很重要的点，先后手最大的差距是2，就是1001这种情况，因为都会采用最佳策略）
 
 为了方便思考，我们引入函数f，f(str)表示回文串str，先手会赢多少；
 f(1001)=-2;
 f(101)=-1; （仅有一个0的情况下）
 f(10001)=1;
 注意，除了没有0，平局的情况是不存在的。
 我们知道回文串的胜负，有两种结果：-2/-1和1。

 假如字符串没有任何位置可以操作1次，之后变成回文串，那么先手者Alice可以reverse，等待后手者操作后，依旧可以执行reverse；（这种策略可以占领1的优势，因为后手在一直补齐）
 直到存在一个操作，可以对某个位置k进行操作，并且操作之后字符串变成回文串strK；
 1、假如f(strK)=1，则Alice可以继续执行reverse操作，因为bob如果将字符串操作为strK，对Alice是有收益的；
 2、假如f(strK)=-1，则Alice继续执行reverse会平局，因为bob花费1的代价让让alice面临-1的情况；（是否平局，取决于在达到下一步操作就能生成回文串的操作步数）
 2、假如f(strK)=-2，则Alice必胜，Alice花费1的代价可以让对手面临-2的情况；
 
 这里可以推出来，先手者必然不会输。（注意，这个前提是有2个0以上）
 
 所以问题的关键是在于上面的情况2，怎么快速找到平局的case。
 
 我们知道这个追赶的步数，应该等于字符串中1和0按照回文串要求不对应的数量。
 比如说10011=>其中的str[1]和str[3]不一样，需要追赶；
 那么统计一下，这个数量，即可得到追赶的步数step。

 假如step=1，则刚好和构成回文串strNew之后，f(strNew)的-1收益持平，此时会平局。
 
 
 
 
 **思考🤔：**
 
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
    static const int N = 100010;
public:
    int n, m;
    string pubStr;
    
    bool isPalindrome(string &str) {
        bool isPalindrome = true;
        for (int i = 0; i < n / 2; ++i) {
            isPalindrome = isPalindrome && (str[i] == str[n - i - 1]);
        }
        return isPalindrome;
    }
    
    int getCount(string &str) {
        int ret = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (str[i] == '0') {
                ++cnt;
            }
        }
        if (cnt == 0) {
            ret = cnt;
        }
        else if (cnt == 1) {
            ret= cnt;
        }
        else if (cnt % 2) {
            ret = (str[(n - 1) / 2] == '0' ? -2 : 1);
        }
        else {
            ret = -2;
        }
        return ret;
    }
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            cin >> pubStr;
            
            int cnt = 0, step = 0;
            for (int i = 0; i < n; ++i) {
                if (pubStr[i] == '0') {
                    ++cnt;
                }
                if (i < n / 2 && pubStr[i] != pubStr[n - i - 1]) {
                    ++step;
                }
            }
            if (cnt == 0) {
                cout << "DRAW" << endl;
            }
            else if (cnt == 1) {
                if (isPalindrome(pubStr)) {
                    cout << "BOB" << endl;
                }
                else {
                    cout << "ALICE" << endl;
                }
            }
            else {
                if (isPalindrome(pubStr)) {
                    if (cnt % 2) {
                        cout << (pubStr[(n - 1) / 2] == '0' ? "ALICE" : "BOB") << endl;
                    }
                    else {
                        cout << "BOB" << endl;
                    }
                }
                else {
                    if (step == 1 && cnt == 2) {
                        cout << "DRAW" << endl;
                    }
                    else {
                        cout << "ALICE" << endl;
                    }
                }
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
 
 Example
 inputCopy
 3
 3
 110
 2
 00
 4
 1010
 outputCopy
 ALICE
 BOB
 ALICE
 
 
 5
 10011
 
 5
 00010
 
 
 */
