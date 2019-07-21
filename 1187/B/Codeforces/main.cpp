//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1187/problem/B)
 **题目大意：**
 有一个小写字母组成的字符串s，长度为n；
 有m个人，每个人有一个名字，假如是t[i]；
 现在小明想知道，对于每个人，至少需要s的前面多少个字符，才能组成他的名字；
 
 假如 𝑠 ="arrayhead"，𝑡[𝑖]="arya"，那么需要前面5个字符array，才能够组成arya的名字；
 假如 𝑠 ="arrayhead"，𝑡[𝑖]="areahydra"，那么需要前面9个字符arrayhead，才能组成areahydra的名字；
 
 输入：
 第一行，整数𝑛，表示字符串长度 (1≤𝑛≤2⋅10^5)
 第二行，字符串s；
 第三行，整数m，表示m个人； (1≤𝑚≤5⋅10^4)
 接下来m行，每行有一个字符串t[i]； (1≤|𝑡[𝑖]|≤2⋅10^5)
 题目保证每个人的名字，都可以由字符串s组成，并且m个人的名字总长度不会超过2⋅10^5。
 
 输出：
 m行，每行有一个数字，表示需要的最少字符数量。
 
 
 **题目解析：**
 先不考虑复杂度，直接的做法是将每个人的名字拿出来匹配，一共匹配m次；
 怎么匹配比较方便？
 把名字统计下，得到b[26]，表示26个字符的数量；
 然后遍历整个字符串，直到26个字母的数量都满足；
 复杂度是O(N)，总的复杂度是O(NM)；
 
 这个复杂度太高，需要优化。
 容易知道，如果前i个字符满足要求，则前i+1个字符也满足要求，那么就可以二分。
 同时为了避免多次计算，可以直接换成a[i][j]表示前i个字符，第j个字母的数量。
 

 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

deque<int> q;
int a[N][26];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    string str;
    cin >> str;
    a[0][str[0] - 'a'] = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            a[i][j] = a[i - 1][j];
        }
        ++a[i][str[i] - 'a'];
    }
    
    int m;
    cin >> m;
    while (m--) {
        string t;
        cin >> t;
        int cnt[26] = {0};
        for (int i = 0; i < t.length(); ++i) {
            ++cnt[t[i] - 'a'];
        }
        
        int l = 0, r = n - 1, ans = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            
            int ok = 1;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] && a[mid][i] < cnt[i]) {
                    ok = 0;
                }
            }
            
            if (ok) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        cout << ans + 1 << endl;
    }
    
    return 0;
}
