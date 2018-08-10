//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/746/problem/A)
 **题目大意：**
 
 给出一个字符串str，包含数字、中括号和字母；
 3[a]=aaa，2[bc]=bcbc；
 现在希望给出一个原串str，求中括号展开后的字符串；（数字为非零整数，且给出的字符串不存在3[], a[b]这样的非法串）
 
 s = "3[a]2[bc]", return "aaabcbc".
 s = "3[a2[c]]", return "accaccacc".
 s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

 
 **题目解析：**
 两种方法：递归、栈实现；
 这里选择代码较为清晰的递归。
 首先，找到数字x；
 接着，找出数字x后面的中括号内容subStr，重复x次;
 返回字符串；
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];


string transfrom(string str) {
    string ret;
    int n = (int)str.length();
    int index = 0;
    while (index < n) {
        if (str[index] >= '1' && str[index] <= '9') { // number
            int sum = str[index] - '0';
            ++index;
            while (str[index] >= '0' && str[index] <= '9') {
                sum = sum * 10 + str[index] - '0';
                ++index;
            }
            // str[index] = '['
            int match = 1;
            ++index;
            int left = index, right = 0;
            
            while (match) {
                if (str[index] == '[') {
                    ++match;
                }
                else if (str[index] == ']') {
                    --match;
                }
                ++index;
            }
            // str[index] = ']'
            right = index - 1;
            string subStr = transfrom(string(str.begin() + left, str.begin() + right));
            for (int i = 0; i < sum; ++i) {
                ret.append(subStr);
            }
        }
        else {
            ret.append(string(str.begin() + index, str.begin() + index + 1));
            ++index;
        }
    }
    return ret;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    string str;
    cin >> str;
    cout << transfrom(str) << endl;
    
    return 0;
}
