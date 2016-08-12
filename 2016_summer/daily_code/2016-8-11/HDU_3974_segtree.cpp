#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
#define maxn 50010

int t, n, x, y;

int ql, qr, p, v, y1, y2;
int minv[maxn<<2];
int lz[maxn<<2];

vector<int> grid[maxn];
int cnt, stt[maxn], ed[maxn];
void dfs(int u){
    stt[u] = ++cnt;
    for (int i = 0; i < grid[u].size(); i++){
        dfs(grid[u][i]);
    }
    ed[u] = cnt;
}

void build(int o, int l, int r){
    int m = (l+r)>>1;
    if(l == r) scanf("%d", &minv[o]);
	else{
		build(o<<1, l, m);
		build(o<<1|1, m+1, r);
		minv[o] = min(minv[o<<1], minv[o<<1|1]);
	}
}

void pushdown(int o){
    if(lz[o] > 0){
        lz[o<<1] = lz[o<<1|1] = lz[o];
        lz[o] = 0;
    }
}

void query(int o, int l, int r){
    if(lz[o] > 0){
        
    }
}

void update(int o, int l, int r){
    if(y1 <= l && r <= y2){
        lz[o] = v;
    }
    else{
        pushdown(o);
        int m = (l+r)>>1;
        if(y1 <= m) update(lc, l, m);
        else maintain(lc, l, m);
        if(y2 > m) update(rc, m+1, r);
        else maintain(rc, m+1, r);
    }
    maintain(o, l, r);
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < n-1; i++){
            scanf("%d%d", &x, &y);
            grid[y].push_back(x);
        }
        cnt = 0;
        dfs(2);
        for (int i = 0; i <= n; i++){
            cout << "i = " << i << endl;
            cout << "\tstt = " << stt[i] << endl;
            cout << "\ted  = " << ed[i] << endl;
        }
    }
    return 0;
}
