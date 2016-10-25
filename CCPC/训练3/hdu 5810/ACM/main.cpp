//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 构造题。n个点，给出n个点能到达点的数量a[i]，构造一个有向图，满足条件。N (1 <= N <= 1000)

 3
 2 1 0
 表示点1，2，3能到达的点的数量2，1，0
 构造1->2->3 满足条件
 
 要求，构造的图不能有重边，不能有环。

 
 题目解析：
 
 
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
const lld N = 1622, M = 3010100, mod = 1000000007ll;

int a[N];
struct Node {
    int index, value;
    
    bool operator < (const Node t)const {
        return value > t.value;
    }
}node[N];
int ansX[N * N], ansY[N * N];

int main(int argc, const char * argv[]) {
    int caseN, ca = 0;
    cin >> caseN;
    while (caseN--) {
        ++ca;
        int n;
        scanf("%d", &n);
        
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            node[i].index = i;
            node[i].value = a[i];
        }
        sort(node + 1, node + 1 + n);
        bool ok = 1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (node[i].value > (n - i)) {
                ok = 0;
            }
            else {
                for (int j = 0; j < node[i].value; ++j) {
                    ansX[cnt] = node[i].index;
                    ansY[cnt] = node[n - j].index;
                    cnt++;
                }
            }
        }
        if (ok) {
            printf("Case #%d: Yes\n", ca);
            cout << cnt << endl;
            for (int i = 0; i < cnt; ++i) {
                printf("%d %d\n", ansX[i], ansY[i]);
            }
        }
        else {
            printf("Case #%d: No\n", ca);
        }
    }
    
}
