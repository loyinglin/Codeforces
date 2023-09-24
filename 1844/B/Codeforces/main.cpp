//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1844/problem/B)
 **题目大意：**
 首先定义MEX，对于一个区间，这个区间内未出现过的最小正整数就是这个区间的MEX值；
 [2,3,1,5,4]的MEX值就是6；
 
 现在需要构造一个的整数数组，要求满足：
 1、数组的元素是由1到n的排列组成；
 2、数组所有的子区间，MEX值是素数的尽可能多；
 
 
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行，整数𝑛 (1≤𝑛≤200000).
  
 **输出：**
 每个样例一行，输出1到n的n个整数。
 
 **Examples**
 **input**
 3
 2
 1
 5



 **output**
 2 1
 1
 5 2 1 4 3



 **题目解析：**
 根据题目的要求，如果某个区间中，数字1没有出现，那么必然MEX值为1，1不是素数；
 那么1必然要被包括在区间内；
 
 想要让区间的MEX为素数，那么这个区间内就不要包括某个素数，这里选择2和3；（因为最小，最容易满足）
 只要2不出现在区间中，那么区间的MEX值必然为2；
 比如说1xxx2，区间1x 1xx 1xxx都满足要求；
 
 为了让结果尽可能大，应该要让数字均匀分布在1的左右两边；
 形成 2 xxxx 1 xxxxx 3这样的布局，就可以让结果尽可能的多。
 
 
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
        for (int i = 2; i < N; ++i) {
            int m = sqrt(i) + 1, find = 0;
            for (int j = 2; j <= m && j < i; ++j) {
                if (i % j == 0) find = 1;
            }
            a[i] = !find;
        }
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            if (n == 1) cout << "1" << endl;
            else if (n == 2) cout << "2 1" << endl;
            else {
                vector<int> ans;
                ans.push_back(2);
                for (int i = 0; i < (n - 3) / 2; ++i) ans.push_back(4 + i);
                ans.push_back(1);
                for (int i = (n - 3)/ 2; i < n - 3; ++i) ans.push_back(4 + i);
                ans.push_back(3);
                //            for (int i = 2; i <= n; ++i) if (!a[i]) ans.push_back(i);
                for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
                cout << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
