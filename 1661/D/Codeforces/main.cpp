//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1661/problem/D)
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
 把每次操作都当成是选择一个线段，那么最终会有m个线段，我们关注每个线段右边终点；
 然后从右到左遍历数组元素，对于第i个元素，尽可能使得元素i满足a[i]>=b[i]，这样一定会有最优解。
 这里的证明比较明显，比如线段[i, j]对于元素j肯定是最优解，[i+1, j+1]会浪费j+1部分，[i-1, j-1]则会无法增加j的大小。
 
 但是按照上的做法，每个元素都要遍历元素i和前面k个元素，总体的复杂度是O(N*K)，会出现超时的情况。
 但是对于已经给定的某个线段数量，我们能在O(N)的时间判断这个是否有解，配合数量的二分，可以在O(N*LogM）的复杂度内得到结果，M是最大的结果。
 
 对于mid条线段，我们先假设全部添加在元素i上面，然后每次计算元素i上面有多少条线段可以左移1位，这个数字就是(a[i]-b[i])/k；
 然后不断计算这个移动的过程，直到线段无法移动（如果移动之后a[i]会小于b[i]，则这个位置无法移动线段）；
 对于元素i，初始化的时候添加mid条线段的复杂度是O(K)，接下来每次移动一条线段都可以用c[i-k-1] -= 1和c[i-1] += 1来标记，后面就需要根据初始化的值以及这个区间内c的大小来得到结果；
 
 思考🤔：
 是否有最优解呢？
 有的，理论最优解应该是O（N），从最初的贪心做法开始分析，最大的重复计算是每次操作之后，进行区间计算的过程。
 这个计算有明显的线性特性，可以进行如下的优化：
 对于数组[1, 3, 4, 7]来说，当我们在最后添加3条线段的时候，我们会得到[0, 3, 6, 9]，但是需要计算3次，这也是复杂度超标的所在。
 接着上面的思路，当我们在第4个元素选择添加3条线段时，我们令a[3]=9，同时记录sum=9，cnt=3，并且用上面的区间标记方式，在c[2]和c[0]的地方标记+3和-3；
 这样当我们访问第3个元素时，我们只需要计算sum-cnt，就可以快速得到之前的结果，并且根据c的信息实时更新cnt的大小即可。
 这样只需要遍历一次数组，并且每次操作都是O(1)，达到了理论最优解O(N)；
  
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
    lld a[N], b[N], c[N], n;
    
    bool check(lld k, lld mid) {
        for (lld i = 0; i <= n; ++i) {
            a[i] = c[i] = 0;
        }
        for (lld i = 0; i < k; ++i) {
            a[n - k + i] = mid * (i + 1);
        }
        
        lld cur = mid, seg = 0; // 当前有cur条线段以i结束，仅有这部分可以左移
        for (lld i = n - 1; i >= 0; --i) {
            seg += c[i];
//            cout << mid <<" " <<  i << " " << a[i] + seg << endl;
            if (a[i] + seg < b[i]) {
                return false;
            }
            lld move = min(cur, (a[i] + seg - b[i]) / k);
            cur = move;
            if (i >= k) {
                c[i - 1] += move;
            }
            if (i >= k + 1) {
                c[i - k - 1] -= move;
            }
        }
        return true;
    }

public:
    void solve() {
        lld t = 1;
        while (t--) {
            lld k;
            cin >> n >> k;
            lld top = 0;
            for (lld i = 0; i < n; ++i) {
                cin >> b[i];
            }
            for (lld i = 0; i < n; i+=k) {
                lld tmp = 0;
                for (lld j = 0; j < k; ++j) {
                    tmp = max(tmp, b[i + j]);
                }
                top += tmp;
            }
            
            lld left = 1, right = top + 1;
            lld ans = right;
            while (left <= right) {
                lld mid = (left + right) / 2;
                if (check(k, mid)) {
                    ans = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
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

/**
 5 3
 1 2 7 2 3
 
 123
 123
 00123
 
 1 2 3
 0 1 2 3
 0 1 2 3
 
 10 5
 483030621364 740929692323 674088011566 788185776410 938925910496 72832564149 851902074507 552704571783 25993072071 857441538155
 
 10 10
 147248897721 807886958573 201571275916 898284529129 24722372125 223587667506 755522975808 887305630476 240874494946 482858523847
 807886958573
 */
