#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int sum[maxn<<5], lc[maxn<<5], rc[maxn<<5], val[maxn<<5];
int tr[maxnm], tot, trcnt;

void init(){
    tot = 0;
    trcnt = 0;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
}

void maintain(int o, int l, int r){
    int mid = (l+r)>>1;
    sum[o] = sum[lc[o]] + sum[rc[o]];
}

int build_tree(int l, int r){
    int root = tot++;
    tr[trcnt++] = root;
    build(root, l, r);
    return root;
}
void build(int o, int l, int r){
    int mid = (l+r)>>1;
    if(l == r) sum[o] = 0;
    else{
        lc[o] = tot++, rc[o] = tot++;
        build(lc[o], l, mid);
        build(rc[o], mid+1, r);
        maintain(o, l, r);
    }
}

int y1, y2, p, q;
int update_tree(int l, int r){
    int root = tot++;
    tr[trcnt++] = root;
    update(root, l, r, tr[trcnt - 2]);
    return root;
}
void update(int o, int l, int r, int ltree){
    int mid = (l+r)>>1;
    if(l == r){ 
        sum[o]++;
        val[o] = q;
    }
    else{
        if(p <= mid){
            lc[o] = tot++;
            rc[o] = rc[ltree];
            update(lc[o], l, mid, lc[ltree]);
        }
        if(p > mid){
            lc[o] = lc[ltree];
            rc[o] = tot++;
            update(rc[o], mid+1, r, rc[ltree]);
        }
        maintain(o, l, r);
    }
}

int query(int l, int r){
    
}
int query(int o, int l, int r, int ltree, int& rk){
    int mid = (l+r)>>1;
    int tmp = sum[o] - sum[ltree];
    int ans1 = -1;
    if(tmp <= rk){
        rk -= tmp;
        return val[o];
    }
    else{
        ans1 = query(lc[o], l, mid, lc[ltree], rk);
        if(rk != 0)
            ans1 = query(rc[o], mid+1, r, rc[ltree], rk);
        return ans1;
    }
}

void pt(){
    for (int i = 0; i < trcnt; i++){
        cout << tr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < tot; i++){
        cout << "i = " << i << endl;
        cout << "\tlc  = " << lc[i] << endl;
        cout << "\trc  = " << rc[i] << endl;
        cout << "\tsum = " << sum[i] << endl;
        cout << "\tval = " << val[i] << endl;
    }
}

int main()
{
    
    return 0;
}
