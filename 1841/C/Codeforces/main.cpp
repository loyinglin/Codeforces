//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1841/problem/C)
 **题目大意：**
 有长度为n的字符串s，由字符A/B/C/D/E组成；
 现在将字符串按照下述规则转成数字：
 1、A、B、C、D、E分别代表数字1、10、100、1000、10000；
 2、如果某个字符，右边的位置存在一个字符比当前字符更大，则添加负号；（比如说AB，A的右边存在B比当前字符A大，那么A代表-1）
 将字符串每个位置数字累加，得到字符串的和；
 比如说：
 ABB = -1 + 10 + 10 = 19；
 BBA = 10 + 10 + 1 = 21；
 
 现在可以修改字符串s中的一个字符，替换为A~E中的任意一个字符；
 问，字符串的和最大为多少？
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例一行，字符串𝑠(1≤|𝑠|≤2⋅105)

 
 
 **输出：**
 每个样例一行，输出修改后最大的字符串和；
 
 **Examples**
 **input**
 4
 DAAABDCA
 AB
 ABCDEEDCBA
 DDDDAAADDABECD

 **output**
 11088
 10010
 31000
 15886



 **题目解析：**
 还是从简单开始思考。
 只有单个字母时，直接选择替换为E，收益为E与当前字母的差距；
 当有两个字母时，就需要考虑特殊情况，正常AB这样的组合，还是会选择替换成EB；但是当BA这样的组合时，继续选A就会导致B变成负数，此时除了正收益，还有额外的负收益；
 那么就需要统一计算，负收益也比较容易计算：替换后，所在位置前，原来ABCD字母价值为正的部分；（注意，如果原来就为负，没有负收益）
 这样从左到右枚举整个数组即可得到最优解。
 
 但是，自己还是犯了一个错误：主观判断，无法证明。
 在分析样例的时候，还是太过急，从两个字母直接推出来最优解，情况还是不够丰富。
 因为修改字母除了修改为最大，还可以修改为较小值。
 这里既然要枚举每个位置的值，是不是也可以考虑枚举每个位置修改为A/B/C/D/E的值？
 这样可以解决DDDDDDDDDDDDDDE这样的case，我们可以修改为DDDDDDDDDDDDDDD。
 
 所以，更严谨的做法，我们应该枚举每一个位置分别对应修改为A/B/C/D/E的情况，但是这样的复杂度是O(N^2），明显超出题目限制；
 但是分析其中冗余的部分，由贪心思想我们可以发现，假如一个字符D要修改，要么就是第一个D，要么是最后一个D；
 为什么呢？
 由最开始的替换为E的思路，这是从博取正收益的角度去出发，在这种情况下，假设要修改的是字符C，那么越往左的字符C，整体收益是越大的；
 假如是我们从减少负收益的角度去出发，假设我们要修改是字符E，那么越往右的字符E，整体收益是越大的；
 所以我们只要最开始出现和最后出现ABCDE位置，一共10个位置，每个位置再枚举修改为A/B/C/D/E的最大收益即可。
 
 
 
 
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
    lld a[N];
    char s[N];
    lld val[5] = {1, 10, 100, 1000, 10000};
    
    lld getSum(int n) {
        lld ret = 0;
        char cur = 0;
        for (int i = n; i > 0; --i) {
            a[i] = val[s[i] - 'A'];
            if (s[i] < cur) a[i] *= -1;
            cur = max(cur, s[i]);
            ret += a[i];
        }
        return ret;
    }
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            scanf("%s", s+1);
            int n = strlen(s+1);
            int posFirst[5] = {0}, posLast[5] = {0};
            for (int i = 1; i <= n; ++i) {
                int idx = s[i] - 'A';
                if (!posFirst[idx]) posFirst[idx] = i;
                posLast[idx] = i;
            }
            lld ans = -0xfffffffffff;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (!posFirst[i]) continue;;
                    char c = 'A' + j;
                    char tmp = s[posFirst[i]];
                    s[posFirst[i]] = c;
                    ans = max(ans, getSum(n));
                    s[posFirst[i]] = tmp;
                }
            }
            
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (!posLast[i]) continue;;
                    char c = 'A' + j;
                    char tmp = s[posLast[i]];
                    s[posLast[i]] = c;
                    ans = max(ans, getSum(n));
                    s[posLast[i]] = tmp;
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
 
