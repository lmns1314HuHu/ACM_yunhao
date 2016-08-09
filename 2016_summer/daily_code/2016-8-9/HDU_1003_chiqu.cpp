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
int num;
int main()
{

    int sbxyh = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int l = 0, r = 0;
        int mx = -1000000000;
        int res = 0, mid = 0;
        for (int i = 0; i < n; i++){
            //if(i < n)
                scanf("%d", &num);
            //else
                //num = -1000000000;
            res += num;
            if(mx < res){
                l = mid;
                r = i;
                mx = res;
            }
            if(res < 0){
                mid = i + 1;
                res = 0;
            }
        }

        printf("Case %d:\n%d %d %d\n", sbxyh++, mx,  l + 1, r + 1);
        if(t == 0);
        else
            puts("");

    }
    return 0;
}
