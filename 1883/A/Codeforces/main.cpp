//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1883/problem/A)
 **题目大意：**
 有这样的一个字符串
 https://espresso.codeforces.com/8764a5e2e2f2eda05775f6cbf1fbc53d7699cad5.png
 现在光标停留在最左边的数字1处，我们可以进行以下的操作：
 1、将当前光标所在位置的数字输出；
 2、移动光标到相邻的数字，比如说从1移动到2，从2移动到3；（1的左边不能移动，0的右边不能移动）
 
 现在想知道，输出特定的4个字符，最少需要几次操作。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行，4个整数；
  
 **输出：**
 每个样例一行，输出最少的操作次数。
 
 **Examples**
 **input**
 10
 1111
 1236
 1010
 1920
 9273
 0000
 7492
 8543
 0294
 8361

 **output**
 4
 9
 31
 27
 28
 13
 25
 16
 33
 24


 **题目解析：**
 输出数字的最小操作方法:
 1、将光标移到指定位置；
 2、展示当前数字；
 
 题目的意思非常简单，但是如果直接通过if去实现，在计算0的位置时，会比较繁琐；（因为数字0在最右边，破坏了字符和数字的对应关系）
 这里有个实现的小技巧，我们将数字0看成10，那么整个数字序列就是从小到大。
 这样在计算操作1的时候，就能通过数字相减直接得到结果。
 
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
            char s[10];
            cin >> s;
            int cur = 1, ans = 4;
            for (int i = 0; i < 4; ++i) {
                int idx = s[i] - '0';
                if (idx == 0) idx += 10;
                ans += abs(cur - idx);
                cur = idx;
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
 
