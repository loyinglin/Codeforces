//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 给出1~9，9个数字的数量；
 从数字中，每次选3个数字组成a+b=c，只要有一个数字不同，视为不同的等式，每个数字只能用一次；
 问最多组成多少个等式；
 每个数字不超过100个。
 
 input
 1 1 1 1 1 1 1 1 1
 
 output
 2
 
 解释：最多有 1+2=3， 和 4+5=9两种。
 
 题目解析：
 总共有
 8种：1+1/2/3/4/5/6/7/8=2/3/4/5/6/7/8/9..
 7种：2+1/2/..../7
 ..
 到最后的
 1种：8+1=9
 总共有36种，其中1+2=3 和 2+1=3 是相同的；
 于是有(36 - 4) / 2 + 4 = 20种； （4种是1+1, 2+2, 3+3, 4+4)
 给20个等式编号；
 dp[[i] 表示状态i，其中二进制位为1表示取该位数对应的等式；总共有2^20个状态；
 状态转移:
 如果i+(1<<k)合法，则有 dp[i+(1<<k)]=dp[i]+1;
 
 ans = max(dp[i]);
 
 复杂度:
 O(2^20 * 20);
 >但是无法解决1+2=3 和 2+1=3的问题；
 
 在上面的基础上，改用搜索，直接枚举所有的可能。
 添加一个剪枝：当目前搜的解无法比之前更优时返回；
 
 
 
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
const int N = 1100, M = 20, inf = 100100100; //注意修改点的范围

int a[M][3] = {
    1, 1, 2,
    2, 2, 4,
    3, 3, 6,
    4, 4, 8,//4
    
    1, 2, 3,
    1, 3, 4,
    1, 4, 5,
    1, 5, 6,
    1, 6, 7,
    1, 7, 8,
    1, 8, 9,//7
    
    2, 3, 5,
    2, 4, 6,
    2, 5, 7,
    2, 6, 8,
    2, 7, 9,//5
    
    3, 4, 7,
    3, 5, 8,
    3, 6, 9,//3
    
    4, 5, 9//1
};
int c[10], ans, sum[10];

bool lookOK(int sum[10]) {
    for (int i = 1; i <= 9; ++i) {
        if (sum[i] > c[i]) {
            return 0;
        }
    }
    return 1;
}


int dfs(int index, int cur) {
    if (cur + (M - index) * 2 <= ans || !lookOK(sum)) {
        return 0;
    }
    int ret = cur;
    for (int i = index; i < M; ++i) {
        int m = i < 4 ? 1 : 2;
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 3; ++k) {
                sum[a[i][k]] += j;
            }
            ret = max(ret, dfs(i + 1, cur + j));
            for (int k = 0; k < 3; ++k) {
                sum[a[i][k]] -= j;
            }
        }
    }
    ans = max(ans, ret);
    return ret;
}

int main(){
    int ca = 0, CASE;
    cin >> CASE;
    while(CASE--){
        for (int i = 1; i < 10; ++i) {
            cin >> c[i];
        }
        memset(sum, 0, sizeof(sum));
        ans = 0;
        dfs(0, 0);
        printf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}

