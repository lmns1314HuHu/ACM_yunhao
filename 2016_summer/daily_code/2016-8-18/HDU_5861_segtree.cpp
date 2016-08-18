#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 200010

int n, m;
int lz[maxn<<2];
int cost[maxn];
int stt[maxn], ed[maxn];
vector< pair<int, int> > qry;

void build(){
    memset(lz, -1, sizeof lz);
}

void pushdown(int o){
    if(lz[o] != -1){
        int lc=o<<1, rc=o<<1|1;
        lz[lc] = lz[rc] = lz[o];
        lz[o] = -1;
    }
}

int y1, y2, v;
void update(int o, int l, int r){
    if(y1 <= l && r <= y2){
        lz[o] = v;
    }
    else{
        pushdown(o);
        int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
        if(y1 <= mid) update(lc, l, mid);
        if(y2 > mid) update(rc, mid+1, r);
    }
}

void dfs1(int o, int l, int r){
    if(lz[o] >= 0 || l == r){
        for (int i = l-1; i < r; i++)
            ed[i] = lz[o];
        return;
    }
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    dfs1(lc, l, mid);
    dfs1(rc, mid+1, r);
}

void dfs2(int o, int l, int r){
    if(lz[o] >= 0 || l == r){
        for (int i = l-1; i < r; i++)
            stt[i] = lz[o];
        return;
    }
    int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    dfs2(lc, l, mid);
    dfs2(rc, mid+1, r);
}

void pt(){
    for (int i = 1; i <= 5; i++){
        cout << "i = " << i << endl;
        cout << "\t lz = " << lz[i] << endl;
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 0; i < n-1; i++){
            scanf("%d", &cost[i]);
        }
        qry.clear();

        build();
        for (int i = 1; i <= m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            if(a > b) swap(a, b);
            qry.push_back(make_pair(a, b));
            a--, b-=2;
            y1 = a+1, y2 = b+1, v = i;
            update(1, 1, n-1);
        }
        dfs1(1, 1, n-1);

        build();
        for (int i = qry.size()-1; i >= 0; i--){
            int a = qry[i].first, b = qry[i].second;
            a--, b-= 2;
            y1 = a+1, y2 = b+1, v = i+1;
            update(1, 1, n-1);
        }
        dfs2(1, 1, n-1);

        ll res = 0;
        for (int i = 0; i < n; i++){
            if(stt[i] == -1) continue;
            res += (cost[i] * (ed[i]-stt[i]));
        }

        //for (int i = 0; i < n-1; i++)
            //cout << stt[i] << " ";
        //cout << endl;
        //for (int i = 0; i < n-1; i++)
            //cout << ed[i] << " ";
        //cout << endl;
        printf("%lld\n", res);
    }
    return 0;
}
