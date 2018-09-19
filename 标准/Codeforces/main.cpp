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
 
 // 数字连续区间，上升区间；
 // rand算法
 
 // 外企更重视的是面对问题，如何抽丝剥茧，逻辑化的去思考；
 // 国内企业问，知不知道一个问题；国外企业问，面对不知道的问题你是如何思考、解决；
 
 
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

/*
 硅谷公司
 有机会来自全球各地的工程师交流
 英文的交流
 
 快，人力成本，试错成本低；
 人，珍惜时间，技术要求改；
 snap压力大；
 
 
 
 
 */

int s[N], d[N];
int a[N];
pair<int, int> ans[N];
int vis[N];
int len[N];
int n, k;

void look(vector<int> ans, int sum, int index) {
    // 1.take
    ans.push_back(a[index]);
    if (sum + a[index] == k) {
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        
        cout << " " << endl;
    }
    if (index + 1 < n) {
        look(ans, sum + a[index], index + 1);
    }
    
    // 2.not take
    ans.pop_back();
    if (index + 1 < n) {
        look(ans, sum, index + 1);
    }
    
}

//


int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*
     8 10
     2 4 3 5 7 6 8 9
     
     
     6 6
     2 3 1 4 6 2
     */
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ans;
    look(ans, 0, 0);
    
    return 0;
}
