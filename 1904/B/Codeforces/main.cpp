//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1904/problem/B)
 **题目大意：**
 有n个元素的整数数组a，现在进行以下操作：
 1、选择某个元素a[i]，移除当前元素a[i]，获得初始分数score=a[i]；
 2、寻找某个元素a[j]，并且满足score>=a[j]，可以移除元素a[j]，同时使得分数score增加a[j]；
 3、不断重复操作2，直到无法执行；
 
 现在想知道，每个元素被作为初始元素时，最多能够移除的元素数量；
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤5000)
 每个样例2行
 第1行整数 𝑛  (1≤𝑛≤1e5 )
 第2行n个整数 𝑎1,𝑎2,…,𝑎𝑛   (1≤𝑎𝑖≤1e9)
   
 **输出：**
 每个样例一行，每行n个整数，第i个数字，表示当第i个元素作为初始元素时，能够移除的最多元素数量。（也就是操作2的最多执行次数）
 
 
 **Examples**
 **input**
 4
 5
 20 5 1 4 2
 3
 1434 7 1442
 1
 1
 5
 999999999 999999999 999999999 1000000000 1000000000



 **output**
 4 3 0 3 1
 1 0 2
 0
 4 4 4 4 4


 **题目解析：**
 将整数数组进行从大到小排序，接着下来再考虑如何决策；
 由于题目的规则很像“大鱼吃小鱼”，可以从数字较小者开始，也就是从右到左：
 1、最小的元素，除非和倒数第二个相同，否则无法吃下任何数字；
 2、从倒数第二个数字开始，每次可以直接累加右边所有的数字，然后如果数字和大于等于左边的数字，就可以一直累加，然后左移一位，直到无法移动；
 此时，该段区间内的所有数字，最终的数字和都是一样的；
 3、重复上面的过程，直到将整个数组分为若干段；
 比如说[20, 5,4,2,1]就可以分为[20],[5,4], [2], [1]，划分规则就是每次从右到左累加和，小于左边一个数字。
 
 类似的思考过程，假设我们排序之后是从左到右去思考，还是以[20, 5,4,2,1]为例子。
 当处理数字20时，按照规则，右边所有数字都能吃掉，ans[0]=4；
 当处理数字5时，如果5左边所有数字累加和大于20，那么就可以吃掉20，此时结果ans[1]=ans[0]; 但是5左边累加数字和，结果是12，那么此时结果就是3；
 因为数组比较长，右边和可以先计算整个数组和sum，然后不断累积减去当前数字。
 
 
 
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
    static const int N = 101010;
    pair<int, int> a[N];
    int ans[N];
    static bool cmp(pair<int, int> x, pair<int, int> y) {
        return x.first > y.first;
    }
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            lld sum = 0;
            for (int i = 0; i < n; ++i) {
                cin >> a[i].first;
                a[i].second = i;
                sum += a[i].first;
            }
            sort(a, a + n, cmp);
            for (int i = 0; i < n; ++i) {
                sum -= a[i].first;
                if (i == 0) {
                    ans[a[i].second] = n - i - 1;
                }
                else {
                    if (sum + a[i].first >= a[i - 1].first) {
                        ans[a[i].second] = ans[a[i - 1].second];
                    }
                    else {
                        ans[a[i].second] = n - i - 1;
                    }
                }
            }
            for (int i = 0; i < n; ++i) cout << ans[i] << " ";
            cout << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
