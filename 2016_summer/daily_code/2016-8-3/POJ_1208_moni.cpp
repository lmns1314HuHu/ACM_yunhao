/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: 模拟
 | Date: 2016/8/3
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

int n;
int fa[30];
int grid[30][30];
char s1[5];
char s2[5];
int a, b;

int getfa(int x){
    if(x != fa[x])
        return fa[x] = getfa(fa[x]);
    return x;
}

void un(int x, int y){
    int fax = getfa(x), fay = getfa(y);
    if(fax != fay){
        fa[fax] = fay;
    }
}

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 0; i < 30; i++){
            grid[0][i] = 0;
            fa[i] = i;
        }
        for (int i = 0; i < n; i++){
            grid[i][grid[0][i]++] = i;
        }
        while(~scanf("%s", s1)){
            if(strcmp(s1, "quit") == 0) break;
            scanf("%d %s %d", &a, s2, &b);
            int af = getfa(a), bf = getfa(b);
            if(af == bf) continue;
            if(strcmp(s1, "move") == 0 && strcmp(s2, "onto") == 0){
                while(grid[0][af]){
                    
                }
            }
            else if(strcmp(s1, "move") == 0 && strcmp(s2, "over") == 0){
                
            }
            else if(strcmp(s1, "pile") == 0 && strcmp(s2, "onto") == 0){
                
            }
            else if(strcmp(s1, "pile") == 0 && strcmp(s2, "over") == 0){
                
            }
        }
    }
    return 0;
}
