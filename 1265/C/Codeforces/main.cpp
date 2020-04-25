//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1265/problem/C)
 **题目大意：**
 金银铜铁，g
 
 输入：
 
 输出：

 
 input
 
 output
 
 
 **题目解析：**
 金银铜铁，共需要4个分数；
 金牌人数要少于银牌和铜牌；
 金银铜加起来不超过一半；
 希望获奖的人尽可能多；
 
 将数字去重，按照数字大小排序，每个数字有一个权值，权值就是人数；
 相当于把数组切分成a、b、c、d共4段，要求sum(a)<sum(b) & sum(a)<sum(b)，并且sum(a+b+c)尽可能的大，又不超过权值总和的1/2；
 
 假设新的数组排序之后是s[1~m]
 从题目的要求来分析，s[1]是分给金牌，s[2~x]分给银牌，x的求法就是直接遍历，累计银牌人数大于金牌；
 同理，铜牌的人数也要大于金牌，然后就可以不断遍历，只要满足s[1], s[2], s[3] 之和小于n/2；
 剩下所有人分给铜牌。
 
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
const int N = 501000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

map<int, int> h;
vector<int> s;

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        h.clear();
        while (!s.empty()) {
            s.pop_back();
        }
        
        for (int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &k);
            ++h[k];
        }
        for (map<int, int>::iterator iter = h.begin(); iter != h.end(); ++iter) {
//            cout << iter->first << " " << iter->second << endl;
            s.push_back(iter->second);
        }
        
        int ans[3] = {0};
        
        if (s.size() >= 4) {
            int x = s.back();
            s.pop_back();
            
            int y = 0;
            while (x >= y && !s.empty()) {
                y += s.back();
                s.pop_back();
            }
         
            int z = 0;
            while (x >= z && !s.empty()) {
                z += s.back();
                s.pop_back();
            }
            
            while (x + y + z <= n / 2) {
                ans[0] = x;
                ans[1] = y;
                ans[2] = z;
                
                if(s.empty()) {
                    break;
                }
                z += s.back();
                s.pop_back();
            }
        }
        
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
           
    
    return 0;
}


/**
 
 */
