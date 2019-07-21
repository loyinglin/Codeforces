//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1185/problem/D)
 **题目大意：**
 n个人参加测试，测试需要老师和学生一对一进行，同一时刻只能有一个学生在测试，每个人测试的耗时不同；
 现在按照顺序进行测试，已知测试的总时间为m，每个人的测试时间为t[i]；
 想要知道对于第i个人，最少需要直接淘汰前面多少个人，才能有足够的时间让其能在规定时间m内完成测试；（每个人是相对独立的，对于第i个人和第i+1个人，淘汰的人可能各不相同）
 
 输入：
 第一行两个整数𝑛 and 𝑀，分别表示n个人和测试总时间M (1≤𝑛≤2⋅1e5, 1≤𝑀≤2⋅1e7)
 第二行是n个整数t[i]，分别表示n个人的测试时间。(1≤𝑡[𝑖]≤100)
 
 输出：
 对于每个人，输出通过测试，需要淘汰的最少人数；
 
 Examples
 input
 7 15
 1 2 3 4 5 6 7
 output
 0 0 0 0 0 2 3
 
 样例解释：
 对于前5个人，都不需要淘汰人即可完成测试；
 对于第6个人，可以淘汰第3、4个人，剩下的人可以完成测试；
 对于第7个人，可以淘汰第3、4、5个人，剩下的人可以完成测试；
 
 
 
 **题目解析：**
 相对上一题，这里的数据量更加大。如果再每次排序，复杂度会到达O(N^2logN)的级别。
 这里可以用优先队列来进行优化：
 维持两个队列，一个是大顶堆top_queue，表示所有已经选中参加考试的人的耗时；
 一个是小顶堆tmp_queue，表示所有已经没有被选中参加考试的人的耗时；
 从左到右遍历每个人，对于第i个人，如果top_queue中所有人的耗时加上a[i]，仍小于等于m，则答案为tmp_queue的size；
 如果top_queue中所有人的耗时加上a[i]大于m，则表示top_queue中的人某些人需要被淘汰；
 我们从耗时最长的人开始淘汰，直到top_queue的总耗时+a[i]<=m，淘汰的人都放入tmp_queue，此时答案为tmp_queue的size；

 在得到第i个人的耗时之后，将a[i]放入tmp_queue，然后不断从tmp_queue取出最小值x，如果top_queue的总耗时+x<=m，则可以把x放入top_queue。
 
 对于第i个人，top_queue 相当于前i-1个人中，总耗时不大于m的集合，top_queue.top为耗时最长的人；
 tmp_queue 表示没被选中人的集合，tmp_queue.top为耗时最短的人；
 
 这个解决理论上是OK的，但是在case13会遇到RunTime Error，比较奇怪；最后查出来是数组越界，但是RE报错在一些完全无关的地方。
 fix这个bug之后，顺利通过。
 
 
 观察题目的数据范围，发现每个人的分数范围是[1, 100]，那么可以用一个人数组来做聚合，避免重复的排序。
 a[i] 表示分数为i的人数；
 对于第i个人，假设其耗时是k，总耗时不能超过m，那么其他人的耗时是left_time=m-k；
 从1~100去遍历分数，对于分数为i的人数有a[i]个；
 int t = min(a[j], left_time / j);
 cnt += t;
 left_time -= t * j;
 我们选中了t个分数为i的人。
 从小到大遍历一次，相当于我们从分数小的开始选，一直到不能选为止，得到总耗时不超过(m-k)的有cnt个人。
 那么答案就是剩下的人。
 
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

priority_queue<int> top_queue;
priority_queue<int, vector<int>, greater<int> > tmp_queue;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        int ans;
        if (sum + t <= m) {
            top_queue.push(t);
            sum += t;
            ans = (int)tmp_queue.size();
        }
        else {
            while (top_queue.size() && sum + t > m) {
                int k = top_queue.top();
                tmp_queue.push(k);
                sum -= k;
                top_queue.pop();
            }
            ans = (int)tmp_queue.size();
            tmp_queue.push(t);
            
            while (!tmp_queue.empty() && sum + tmp_queue.top() <= m) {
                int k = tmp_queue.top();
                tmp_queue.pop();
                top_queue.push(k);
                sum += k;
                if (top_queue.size() >= n) {
                    break;
                }
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    
    
    
//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < n; ++i) {
//        int k;
//        cin >> k;
//        int left_time = m - k;
//        int cnt = 0;
//        for (int j = 1; j <= 100; ++j) {
//            if (left_time && a[j]) {
//                int t = min(a[j], left_time / j);
//                cnt += t;
//                left_time -= t * j;
//            }
//        }
//        ++a[k];
//        cout << i - cnt << " ";
//    }
//
//    cout << endl;
//
    
    
    
    return 0;
}
