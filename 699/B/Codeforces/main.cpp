//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/699/problem/B
 题目大意：n * m的棋盘上若干点  找一个点 横竖能覆盖所有点。
 题目解析：
 方法1：假设所有点符合，每遇到一个点，把不符合的去掉；
 
 方法2：假设某一点符合，求这一个点覆盖的点数是否包括其他所有需要覆盖的点；
 
 
 ************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

#define N 200200

struct Node {
    int x, y;

    bool operator<(const Node &tmp) const
    {
        if (tmp.x == x) {
            return tmp.y < y;
        }
        else {
            return tmp.x < x;
        }
    };
    bool operator==(const Node &tmp) const
    {
        return x == tmp.x && y == tmp.y;
    };
}node[N];
set<Node> nodes;
long long a[N];
char str[2002][2002];

int main(int argc, const char * argv[]) {
    // insert code here...

    long long n, m, OK = 1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }

    for (int i = 0; i < n && OK; ++i) {
        for (int j = 0; j < m && OK; ++j) {
            Node tmp;
            tmp.x = i;
            tmp.y = j;
            nodes.insert(tmp);
        }
    }


    for (int i = 0; i < n && OK; ++i) {
        for (int j = 0; j < m && OK; ++j) {
            if (str[i][j] == '*') {
                set<Node>::iterator it = nodes.begin();
                while (it != nodes.end()) {
                    if (it->x == i || it->y == j) {
                        ++it;
                    }
                    else {
                        nodes.erase(it++);
                    }
                }
                if (nodes.size() == 0) {
                    OK = 0;
                }
            }
        }
    }

    if (OK) {
        cout << "YES" << endl;
        cout << nodes.begin()->x + 1 << " " << nodes.begin()->y + 1 << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}

/*
#include<iostream>
using namespace std;
int i,j,a[1005],b[1005],k,s,n,m;
int main(){
    char c[1005][1005];
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>c[i][j];
            if(c[i][j]=='*'){
                k++;
                a[i]++;
                b[j]++;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) {
            s=a[i]+b[j];
            if(c[i][j]=='*'){
                s--;
            }
            if(s==k) {
                cout<<"YES"<<endl<<i+1<<" "<<j+1;
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}
 */



