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

int t, n;

int main()
{
    scanf("%d", &t);
    for(int w = 1; w <= t; w++){
        scanf("%d", &n);
        if(n == 1) printf("Case %d: 1\n", w);
        else if(n == 2) printf("Case %d: 2\n", w);
        else printf("Case %d: %d\n",w, 2*n-4);
    }
    return 0;
}
