//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1821/problem/B)
 **题目大意：**
 给出一个由n个整数组成的数组a，在数组中选择区间[l, r]，将区间内的整数按照非降序进行处理得到整数数组b，比如说：
 整数数组a为[6,7,3,4,4,6,5]，选择区间[2, 5]得到整数数组b为[6,3,4,4,7,6,5]；（区间外的整数位置不变）
 
 现在已知整数数组a和变化后的整数数组b，求区间最长可能为多少？
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例3行：
 第一行整数n(2≤𝑛≤2⋅1e5)
 第二行整数数组a
 第二行整数数组b
 注意：数组a和数组b至少有一个位置的元素不相同。
  
 **输出：**
 每个样例一行，输出区间[l, r]，表示可以选择进行操作的最长区间，如果由多个答案，输出任意一个；（题目保证有解）
 
 **Examples**
 **input**
 3
 7
 6 7 3 4 4 6 5
 6 3 4 4 7 6 5
 3
 1 2 1
 1 1 2
 3
 2 2 1
 2 1 2

 **output**
 2 5
 1 3
 2 3


 
 **题目解析：**
 假如不考虑复杂度，那么应该枚举区间[x, y]，然后计算每个区间的可行性，这样复杂度为枚举复杂度 * 验证复杂度，枚举就已经超过题目限制；
 注意题目给出的条件，数组a和b有元素不相同，那么至少存在2个位置不相同，否则题目无解；
 假定第一个不相同元素的位置是x，最后一个不相同元素的位置是y，那么区间[x, y]必然是一个解，但不是最长解：
 假设区间[x, y]右边的元素比区间[x, y]内的元素更大，那么可以纳入到这个区间内，因为排序完无影响；
 同理对于区间[x, y]左边的元素，只要小于的等于区间内最小值，那么同意可以纳入到区间中；
 
 注意：
 区间外的整数，不一定有序的，比如说：
 2 2 4 3 5 4
 2 2 3 4 5 4
 
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
    int b[N];
public:
    void solve() {
        int t;
        cin >> t;
        int cnt = 0;
        while (t--) {
            int n, x, y = 0;
            cnt++;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            for (int i = 0; i < n; ++i) cin >> b[i];
            x = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i]) {
                    if (x == -1) x = i;
                    else y = i;
                }
            }
            
            int valMin = b[x], valMax = b[y];
            while (x > 0) {
                if (b[x - 1] <= valMin) --x;
                else break;
                valMin = min(valMin, b[x]);
            }
            while (y < n - 1) {
                if (b[y + 1] >= valMax) ++y;
                else break;
                valMax = max(valMax, b[y]);
            }

            cout << (x + 1) << " " << (y + 1) << endl;
            
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
