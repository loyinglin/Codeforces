//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1783/problem/A1)
 **题目大意：**
 n张桌子排成一行，现在Alice开始分配桌子：
 1、每次分配的桌子数量依次递增，从1张、2张、3张、、n张，开始分配，直到分配结束；（假如最后一次不足n张，也会分配）
 2、第1次分配Alice，然后接下来2次分给Bob，2次分给Alice，不断循环；
 
 问最终Alice和Bob各自能分配到多少张桌子；
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤200)
 每个样例2行，第一行整数𝑛 (2≤𝑛≤1e6）
 
  
 **输出：**
 每个样例一行，分别输出Alice和bob能分配到的桌子数量。
 
 **Examples**
 **input**
 5
 10
 6
 17
 8
 1000000

 **output**
 5 5
 1 5
 10 7
 3 5
 500202 499798


 
 **题目解析：**
 最简单的做法，遍历数组然后不断记住当前是第几次分配和桌子归属，O(N)可以得到Alice和Bob的桌子数量；
 这里面我们尝试用更快的方法来求解。
 按照题目每次分配桌子规则的要求，我们假设可以分配k次，则有(1+2+3+...+k)=n+z，其中z是一个补偿值，因为最终第k次可能不足，我们用z将其补足；
 我们知道前k项和是 (1+k)  * k / 2，通过n我们可以快速计算出来k的大小，以及第k次分配的真实数量；
 我们令k=sqrt(2 * n)，然后再累加k，直到(1+k)*k/2大于等于n即可；（这个时间复杂度是O(1)）
 当我们知道k之后，就可以按照要求，枚举1、2、3、、、k的归属，这样做法的时间复杂度是根号N，即是O（sqrt(N) ）；
 但是我们还想追求更快的速度：
 我们知道，Alice分得1之后，Bob和Alice会分别获得2个数字；
 这样Alice可以得到公式Alice=(0+1) + (4+5) + (8+9) + ...；
 Bob可以得到公式Bob=(2+3) + (6+7) + (10+11) + ... ；
 我们用int(k/4)可以得到最终公式的项数，剩下的不足4个数字，则可以再手动分配，这样的复杂度是O(1)，整个题目的复杂度可以降为1；
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
            int n;
            cin >> n;
            int k = sqrt(n);
            while ((1 + k) * k / 2 < n) {
                ++k;
            }
            int diffZ = (k + 1) * k / 2 - n; // 最后一个不够的数量
            
            lld ansA = 0, ansB = 0;
            int cntA = (k - 1) / 4 + 1;
            ansA = (0 + 1 + (cntA - 1) * 4 + (cntA - 1) * 4 + 1) * cntA / 2;
            int leftA = k - ((cntA - 1) * 4 + 1);
            if (leftA >= 3) ansA += cntA * 4;
            
            int cntB = (k + 1) / 4;
            ansB = (2 + 3 + (cntB - 1) * 4 + 2 + (cntB - 1) * 4 + 3) * cntB / 2;
            int leftB = k - (cntB * 4 - 1);
            if (leftB >= 3) ansB += cntB * 4 + 2;
            
            if (k % 4 == 0 || k % 4 == 1) ansA -= diffZ;
            else ansB -= diffZ;
            
            cout << ansA << " " << ansB << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
