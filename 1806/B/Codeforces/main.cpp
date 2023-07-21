//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1806/problem/b)
 **题目大意：**
 MEX是整数数组中未出现的最小非负整数，比如说：
 [2,2,1]的MEX是0；
 [0,1,2]的MEX是3；
 现在给出整数数组a，可以任意调整数组a的元素顺序，然后再用数组a生成新的数组 [𝑎1+𝑎2,𝑎2+𝑎3,…,𝑎𝑛−1+𝑎𝑛]；
 问，新生成数组的MEX最小是多少？
 
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行；
 第一行整数 𝑛 (2≤𝑛≤2⋅1e5).
 第二行n个整数𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤2⋅1e5).
 
  
 **输出：**
 每个样例一行，输出最小的MEX；
 
 **Examples**
 **input**
 3
 2
 0 0
 3
 0 0 1
 8
 1 0 0 0 2 0 3 0


 **output**
 1
 0
 1


 
 **题目解析：**
 假设只有一个元素，那么MEX就取决于整数是否为0；
 当有2个元素时，如果都为0，那么结果为1；如果都不为0，那么结果是0；如果存在一个非零整数，那么取决于非零整数是1还是2；
 此时我们发现，元素都可以抽象为0、1、非1正整数；
 
 整数0的个数，假设有x个；
 x = n，答案为1；
 x > (n+1)/2，0过多，此时一定会有0，那么可以把所有非零整数放在起始位置，只要整数存在任意数字非1，答案为1；否则将整数用0间隔开，答案为2 ；（01010，010100，000011）
 x <= (n+1)/2，0数量不足，此时必然可以用非零整数去间隔开0，答案为0；
 
 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            int zeroCnt = 0, notOneCnt = 0;
            for (int i = 0; i < n; ++i) {
                int tmp;
                cin >> tmp;
                if (tmp == 0) ++zeroCnt;
                else if (tmp > 1) ++notOneCnt;
            }
            int ans = 0;
            if (zeroCnt == n) ans = 1;
            else if (zeroCnt <= (n + 1) / 2) ans = 0;
            else {
                ans = 1 + (notOneCnt == 0);
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
 
