//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1836/problem/C)
 **题目大意：**
 有3个正整数a、b、c，并且满足a+b=c；
 现在已知a、b、c三个整数的位数，用十进制表示分别为A、B、C；
 想知道所有满足a+b=c的字符串中，按照字典序，第k个字符串是什么。
 以 𝐴=1 , 𝐵=1 , 𝐶=2 为例
 第1个字符串是，1+9=10
 第2个字符串是，2+8=10
 第3个字符串是，2+9=11
 ...
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例一行，整数𝐴 , 𝐵 , 𝐶 , 𝑘 (1≤𝐴,𝐵,𝐶≤6 , 1≤𝑘≤1e12 ).
  
 
 **输出：**
 每个样例一行，如果存在，得输出第k个组合；
 如果不存在，则输出-1；
 
 **Examples**
 **input**
 7
 1 1 1 9
 2 2 3 1
 2 2 1 1
 1 5 6 42
 1 6 6 10000000
 5 5 6 3031568815
 6 6 6 1000000000000


 **output**
 2 + 1 = 3
 10 + 90 = 100
 -1
 9 + 99996 = 100005
 -1
 78506 + 28543 = 107049
 -1




 **题目解析：**
 首先，我们知道数字c长度不会比数字a和数字b短，因为两个正整数相加，位数不会变成少；
 其次，两个正整数相加，位数最多变长1位，因为进位不可能连续变长2位，比如说99 + 99=199，2个两位数相加，数字和最多是三位；
 
 剩下所有的数字，总能找出A+B=C的组合。
 由于要按照字典序，那么枚举A优先级最高，其次是枚举B，最后C由A+B决定，不用枚举（但要满足位数限制）；
 所以A首先从pow(10, A-1)开始枚举，也就是A=2则从10开始枚举，A=3则从100开始枚举；
 数字B的枚举同样有个区间[minB, maxB]，minB=pow(10, B-1)，maxB=pow(10, B) - 1；
 数字C的结果区间同样是[minC, maxC]；
 如果想要满足A+B=C，那么A+maxB应该要大于等于minC，并且A+minB应该要小于等于maxC；
 分析到这里，就可以很容易知道，当固定A之后，B的取值区间应该就是minC-A到maxC-A。
 
 整个算法要枚举A的数值，每次枚举复杂度O(1)，整个算法复杂度O(A)；
 
 
 
 
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
 
class Solution {
    typedef long long lld;
     
    static const lld N = 201010;
    
public:
    void solve() {
        lld t;
        cin >> t;
        while (t--) {
            lld a,b,c,k;
            cin >> a >> b >> c >> k;
            if (c < a || c < b || c > (max(a, b) + 1)) {
                cout << -1 << endl;
                continue;;
            }
            
            lld find = 0;
            for (lld i = pow(10, a - 1); i < pow(10, a); ++i) {
                // i + j = l
                lld minJ = pow(10, b - 1);
                lld maxJ = pow(10, b) - 1;
                lld minL = pow(10, c - 1);
                lld maxL = pow(10, c) - 1;
                if (i + maxJ >= minL && i + minJ <= maxL) {
                    lld startJ = max(minJ, minL - i);
                    lld endJ = min(maxJ, maxL - i);
                    lld sum = endJ - startJ + 1;
                    if (sum < k) k -= sum;
                    else {
                        find = 1;
                        printf("%lld + %lld = %lld\n", i, startJ + k - 1, i + startJ + k - 1);
                        break;
                    }
                }
            }
            if (!find) cout << -1 << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
