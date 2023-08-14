//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1834/problem/C)
 **题目大意：**
 有两个字符串S和T，长度均为n；
 现在Alice和Bob两个人在玩有一个游戏，两个人轮流行动，Alice先手。
 Alice的操作，是选择字符串S或者字符串T中的某一个元素，将其修改为任意字符；
 Bob的操作，是选择字符串S或者字符串T，翻转该字符串；
 
 当字符串完全相同时，游戏结束。
 
 Alice的目标是尽可能少行动次数，Bob的目标是尽可能多行动次数；
 假设Alice和Bob的行动都是最优决策。
 现在想要知道，当Alice和Bob总共需要行动多少步。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例3行，
 第一行，整数𝑛(1≤𝑛≤1e5)
 第二行，字符串S；
 第三行，字符串T；

 
 
 **输出：**
 每个样例一行，输出最终行动步数。
 
 **Examples**
 **input**
 7
 5
 abcde
 abxde
 5
 hello
 olleo
 2
 ab
 cd
 7
 aaaaaaa
 abbbbba
 1
 q
 q
 6
 yoyoyo
 oyoyoy
 8
 abcdefgh
 hguedfbh

 **output**
 1
 2
 3
 9
 0
 2
 6



 **题目解析：**
 先分析Alice和Bob的策略。
 先从Alice的视角来看，最终游戏必然会停止，因为Alice可以把字符串S、T修改为完全相同的字符组成，这样使得Bob的翻转操作无效；
 为了尽可能减少步数，必须利用Bob的翻转操作，例如说当Bob遇到abc和cba时，由于Bob必须选择一个字符串翻转，最终游戏必然会停止。
 我们以字符串S为参考下，最终结果要么是字符串S、要么是字符串revertS；
 计算得到字符串T和字符串S、字符串T和字符串revertS的差异部分，最终的游戏过程就是Alice修改差异部分字符，然后Bob不断翻转，最终字符串以S或者revertS结束。
 （注意，这里为了简化分析，利用了两个隐性条件，Alice修改S和修改T是等价的，Bob翻转字符串S和字符串T是等价的）
 
 不同的是，当最终以字符串S结束时，翻转次数为偶数；
 当最终以字符串revertS结束时，翻转次数为奇数。
 
 
 3333
 3
 abc
 ade
 5
 abcde
 adcbe
 5
 abcde
 fbcdf
 3
 bac
 eaf
 
 
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
    char a[N], b[N];
    
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cin >> a >> b;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i]) ++cnt1;
                if (a[n - i - 1] != b[i]) ++cnt2;
            }
            
            if (cnt1 == 0) cout << 0 << endl;
            else {
                /*
                 1次，翻转成本0 0
                 2次，翻转成本2 0 21 0 12
                 3次，翻转成本2 0 21 0 12 0
                 4次，翻转成本4 0 21 0 12 0 21 0 12
                 5次，翻转成本4 0 21 0 12 0 21 0 12 0
                 */
                int ans1 = cnt1 + cnt1 / 2 * 2; //翻转成本为偶数

                /*
                 1次，翻转成本1 0 21
                 2次，翻转成本1 0 21 0
                 3次，翻转成本3 0 21 0 12 0 21
                 4次，翻转成本3 0 21 0 12 0 21 0
                 5次，翻转成本5 0 21 0 12 0 21 0 12 0 21
                 */
                cnt2 = max(1, cnt2);
                int ans2 = cnt2 + (cnt2 - 1) / 2 * 2 + 1;
                cout << min(ans1, ans2) << endl;
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
 
