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
    ll a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", a+b);
    }
    return 0;
}
