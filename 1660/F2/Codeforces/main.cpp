//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1660/problem/F1)
 **题目大意：**
 给出由+和-组成的字符串，我们称字符串为平衡的字符串，假如+和-的字符是相同的；
 现在可以对字符串执行操作，每次将两个相邻的-号合并为+号；假如若干次操作之后，字符串变成了平衡的字符串，那么这个字符串可以称之为特殊的字符串；
 
 现在给出长度为n的字符串，问字符串中有多少子串是特殊的；
 
 
  **输入：**
 第一行，整数𝑡 表示t个样例
 每个样例两行，第一行是整数𝑛
 第二行是字符串；
 
 **输出：**
输出满足要求的子串数量；
 
 **Examples**
 **input**
 
 **output**
 
 **题目解析：**
 这是hard难度，题目给出来的范围比较大，O(N\*N)的复杂度枚举所有字符串的子串的方式已经不适用；
 首先需要对我们已经采用的方法进行简化，countx和county其实可以简化为countx-county的方式，并且由二维简化为一维：
 我们用sum[i]表示前i个字符相加的结果，字符+表示-1，字符-表示+1；
 那么子串[i, j]可以用sum[j] - sum[i - 1]的方式快速得到结果，(sum[j] - sum[i - 1])%3==0 && sum[j] >= sum[i - 1] 表示有解；
 
 从左到右遍历字符串，对于第j个字符，首先得到sum[j]，然后遍历i∈[1, j-1]判断 (sum[j] - sum[i - 1])%3==0 && sum[j] >= sum[i - 1] 的数量；
 这个遍历过程存在较多重复计算，我们只在乎i∈[1, j-1]这个区间中sum[i]的值，而对i的位置并不关心，并且sum[i]的值最多也只有2n+1种可能（取值范围是[-n, n]）；
 那么如果我们把sum[i]的结果直接存到[-n, n] 这个区间上，我们就可以直接获取遍历这个区间的值即可。
 以n=4为例，sum[i]的结果可能有[-4,-3,-2,-1,0,1,2,3,4]，如果sum[j]=3，那么我们只需要取sum[i]=3/0/-3的值；如果sum[j]=2，那么我们只需要取sum[i]=-1/-4的值；
 由于我们只在乎%3的结果，我们可以用cnt[0,1,2]来表示sum[i]%3的值和，这样从数组中取值就不需要遍历，可以很快取到某个余数的值；
 
 但是这里还有一个条件是sum[j] >= sum[i - 1]，sum[j]=0的时候，sum[i]=3这种情况是不允许的，所以cnt的值是需要维护的，维护方式就是：
 当我们sum[j]变小的时候，cnt作为累加和，要退掉之前累加的值；
 比如说sum[j]=2的时候，cnt累加了[-4, 2]的区间；sum[j+1]=1的时候，cnt累加了[-4, 1]的区间；也就是cnt需要退掉sum[j]=2的值；
 
 由于sum[i]的取值范围是[-n, n] 我们可以将sum[i]+n，这样取值范围变成[0, 2n]，好处是可以用数组来表示，并且不影响我们对结果的结算，因为 (sum[j] - sum[i - 1])等于 (sum[j] + n）-（sum[i-1] + n），sum[j] >= sum[i-1] 等于 sum[j] + n >= sum[i-1] + n；
 
 
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
    char str[N];
    int sum[N * 2];
    int cnt[3];

public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cin >> (str + 1);
            lld ans = 0;
            int preCount = n;
            memset(cnt, 0, sizeof(cnt));
            memset(sum, 0, sizeof(sum));
            sum[preCount] = 1;
            cnt[preCount % 3] = 1;
            for (int i = 1; i <= n; ++i) {
                int curCount = preCount + (str[i] == '-' ? 1 : -1);
                int index = curCount % 3;
                if (curCount < preCount) {
                    cnt[preCount % 3] -= sum[preCount];
                }
                else {
                    cnt[curCount % 3] += sum[curCount];
                }
                ans += cnt[index % 3];
                cnt[curCount % 3]++;
                sum[curCount]++;
                preCount = curCount;
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
 */
