//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1195/problem/b)
 **题目大意：**
 小明有个糖果盒子，起始的时候是空的。
 小明会进行n次操作，每次可以选择：
 1、吃掉盒子里的一个糖果；（如果里面有糖果的话）
 2、放进去x个糖果，之后x=x+1；
 
 最后盒子里会剩下k个糖果；
 
 例如下面的9个操作：
 put 1 candy,
 put 2 candies,
 eat a candy,
 eat a candy,
 put 3 candies,
 eat a candy,
 put 4 candies,
 eat a candy,
 put 5 candies.
 
 最终会剩下11个糖果。（1+2−1−1+3−1+4−1+5=11）
 
 现在给出操作次数n，还有最终剩下的k个糖果，问小明会吃掉几个糖果。
 
 输入：
 第一行，𝑛 and 𝑘 (1≤𝑛≤10^9; 0≤𝑘≤10^9)
 
 输出：
 小明吃掉的糖果数；（题目保证数据是有解的）
 
 Examples
 input
 5 3
 1
 3
 1
 1
 2
 output
 4
 
 **题目解析：**
 由题目知道，吃掉的糖果是1、2、3、4、、、，那么假设吃掉的是1~t的糖果。
 那么剩下的(n-t)次糖果，肯定是吃糖果的操作。
 如果题目有解，那么就有：
 总共的放进去糖果数 = 吃糖果数 + 剩下糖果数；
 即是：(1+t)*t/2 = (n-t) + k；
 
 可以从1开始遍历t，最多重复sqrt(10^9)次就会有解，复杂度可以接受。
 
 
 
 
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


int main(int argc, const char * argv[]) {
    // insert code here...
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < 100000; ++i) {
        lld sum = (1ll + i) * i / 2;
        if (sum == (k + (n - i))) {
            cout << sum - k << endl;
            return 0;
        }
    }
    
    return 0;
}
