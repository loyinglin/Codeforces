###前言
>在上文[程序员进阶之算法练习（八）附两道搜狐笔试题](http://www.jianshu.com/p/c83959243a03)中，在搜狐笔试题的基础上稍微改编后的题目：
####《宝石二》
有一串宝石首尾相连，用一个大写字母表示一个宝石，每个宝石有相应价值；
现在需要从这一串宝石中截取一段宝石，要求这一段宝石包含ABCDE这5种字母；求剩下最大价值数？
input
8
AFBCFFDE
1 2 3 4 5 6 7 8
output
11
####《袋鼠二》
袋鼠喜欢在弹簧上弹跳；
有n个弹簧排成一列，每个弹簧可以弹到下一个弹簧；
输入n个数字，代表袋鼠对n个弹簧的喜欢值；
袋鼠只喜欢跳到喜欢值大于等于起始位置喜欢值的弹簧；
袋鼠可以在任意弹簧位置起跳；
袋鼠的开心值=起始点的喜欢值*经过的弹簧数；
求袋鼠最大的开心值。
input
5
1 2 3 4 5
output
9
袋鼠在位置1，2，3，4，5起跳的开心值分别为5，8，9，8， 5。
####扩展题的答案见最后。

###正文
这次是CF708 DIV1的题目，只有3道。（后面2道不会）
>看完题目大意，先思考，再看解析；觉得题目大意不清晰，点击题目链接看原文。

[文集：](http://www.jianshu.com/notebooks/5402645/latest)
[程序员进阶之算法练习（一）](http://www.jianshu.com/p/eb278b6fa9cf)
[程序员进阶之算法练习（二）](http://www.jianshu.com/p/e808ae6e7c93)
[程序员进阶之算法练习（三）](http://www.jianshu.com/p/4543e08d92af)
[程序员进阶之算法练习（四）](http://www.jianshu.com/p/1f972ffe3aef)
[程序员进阶之算法练习（五）](http://www.jianshu.com/p/84ff161de03f)
[程序员进阶之算法练习（六）](http://www.jianshu.com/p/c15a12be41f6)
[程序员进阶之算法练习（七）](http://www.jianshu.com/p/9b5d7cca47c4)
[程序员进阶之算法练习（八）附两道搜狐笔试题](http://www.jianshu.com/p/c83959243a03)
[代码地址](https://github.com/loyinglin/Codeforces/tree/master/708)



###A
[题目链接](http://codeforces.com/contest/708/problem/A)
**题目大意**：输入一个长度为s的字符串，可以选择一个子串，把子串里每个字母的字典序-1（'a'变成'z'），求操作后的最小字典序字符串。
 s (1 ≤ s ≤ 100 000)
 >Examples
 input
 codeforces
 output
 bncdenqbdr
 
 >input
 abacaba
 output
 aaacaba

**代码实现**：
```
    cin >> str;
    int n = strlen(str);
    int flag = 0, changing = 0;
    int i = 0;
    while (i < n && str[i] == 'a') {
        ++i;
    }
    if (i == n) {
        str[n - 1] = 'z';
    }
    else {
        while (i < n && str[i] != 'a') {
            str[i] -= 1;
            ++i;
        }
    }
    cout << str << endl;

```
**题目解析**：
因为操作不会减短字典序，即操作之后的字符串应该是等长的；
 容易知道，'a'是不需要操作的，那么找到第一个不为'a'的字符串，开始变小，直到遇到下一个'a'即可；
 
###B
[题目链接](http://codeforces.com/contest/708/problem/B)
**题目大意**：一个由字符'0'和字符'1'组成的字符串，给出所有长度为2的子序列（不是子串）中，a00, a01, a10, a11的数量。
 构造一个字符串满足条件条件。如果没有就输出”Impossible“。
 数字范围为 10e9。
 
 >Examples
 input
 1 2 3 4
 output
 
 >Impossible
 input
 1 2 2 1
 output
 0110

**代码实现**：
```
// 从01开始枚举，每个1，最多有i个01
    lld x = 0, y = 0; // 前面是y个1，接着输出0，第x个0后输出1，再接着输出0，其余1在最后
    if (i == 0 || j == 0) {
        x = 0;
        y = 0;
    }
    else {
        x = b % i;
        y = j - (b / i);
        if (x != 0) {
            if (y > 0) {
                --y;
            }
        }
    }
    
    for (int z = 0; z < y; ++z) {
        putchar('1');
    }
    
    for (int z = 0; z < x; ++z) {
        putchar('0');
    }
    if (x != 0) {
        j--;
        putchar('1');
    }
    for (int z = (int)x; z < i; ++z) {
        putchar('0');
    }
    for (int z = 0; z < j - y; ++z) {
        putchar('1');
    }
    puts("");
```
**题目解析**：
假设构建出来的字符串长度是n，所有长度为2的子序列有1+2+3...+(n-1)=(n-1)\*n/2，那么sum必须满足这个条件；
 同理，对00和11，可以求出i（字符串中0的个数）和 j（字符串中1的个数），要满足i+j=n；
 接下来构建01和10，容易知道a[01]+a[10]的总数是不变的，那么
当我们构建一个01的时候，就少构建一个10，总和会满足a[01] + a[10]，
 故而我们只需构建满足a[01]的字符串，那么a[10]也会满足。
 
 对于a[01]，我们用贪心来构建。
 假设把所有的1放在最右边，那么此时的最大值是i*j。
 容易知道，我们只需把 a[01]/i 个1放在最右边即可；
 如果 a[01] % i 不为零，可以在a[01]%i个0后面放一个1，剩下的1全部放最前面即可；



###C
[题目链接](http://codeforces.com/contest/708/problem/C)
**题目大意**：输入一棵树。replace操作是去掉树上的一条边，然后添加一条边重新形成一棵树。
 问：对树上每一个节点，是否能通过不超过1次replace操作，让树在去掉这个节点后，剩下所有的子树的大小都不超过n/2。
 n (2 ≤ n ≤ 400 000)
 
 >Examples
 input
 3
 1 2
 2 3
 output
 1 1 1
 
 >input
 5
 1 2
 1 3
 1 4
 1 5
 output
 1 0 0 0 0
 
 
 第一个样例中，3是n，点数；
 接下来有n-1条边；
 边是u到v；
  输出是0和1，0表示不能，1表示可以。
 


**代码实现**：
```


int dfs(int u) {
    dfn[u] = 1;
    int sum = 1;
    for (int t = pre[u]; t != -1; t = e[t].next) {
        int v = e[t].v;
        if (!dfn[v]) {
            sum += dfs(v);
            child[u] = max(child[u], child[v]);
        }
    }
    if (sum <= n / 2) {
        child[u] = max(child[u], sum);
    }
//    cout << u << " num : " << child[u] << endl;
    return num[u] = sum;
}

void look(int u, int father) {
    if (n - num[u] - fat[u] > n / 2) {
        ans[u] = 0;
    }
    pair<int , int> pr[3];
    for (int t = pre[u]; t != -1; t = e[t].next) {
        int v = e[t].v;
        if (v != father) {
            if (num[v] - child[v] > n / 2) {
                ans[u] = 0;
            }
            pr[2] = make_pair(child[v], v);
            sort(pr, pr + 3);
            reverse(pr, pr + 3);
        }
    }
    
    for (int t = pre[u]; t != -1; t = e[t].next) {
        int v = e[t].v;
        if (v != father) {
            fat[v] = max(fat[u], pr[pr[0].second == v ? 1 : 0].first);
            if (n - num[v] <= n / 2) {
                fat[v] = n - num[v];
            }
            look(v, u);
        }
    }
}
```
**题目解析**：
 容易知道，去掉一个点之后，产生的子树集合从1到n-1都有可能。
 要让所有的子树都不大于n/2，即是要产生2个或以上的集合，并且最大的集合数量小于n/2。
 接下来对replace操作进行抽象。
 贪心可知，replace操作一定发生在最大的子树上。并且是把子树上点最接近n/2的子树，转移成新的子树。
 故而，只要统计每个点上，子树上最接近n/2的子树大小。
 然后在点选中最大一个子树，在这个子树点上判断去掉最近接n/2的节点后，最大的子树是否满足n/2。（需要注意的是，可能从父节点传过来，父节点的数量为n-num[k]）

###总结
**这次虽然只有3道题，难度和之前的5道题一致。后面的2个题是数论题，没兴趣接着做。
在闲暇之余看了统计学习中的监督学习，还没看完但是感触十分复杂。一是觉得统计学习没有想象中高深，建模、策略、算法三者中后两者还算熟悉，欠缺的是数学；二是不再觉得当初毕业没有投算法岗是个遗憾，毕竟相对而言，我觉得开发岗更有趣。
很多事情，看起是无心的选择，实则是内心真实感受的无意识表达。于是我也似乎明白，从后端开发到前端开发的原因。 
我喜欢决策，喜欢寻求最优解，喜欢用一个模型来思考问题，我喜欢循序渐进，喜欢熟悉的东西。
最重要的是，我很懒。**

>迷惘不可怕，执迷不悟才会迷失。

###扩展题答案
####《宝石二》
 把字符串复制一篇，append到最后，题目变成在字符串长度为2*N的字符串中，找到价值最小的一串包含ABCDE5个字母的子串。
 *  容易知道，如果[i, j]包含ABCDE，那么[i, j + 1]必然也包含ABCDE；（性质1）
 * 如果[i, j]包含ABCDE的状态为01010, 那么当j+1的字符为'A'的之后，[i, j + 1]包含的状态为11010;（性质2）
 
 
 我们用dp[i][j]来表示，以第i个字符结尾，字串包括ABCDE的状态为j的最小价值；（把是否包含ABCDE转成01010）
 那么有dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]); （因为如果i-1包含j，那么j也包含，以上**性质1**）
 dp[i][j | k] = min(dp[i][j | k], dp[i - 1][j] + a[i]); （**性质2**）
```
int n;
    while (scanf("%d", &n) != EOF) {
        scanf("%s", str + 1);
        lld total = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            total += a[i];
        }
        for (int i = 0; i <= n * 2; ++i) {
            for (int  j = 1; j < M; ++j) {
                dp[i][j] = llinf;
            }
        }
        dp[0][0] = 0;
        lld minSum = llinf;
        for (int i = 1; i <= n * 2; ++i) {
            int id = str[i > n ? i - n : i] - 'A';
            for (int j = 0; j < M; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i > n ? i - n : i]);
                if (id < 5) {
                    dp[i][j | (1 << id)] = min(dp[i][j | (1 << id)],
                                                     dp[i - 1][j] + a[i > n ? i - n : i]);
                }
                
            }
            minSum = min(minSum, dp[i][M - 1]);
        }
        if (minSum == llinf) {
            cout << -1 << endl;
        }
        else {
            cout << total - minSum << endl;
        }
        
    }
```

####《袋鼠二》
倒着来,dp[i]表示第i个能往后跳的位置，然后对i-1，如果a[i-1]>a[i]，证明i-1的位置是不能往后跳的；如果a[i-1]<=a[i]，那么ans=max(ans, (dp[i] + 1)*a[i-1]);  同时更新dp[i-1]。
 ```
int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            d[i] = 0;
        }
        
        lld ans = a[n];
        d[n] = 1;
        for (int i = n - 1 ; i > 0; --i) {
            if (a[i] <= a[i + 1]) {
                d[i] = d[i + 1] + 1;
                ans = max(ans, d[i] * a[i]);
            }
            else {
                ans = max(ans, a[i]);
                d[i] = 1;
            }
        }
        
        
        cout << ans << endl;
    }
    
```