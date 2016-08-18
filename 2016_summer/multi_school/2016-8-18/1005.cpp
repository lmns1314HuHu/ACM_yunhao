#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
#define CL(a) memset(a, 0, sizeof(a))

using namespace std;

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;
const int maxn = 1000001;

int sum[maxn], lazb[maxn], laze[maxn], ans[maxn];

struct node{
    int lv, rv, tag, beg;    
}tr[maxn*4+7];

void build(int root, int l, int r){
    tr[root].lv = l;
    tr[root].rv = r;
    tr[root].tag = -1;
    tr[root].beg = -1;
    if(l == r)
        return;
    int mid = (l+r) >> 1;
    build(root << 1, l, mid);
    build(root << 1|1, mid+1, r);
}

void update(int root, int l, int r, int v, int be){
    if(tr[root].lv == l && tr[root].rv == r){
        tr[root].tag = v;
        if(tr[root].beg == -1)
            tr[root].beg = be;
        return;
    }
    if(tr[root].tag > 0){
        update(root<<1, tr[root<<1].lv, tr[root<<1].rv, tr[root].tag, tr[root].beg);
        update(root<<1|1, tr[root<<1|1].lv, tr[root<<1|1].rv, tr[root].tag, tr[root].beg);
        tr[root].tag = 0;
    }
    int mid = (tr[root].lv + tr[root].rv) / 2;
    if(tr[root].beg > 0 && tr[root].beg < be){
        be = tr[root].beg;
    }
    if(l > mid)
        update(root<<1|1, l, r, v, be);
    else if (r <= mid)
        update(root << 1, l, r, v, be);
    else{
        update(root<<1, l, mid, v, be);
        update(root<<1|1, mid+1, r, v, be);
    }
}
/*
int query(int root, int l, int r,int cur){
    if(tr[root].lv == l && tr[root].rv == r && tr[root].tag != 0){
        if(tr[root].tag == -1)
            return 0;
        else{
            if(cur <= tr[root].tag){
                return sum[r] - sum[l-1];
            }
            return 0;
        }
    }
    int mid = (tr[root].lv + tr[root].rv) / 2;
    if(l > mid){
        return query(root<<1|1, l, r, cur);
    }
    else if(r <= mid){
        return query(root<<1, l, r, cur);
    }
    else{
        return query(root<<1, l, mid, cur) + query(root<<1|1, mid+1, r, cur);
    }
}
*/
void pushDown(int root){
    if(tr[root].lv == tr[root].rv){
        if(tr[root].tag > 0){
            laze[tr[root].lv] = tr[root].tag;
        }
        else
            laze[tr[root].rv] = 0;
        if(tr[root].beg > 0){
            lazb[tr[root].lv] = tr[root].beg;
        }
        else
            lazb[tr[root].lv] = 0;
        return;
    }
    if(tr[root].tag > 0){
        update(root<<1, tr[root<<1].lv, tr[root<<1].rv, tr[root].tag, tr[root].beg);
        update(root<<1|1, tr[root<<1|1].lv, tr[root<<1|1].rv, tr[root].tag, tr[root].beg);
    }
    pushDown(root<<1);
    pushDown(root<<1|1);
}

struct Fuck{
    int a, b;
}fuck[maxn];

int main()
{
    int n, m, cur;
    while(~scanf("%d%d", &n, &m)){
        cur = 1; sum[0] = 0;
        build(1, 1, n-1);
        for(int i = 1; i <= n-1; i ++){
            scanf("%d", &sum[i]);
        }
        for(int i = 1; i <= m; i ++){
            scanf("%d%d", &fuck[i].a, &fuck[i].b);
            fuck[i].b --;
            update(1, fuck[i].a, fuck[i].b, i, i);
        }
        pushDown(1);
        CL(ans);
        for(int i = 1; i <= n - 1; i ++){
            if(laze[i] == 0)
                continue;
            ans[lazb[i]] += sum[i];
            ans[laze[i] + 1] -= sum[i];
        }
        for(int i = 1; i <= m; i ++){
            ans[i+1] += ans[i];
        }
        for(int i = 1; i <= m; i ++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
