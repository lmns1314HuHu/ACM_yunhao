/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
 | Date: 
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int t, n;
    ll a;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ll res = 0;
        for (int i = 0; i < n; i++){
            scanf("%lld", &a);
            res += a;
        }
        printf("%lld\n", res);
        if(t != 0) printf("\n");
    }
    return 0;
}
