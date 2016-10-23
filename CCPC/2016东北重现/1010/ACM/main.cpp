//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright &#169; 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=5924
 题目大意：
 游戏中一个人穿着suit 穿越一个充满敌人的区域；
 每秒会受到A的伤害，人有 H（血量）, V(速度），R（回复）；单位都是1，可以认为每秒先受到攻击，如果血量>=0，则可以回复，否则死亡；
 区域的长度为D；
 @胡钧
 人的初始H/V/R 都是0，现在可以increase H/V/R， 代价分为是 G1/G2/G3；（每次increase1，速度不能大于D）
 问穿越的最小代价
 
 
 
 题目解析：
 要求G1/G2/G3的数量，假设是x/y/z。
 枚举y，算出通过时间T=float(D/V)，T'=round(D/V)为回血次数；
 根据题目有，x>=A 而且 x - T A + T’ z >= 0，这里我们可以做一次贪心，假设最后的结果为x - T A + T’ z = 0，推出 z表达式；
 把z的表达式带入xG1 + yG2 + z*G3，求出关于x的一次函数。
 然后根据x的系数的正反，我们可以直接求出x的最优解（一次函数的最优解要么最左，要么最右），然后根据z的表达式求出z。
 
 
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
const int N = 33, M = 33;



int main(int argc, const char * argv[]) {
    // insert code here...
    lld t;
    cin >> t;
    for (lld k = 1; k <= t; ++k) {
        lld ans = 0x7fffffff7fffffffll;
        lld bug[3];
        lld d, a, g1, g2, g3;
        cin >> d >> a >> g1 >> g2 >> g3;
        
        for (lld v = 1; v <= d; ++v) {
            lld x, y = v, z;
            lld rTime = d / v; // 能回复的次数
            if (rTime * v == d) {
                --rTime;
            }
            lld lose = round(1.0 * d * a / v); // 总共被攻击的血量
            if (lose * v < d * a) {
                ++lose;
            }

            if (g1 * rTime >= g3) {
                x = a;
            }
            else {
                x = lose;
            }
            if (rTime == 0) {
                z = 0;
            }
            else {
                z = (lose - x) / rTime;
                if (z * rTime < lose - x) {
                    ++z;
                }
            }
            if (x * g1 + y * g2 + z * g3 < ans) {
                bug[0] = x, bug[1] = y, bug[2] = z;
            }
            ans = min(ans, x * g1 + y * g2 + z * g3);
            ans = ans;
        }
        printf("Case #%lld: %lld\n", k, ans);
//        cout << bug[0] << " " << bug[1] << " " << bug[2] << endl;
    
    }
    
    
    return 0;
}
