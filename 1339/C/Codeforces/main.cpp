//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1339/problem/C)
 **题目大意：**
 给出n个整数的数组，现在每秒可以对数组进行一次操作：
 第x秒，可以从数组中选择出来若干个数，将每个数加上2^(x-1）；
 
 现在希望数组满足𝑎1≤𝑎2≤…≤𝑎𝑛 ，问最少需要多少秒；
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来t个样例，第一行，整数𝑛  (1≤𝑛≤10^5)
 第二行，n个整数 𝑎1,𝑎2,…,𝑎𝑛 (−10^9≤𝑎𝑖≤10^9).
 
 **输出：**
 最少需要秒数；
 
 **Examples**
 **input**
 3
 4
 1 7 6 5
 5
 1 2 3 4 5
 2
 0 -4
 **output**
 2
 0
 3
 
 
 **题目解析：**
 按照题意，分别可以加上数字1、2、4、8、16、、、
 由于数字递增很快（指数级），可以遇见不会添加很多次；
 那么可以考虑暴力来解决，枚举x=0、1、2、3、4、5、6的情况是否满足要求，每次枚举的复杂度是O（NLogM）；M是数字大小，最多枚举LogM次；
 
 接着，需要找一种能快速验证，当x=k的时候，是否满足要求；
 由贪心的思想，我们知道对于数字a[n]，由于预期a[n]是最大的数字，可以直接将所有的数字加到a[n]上；
 对于数字a[n-1]，我们希望a[n-1]在满足a[n-1]<=a[n]的情况下，尽可能的大；
 同理，我们希望a[n-2]、a[n-3]、、、都是如此的处理；
 
 那么问题变成，如何保证a[i-1]在满足a[i-1]<=a[i]的情况下，a[i-1]尽可能的大？
 答案就是：从大到小的加数字(2^(x-1))，直到数字无法添加，此时数字就是最大；
  
 注意，这里不是从小到大；比如说数字6变成12，如果从大到小有6+4+2=12，但是如果变成从小开始，则会出现取了数字1、2之后，无法取4，最大值就是9；
 
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
const int N = 100010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld p[N];
lld a[N];

bool check(int n, int k) {
    lld last = llinf;
    for (int i = n - 1; i >= 0; --i) {
        lld tmp = a[i];
        for (int j = k; j >= 1; --j) {
            if (tmp + p[j-1] <= last) {
                tmp += p[j - 1];
            }
        }
        if (tmp > last) {
            return false;
        }
        last = tmp;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    p[0] = 1;
    for (int i = 1; i < 31; ++i) p[i] = p[i-1] * 2;
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        int k = 0;
        while (1) {
            if (check(n, k)) {
                cout << k << endl;
                break;
            }
            k++;
        }
    }   
    
    return 0;
}
