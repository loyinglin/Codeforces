#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long lld;

int ansLook(char *str, int len, int p) {
    for (int i = 0; i + p < len; ++i) {
        if (str[i] != str[i + p]) {
            return 0;
        }
    }
    return 1;
}
//#define OUTPUT

int main () {
    
#ifdef OUTPUT
    //         数据
    freopen("input.txt", "w", stdout);
    int t = 10;
    cout << t << endl;
    while (t--) {
        int n = 10;
        char str[111];
        for (int i = 1; i <= n; ++i) {
            putchar(str[i] = 'a'+arc4random_uniform(5));
        }
        puts("");
        cout << (n + 1) * n / 2 << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                cout << i << " " << j << endl;
            }
        }
        
    }
    return 0;
#endif
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int ca;
    cin >> ca;
    while (ca--) {
        static int zzz = 0;
        printf("Case #%d:\n", ++zzz);
        char str[1111];
        cin >> str + 1;
        int n = strlen(str + 1);
        
        int tot;
        cin >> tot;
        while (tot--) {
            
            int x, y;
            cin >> x >> y;
            
            for (int k = 0; x + k <= y; ++k) {
                if (ansLook(str + x, y - x + 1, k + 1)) {
                    cout << k+1 << endl;
                    break;
                }
            }

        }
        
    }

}
