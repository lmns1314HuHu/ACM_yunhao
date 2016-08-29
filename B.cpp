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
#include <cmath>

using namespace std;
typedef long long ll;

int n;
int num[505][505];
ll he[505][2];
ll zhuhe, fuhe;

int main()
{
    scanf("%d", &n);
    int shux = 0, shuy = 0;
    memset(he, 0, sizeof he);
    zhuhe = fuhe = 0;

    for (int i = 0; i < n; i++){
        ll sum = 0;
        for (int j = 0; j < n; j++){
            scanf("%d", &num[i][j]);
            sum += num[i][j];
            if(num[i][j] == 0){
                shux = i;
                shuy = j;
            }
            if(i == j) zhuhe += num[i][j];
            if(i + j == n-1) fuhe += num[i][j];
        }
        he[i][0] = sum;
    }
    for (int i = 0; i < n; i++){
        ll sum = 0;
        for (int j = 0; j < n; j++){
            sum += num[j][i];
        }
        he[i][1] = sum;
    }

    ll gethe = 0;
    for (int i = 0; i < n; i++){
        if(i != shux){
            gethe = he[i][0];
            break;
        }
    }
    ll res = gethe - he[shux][0];
    he[shux][0] += res;
    he[shuy][1] += res;
    if(shux == shuy) zhuhe += res;
    if(shux+shuy == n-1) fuhe += res;

    bool flag = true;
    if(res <= 0) flag = false;
    for (int i = 0; i < n; i++){
        if(he[i][0] != he[i][1]){
            flag = false; break;
        }
    }
    for (int i = 1; i < n; i++){
        if(he[i][0] != he[i-1][0]){
            flag = false; break;
        }
    }
    if(he[0][0] != zhuhe || he[0][0] != fuhe) flag = false;
    if(n == 1){flag = true; res = 1;}
    if(flag) printf("%lld\n", res);
    else printf("-1\n");
    return 0;
}
