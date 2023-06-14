//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1823/problem/B)
 **题目大意：**
 给出1到n的整数排列所形成的数组p以及整数k，现在可以对数组进行下列操作形成从小到大的数组：
 选择任意两个相差为k的位置，交换他们的位置上的元素；
 比如说数组[3,2,1] 和 k=2，那么可以选择位置1和位置3进行交换，得到数组[1,2,3]，满足题目要求；
 
 但是有些数组的无法满足要求，比如说[2,4,3,1]和k=2，此时无法通过交换得到数组[1,2,3,4]；
 这种情况下，此时允许在最初的时候（进行交换操作之前），对选择任意数组两个位置，进行交换（该交换只允许一次），比如说：
 数组[2,4,3,1]选择整数1和2交换得到[1,4,3,2]，然后再进行交换操作，可以得到从小到大的数组[1,2,3,4]；
 
 现在的任务是给出数组p和整数k，问是否能得到从小到大的数组。
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例2行
 第一行 n和𝑘，表示数组长度和整数k (2≤𝑛≤2⋅1e5; 1≤𝑘≤𝑛−1)
 第二行 n个整数  𝑝1,𝑝2,…,𝑝𝑛 （1≤𝑝𝑖≤n）
 
  
 **输出：**
 每个样例一行，输出0/1/-1，分别表示：
 0，有解，并且不需要提前交换；
 1，有解，但是必须要提交交换；
 -1，无解；
 
 **Examples**
 **input**
 6
 4 1
 3 1 2 4
 4 2
 3 4 1 2
 4 2
 3 1 4 2
 10 3
 4 5 9 1 8 6 10 2 3 7
 10 3
 4 6 9 1 8 5 10 2 3 7
 10 3
 4 6 9 1 8 5 10 3 2 7


 **output**
 0
 0
 1
 0
 1
 -1

 
 **题目解析：**
 当k=1的时候，肯定有解，因为可以随意交换；
 当k>1的时候，每个位置能和相距为k的位置交换，那么将距离为k的元素全部提取出来，这部分元素就能任意交换，比如说数组[1,2,3,4,5,6,7]
 k=2时，数组可以拆分为[1,3,5,7]和[2,4,6]，这两个数组的元素就能任意交换；
 k=3时，整数可以拆分为[1,4,7], [2,5], [3,6] 这样三个数组；
 我们将数组p，拆分成k个数组，每个数组如果都按照上述的规律展示，那么不需要做提前交换，就可以有解；
 
 通过不匹配当前数组的元素数量，如果为2，那么通过提前交换就有解；如果为其他值则无解；
 
 举个例子，假设数组4 1 3 5 2 6 7，我们拆分得到
 457
 12
 36
 
 那么可以得到4应该在第二组，而不是第一组；
 1不应该在第二组，而是应该在第一组；
 此时提前交换1和4，有解；
 
 
 
 
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
            int n, k;
            cin >> n >> k;
            for (int i = 1; i <= n; ++i) cin >> a[i];
            if (k == 1) cout << 0 << endl;
            else {
                int cnt = 0;
                for (int i = 1; i <= k; ++i) {
                    int idx = i;
                    while (idx <= n) {
                        if ((a[idx] - i) % k) ++cnt;
                        idx += k;
                    }
                }
                if (cnt == 2) cnt = 1;
                cout << (cnt < 2 ? cnt : -1) << endl;
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
 
