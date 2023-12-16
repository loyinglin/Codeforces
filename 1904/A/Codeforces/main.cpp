//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1904/problem/A)
 **题目大意：**
 在一个国际象棋的棋盘上，有一个棋子，它的移动规则类似马，能够朝着横or竖方向移动距离a，然后朝竖or横（和之前不同）移动距离b；
 比如说马的移动规则就是a=1，b=2；
 
 现在棋盘上还有另外两个棋子K和Q，问棋盘上有多少个特殊位置，在该位置上面可以移动棋子K所在位置，也可以移动到棋子Q所在位置。
 
 如下，该图上面的马，可以移动到另外两个棋子的位置。
 ![如图](https://espresso.codeforces.com/1b32f6a17c0698916369710ca4b973aca05a26af.png)
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例3行
 第1行整数 𝑎  and 𝑏  (1≤𝑎,𝑏≤1e8)
 第2行整数 𝑥𝐾 and 𝑦𝐾 (0≤𝑥𝐾,𝑦𝐾≤1e8 )
 第3行整数 𝑥𝑄 and 𝑦𝑄 (0≤𝑥𝑄,𝑦𝑄≤1e8 )
  
 **输出：**
 每个样例一行，输出满足要求的位置数量。
 
 
 **Examples**
 **input**
 4
 2 1
 0 0
 3 3
 1 1
 3 1
 1 3
 4 4
 0 0
 8 0
 4 2
 1 4
 3 4



 **output**
 2
 1
 2
 0


 **题目解析：**
 能够攻击到k的位置，应该有左右上下8个角落；
 同理，能够攻击到q的位置，也同样有8个角落；
 接下来枚举前面的位置，看是否有位置与后面的角落重合，即可。
 
 tips：
 1、为了方便枚举，可以把4个方向用dir[4][2]的数组来枚举；
 2、a和b不相同的时候，要考虑a和b互换的情况；
 
 
 
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
    int dir[4][2] = {1,1,  -1,1,  1,-1,   -1,-1};
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int val[2], x1, y1, x2, y2;
            cin >> val[0] >> val[1];
            cin >> x1 >> y1;
            cin >> x2 >> y2;
            int ans = 0;
            for (int i = 0; i < 8; ++i) {
                int a = val[i % 2];
                int b = val[(i + 1) % 2];
                if (a == b && i % 2) continue;;
                int idx1 = dir[i/2][0] * a + x1;
                int idy1 = dir[i/2][1] * b + y1;
                for (int j = 0; j < 8; ++j) {
                    int a2 = val[j % 2];
                    int b2 = val[(j + 1) % 2];
                    if (a2 == b2 && j % 2) continue;;
                    if ((idx1 + dir[j/2][0] * a2 == x2) && (idy1 + dir[j/2][1] * b2 == y2)) {
                        ++ans;
                        break;
                    }
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
 
