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
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        ll a, res = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%lld", &a);
            res += a;
        }
        printf("%lld\n", res);
    }
    return 0;
}
