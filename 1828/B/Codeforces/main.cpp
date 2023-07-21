//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1828/problem/B)
 **题目大意：**
 有1到n的n个整数数组a，现在这n个整数是unsort的状态，也就是至少存在一个整数a[i] ≠ i；
 可以选择一个整数k，对于数组中任意两个整数a[i]和a[j]，只要满足i-j=k，则可以交换a[i]和a[j]；
 想知道，如果想要把数组调整为有序状态（a[i] = i），整数k最大值可能为多少？
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行，第一行整数𝑛 (1≤𝑛≤2⋅1e5)
 第二行 n个整数，a1,a2,…,a𝑛 (1≤a𝑖≤𝑛 )
 
 
 **输出：**
 对于每个样例，输出k的最大可能值；
 
 **Examples**
 **input**
 7
 3
 3 1 2
 4
 3 4 1 2
 7
 4 2 6 7 5 3 1
 9
 1 6 7 4 9 2 3 8 5
 6
 1 5 3 4 2 6
 10
 3 10 5 2 9 6 7 8 1 4
 11
 1 11 6 4 8 3 7 5 9 10 2
 
 **output**
 1
 2
 3
 4
 3
 2
 3


 **题目解析：**
 首先，题目一定有解，比如说k=1的时候，就可以使用冒泡排序，最终使得数组有序；
 当k=2的时候，奇数位置的数字可以互相交换，偶数位置的数字可以相互交换；那么要求所有数字与所属位置的距离，应该都为2，或者2的倍数（多次交换，即可得到2的倍数距离）；
 当k=3的时候，与k=2类似，位置1、2、3只能和4、5、6等位置交换；
 ..
 这样我们将整数数组与所属位置进行匹配，就可以得到整数数组b，排除掉b[i]=0的部分（已经匹配）；
 只要存在最大公约数k，对于所有的b[i]都有b[i]%k==0，那么这个k是可行的。
 
 那么怎么找到这个k？
 有个简单的做法，我们找到最大的整数，将整数进行因数分解，再分别判断每个因素是否为最大公约数即可。
 （仔细分析一下，发现这里不要最大整数，取任意整数均可）
 
 
 
 
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
    int a[N], b[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            for (int i = 0; i < n; ++i) b[i] = abs(a[i] - i - 1);
            sort(b, b + n, greater<int>());
            vector<int> tmp;
            tmp.push_back(1);
            tmp.push_back(b[0]);
            for (int i = 2; i * i <= b[0]; ++i) {
                if (b[0] % i == 0) {
                    tmp.push_back(i);
                    tmp.push_back(b[0] / i);
                }
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            int ans = 0;
            for (int i = 0; i < tmp.size() && !ans; ++i) {
                int ok = 1;
                for (int j = 0; j < n && b[j] != 0; ++j) {
                    if (b[j] % tmp[i] != 0) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ans = tmp[i];
                }
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
 
