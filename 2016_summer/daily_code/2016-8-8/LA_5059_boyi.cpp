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

int sg[1010];
bool visit[1010];

void getsg(){
    sg[0] = 0;
    sg[1] = 0;
    for (int i = 2; i < 100; i++){
        memset(visit, 0, sizeof visit);
        for (int j = 1; j <= i/2; j++){
            visit[sg[i-j]] = true;
        }
        for (int j = 0; ; j++){
            if(!visit[j]){
                sg[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < 100; i++){
        cout << "sg[" << i << "] = " << sg[i] << endl;
    }
    cout << endl;
}

ll calc_sg(ll num){
    if(num % 2 == 0)
        return num / 2;
    else{
        return calc_sg(num / 2);
    }
}

int t, n;
ll num;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ll res = 0;
        for (int i = 0; i < n; i++){
            scanf("%lld", &num);
            res ^= calc_sg(num);
        }
        if(res != 0)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
