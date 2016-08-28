//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/706/problem/E
 题目大意：N*M的矩阵，共有q个询问，每次输入 ai, bi, ci, di, hi, wi, 表示起点为（a，b）和（c，d）的两个大小为（w，h）的矩阵进行交换；最后输出变换后矩阵。（两个子矩阵不重叠、没有相交的点） (2 ≤ n, m ≤ 1000, 1 ≤ q ≤ 10 000)
 题目解析：
 因为子矩阵不相交，先看看暴力的做法。
 a[N][M]的数组存矩阵，对每个子矩阵的点，交换一遍；复杂度O(NMQ)。
 题目中的N*M*Q = 10 ^ 10，不可行。
 
 先看一行的情况
 假设有8个数字
 1，2，3，4，5，6，7，8
 要交换[2,3]和[5,6]，正常的做法是把2的值赋值为5，5的值赋值为2，3的值赋值为6，6的值赋值为3；
 很容易想到，这个是数组的做法。
 如果是链表的方式，那么只需把1的下一个指针 和 4的下一个指针交换，3的下一个指针交换和6的下一个指针交换，即可得到交换后的序列。
 交换的时间是O(1)，查找的时间是O（N）。
 对于矩阵，复杂度为O（NQ）= 10^7，可以接受。
 
 具体细节：
 每个点，一个bottom指向下面的点，一个right指向右边的点，那么一个3*3子矩阵需要修改的边如下：
 *TTT*
 L000R
 L000R
 L000R
 *BBB*
 
 为了防止修改过程中，再次遍历节点时导致点位置发生变化。
 用stack把需要修改的点存下来。
 最后再统一进行修改即可。
 
 
 
 
 TLE之后，查看了别人的做法，发现大同小异。
 看起来要进行常数级别的优化，把cin改成scanf，果然就过了。
 
 S###*
 #000#
 #000#
 #000#
 *###0
 
 可以优化的地方：遍历的时候，根据S的位置，绕着矩阵遍历一遍即可。
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
const int N = 1010, M = 1010, inf = 10110110;

struct Node {
    int value;
    Node *right, *bottom;
}node[N][M];
vector<Node*> stacks1[4];
vector<Node*> stacks2[4];

void changeTwoNodeRight(Node *p1, Node *p2) {
    Node *tmp = p1->right;
    p1->right = p2->right;
    p2->right = tmp;
}
void changeTwoNodeBottom(Node *p1, Node *p2) {
    Node *tmp = p1->bottom;
    p1->bottom = p2->bottom;
    p2->bottom = tmp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &node[i][j].value);
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            node[i][j].right = &node[i][j + 1];
            node[i][j].bottom = &node[i + 1][j];
        }
    }
    
    while (q--) {
        int x1, y1, x2, y2, h, w;
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
        
        for (int i = 0; i < 4; ++i) {
            stacks1[i].clear();
            stacks2[i].clear();
        }
        Node *p1, *p2;
        // 1
        p1 = &node[x1][0];
        for (int i = 1; i < y1 + w; ++i) {
            p1 = p1->right;
        }
        p2 = &node[x2][0];
        for (int i = 1; i < y2 + w; ++i) {
            p2 = p2->right;
        }
        for (int i = 0; i < h; ++i) {
            //            changeTwoNodeRight(p1, p2);
            stacks1[0].push_back(p1);
            stacks2[0].push_back(p2);
            p1 = p1->bottom;
            p2 = p2->bottom;
        }
        
        // 2
        p1 = &node[0][y1];
        for (int i = 1; i < x1 + h; ++i) {
            p1 = p1->bottom;
        }
        p2 = &node[0][y2];
        for (int i = 1; i < x2 + h; ++i) {
            p2 = p2->bottom;
        }
        for (int i = 0; i < w; ++i) {
            //            changeTwoNodeBottom(p1, p2);
            stacks1[1].push_back(p1);
            stacks2[1].push_back(p2);
            p1 = p1->right;
            p2 = p2->right;
        }
        
        // 3
        p1 = &node[x1][0];
        for (int i = 1; i < y1; ++i) {
            p1 = p1->right;
        }
        p2 = &node[x2][0];
        for (int i = 1; i < y2; ++i) {
            p2 = p2->right;
        }
        for (int i = 0; i < h; ++i) {
            //                changeTwoNodeRight(p1, p2);
            stacks1[2].push_back(p1);
            stacks2[2].push_back(p2);
            p1 = p1->bottom;
            p2 = p2->bottom;
        }
        
        // 4
        p1 = &node[0][y1];
        for (int i = 1; i < x1; ++i) {
            p1 = p1->bottom;
        }
        p2 = &node[0][y2];
        for (int i = 1; i < x2; ++i) {
            p2 = p2->bottom;
        }
        for (int i = 0; i < w; ++i) {
            //                changeTwoNodeBottom(p1, p2);
            stacks1[3].push_back(p1);
            stacks2[3].push_back(p2);
            p1 = p1->right;
            p2 = p2->right;
        }
        
        for (int i = 0; i < h; ++i) {
            changeTwoNodeRight(stacks1[0][i], stacks2[0][i]);
            changeTwoNodeRight(stacks1[2][i], stacks2[2][i]);
        }
        
        for (int i = 0; i < w; ++i) {
            changeTwoNodeBottom(stacks1[1][i], stacks2[1][i]);
            changeTwoNodeBottom(stacks1[3][i], stacks2[3][i]);
        }
        
    }
    
    
    for (int i = 1; i <= n; ++i) {
        Node* tmp = node[i][0].right;
        for (int j = 1; j <= m; ++j) {
            cout << tmp->value << " ";
            tmp = tmp->right;
        }
        cout << endl;
    }
    
    return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct dl{
    int v;
    dl *d,*r;
}e[N][N];

int main(){
    int n,m,q,i,j,a,b,c,d,s,t;
    dl *x,*y,*u,*v;
    cin>>n>>m>>q;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            scanf("%d",&e[i][j].v);
    for(i=0;i<=n;++i)
        for(j=0;j<=m;++j)
            e[i][j].d= &e[i+1][j],e[i][j].r= &e[i][j+1];
    while(q--){
        x= y= &e[0][0];
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&s,&t);
        while(--a)x= x->d;
        while(--b)x= x->r;
        while(--c)y= y->d;
        while(--d)y= y->r;
        u = x,v= y;
        for(i=0;i<s;++i)
            u= u->d,v= v->d,
            swap(u->r,v->r);
        for(i=0;i<t;++i)
            x= x->r,y= y->r,
            swap(x->d,y->d);
        for(i=0;i<t;++i)
            u= u->r,v= v->r,
            swap(v->d,u->d);
        for(i=0;i<s;++i)
            x= x->d,y= y->d,
            swap(x->r,y->r);
    }
    x= &e[0][0];x= x->d;
    for(i=0;i<n;++i){
        y= x;
        for(j=0;j<m;++j)
            y= y->r,printf("%d ",y->v);
        putchar('\n');
        x= x->d;
    }
}
*/