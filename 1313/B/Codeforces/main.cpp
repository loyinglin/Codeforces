//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1313/problem/B)
 **题目大意：**
 n个人参加比赛，比赛分上半场和下半场，分别会产生1~n的名次；（没人并列）
 最终的比赛排名，是根据两场比赛的名次之和进行排列；
 比如说小明参加5个人的比赛，上半场和下半场分别拿了第1名和第3名，名次之和是4，那么有两种可能性，
 最好的情况：
 最坏的情况：
 
 
 现已知小明的上下半场的名次分别是x和y，最好和最坏的名次，分别是多少？
 
 
 **输入：**
  第一行，整数𝑡，表示样例个数 (1≤𝑡≤100)
  接下来t行，每行有整数𝑛, 𝑥, 𝑦 (1≤𝑛≤10^9, 1≤𝑥,𝑦≤𝑛)
 
 **输出：**
 每个样例一行，两个整数，分别表示最好和最坏的名次
  
 **Examples**
 input
 1
 5 1 3
 output
 1 3
 
 
 
 **题目解析：**
 分两种情况来考虑，先看名次最好的情况；（a、b顺序没有关系，我们另a<b）
 假设n个人，小明的名次是a+b，那么应该尽量安排其他人的名次>=a+b+1，我们另k=a+b+1；
 k<=n的时候，其他人可以一大一小（n配1、n-1配2这样)，那小明最好的名次是1；
 如果k>n的时候，有k-n-1个人，肯定无法分配使得名次比小明差，我们把这些人提取出来，小配小，比如说1配1，2配2；（贪心的思想）
 又因为小明本身占用了名次a和b，如果b还在剩下的名次里面，还要占用一个名额，小明最好的名次是k-n-1-1；如果b<k-n，则不需要关注，此时名次是k-n-1;
 
 如果是名次最差的情况，那么只需要尽可能分配其他的名次，使得名次之和大于等于小明；
 小明的名次之和是k=a+b，如果k>n，则必然是最后一名；（其他人可以1配n，2配n-1这样）
 如果k<n，最多只能找到(n-k-2)个人，名次组合和小明一样；（假如8个人，小明是2+3，那么必然是1+4，3+2，4+1）
 那么小明就是k-1名；
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];
int a[N];

bool cmp(int a, int b) {
    return a > b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        int ansFirst, ansLast;
        int k = a + b + 1;
        if (k <= n) {
            ansFirst = 1;
        }
        else {
            ansFirst = k - n - 1;
            if (b >= k - n) {
                ++ansFirst;
            }
        }
        
        int x = a + b;
        if (x > n) {
            ansLast = n;
        }
        else {
            ansLast = x - 1;
        }
        
        cout << ansFirst << " " << ansLast << endl;
    }
    
    
    return 0;
}
