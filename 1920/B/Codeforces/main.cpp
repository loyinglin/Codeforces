//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1920/problem/B)
 **题目大意：**
 有n个正整数的数组a，现在Alice和Bob在玩游戏，Alice先操作，Bob再操作；
 Alice会移除数组中，最多k个元素；
 Bob会将数组中，最多x个元素乘以-1；
 
 每个人只行动一次，Alice想要让最终数组的元素和尽可能大，Bob想要让数组的元素和尽可能小；
 问最终的数字和为多少；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行，整数𝑛 , 𝑘 , and 𝑥  (1≤𝑛≤2⋅1e5 , 1≤𝑥,𝑘≤𝑛 )
 第二行，n个整数𝑎1,𝑎2,…,𝑎𝑛  (1≤𝑎𝑖≤1000)
  
 **输出：**
 每个样例一行，输出最终的数字和；
 
 **Examples**
 **input**
 8
 1 1 1
 1
 4 1 1
 3 1 2 4
 6 6 3
 1 4 3 2 5 6
 6 6 1
 3 7 3 3 32 15
 8 5 3
 5 5 3 3 3 2 9 9
 10 6 4
 1 8 2 9 3 3 4 5 3 200
 2 2 1
 4 3
 2 1 2
 1 3

 
 **output**
 0
 2
 0
 3
 -5
 -9
 0
 -1


 **题目解析：**
 由于题目有k和x两个变量，我们先考虑x=1个数字的情况；
 假设题目数据已经从大到小排序，数组还是a，以4、3、2、1为例；
 先考虑bob的操作（为什么是先考虑后手？因为这样思考简单）
 假设Alice没有操作，那bob一定会选择-4，也就是数组最大的元素；（如果x=2，那么就是前2个）
 
 那么Alice如果操作呢？
 移除4的好处是最终消除了-4，但是增加了-3，同时移除原来正数3，总体的代价应该是4-3-3=-2，所以Alice不操作结果更佳；
 
 由此可知道数组排序后，Alice如果移除，一定是移除前面若干个数字；Bob的负数操作，也一定是前面x个数字。
 那么只需要枚举下k=0、1、2、3、、、k的情况，对应的结果。（边界情况比较容易些错，可以直接模拟，简化过程）
  
 
 注意：
 一些特殊case
 k=2, x=2
 4+3+2+1
 -4-3+2+1=-4
 -3-2+1=-4
 -2-1=-3
 
 k=2, x=2
 6+6+3.5+1
 -6-6-+4.5=-7.5
 -3.5-1=-4.5
 
 
 
 
 
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
    lld a[N], sum[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k, x;
            cin >> n >> k >> x;
            for (int i = 0; i < n; ++i) cin >> a[i];
            sort(a, a + n, greater<int>());
            sum[0] = a[0];
            // [left, mid, right]
            // left是移除，mid是负数，right是剩下
            lld leftSum = 0, midSum = 0, rightSum = 0;
            for (int i = 0; i < x; ++i) midSum += a[i];
            for (int i = x; i < n; ++i) rightSum += a[i];
            lld ans = rightSum - midSum;
            for (int remove = 1; remove <= k; ++remove) {
                midSum -= a[remove - 1]; //移除当前这个数字
                if (remove + x <= n) {
                    // 右边还有剩余
                    midSum += a[remove + x - 1]; // midSum增加这个数字
                    rightSum -= a[remove + x - 1]; // rightSum移除这个数字
                }
                ans = max(ans, rightSum - midSum);
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
 
