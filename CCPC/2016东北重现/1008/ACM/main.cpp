//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright &#169; 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 给出一个栈，现在进行下面四种操作：
 ∙ PUSH x：push x（x只能是0或者1）到栈顶；
 ∙ POP： 弹出栈顶；
 ∙REVERSE： 反转栈，top变成bottom，bottom变成top；
 ∙QUERY：对top,top-1,top-2, ... , bottom 进行**NAND**操作，并输出结果（栈内数字不变）
 **NAND**的操作如下：
  0 nand 0 = 1∙
  0 nand 1 = 1∙
  1 nand 0 = 1∙
  1 nand 1 = 0.
 
 
 Sample Input
 2
 8
 PUSH 1
 QUERY
 PUSH 0
 REVERSE
 QUERY
 POP
 POP
 QUERY
 3
 PUSH 0
 REVERSE
 QUERY
 
 
 Sample Output
 Case #1:
 1
 1
 Invalid.
 Case #2:
 0
 
 
 题目解析：
 
 
 对于现在的栈T，从bottom往上算
 1、bottom=0，size>1则ans=1，否则为0；
 2、bottom=1，size=1,ans=1；
 size>1，假设连续的1个数为t，如果size-t<2,则这部分可以忽略；（因为可能为1个0，或者没有，都没影响）
 size-t>=2,则t=t+1;（长度加1）
 最后ans = (t+1)%2;
 
 
 每个值存三个信息，left, right, value.
 left表示连续的最左下标；
 right表示连续的最右下标；
 对于一段连续的1，只维护最左点的和最右点的信息即可；
 
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
const int N = 2100000, M = 33, inf = 0x7fffffff;

struct Node {
    int left, right, value;
    Node(int l, int r, int v)
    {
        left = l;
        right = r;
        value = v;
    }
    Node()
    {
        
    }
}node[N * 2];


int main(int argc, const char * argv[]) {
    // insert code here...
    lld t;
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        int n, isHead = 1, l = -1, r = -1;
        cin >> n;
        printf("Case #%d:\n", z);
        while (n--) {
            char op[20];
            scanf("%s", op);
            if (op[0] == 'P' && op[1] == 'U') {
                int k;
                scanf("%d", &k);
                if (l == -1) {
                    l = N;
                    r = N;
                    node[l].left = node[l].right = l;
                    node[l].value = k;
                }
                else {
                    if (isHead) {
                        if (k == node[l].value) {
                            node[l - 1].value = node[l].value;
                            node[l - 1].left = l - 1;
                            node[l - 1].right = node[l].right;
                            node[node[l].right].left = l - 1;
                        }
                        else {
                            node[l - 1].value = k;
                            node[l - 1].left = node[l - 1].right = l - 1;
                        }
                        --l;
                    }
                    else {
                        if (k == node[r].value) {
                            node[r + 1].value = node[r].value;
                            node[r + 1].right = r + 1;
                            node[r + 1].left = node[r].left;
                            node[node[r].left].right = r + 1;
                        }
                        else {
                            node[r + 1].value = k;
                            node[r + 1].left = node[r + 1].right = r + 1;
                        }
                        ++r;
                    }
                }
            }
            if (op[0] == 'R') {
                isHead = !isHead;
            }
            if (op[0] == 'Q') {
                if (l == -1) {
                    printf("Invalid.\n");
                }
                else if (l == r){
                    printf("%d\n", node[l].value);
                }
                else {
                    int ans;
                    if (isHead) { //从左到右算
                        if (node[r].value == 0) {
                            ans = 1;
                        }
                        else {
                            int len = node[r].right - node[r].left + 1;
                            if (r - l + 1 > len + 1) {
                                ++len;
                            }
                            ans = (len) % 2;
                        }
                    }
                    else {
                        if (node[l].value == 0) {
                            ans = 1;
                        }
                        else {
                            int len = node[l].right - node[l].left + 1;
                            if (r - l + 1 > len + 1) {
                                ++len;
                            }
                            ans = (len) % 2;
                        }
                    }
                    printf("%d\n", ans);
                }
                
            }
            if (op[0] == 'P' && op[1] == 'O') {
                if (r == l) {
                    r = l = -1;
                }
                else {
                    if (isHead) {
                        int k = node[l].value;
                        if (k == node[l + 1].value) {
                            node[l + 1].left = l + 1;
                            node[l + 1].right = node[l].right;
                            node[node[l].right].left = l + 1;
                        }
                        ++l;
                    }
                    else {
                        int k = node[r].value;
                        if (k == node[r - 1].value) {
                            node[r - 1].left = node[r].left;
                            node[r - 1].right = r - 1;
                            node[node[r].left].right = r - 1;
                        }
                        --r;
                    }
                }
            }
        }
    }
    
    
    return 0;
}
