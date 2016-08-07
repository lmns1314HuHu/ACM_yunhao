/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: 博弈
 | Date: 2016/8/7
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

int n, m, k;
int a, b;
struct edge {
    int u, v;
}E[505];

vector<int> V[105];
bool visit[105];
int sg[505];

void getsg(){
    queue<int> q;
    q.push(1);
    sg[0] = 0;
    while(!q.empty()){
        int vnu = q.front();
        q.pop();
        //if(visit[enu]) continue;
        for (int i = 0; i < V[vnu].size(); i++){
            int enu = V[vnu][i];
            if(visit[E[enu].b]) continue;
            q.push(enu.b);
        }
    }
}

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++){
            scanf("%d%d", &m, &k);
            for (int i = 0; i <= m; i++)
                V[i].clear();
            int cnt = 0;
            memset(visit, 0, sizeof visit);
            for (int i = 0; i < k; i++){
                scanf("%d%d", &a, &b);
                E[cnt].a = a;
                E[cnt].b = b;
                V[a].push_back(cnt++);
                E[cnt].a = b;
                E[cnt++].b = a;
                V[b].push_back(cnt++);
            }
        }
    }
    return 0;
}
