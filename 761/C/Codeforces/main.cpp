//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/761/problem/C
 题目大意：
 n个字符串，长度均为m；
 现在要从n个字符串中，每个选出一个字符，组成一个长度为n密码，要求：
 包括数字、小写字母、特殊字符（'#','*','&'中的一个）;
 
 现在假设选择字符的光标停在每个字符的最左边，每次可以左移或者右移操作，如果在最左边左移会变到最右边，在最右边右移会变到最左边；
 问，最少需要操作几次，才能选出一个合法的密码？（数据保证，必然存在合法的密码）

 Examples
 input
 3 4
 1**2
 a3*0
 c4**
 output
 1
 样例解释：选中的密码是1a*，仅需把第三行的c移动到最右边；
 
 n, m (3 ≤ n ≤ 50, 1 ≤ m ≤ 50)
 
 
 题目解析：
 题目的要求是选出合法的密码，那么最多移动三个光标；（其他的光标不动）
 现在的抉择是移动哪些光标，使得次数最少；
 先看暴力的情况：
 从50个选择3个的排列是50*49*48，每次枚举的复杂度是m*2;
 总的复杂度是O(N^3 * M)；
 是可行的方案。
 
 
 
 其他解法：
 每行有四种抉择，不动，移动到小写字母，移动到数字，移动到特殊字符；
 那么可以用dp[i][j] 来表示前i行，密码已满足状态为j的最小光标移动距离；j ∈ [0, 1 << 3]，用二进制来表示状态j；
 每行有四个转移方程，复杂度为O(M);
 总体的复杂度是O(NM);
 
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
const int N = 60, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

char a[N][N];

inline bool match(char c, int type) {
    if (type == 0) {
        return c >= '0' && c <= '9';
    }
    else if (type == 1) {
        return c >= 'a' && c <= 'z';
    }
    else if (type == 2) {
        return c == '#' || c == '*' || c == '&';
    }
    return false;
}

int find(int u, int m, int type) {
    int ret = M;
    char *str = a[u];
    for (int i = 0; i < m; ++i) {
        if (match(str[i], type)) {
            ret = min(ret, i);
        }
    }
    for (int i = m - 1; i > 0; --i) {
        if (match(str[i], type)) {
            ret = min(ret, m - i);
        }
    }
    return ret;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = M;
    for (int i = 0; i < n; ++i) { // num
        for (int j = 0; j < n; ++j) { // char
            for (int k = 0; k < n; ++k) { // spe
                if (i == j || j == k || i == k) {
                    continue;
                }
                int tmp = 0;
                tmp += find(i, m, 0);
                tmp += find(j, m, 1);
                tmp += find(k, m, 2);
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
