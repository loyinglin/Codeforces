//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1523/problem/D)
 **题目大意：**
 小明和n个朋友一起选课，一共有m门课，小明知道每个朋友喜欢的课程，并且每个人喜欢的课程数不会超过p；
 现在想知道怎么选修课程，才能满足 至少有N/2（向上取整）个同学都喜欢他选择的课程；
 
 
 **输入：**
 第一行是整数 𝑛,𝑚 and 𝑝 (1≤𝑛≤2⋅1e5, 1≤𝑝≤𝑚≤60, 1≤𝑝≤15)
 接下来n行，每行是m个0/1整数，1表示喜欢这个课程；
 
 **输出：**
 结果输出一行，m个0/1整数，1表示对这个课程的细化。
 
 **Examples**
 **input**
 5 5 4
 11001
 10101
 10010
 01110
 11011
 **output**
 10001
 
 **题目解析：**
 dp[i]表示小明选择了课程状态为i的喜欢人数，i表示为二进制，1则表示选中该课程。
 那么把所有的选修与小明的喜欢状态进行与操作，得到state[1~n]，然后dp[state[i]]++，这样dp[1~2^k]就可以表示为小明与所有人喜欢的最大交集的数量。
 然后接下来就有dp[(100)2]+=dp[(101)2]等状态递归，原来是因为我们统计了和小明喜欢状态为101的人，自然可以累加到dp[100]上面，同时也可以累加到dp[001]上面。

 另外只需要把小明喜欢的课程直接拿出来，离散化处理即可，非小明喜欢的直接去掉。
 注意，状态压缩的时候，要考虑重复的情况，比如说111=>110,101  但是110和101都可以转移到100，所以如果先枚举状态，再枚举转移的状态位，会出现数据重复。
 
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
//#include <bits/stdc++.h>
using namespace std;
//mt19937_64 rd(time(0)); //蒙特卡洛随机数

typedef long long lld;

class Solution {
    static const int N = 200010, M = 65, P = 16;
    int bit_count(int k) {
        int ret = 0;
        while (k) {
            ret += k%2;
            k /= 2;
        }
        return ret;
    }
public:
    int n, m, p;
    char str[N][M];
    int ans;
    bool ans_out[M];
    int dp[1<<P];
    int look(int k) { // 随机选择k
        int ret = 0, cnt = 0;
        for (int i = 0; i < m; ++i) {
            cnt += str[k][i] == '1';
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            if (i != k) {
                int state = 0;
                for (int j = 0; j < m; ++j) {
                    if (str[k][j] == '1') { // 离散化处理，将i与k的交集，用state来表示
                        state = state * 2 + (str[i][j] == str[k][j]);
                    }
                }
                ++dp[state];
            }
        }
        int max_state = (1<<cnt) - 1;
        ++dp[max_state]; // 最大的状态，就是所有的数字都选中，k是所有子集都有
        
        
        int tmp = 1;
        while (tmp <= max_state) { // tmp是每次转移的书籍，从最小的状态1开始，到2、4、8等，每次只能转移一个，避免重复
            int cur_state = max_state;
            while (cur_state > 0) {
                if (dp[cur_state] >= (n+1)/2) {
                    int cnt = bit_count(cur_state);
                    if (cnt > ans) { // 记录答案
                        ans = cnt;
                        int bit = 1;
                        for (int i = m - 1; i >= 0; --i) { // 注意这里是要逆序
                            if (str[k][i] == '0') {
                                ans_out[i] = false;
                            }
                            else {
                                ans_out[i] = bit & cur_state;
                                bit = bit * 2;
                            }
                        }
                    }
                }
                if (tmp & cur_state) {
                    dp[cur_state - tmp] += dp[cur_state];
                }
                --cur_state;
            }
            tmp = tmp * 2;
        }
        
        return ret;
    }
public:
    void solve() {
        cin >> n >> m >> p;
        for (int i = 0; i < n; ++i) {
            scanf("%s", str[i]);
        }
        
//        {
//            n = 200000;
//            m = p = 2;
//            for (int i = 0; i < n/2; ++i) {
//                memcpy(str[i], "11", 3);
//            }
//            memcpy(str[arc4random_uniform(n/2)], "10", 3);
//            for (int i = n/2; i < n; ++i) {
//                memcpy(str[i], "00", 3);
//            }
//        }
        
        ans = 0;
//        srand((unsigned long long)new char);
        for (int i = 0; i < 100; ++i) {
            look(rand()%n);
        }
        for (int i = 0; i < m; ++i) {
            cout << (ans_out[i]?"1":"0");
        }
        cout << endl;
    }
}
ac;


class SolutionB {
    static const int N = 200010, M = 65, P = 16;
    int n,p,m,b[65],res,ans[65],dp[1<<16],cnt[1<<16],pos[65]; char a[N][65];

public:
    void look(int id) {
        int idx=0; memset(b,-1,sizeof b); memset(dp,0,sizeof dp);
        for(int i=1;i<=m;i++) if(a[id][i]=='1') b[i]=idx,pos[idx++]=i;
        for(int i=1;i<=n;i++){
            int s=0;
            for(int j=1;j<=m;j++) if(a[i][j]!='0'&&b[j]!=-1) s|=(1<<b[j]);
            dp[s]++;
        }
        for(int i=0;i<p;i++)
            for(int j=0;j<(1<<p);j++) if(!(j>>i&1)) dp[j]+=dp[j|(1<<i)];
        for(int s=1;s<(1<<p);s++) if(dp[s]>=(n+1)/2&&cnt[s]>res){
            res=cnt[s];
            for(int j=1;j<=m;j++) ans[j]=(b[j]!=-1&&(s>>b[j]&1));
        }
    }
    
    void solve() {
        cin>>n>>m>>p;
        for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
        for(int i=1;i<(1<<p);i++) cnt[i]=cnt[i>>1]+(i&1);
        for(int i=1;i<=30;i++) look(rand()%n+1);
        for(int i=1;i<=m;i++) printf("%d",ans[i]);
    }
}
acB;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}

/**
 
 8 2 2
 11
 11
 00
 00
 10
 00
 00
 11
 
 
 6 5 4
 00000
 00000
 11000
 00111
 00111
 00101
 
 2 41 2
 00000000000000000000000000000000000000011
 00000000000000000000000000000000000000001
 
 8 60 15
 111111111111111000000000000000000000000000000000000000000000
 111111111111111000000000000000000000000000000000000000000000
 111111111111111000000000000000000000000000000000000000000000
 111111111111111000000000000000000000000000000000000000000000
 000000000000000000000000000000000000000000000000000000000000
 000000000000000000000000000000000000000000000000000000000000
 000000000000000000000000000000000000000000000000000000000000
 000000000000000000000000000000000000000000000000000000000000
 
 
 */
