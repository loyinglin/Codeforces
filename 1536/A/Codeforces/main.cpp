//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1536/problem/A)
 **题目大意：**
 给出n个数字𝑎1,𝑎2,⋯,𝑎𝑛 ，要求构造一个长度不超过300的整数数组b，要求：
 数组b中没有重复的元素；
 数组b包括了数组a的所有数字；
 数组b任意两个数字的差，其绝对值可以在数组b中找到相同数字。
 
  **输入：**
 第一行是整数t，表示有t个样例 (1≤𝑡≤50 ).
 每个样例第一行是整数𝑛 (2≤𝑛≤100)；
 第二行是n个整数 𝑎1,𝑎2,⋯,𝑎𝑛  (−100≤𝑎𝑖≤100)
 
 **输出：**
 如果有解，先输出YES，再输出整数k，表示有k个整数； (𝑛≤𝑘≤300)
 𝑏1,𝑏2,⋯,𝑏𝑘 (−1e9≤𝑏𝑖≤1e9)
 如果无解则输出NO；
 
 **Examples**
 **input**
 4
 3
 3 0 9
 2
 3 4
 5
 -7 3 13 -2 8
 4
 4 8 12 6

 **output**
 yes
 4
 6 0 3 9
 yEs
 5
 5 3 1 2 4
 NO
 Yes
 6
 8 12 6 2 4 10

 
 **题目解析：**
 构造出来的数组b中不会存在负数，证明：
 假设a[i]-a[j]，a[j]小于零，则必然需要一个比a[i]的数字a[k]，但是a[k]-a[j]又会产生更大的数字；
 
 所以数组a中存在负数无解；
 其他的情况，就用1、2、3、4到max来填充即可。
 
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
    static const int N = 200010;
public:

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            int maxNum = 0, minNum = 200;
            for (int i = 1; i <= n; ++i) {
                int k;
                cin >> k;
                maxNum = max(maxNum, k);
                minNum = min(minNum, k);
            }
            if (minNum < 0) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
                cout << maxNum + 1 << endl;
                for (int i = 0; i <= maxNum; ++i) {
                    cout << i << " ";
                }
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
