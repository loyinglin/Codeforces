//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 题目解析：
 
 max：即代码中 val 变量，它表示该状态能够接受的最长的字符串长度。
 min：表示该状态能够接受的最短的字符串长度。实际上等于该状态的 par 指针指向的结点的 val + 1。
 max-min+1：表示该状态能够接受的不同的字符串数。
 right：即 end-set 的个数，表示这个状态在字符串中出现了多少次，该状态能够表示的所有字符串均出现过 right 次。
 par：par 指向了一个能够表示当前状态表示的所有字符串的最长公共后缀的结点。所有的状态的 par 指针构成了一个 parent 树，恰好是字符串的逆序的后缀树。
 parent 树的拓扑序：序列中第i个状态的子结点必定在它之后，父结点必定在它之前。
 
 
 SAM 的状态要多维护两个信息：lcs，当多个串的最长公共子串的最后一个字符落在该状态上的长度；nlcs，当前串的最长公共子串的最后一个字符落在该状态上的长度。
 ************************* 题解 ***********************/
#include<iostream>
using namespace std;
const int N = 101010;
int NEXT[N],extand[N];
void getNEXT(char *T){// NEXT[i]: 以第i位置开始的子串 与 T的公共前缀
    int i,length = strlen(T);
    NEXT[0] = length;
    for(i = 0;i<length-1 && T[i]==T[i+1]; i++);
    NEXT[1] = i;
    int a = 1;
    for(int k = 2; k < length; k++){
        int p = a+NEXT[a]-1, L = NEXT[k-a];
        if( (k-1)+L >= p ){
            int j = (p-k+1)>0? (p-k+1) : 0;
            while(k+j<length && T[k+j]==T[j]) j++;// 枚举(p+1，length) 与(p-k+1,length) 区间比较
            NEXT[k] = j, a = k;
        }
        else NEXT[k] = L;
    }
}
void getextand(char *S,char *T){
    memset(NEXT,0,sizeof(NEXT));
    getNEXT(T);
    int Slen = strlen(S), Tlen = strlen(T), a = 0;
    int MinLen = Slen>Tlen?Tlen:Slen;
    while(a<MinLen && S[a]==T[a]) a++;
    extand[0] = a, a = 0;
    for(int k = 1; k < Slen; k++){
        int p = a+extand[a]-1, L = NEXT[k-a];
        if( (k-1)+L >= p ){
            int j = (p-k+1)>0? (p-k+1) : 0;
            while(k+j<Slen && j<Tlen && S[k+j]==T[j] ) j++;
            extand[k] = j;a = k;
        }
        else extand[k] = L;
    }
}

int main(){
    // insert code here...
    //    freopen("input.txt", "w", stdout);
    //    for (int i = 0; i < 250000; ++i) {
    //        putchar(arc4random_uniform(26) + 'a');
    //    }
    //    cout << endl;
    //    for (int i = 0; i < 250000; ++i) {
    //        putchar(arc4random_uniform(26) + 'a');
    //    }
    //    return 0;
    //    freopen("input.txt", "r", stdin);
    
    char s[N],t[N];
    while(~scanf("%s %s",s,t)){
        getextand(s,t);
        
        for(int i = 0; i < strlen(s); i++)
            printf("%d %d\n", i + 1, extand[i]);
        puts("");
    }
}

