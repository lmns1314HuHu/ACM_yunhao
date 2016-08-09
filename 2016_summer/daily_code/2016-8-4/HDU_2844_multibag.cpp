/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 多重背包
 | Date: 2016/8/1
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
#define maxn 110

int n, m;
int A[maxn], C[maxn];
int v[maxn*1000], c[maxn*1000];
int dp[100010];

int main()
{
    while(~scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) break;
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &C[i]);
        int k = 1;
        for (int i = 0; i < n; i++){
            for (int j = 1; j <= C[i]; j++){
                v[k++] = j * A[i];
            }
        }
    }
    return 0;
}
