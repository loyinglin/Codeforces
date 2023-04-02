//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1788/problem/B)
 **题目大意：**
 给出一个整数n，将整数n拆成两个整数A和B，要求满足：
 A+B=n；
 A和B的数字和最多相差1；
 
 数字和的意思就是将整数A的各个位置数字相加，比如说198就是1+9+8=18，208就是2+0+8=10；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例1行，第一行整数𝑛 (2≤𝑛≤1e9）

 
  
 **输出：**
 每个样例一行，输出A和B，题目保证结果存在；
 
 **Examples**
 **input**
 5
 1
 161
 67
 1206
 19
 **output**
 1 0
 67 94
 60 7
 1138 68
 14 5
 
 **题目解析：**
 当n是偶数的时候，A=B=n/2，必然满足要求；
 当n是奇数时，我们可以令A=n/2, B=n - n/2，这样有A和B必然满足A+B=n情况，接下来讨论AB数字和相差1的的情况：
 1、当A的个位数小于9时，A和B必然数字和只差1，比如说81和82，78和79；
 2、当A的个位数等于9时，由于B会进位，最终A和B的数字和会产生一个差值，比如说9和10，39和40，99和100；
 由此我们可以产生一个朴素的做法：令A--，B++，最终肯定能够找到符合要求的数字；
 
 但是这么做的话，会出现超时（TLE）的情况，我们来分析下复杂度。
 当数字为999和1000时，数字和相差(9+9+9) - 1 = 26的情况，那么要A的数字和-13，B的数字和+13；
 我们知道获得数字和13最快的情况是十位数4+个位数9，那么结果为A=999-49=950，B=1000+49=1049；
 如果采用枚举的复杂度，需要枚举49次；
 
 最坏的情况，数字n为199999999，A=99999999，B=100000000，A和B的数字和相差(9 * 8) - 1=71，也就是说A需要减去数字和35，B需要加上数字和36；
 最终数字A为 99999999 - 8999 = 99991000，数字和是72-35=37；
 最终数字B为100000000 + 8999 = 1000089999，数字和是1+36=37；
 枚举的复杂度是10000左右，加上每次计算数字和的复杂度 和 样例数量，最终复杂度为10000 * 10 * 10000 = 1e9，复杂度偏高；
 
 优化方式1：每次在计算A--和B++的时候，直接按照数字和一半进行操作，比如说数字和一半是37，那么A-=37，B+=37，这样效率能加快一些；因为最终数字和会逐步收敛，结果保证是正确的；
 
 优化方式2：直接按照数字和之差，从个位数开始往高位填9，直到数字和小于9，则在当前位数填下剩余数字，比如说37就得到8999，13就得到49；这样可以O(1)得到最优解。
 
 
 
 
 
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
    int digSum(int x) {
        int ret = 0;
        while (x) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            int x = n / 2, y = n - x;
            while (abs(digSum(x) - digSum(y)) > 1) {
                int dif = abs(digSum(x) - digSum(y)) / 2;
                x -= dif;
                y += dif;
            }
            cout << x << " " << y << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
