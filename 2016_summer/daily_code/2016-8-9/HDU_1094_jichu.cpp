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
    int n;
    while(~scanf("%d", &n)){
        ll a, res = 0;
        for (int i = 0; i < n; i++){
            scanf("%lld", &a);
            res += a;
        }
        printf("%lld\n", res);
    }
    return 0;
}
