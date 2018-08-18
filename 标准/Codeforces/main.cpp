//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/746/problem/A)
 **题目大意：**
 1、整数求出1的数字
 2、二叉树的深度
 3、Https
 4、DNS劫持
 5、property；
 6、category属性；
 7、iOS装载；
 
 流程。
 
 1、职责；
 2、什么部门过来；
 3、薪酬；
 4、工时；

 snapchat  +  glass
 括号匹配
 CoreCemara Team
 10 -
 英文
 Snap 
 
 
 // snap app；合作关系；相机；feature划分；
 // 福田；嘉里建设广场
 //
 拓扑排序
 
 输入：
 输出：
 
 **Examples**
 **input**
 **output**
 
 **题目解析：**
 
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

// android，硬件
// Camera，性能
// 用户新增、留存
// 图片质量、自动化、标准

// 底层架构，performance；video；image 拍照
// 曝光、人脸、抠像、

// 出差；项目需求驱动；设计、研究人员对接；
// 深圳偏工程；

// 

int s[N], d[N];
int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    /*
     2
     3
     8:00 9:00
     11:00 12:00
     14:00 15:00
     
     2
     10:00 11:00
     17:00 18:00
     */
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x, y;
            scanf("%d:%d", &x, &y);
            x -= 8;
            s[x * 60 + y]++;
            scanf("%d:%d", &x, &y);
            x -= 8;
            d[x * 60 + y]--;
        }
    }
    
    a[0] = s[0];
    for (int i = 1; i <= 60 * 10; ++i) {
        a[i] = a[i - 1] + s[i] + d[i];
    }
    a[60 * 10 + 1] = 1;
    int cur = 0;
    for (int i = 1; i <= 60 * 10 + 1; ++i) {
        if (a[i] == 0 && a[i - 1] != 0) {
            cur = i;
        }
        if (a[i] != 0 && a[i - 1] == 0 && cur != i - 1) {
            printf("%d:%02d - %d:%02d\n", cur / 60 + 8, cur % 60, (i - 1) / 60 + 8, (i - 1) % 60);
        }
    }
    
    return 0;
}
