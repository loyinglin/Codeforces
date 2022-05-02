//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1661/problem/C)
 **题目大意：**
 有n个整数，现在可以执行若干次操作，每次操作可以选择数组中某个元素进行增长，也可以选择跳过该操作；
 这样进行第1次操作、第2次操作、第3次操作....
 假如第1、2、3次操作中，第k次操作是选择数组元素a[i]，则如果k是奇数则使a[i]=a[i]+1；如果k是偶数则使a[i]=a[i]+2；
 
 现在想知道，最好经过多少次操作可以让整个数组的元素相等。
 
  **输入：**
 第一行整数𝑡，表示t个样例 (1≤𝑡≤2⋅1e4)
 每个样例2行，第一行是整数 𝑛 (1≤𝑛≤3⋅1e5)
 第二行是整数 ℎ1,ℎ2,…,ℎ𝑛 (1≤ℎ𝑖≤1e9)
 
 **输出：**
 每个样例一行，最少的操作数。
 
 
 **Examples**
 **input**
 3
 3
 1 2 4
 5
 4 4 3 5 5
 7
 2 5 4 8 3 7 4
 **output**
 4
 3
 16
 
 **题目解析：**
 目标是所有整数一样，那么假设maxItem是数组中最大的元素，最终的结果必然是maxItem或者maxItem+1；
 证明：可以用反证法，假如最终结果是maxItem+2，那么必然可以将所有整数-2（或者连续-1两次），得到最终元素maxItem。
 
 现在问题就变成，假如n个元素都要变成maxItem，最少需要多少次操作。
 根据对于第i个元素a[i]，我们得到diff=maxItem-a[i]；
 如果diff是偶数，那么需要diff/2次+2操作；如果diff是奇数，那么需要diff/2次+2操作和1次+1操作；
 我们用odd表示+1操作次数，event表示+2操作次数，根据上面的规则，我们可以算出来总的odd和even。
 
 接下来考虑替换的问题，假如even比odd大，那么存在一种替换关系：
 两个+1操作可以替换成1个+2操作；
 那么我们用tmp = (even - odd)/3，可以得到tmp次无缝替换；（为什么要/3？以为在把+2替换成+1的时候，+2的数量也会-1）
 
 这样令odd = odd + tmp * 2, even = even - tmp，得到无法替换的odd和even次数；
 此时还存在一种特殊情况，就是even - odd = 2的情况：
 此时仍然1个+2可以替换成2个+1，整体的代价为1。
 比如说样例
 3
 1 1 3
 odd=0，even=2，如果不做任何替换，则ans=even*2=4；
 但是可以把1个+2替换成2个+1，此时odd=2, even=1,此时ans = odd * 2 - 1 = 3;
 
 得到最终的odd和even数量后，就可以得到答案：
 如果odd>even, 则 ans = odd * 2 - 1;
 如果odd<=even，则 ans = even * 2；
 
 注意：题目需要用long long来处理，避免整数溢出；以及整体数据量偏大，注意数组边界，避免越界；
 
 
  
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
    static const int N = 301010;
    lld a[N];
    
    lld check(lld n, lld maxItem) {
        lld ans = 0;
        lld odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            lld diff = maxItem - a[i];
            even += diff / 2;
            if (diff % 2) {
                odd += 1;
            }
        }
//        cout << "max:" << maxItem << " odd: " << odd << " even: " << even  << " ans: " << ans << endl;
        // 接下来就是将多余的even拆成odd来实现
        // (even - odd) / 3  这部分是一定可以拆的
        if (even > odd && (even - odd) / 3) {
            lld tmp = (even - odd) / 3;
            odd += tmp * 2;
            even -= tmp;
        }
        if (even == 0 && odd == 0) {
            ans = 0;
        }
        if (odd > even) {
            ans = odd * 2 - 1;
        }
        else {
            if (even - odd == 2) {
                ans = even * 2 - 1;
            }
            else {
                ans = even * 2;
            }
        }
        
        return ans;
    }

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            lld maxItem = 0;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                maxItem = max(maxItem, a[i]);
            }
            cout << min(check(n, maxItem), check(n, maxItem + 1)) << endl;
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
 33
 7
 1 1 1 1 1 1 2
 2
 1 3
 3
 1 5 3
 3
 4 4 1
 
 */
