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

int n, s;
int num[25];
int sg[1<<13+5];
int son[9000][2000];

int main()
{
    while(~scanf("%d", &n)&&n){
        scanf("%d", &s);
        for (int i = 0; i < 2*n; i++){
            scanf("%d", &num[i]);
        }
    }
    return 0;
}
