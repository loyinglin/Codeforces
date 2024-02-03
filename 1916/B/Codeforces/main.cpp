//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1916/problem/B)
 **题目大意：**
 给出两个整数a和b，现在要找到整数x，满足条件：
 1、1≤𝑎<𝑏<𝑥，且1≤𝑥≤1e9；
 2、a和b是x的因数，且是因数（x不算）中最大的两个；
 
 比如说12 的因数有 [1,2,3,4,6]，那么a和b就是4和6；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行，整数𝑎 , 𝑏 (1≤𝑎<𝑏≤1e9)
 
  
 **输出：**
 每个样例一行，输出满足要求的x；（题目保证有解）
 
 **Examples**
 **input**
 8
 2 3
 1 2
 3 11
 1 5
 5 10
 4 6
 3 9
 250000000 500000000

 **output**
 6
 4
 33
 25
 20
 12
 27
 1000000000

 
 **题目解析：**
 先从小样例开始分析，容易知道当a=1的时候，答案是b^2；
 当a=2的时候
 [2, 3]=6
 [2, 4]=8
 [2, 5]=10
 [2, 6]无解；（12的时候，3、4因子更大）
 
 当a=3的时候
 [3, 4]=12
 [3, 5]=15
 [3, 6]无解；（12的时候，因子4更大）
 
 当a=4的时候
 [4, 5]=20
 [4, 6]=12
 [4, 7]=28
 [4, 8]=16
 [4, 9]无解；（36的时候，因子3x12=36，12更大）
 
 我们发现，有解/无解的时候，与a、b的因子有一个强关联，
 
 比如说[2, 6]无解，实际上6=2x3，那不管乘以任何数字k，都容易产生2*k、3*k这样的因子，一定比2要大；
 [4, 9]无解，也是同理4=2x2, 9=3x3，理论上的有4、9因子的最小值就是2x2x3x3=36，但是会产生很多较大因子。
 
 比如说有解的时候，大多数值都是最小公倍数。
 但是有例外是[2, 4]和[4, 8]，当他们b整除a的时候，最小公倍数是b，但是题目要求是x>b，所以x要乘以一个值k。
 下面说明k的取值关系。
 
 // 假设k=b/a，那么b=k*a, b*(b/a)=b*k=(a*k)*k
 // 假如是b*2的话，b*2=a*k*2，那么因子里面就会多出来一个2*a，此时如果一旦b/a != 2，那么必然会有一个2*a的因子 大于原来的因子a；
 // 假如是b * (b/a)的话，只会产生一个k*k的因子，a*k是等于b的，并且我们可以知道有解的条件是k*k<a

 这样题目的大体思路就有了。
 注意：最小公倍数的求法，可以用最大公约数来算。（我自己忘了，竟然尝试用因数分解去做，结果超时了）
 
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
    long gcd(lld a, lld b){
        if (b==0) return a;
        return gcd(b, a%b);
    }
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int a, b;
            cin >> a >> b;
            int n = a, m = b;
            if (m % n == 0) {
                // 表示b是a的倍数，此时只需要将m*(m / n)就行
                // 假设k=m/n，那么m=k*n, m*(m/n)=m*k=(n*k)*k
                // 假如是m*2的话，m*2=n*k*2，那么因子里面就会多出来一个2*n，此时如果一旦m/n != 2，那么必然会有一个2*n的因子 大于原来的因子n；
                // 假如是m * (m/n)的话，只会产生一个k*k的因子，n*k是等于m的，并且我们可以知道有解的条件是k*k<n
                cout << m * (m / n) << endl;
            }
            else {
                lld ans = a * 1LL * b / gcd(a, b);
                cout << ans << endl;
            }
        }
    }
    /*
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int a, b;
            cin >>a >> b;
            int n = a, m = b;
            if (a == 1) {
                cout << b * b << endl;
                continue;;
            }
            map<int, int> h1, h2;
            
            if (m % n == 0) {
                // 表示b的因数完全覆盖a，此时只需要将m*(m / n)就行
                cout << m * (m / n) << endl;
            }
            else {
                int x = sqrt(a) + 1, y = sqrt(b) + 1;
                for (int i = 2; i < x && i <= a; ++i) {
                    while (a % i == 0) {
                        h1[i]++;
                        a /= i;
                    }
                }
                if (a != 1) h1[a] = 1;
                for (int i = 2; i < y && i <= b; ++i) {
                    while (b % i == 0) {
                        h2[i]++;
                        b /= i;
                    }
                }
                if (b != 1) h2[b] = 1;
                
                
                int ans = m; // 只需要统计a比b多的因数，乘以到ans即可
                for (map<int, int>::iterator it = h1.begin(); it != h1.end(); ++it) {
                    int value = it->first, count = it->second;
                    if (h2.find(value) == h2.end() || h2[value] < count) {
                        int k = 0;
                        if (h2.find(value) == h2.end()) k = count;
                        else k = count - h2[value];
                        for (int j = 0; j < k; ++j) ans *= value;
                    }
                }
                cout << ans << endl;
            }
        }
    }
     */
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
