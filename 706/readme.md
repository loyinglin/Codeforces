###前言
>最近来公司面试的开发者很多，经验从1、2年，到5、6年都有，大都不堪重用。  
或许在一些程序员眼里，能实现功能，保证上线即可。代码质量，可扩展性，复杂度估计，都无所谓。   
简书上也很多人问我某个功能怎么实现，某个功能会导致手机发烫，如何优化。 
而这些，就是为什么要进行算法训练的原因。    
算法练习带来的代码功力可以轻松驾驭各种功能的实现，对时间和空间的严格限制让我们必须对代码进行优化。同时做完每道题，都要通过大量的数据测试，代码存在瑕疵很难通过最后的数据。   
不是说每个优秀的程序员都要进行算法训练，而是进行算法训练会让自己变得更加优秀。 

这次有五道题：
 * A题是普通的实现题；   
 * B题可以各凭本事实现；  
 * C题是一个简单的动态规划；    
 * D题可以用二分，也可以用字典树； 
 * E题考验代码实现功底；  

>看完题目大意，先思考，再看解析；觉得题目大意不清晰，点击题目链接看原文。

[文集：](http://www.jianshu.com/notebooks/5402645/latest)
[程序员进阶之算法练习（一）](http://www.jianshu.com/p/eb278b6fa9cf)  
[程序员进阶之算法练习（二）](http://www.jianshu.com/p/e808ae6e7c93)  
[程序员进阶之算法练习（三）](http://www.jianshu.com/p/4543e08d92af)  
[程序员进阶之算法练习（四）](http://www.jianshu.com/p/1f972ffe3aef)  
[程序员进阶之算法练习（五）](http://www.jianshu.com/p/84ff161de03f)  
[程序员进阶之算法练习（六）](http://www.jianshu.com/p/c15a12be41f6)  
[代码地址](https://github.com/loyinglin/Codeforces/tree/master/705) 



###A
[题目链接](http://codeforces.com/contest/706/problem/A) 
**题目大意**：点A在（a，b），n个点以速度v[i]，向A靠近，求最短时间。    
 输入：    
 a，b，表示点A的坐标；   
 n，表示n个点；   
 还有n个 x,y,v 表示点的坐标(x, y)和速度v。   
**代码实现**：
```
    double minTime = 0x1.fffffep+127f;
    while (n--) {
        int x, y, v;
        cin >> x >> y >> v;
        minTime = min(minTime, sqrt((x- a) * (x - a) + (y - b) * (y - b)) / v);
    }
    printf("%.7f", minTime);
```
**题目解析**：  
计算每个点与A的距离，除以对应的速度v，取最小时间即可。    

###B  
[题目链接](http://codeforces.com/contest/706/problem/B) 
**题目大意**：n个数，q个询问，对于每个询问k，输出n个数中小于等于k的数量；   
 n的范围 (1 ≤ n ≤ 100 000） 
 n个数，x[i] (1 ≤ x[i] ≤ 100 000)  
 q的范围， (1 ≤ q ≤ 100 000)    
**代码实现**：
```
     for (int i = 1; i < N; ++i) {
        dp[i] = a[i] + dp[i - 1];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        k = min(k, N - 1);
        cout << dp[k] << endl;
    }

```
**题目解析**：  
 方法多种多样：  
 1、排序，二分查找；  
 2、动态规划；  
 3、树状数组；  
 
 这里用方法2.  
dp[i] 表示小于等于i的数量；  
dp[i] = dp[i-1]+a[i]; a[i]是大小=i的数量。  


###C
[题目链接](http://codeforces.com/contest/706/problem/C)  
**题目大意**：n个字符串，可以对每个字符串进行reverse的操作，代价为cost[i]，求让n个字符串按照字符顺序排列的最小代价，如果不能输出-1；  
 字符串的总长度不会超过10w， n (2 ≤ n ≤ 100 000)。  


**代码实现**：
```

    dp[1][0] = 0;
    dp[1][1] = a[1];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i][1] = inf;
        string currentRe = reStr[i];
        string lastRe = reStr[i - 1];
        if (str[i] >= str[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (str[i] >= lastRe) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (currentRe >= str[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        }
        if (currentRe >= lastRe) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
        }
    }
    
    sum = min(dp[n][0], dp[n][1]);
    if (sum == inf) {
        sum = -1;
    }
    
    cout << sum << endl;
```
**题目解析**：  
容易想到每个字符串只有原样+reverse两种状态。  
 dp[i][0]表示第i个字符串为原串的最小代价；  
 dp[i][1]表示第i个字符串为reverse串的最小代价；  
 可能有以下四种状态转移。  
 dp[i][0] = min(dp[i][0], dp[i - 1][0]);  
 dp[i][0] = min(dp[i][0], dp[i - 1][1]);  
 dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);  
 dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);  
 最终：  
sum = min(dp[n][0], dp[n][1]);  
如果sum不为inf就存在解。  


###D
[题目链接](http://codeforces.com/contest/706/problem/D)  
**题目大意**：  
 q个操作, q=200,000  
 操作1：在集合A，加入数x  
 操作2：在集合A，删除数x  
 操作3：输入数x，寻找集合A中，与x异或值最大。  
x (1 ≤ x ≤ 10e9）  

**代码实现**：
```
    int n;
    cin >> n;
    
    while (n--) {
        char type[20];
        scanf("%s", type);
        lld x;
        cin >> x;
        sets.insert(0);
        if (type[0] == '+') {
            sets.insert(x);
        }
        else if (type[0] == '-') {
            sets.erase(sets.find(x));
        }
        else {
            lld ans = 0;
            lld sum = 0;
            for (int i = 30; i >= 0; --i) {
                lld k = 1LL << i;
                lld t = sum + k ^ (x & k);
                
                if (sets.lower_bound(t) != sets.end()) { //存在解
                    lld find =  *sets.lower_bound(t);

                    if (find <= t + (k - 1)) {
                        ans += k;
                        sum = t;
                    }
                    else {
                        sum = sum + (x & k);
                    }
                }
                
            }
            cout << ans << endl;
        }
    }

```
**题目解析**：  
简单的做法，对每个询问，遍历查找集合。复杂度太高。  
 把异或操作按二进制来看，对于每一位，都尽量使其变为1。  
 那么，可以按照二进制，从高位开始枚举是否可以为1。  
 第i位为1，如果x的第i位为1，需要寻找第i位为0数；  
 如果x的第i位为0，需要寻找第i位为1的数；  
 
 如何确定集合里面是否存在第i位为0或者为1的数字？  
 对于第i位为1，集合A存在大于等于1<<（i-1）的数字，那么就存在第i位为1的数字；  
 对于第i位为0，集合A存在大于等于0的数字，那么就存在第i位为0的数字；  
 
 用multiset和upper_bound来处理，即可。  
 
>备注：用字典树亦可解。   



###E
[题目链接](http://codeforces.com/contest/706/problem/E)  
**题目大意**：：N*M的矩阵，共有q个询问，每次输入 ai, bi, ci, di, hi, wi, 表示起点为（a，b）和（c，d）的两个大小为（w，h）的矩阵进行交换；最后输出变换后矩阵。  
（两个子矩阵不重叠、没有相交的点） (2 ≤ n, m ≤ 1000, 1 ≤ q ≤ 10 000)  


**代码实现**：
```

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
    
```
**题目解析**：  
 因为子矩阵不相交，先看看暴力的做法。  
 a[N][M]的数组存矩阵，对每个子矩阵的点，交换一遍；复杂度O(NMQ)。  
 题目中的N\*M*Q = 10 ^ 10，不可行。  
 
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
 \*TTT\*  
 L000R  
 L000R  
 L000R  
 \*BBB\*  
 
 为了防止修改过程中，再次遍历节点时导致点位置发生变化。  
 用stack把需要修改的点存下来。  
 最后再统一进行修改即可。  
 
 
 
 
 TLE之后，查看了别人的做法，发现大同小异。  
 看起来要进行常数级别的优化，把cin改成scanf，果然就过了。  
 
 S###\*  
 \#000#  
 \#000#  
 \#000#  
 \*###0  
 
 可以优化的地方：遍历的时候，根据S的位置，绕着矩阵遍历一遍即可。  


###总结
>前言讲了一些最近的感慨，编程能力是由各方面组成的。  
算法训练不是万能的。在这里，你学不到设计模式，学不到软件架构，学不到操作系统，学不到网络原理，学不到数据库。。。  
简单来说，这个算法训练让你智商变高，同时承受能力变强。  
因为这个算法训练是如此的枯燥和无聊，相比之下项目中的需求实现反而是一种简单而有趣的事情。  
举个例子：最近写AAC解码器遇到一个问题，解码器经常爆出各种奇怪的error信息。为了解决这个问题，我找了很多网上的demo，到苹果官网对比官方教程。问题足足困扰了我5、6个小时，甚至最后都使出二分代码的绝招。而这种情况在算法训练过程中是很正常的。  

我也明白，大多数人在学生时代没有兴趣玩算法，毕业之后更不可能花更多的时间去玩。  
毕竟，做好业务需求，时间长了一样做leader。反正核心的功能都会有第三方库，网上还有别人的解决方案。走架构这一条路也是很多人的选择。  
更何况，写代码对有的人来说只是一份工作。  