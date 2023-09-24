//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1846/problem/F)
 **题目大意：**
 有n个人，每个人都有一个0~9的序号；这里面有个模仿者，他的序号可能会发生变化。
 小明想要找出来模仿者，游戏规则是这样：
 1、首先会给出n个整数，表示n个人的序号；
 2、小明可以挑选若干个人（可以是0个），如果这些人不包括模仿者，系统会移除选中的人；
 3、剩下的人顺序会打乱，此时模仿者的序号可能会变成0~9任意中一个，注意模仿者最多连续两次保持同一个数字；接着进入步骤2；
 4、小明在游戏过程中，可以随时指定某个位置的人为模仿者；
 
 如果小明在步骤2挑选到模仿者，则游戏失败；
 如果小明在步骤2执行超过5次，则游戏失败；
 如果小明在步骤4挑选到正确模仿者，则游戏胜利；如果在步骤4挑选错误，则游戏失败。
 
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例第一行整数𝑛 (1≤𝑛≤200).
 接下来一行n个整数 𝑎1 ,𝑎2 ,...,𝑎𝑛  (1≤𝑎𝑖≤9)
 
 **输出：**
 如果小明要执行操作2，则输出-开头，然后输出移除人数m，接下来是m个整数，表示要移除人数的位置；（移除之后，操作3会输出剩下人数的序号）
 如果小明要执行操作4，则输出!开头，然后输出模仿者的位置；
 
 **Examples**
 **input**
 3
 5
 1 1 2 2 3

 2 1 1 2

 2 2 2

 2

 8
 1 2 3 4 3 4 2 1

 4 3 4 3 2 2 1 3
  
 2 3 3 2

 5 3 2

 2 5

 15
 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1

 1 2 3 4 5 6 7 8 7 9 5 4 3 2 1


 **output**
- 1 5

- 1 3

- 2 1 2

! 1


- 0

- 4 1 3 7 8

- 1 4

- 1 2

! 2


- 0

! 10



 **题目解析：**
 从操作1给出的初始信息，我们并不能马上确定模仿者；
 那么在进行操作2就要慎重，因为有可能选择到模仿者；
 我们利用模仿者最多连续2个回合保持相同数字的规则，先按兵不动，直到模仿者改变序号，那么我们遍历数组就可以知道哪个整数增加了，这个整数必然是模仿者所在整数；
 如果这个整数只有1个，那么找到模仿者，游戏结束；
 如果这个整数有多个，那么就把这个整数之外的数字移除，接着按兵不动，直到模仿者变化出新的数字。
 

 
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
 
class Solution {
    static const int N = 10;
    int a[202];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            
            vector<int> cnt(N, 0);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                cnt[a[i]]++;
            }
            
            cout << "- 0" << endl; // don't move
            do {
                int check = 0;
                vector<int> change(N, 0);
                for (int i = 0; i < n; ++i) {
                    cin >> a[i];
                    change[a[i]]++;
                }
                for (int i = 1; i < N; ++i) {
                    if (change[i] > cnt[i]) check = i;
                }
                // 直到变化
                if (check) {
                    if (change[check] == 1) {
                        for (int i = 0; i < n; ++i) if (a[i] == check) cout << "! " << i + 1 << endl;
                        break;
                    }
                    else {
                        vector<int> out;
                        for (int i = 0; i < n; ++i) {
                            if (a[i] != check) out.push_back(i + 1);
                        }
                        cout << "- " << out.size();
                        for (int i = 0; i < out.size(); ++i) cout << " " << out[i];
                        cout << endl;
                        n -= out.size();
                    }
                    for (int i = 0; i < N; ++i) if (i != check) cnt[i] = 0;
                    cnt[check] = change[check];
                }
                else {
                    cout << "- 0" << endl; // don't move
                }
                
            } while (true);
        }
        cout.flush();
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
