//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1922/problem/A)
 **题目大意：**
 有三个长度为n的字符串a、b、c，字符串都是小写字符；
 有一个长度为n的模版t，模版会与字符串a、b、c匹配，匹配规则如下：
 1、假如模版的字符为小写字母，则对应位置必须是相同字符才算匹配；
 2、假如模版的字符为大写字母，则对应位置则不能是相同字符才算匹配；
 比如说模板abc和字符串abc是匹配的，模板ABC和字符串def也是匹配的，模板ABC和字符串abc是不匹配的；
 
 现在已知字符串a、b、c，问是否能够构造一个模板t，要求字符串a和b是匹配的，字符串c是不匹配的。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例4行
 第一行，整数𝑛(1≤𝑛≤20)，字符串长度
 第2、3、4行，分别是字符串a、b、c；
  
 **输出：**
 每个样例第一行，有解则输出YES，无解则输出NO；
 
 **Examples**
 **input**
 4
 1
 a
 b
 c
 2
 aa
 bb
 aa
 10
 mathforces
 luckforces
 adhoccoder
 3
 acc
 abd
 abc


 **output**
 YES
 NO
 YES
 NO

 样例解释：
 样例1，直接用模板C
 样例3，可以用模板CODEforces

 **题目解析：**
 题目的意思比较绕，但是匹配规则还是比较清晰的，可以先简化题目。
 
 先考虑字符串a和b，对于某个位置的字符：
 如果a和b相同（假设都是字符x），那么模版可以字符x，也可以是字符X以外的大写字符；
 如果a和b相同（假设是字符x和字符y），那么模版必须是字符X、Y以外的大写字符；
 
 我们发现，不管字符串a和b的取值，总是可以找到满足要求的模版；
 
 那么再考虑字符串c，要使得模版至少有一个配置是不匹配的，也就是至少有一个位置，字符串c该位置的字符与前面的都不同。
 
 
 
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
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            string a, b, c;
            cin >> a >> b >> c;
            int ans = 0;
            for (int i = 0; i < n; ++i) if (a[i] != c[i] && b[i] != c[i]) ans = 1;
            cout << (ans > 0 ? "YES" : "NO") << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
