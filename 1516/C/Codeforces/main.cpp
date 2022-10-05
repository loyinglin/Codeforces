//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1516/problem/C)
 **题目大意：**
 有n个整数的数组a，现在将数组分成两个集合，如果两个集合内的整数之和相等，则是不美好的；
 现在希望去掉若干个数字，要求n个数字无法拆成两个集合，这两个集合的和是相等的。
  
 **输入：**
 第一行是整数𝑛 (2≤𝑛≤100)
 第二行是n个整数𝑎1 , 𝑎2, …, 𝑎𝑛 (1≤𝑎𝑖≤2000)
 **输出：**
第一行是需要移除的整数个数m，第二行是m个需要移除整数的下标；
 
 **Examples**
 **input**
 4
 6 3 9 12
 **output**
 1
 2
 
 **题目解析：**
 假设n个数字分成集合a[x]和b[y]，并且sum(a) = sum(b)，那么sum(a)=sum(n)/2。
 最开始的想法是，如果sum(a)=sum(b)，那么只要去掉一个集合a或者b中的奇数，那么必然会出现sum(a)!=sum(b)； （因为奇数和偶数必定不相同）
 问题就变成题目中是否存在一个解，使得sum(a)==sum(b) ：
 如果有存在，则去掉n个数字中的奇数；
 如果不存在，则不需要去掉任何数字；
 
 注意，这里很容易产生误解：觉得去掉最小/最大的整数也是可行的。
 例子： 4 4 6 6 8 8
 去掉4之后可以拆分为 4 + 6 + 6 = 8 + 8
 去掉8之后可以拆分为 4 + 4 + 6 = 6 + 8
 **直接找一个数字最小、最大都无法直接确定。**

 我们回到最初判断，我们会首先认为，如果sum(n)是奇数，则无解；
 那么假如数组中存在一个奇数，我们只要去掉这个奇数即可。
 那如果数组中一个奇数都没有呢？
 假如数组都是偶数，假设最终分出来的两个集合a和b，我们对两边的集合除以2，不影响sum(a)=sum(b)；
 如果还是没有奇数，我们可以继续这样操作。容易知道，这样是一定可以找到一个奇数。
 根据上面的思路，我们把每一个数字看成二进制，最右边1出现之后，就是奇数了。那么即是寻找n个数字中，最右边1最早出现的位置。
 
 如果要判断n个数字中，能不能凑出来sum(n)/2的数字，这个不就是背包嘛。
 
 
 
 **思考🤔：**
 
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
    static const int N = 101, M = 101*2000;
public:
    int n, m;
    int a[N], dp[M], ans[N];
    
    int bitpos(int n) {
        int pos = 0;
        while (n % 2 == 0) {
            n /= 2;
            pos++;
        }
        return pos;
    }
    
public:
    void solve() {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        
        bool ok = 1;
        if (sum % 2) {
            ok = 0;
        }
        else {
            sum /= 2;
            dp[0] = 1;
            
            for (int i = 0; i < n; ++i) {
                for (int j = sum; j > 0; --j) {
                    if (j >= a[i]) {
                        dp[j] |= dp[j-a[i]];
                    }
                }
            }
            ok = dp[sum];
        }
                
        if (ok) {
            int minIndex = 0, minPos = bitpos(a[0]);
            for (int i = 1; i < n; ++i) {
                if (bitpos(a[i]) < minPos) {
                    minPos = bitpos(a[i]);
                    minIndex = i;
                }
            }
            cout << 1 << " " << minIndex + 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    
}
ac;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 111
 7 4
 3 5 4 4 6 3 2

 7 5
 3 5 4 4 6 3 2
 
 7 6
 3 5 4 4 6 3 2
 
 7 7
 3 5 4 4 6 3 2
 
 
 5 4
 4 1 2 3 4
 
 4 3
 4 1 2 3

 
 6 6 6 6 6 3 2
 3 1 2 2
 */
