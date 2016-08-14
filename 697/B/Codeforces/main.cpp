//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 
 题目链接：http://codeforces.com/contest/697/problem/B
 题目大意：输入一个科学计数法的数字，输出一个十进制计数的数字。
 比如
 输入8.549e2，输出854.9；
 输入8.549e3，输出8549；
    
 题目解析：
 科学计数法的e，如果不为零，那么会对小数点的位置造成影响，比如：整数部分存在前导零、小数部分全部为零、整数小数部分全部为零的情况；
 对着多种情况进行分类讨论即可。
 
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
const int N = 10100, M = 3010100, inf = 10110110;

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
char str[N];

int main(int argc, const char * argv[]) {
    // insert code here...
   
    int a, b;
    scanf("%s", str);
    
    sscanf(str, "%d", &a);
    
    int p = 0;
    while (str[p] != 'e') {
        ++p;
    }
    sscanf(str + p + 1, "%d", &b);
    
    p = 0;
    while (str[p] != '.') {
        ++p;
    }
    
    while (b && str[p + 1] != 'e') { // 小数点右移
        --b;
        char tmp = str[p];
        str[p] = str[p + 1];
        str[p + 1] = tmp;
        ++p;
    }
    if (b > 0) {
        while (b--) {
            str[p++] = '0';
        }
        str[p] = '.';
        str[p + 1] = 'e';
    }
    
    int start = 0;
    while (str[start] == '0') { // 去掉前导零
        ++start;
    }
    if (str[start] == '.') { // 前面全部为零
        --start;
    }
    int end = 0;
    while (str[end] != 'e') {
        ++end;
    }
    if (str[end - 1] == '0') { // e前面是点，去掉小数部分
        --end;
    }
    
    if (str[end - 1] == '.') { // e前面是点，去掉小数部分
        --end;
    }
    
    
    if (str[start] == '0' && str[end - 1] == '0') {
        end = start + 1;
    }
    
    for (int i = start; i < end; ++i) {
        putchar(str[i]);
    }
    
    
    return 0;
}



/*
 
 #include<bits/stdc++.h>
 int main(){
 int a,l,b;
 char d[101];
 scanf("%d.",&a);
 scanf("%[^e]%ne%d",d,&l,&b);
 if(l==1&&d[0]==48&&!b)
 printf("%d\n",a);
 else if(b>=l)
 printf("%d%s%.*d\n",a,d,b-l,0);
 else
 printf("%d%.*s.%s\n",a,b,d,d+b);
 }
 
 
 */
