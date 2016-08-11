//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
    题目链接：http://codeforces.com/contest/702/problem/B
    题目大意：给出n个数字，寻找a[i] + a[j] = 2^x，并且i < j。算出总共有多少对存在？
    题目解析：
 对数组进行从小到大排序，假设有a[i] + a[j] = 2 ^x，并且i < j，x为大于a[j]的最小的2的幂。
 那么在[1, j - 1]的区间内，不存在a[i] + a[j] = 2 ^ (x - 1)和 a[i] + a[j] = 2 ^ (x + 1)。
 故而排序后，对于a[j]，只要求出值为(2^x - a[j])的区间即可。用二分查找。


************************* 题解 ***********************/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 200000

struct Node {
    int value, pos;
    
    bool operator<(const Node &tmp) const
    {
        return value < tmp.value;
    };
}node[N];
long long a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
   
    long long n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        long long k = 1;
        while (k <= a[i]) {
            k = k << 1;
        }
        k -= a[i];
        
        long long left = 0, right = i - 1;
        long long l = left, r = right;
        while (left < right) { // 寻找 == k的左边界
//            printf("%d %d %d \n", i, left, right);
            long long mid = (left + right) / 2;
            if (a[mid] > k) {
                right = mid - 1;
            }
            else if (a[mid] < k) {
                left = mid + 1;
            }
            else {
                l = mid;
                right = mid;
            }
        }
//        printf("%d %d %d \n ------ \n", i, left, right);
        if (a[left] == k) {
            l = left;
        }
        left = 0;
        right = i - 1;
        while (left < right) { //选择 == k的右边界
//            printf("%d %d %d \n", i, left, right);
            long long mid = (left + right) / 2;
            if (a[mid] > k) {
                right = mid - 1;
            }
            else if (a[mid] < k) {
                left = mid + 1;
            }
            else {
                r = mid;
                left = mid + 1;
            }
        }
//        printf("%d %d %d \n", i, left, right);
        if (a[right] == k) {
            r = right;
        }
        
        if (a[l] == k && a[r] == k && r >= l) {
            count += r - l + 1;
//            if (a[l] == a[i]) {
//                --count; // 排除自己
//            }
        }
    }
    cout << count << endl;
    
    return 0;
}


//#include <map>
//map<int,int> M;
//long long ans=0;
//int main(){
//    int n,a;
//    cin>>n;
//    while(n--){
//        cin>>a;
//        for(int i=0;i<=31;i++)	ans+=M[(1LL<<i) - a];
//        M[a]++;
//    }
//    cout<<ans;
//}