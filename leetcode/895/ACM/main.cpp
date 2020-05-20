//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/maximum-frequency-stack/)
 **题目大意：**
 实现 FreqStack，模拟类似栈的数据结构的操作的一个类。

 FreqStack 有两个函数：

 push(int x)，将整数 x 推入栈中。
 pop()，它移除并返回栈中出现最频繁的元素。
 如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。

 >示例：
 输入：
 ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
 [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
 输出：[null,null,null,null,null,null,null,5,7,5,4]
 解释：
 执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

 pop() -> 返回 5，因为 5 是出现频率最高的。
 栈变成 [5,7,5,7,4]。

 pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
 栈变成 [5,7,5,4]。

 pop() -> 返回 5 。
 栈变成 [5,7,4]。

 pop() -> 返回 4 。
 栈变成 [5,7]。
  

 提示：

 对 FreqStack.push(int x) 的调用中 0 <= x <= 10^9。
 如果栈的元素数目为零，则保证不会调用  FreqStack.pop()。
 单个测试样例中，对 FreqStack.push 的总调用次数不会超过 10000。
 单个测试样例中，对 FreqStack.pop 的总调用次数不会超过 10000。
 所有测试样例中，对 FreqStack.push 和 FreqStack.pop 的总调用次数不会超过 150000。

  
 **题目解析：**
 
 每个数字出现的时候，计算下当前这个数字出现了几次，得到两个信息：value和count；
 
 假设当前有k个桶，桶1放count为1的数字，桶2放count为2的数字；
 
 比如说【5，7，5】第3个数字5，value=5，count=2，则放入桶2的末尾；
 
 pop的时候，找到当前出现的最后一个桶，把桶里最后一个元素拿出来，如果该桶空了，就pop掉。
 

 
 
 
 
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
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1

//
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        long long ans = 0, size = 0;
//        for (long long i = 0; i < height.size(); ++i)
//            for (long long j = i + 1;j < height.size(); ++j)
//                ans = max(ans, min(height[i], height[j]) * (j - i));
//        return ans;
//    }
//};
//
//
typedef long long lld;
const int N = 50000;

//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int ans = 0;
//        vector<pair<int, int> > vec;
//        vec.push_back(make_pair(height[0], 0));
//
//        for (int i = 1; i < height.size(); ++i) {
//            for (int index = 0; index < vec.size(); ++index) {
//                int width = i - vec[index].second;
//                int tmp = min(height[i], vec[index].first) * width;
//                ans = max(ans, tmp);
//            }
//
//            if (height[i] > vec.back().first) {
//                vec.push_back(make_pair(height[i], i));
//            }
//        }
//
//        return ans;
//    }
//
//}leetcode;


class FreqStack {
    vector<vector<int> > vec;
    unordered_map<int, int> cntMap; // 前面出现过的次数
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        int count = cntMap[x];
        if (vec.size() <= count) {
            vector<int> tmpVec;
            tmpVec.push_back(x);
            vec.push_back(tmpVec);
        }
        else {
            vec[count].push_back(x);
        }
        ++cntMap[x];
    }
    
    int pop() {
        int ret = vec.back().back();
        vec.back().pop_back();
        if (vec.back().empty()) {
            vec.pop_back();
        }
        cntMap[ret]--;
        return ret;
    }
    
}leetcode;

int main(int argc, const char * argv[]) {
    leetcode.push(1);
    leetcode.push(1);
    leetcode.push(1);
    leetcode.push(2);
    cout << leetcode.pop() << endl;
    cout << leetcode.pop() << endl;
    leetcode.push(2);
    leetcode.push(2);
    leetcode.push(1);
    cout << leetcode.pop() << endl;
    cout << leetcode.pop() << endl;
    cout << leetcode.pop() << endl;
    cout << leetcode.pop() << endl;
    
    
    return 0;
}
