//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1890/problem/A)
 **题目大意：**
 有n个整数组成的数组a，现在可以对数组a的元素任意打乱顺序，要求满足：
 假设打乱后的数组是b，要满足：𝑏1+𝑏2=𝑏2+𝑏3=…=𝑏𝑛−1+𝑏𝑛=k
 也就是相邻两个数字的和相同。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤100)
 每个样例两行
 第一行整数𝑛(2≤𝑛≤100)
 第二行n个整数𝑎1,𝑎2,…,𝑎𝑛(1≤𝑎𝑖≤1e5).
  
 **输出：**
 每个样例一行，通过打乱顺序生成满足要求的数组，如果有解，则输出YES；如果无解，则输出NO；
 
 **Examples**
 **input**
 5
 2
 8 9
 3
 1 1 2
 4
 1 1 4 5
 5
 2 3 3 3 3
 4
 100000 100000 100000 100000


 **output**
 Yes
 Yes
 No
 No
 Yes


 **题目解析：**
 将两两相邻的数字相加，a1+a2, a2+a3...
 全部累加，得到(a1+a2)+(a2+a3)+(a3+a4)...
 最终就是a1+2x(a2+a3+...+a[n-1])+an
 这样只要枚举a1和an的值，就可以通过数组和sum，快速得到(a2+a3+...a[n-1])=sum-a1-an；
 那么两数相加和k = (a1 + 2x(sum-a1-an) + an) / (n - 1)；
 
 a1是枚举，那么a2=k-a1，以此类推枚举a3，在这个过程中如果发现数组b不存在当前的数字，那么则无解。
 但是走到这步的时候，发现了数组的规律： a1, k - a1, a1, k-a1
 其实不用复杂计算，最终数组结果必然只有2个数字。
 那么只需要统计数组a的元素，如果大于2个元素则必然无解。
 只有1个元素，或者2个元素的数量相差不超过1，就有解。
 
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
            int sum = 0;
            map<int, int> h;
            vector<int> vec;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                sum += a[i];
                h[a[i]]++;
                if (h[a[i]] == 1) vec.push_back(a[i]);
            }
            int ans = 0;
            if (vec.size() == 1) ans = 1;
            else if (vec.size() == 2) {
                if (abs(h[vec[0]] - h[vec[1]]) <= 1) ans = 1;
            }
            cout << (ans ? "YES" : "NO") << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
