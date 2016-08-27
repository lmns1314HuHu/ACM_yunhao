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
#define maxn 10010
int n;
int fa[maxn], dep[maxn], siz[maxn], son[maxn], tp[maxn], w[maxn];

struct Edge{
    int to, next;
}edge[maxn];
int totedge, head[maxn];
void init_edge(){
    totedge = 0;
    memset(head, -1, sizeof head);
}
void add_edge(int u, int v){
    edge[totedge].to = v;
    edge[totedge].next = head[u];
    head[u] = totedge++;
}

void dfs1(){
    
}

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 0; i < n-1; i++){
            
        }
    }
    return 0;
}
