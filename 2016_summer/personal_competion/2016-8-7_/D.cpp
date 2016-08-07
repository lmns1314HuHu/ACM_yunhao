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

int t, n, m, k, q;
int u, v;
int x, y, z;
int pin[55];
bool grid[55][55];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &n, &m, &k, &q);
        for (int i = 0; i < n; i++){
            scanf("%d", &pin[i]);
        }
        memset(grid, 0, sizeof grid);
        for (int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            grid[u][v] = 1;
        }
        for (int i = 0; i < q; i++){
            scanf("%d%d%d", &x, &y, &z);
        }
    }
    return 0;
}
