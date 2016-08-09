/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: DP
 | Date: 2016-8-5
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

int n;
struct node {
    int val, deadline;
    bool operator < (const node& no) const {
        return val < no.val;
    }
};
int cnt[10010];
int curs[10010];
int fa[10010];
priority_queue<node> q;

int getfa(int x){
    if(x != fa[x])
        return fa[x] = getfa(fa[x]);
    return x;
}

void un(int a, int b){
    int fathera = getfa(a);
    int fatherb = getfa(b);
    if(fathera != fatherb){
        fa[fathera] = fatherb;
        curs[fatherb] = min(curs[fathera], curs[fatherb]);
    }
    curs[fatherb]--;
}

int main()
{
    while(~scanf("%d", &n)){
        while(q.size()) q.pop();
        node no;
        int mx_d = 0;
        for (int i = 0; i < n; i++){
            scanf("%d%d", &no.val, &no.deadline);
            if(no.deadline > mx_d)
                mx_d = no.deadline;
            q.push(no);
        }
        for (int i = 0; i <= mx_d; i++){
            curs[i] = i;
            fa[i] = i;
        }
        int ans = 0;
        while(!q.empty()){
            node u = q.top();
            q.pop();
            int v = u.val, d = u.deadline;

            int father = getfa(d);
            int nxtid = curs[father];
            un(nxtid, father);

            if(curs[getfa(father)] >= 0){
                ans += v;
                //printf("%d ", v);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
