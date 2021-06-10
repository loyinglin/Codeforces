//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1519/problem/A)
 **题目大意：**
 有n个学生想参加比赛，每个学生都有一个自己的学校u[i]，以及能力强度s[i]；
 现在已知，假如主办方决定队伍人数是k人一队，则每个学校会按照能力高低，从高开始组队（k个人一队），如果剩余不足k人，则放弃；
 问：当k=1、2、3... k的时候，能参加比赛的人，总的能力强度分别是多少。
 
 **输入：**
 第一行整数t，表示有t个样例（1≤𝑡≤1000）
 每个样例两行，第一行是整数n，表示字符串长度 (1≤𝑛≤50)
 第二行是字符串
 **输出：**
 
 
 **Examples**
 **input**

 
 **output**

 
 **题目解析：**
 先按照学校分类，然后排期得到每个学校能力从小到大的数据； => 复杂度O（NlogN），极端情况所有人都是同一个学校。
 接下来计算k=1.2.3....n的时候，所有学生的能力值。
 对于某个学校（学生人数是count[i]），我们知道最终无法组成队伍的人有count[i]%k，也就是前k个；
 那么对于k=t，将所有学校排序后的前(count[i]%t)数字累加起来，就是所有无法参加比赛人之和。
 
 注意：
 由于k很多种情况，学校也可能有很多个，这里需要注意实现方式，否则很容易超时。
 1、只枚举存在的学校；（不需要从1到n去枚举，这个通过map可以实现）
 2、每个学校，在枚举k=1.2.3...n的时候，只需要考虑到k=学校人数即可；（由于所有学校的总人数=n，所以k枚举的总次数=n）
 
 
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
    static const int N =200010;
public:
    int n, m;
    int u[N], s[N];
    lld ans[N], sum[N];
    map<int, vector<lld>> h;
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            h.clear();
            for (int i = 0; i < n; ++i) {
                cin >> u[i];
                ans[i+1] = 0;
                sum[i+1] = 0;
            }
            for (int i = 0; i < n; ++i) {
                cin >> s[i];
                sum[u[i]] += s[i];
                h[u[i]].push_back(s[i]);
            }
            
            for (map<int, vector<lld>> ::iterator it = h.begin(); it != h.end(); ++it) {
                sort(it->second.begin(), it->second.end());
                
                vector<lld> tmp;
                tmp.push_back(0);
                for (int i = 1; i <= it->second.size(); ++i) {
                    ans[i] += sum[it->first];
                    tmp.push_back(tmp[i-1] + it->second[i-1]);
                    if (it->second.size()%i) {
                        ans[i] -= tmp[it->second.size() % i];
                    }
                    
                }
            }
            for (int i = 1; i <= n; ++i) {
                cout << ans[i] << " ";
            }
            cout << endl;
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
 inputCopy
 4
 7
 1 2 1 2 1 2 1
 6 8 3 1 5 1 5
 10
 1 1 1 2 2 2 2 3 3 3
 3435 3014 2241 2233 2893 2102 2286 2175 1961 2567
 6
 3 3 3 3 3 3
 5 9 6 7 9 7
 1
 1
 3083
 
 outputCopy
 29 28 26 19 0 0 0
 24907 20705 22805 9514 0 0 0 0 0 0
 43 43 43 32 38 43
 3083
 */
