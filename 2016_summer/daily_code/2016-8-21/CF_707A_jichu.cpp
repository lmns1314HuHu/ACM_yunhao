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

int n, m;
char grid[110][110];

int main()
{
    scanf("%d%d", &n, &m);
    bool flag = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            getchar();
            scanf("%c", &grid[i][j]);
            if(grid[i][j] == 'C' || grid[i][j] == 'M' || grid[i][j] == 'Y')
                flag = true;
        }
    }
    if(flag)
        printf("#Color\n");
    else printf("#Black&White\n");
    return 0;
}
