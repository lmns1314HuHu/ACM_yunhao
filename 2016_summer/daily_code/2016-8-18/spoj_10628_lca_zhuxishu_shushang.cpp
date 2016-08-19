#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

#define maxn 100005
#define maxm 100005

int n, m;
int u, v;
int x, y, z;
vector<int> grid[maxn];
int val[maxn], valc[maxn];
bool visit[maxn];

int len;
int tot, trcnt;
int tr[maxn];
int lc[maxn*30], rc[maxn*30], sum[maxn*30];

int zong;
int dep_lca[maxn*4], pos_lca[maxn*4], eula[maxn*4];
int dp[maxn*4][12];
int ans[maxn];

void init(){
    tot = trcnt = 0;
    memcpy(valc, val, sizeof val);
    sort(valc, valc+n);
    len = unique(valc, valc+n)-valc;
}
int build(int l, int r){
    int root = tot++;
    sum[root] = 0;
    if(l != r){
        int mid = (l+r)>>1;
        lc[root] = build(l, mid);
        rc[root] = build(mid+1, r);
    }
    return root;
}
int update(int Lroot, int l, int r, int pos){
    int newroot = tot++;
    sum[newroot] = sum[Lroot] + 1;
    if(l != r){
        int mid = (l+r)>>1;
        if(pos <= mid){
            lc[newroot] = update(lc[Lroot], l, mid, pos);
            rc[newroot] = rc[Lroot];
        }
        else{
            lc[newroot] = lc[Lroot];
            rc[newroot] = update(rc[Lroot], mid+1, r, pos);
        }
    }
    return newroot;
}
int query(int Rroot, int Lroot, int l, int r, int rk){
    int mid = (l+r)>>1;
    if(l == r) return l;
    int tmp = sum[lc[Rroot]] - sum[lc[Lroot]];
    if(tmp >= rk) return query(lc[Rroot], lc[Lroot], l, mid, rk);
    else return query(rc[Rroot], rc[Lroot], mid+1, r, rk-tmp);
}

void dfs_update(int child, int fa){
    int hash = lower_bound(valc, valc+len, val[child-1])-valc;
    tr[child] = update(tr[fa], 0, len-1, hash);
    for (int i = 0; i < grid[child].size(); i++){
        if(i == fa) continue;
        dfs_update(grid[child][i], child);
    }
}

int rmq[2*MAXN];
struct ST{
int mm[2*MAXN];
int dp[2*MAXN][20];//最小值对应的下标
void init(int n)
{
mm[0] = -1;
for(int i = 1;i <= n;i++)
{
mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
dp[i][0] = i;
}
for(int j = 1; j <= mm[n];j++)
for(int i = 1; i + (1<<j) - 1 <= n; i++)
dp[i][j] = rmq[dp[i][j-1]] <
rmq[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}
int query(int a,int b)//查询[a,b]之间最小值的下标
{
if(a > b)swap(a,b);
int k = mm[b-a+1];
return rmq[dp[a][k]] <=
rmq[dp[b-(1<<k)+1][k]]?dp[a][k]:dp[b-(1<<k)+1][k];
}
};
//边的结构体定义
struct Edge
{
int to,next;
};
Edge edge[MAXN*2];
120 / 173
ACM 模板
kuangbin上海大学 ACM 模板 by kuangbin
int tot,head[MAXN];
int F[MAXN*2];//欧拉序列,就是dfs遍历的顺序,长度为2*n-1,下标从1开始
int P[MAXN];//P[i]表示点i在F中第一次出现的位置
int cnt;
ST st;
void init()
{
tot = 0;
memset(head,-1,sizeof(head));
}
void addedge(int u,int v)//加边,无向边需要加两次
{
edge[tot].to = v;
edge[tot].next = head[u];
head[u] = tot++;
}
void dfs(int u,int pre,int dep)
{
F[++cnt] = u;
rmq[cnt] = dep;
P[u] = cnt;
for(int i = head[u];i != -1;i = edge[i].next)
{
int v = edge[i].to;
if(v == pre)continue;
dfs(v,u,dep+1);
F[++cnt] = u;
rmq[cnt] = dep;
}
}
void LCA_init(int root,int node_num)//查询LCA前的初始化
{
cnt = 0;
dfs(root,root,0);
st.init(2*node_num-1);
}
int query_lca(int u,int v)//查询u,v的lca编号
{
return F[st.query(P[u],P[v])];
}
bool flag[MAXN];

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 0; i < n; i++) scanf("%d", &val[i]);
        init();
        tr[0] = build(0, len-1);
        for (int i = 0; i < n-1; i++){
            scanf("%d%d", &u, &v);
            grid[u].push_back(v);
            grid[v].push_back(u);
        }
        dfs_update(1, 0);
        zong = 0;
        memset(visit, 0, sizeof visit);
        while(m--){
            scanf("%d%d%d", &x, &y, &z);
            printf("%d\n", lca(x, y));
        }
    }
    return 0;
}
