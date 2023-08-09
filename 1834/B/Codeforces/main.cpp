//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1834/problem/B)
 **题目大意：**
 有两个很大的整数，用字符串L和字符串R表示，其中L代表的数字小于R代表的数字；
 现在想在区间[L, R]中找到2个数字，使得这两个数字的十进制表示上，每一位的绝对值差尽可能大。
 
 十进制位数差，就是将两个整数每一位的数字进行想减，然后累加绝对值，如果位数不相同则补前导零；
 比如说：
 55和37，结果 |5−5|+|3−7|=4
 190和209，结果 |1−2|+|9−0|+|0−9|=19
 1909和90，结果  |1−0|+|9−0|+|0−9|+|9−0|=28
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤5000)
 每个样例一行，字符串L和字符串R，长度不超过100；

 
 
 **输出：**
 每个样例一行，输出区间内最大的十进制位数差。
 
 **Examples**
 **input**
 6
 53 57
 179 239
 13 37
 132228 132228
 54943329752812629795 55157581939688863366
 88 1914


 **output**
 4
 19
 11
 0
 163
 28




 **题目解析：**
 当只有1位时，十进制差就是个位数想减；
 当有2位时，如果第一位相同，则结果为第二位相差；
 如果第一位不相同，那么结果为第一位之差，加上第二位9和0的差距；因为L的第二位总是能上升到9，R的第二位总是能降低为0；
 举例说明，区间[23, 46]，29肯定在区间内，因为十位数2<4，那么29肯定小于46；又由于9>=3，29在区间内；
 同理，46可以选出40，满足在区间内；
 
 那么当我们找到某一位不相同时，这一位后面的数字都可以填充9999..和0000...，然后再累加上当前位数差值，就是最大的结果。
 
 
 
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
    char a[N], b[N];
    
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> a >> b;
            int n = strlen(a);
            int m = strlen(b);
            int ans = 0;
            if (n < m) {
                ans = b[0] - '0' + (m - 1) * 9;
            }
            else if(n > m){
                ans = a[0] - '0' + (n - 1) * 9;
            }
            else {
                int k = -1;
                for (int i = 0; i < n; ++i) if(a[i] != b[i]) {
                    k = i;
                    break;
                }
                if (k == -1) ans = 0;
                else {
                    ans = abs(a[k] - b[k]) + (n - 1 - k) * 9;
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
 
