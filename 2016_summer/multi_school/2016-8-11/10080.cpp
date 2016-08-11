#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

#define maxn 100010

int n, m, x, y, z, k;
ll b[maxn];
struct node{
    int l, r;
    bool allequal;
    int lz;
    ll sum;
}tr[maxn*4];

bool check(int d){
    int lc=d<<1, rc=d<<1|1;
    if(tr[lc].allequal && tr[rc].allequal){
        int avl = tr[lc].sum / (tr[lc].r - tr[lc].l + 1);
        int avr = tr[rc].sum / (tr[rc].r - tr[rc].l + 1);
        if(avl == avr) return true;
    }
    return false;
}

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    tr[d].allequal = false;
    tr[d].lz = 0;
    if(l == r){
        tr[d].sum = b[l];
        tr[d].allequal = true;
        return;
    }
    int mid = (l+r)>>1, lc=d<<1, rc=d<<1|1;
    build(lc, l, mid);
    build(rc, mid+1, r);

    tr[d].allequal = check(d);
    tr[d].sum = tr[lc].sum + tr[rc].sum;
}

void update2(int d, int l, int r){
    if(tr[d].lz == 0){
        int ava = tr[d].sum / (tr[d].r - tr[d].l + 1);
        if(ava == 1) return;
    }
    if(tr[d].l == tr[d].r){
        tr[d].sum = sqrt(tr[d].sum);
        tr[d].lz = 0;
        if(tr[d].sum == 1) tr[d].allone = true;
        return;
    }
    int mid = (tr[d].l+tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
    if(tr[d].lz != 0){
        tr[lc].lz += tr[d].lz;
        tr[rc].lz += tr[d].lz;
        tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[d].lz;
        tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[d].lz;
        tr[d].lz = 0;
        tr[lc].allone = false;
        tr[rc].allone = false;
    }
    if(r <= mid) update2(lc, l, r);
    else if(l > mid) update2(rc, l, r);
    else{
        update2(lc, l, mid);
        update2(rc, mid+1, r);
    }
    tr[d].allone = (tr[lc].allone && tr[rc].allone);
    tr[d].sum = tr[lc].sum + tr[rc].sum;
}

void update1(int d, int l, int r, int v){
    if(tr[d].l == l && tr[d].r == r){
        tr[d].lz += v;
        tr[d].sum += (tr[d].r - tr[d].l + 1) * v;
        tr[d].allone = false;
        return;
    }

    int mid = (tr[d].l+tr[d].r)>>1, lc=d<<1, rc=d<<1|1;

    //pushdown
    if(tr[d].lz != 0){
        tr[lc].lz += tr[d].lz;
        tr[rc].lz += tr[d].lz;
        tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[d].lz;
        tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[d].lz;
        tr[lc].allone = false;
        tr[rc].allone = false;
        tr[d].lz = 0;
    }

    //go to child
    if(r <= mid) update1(lc, l, r, v);
    else if(l > mid) update1(rc, l, r, v);
    else{
        update1(lc, l, mid, v);
        update1(rc, mid+1, r, v);
    }

    tr[d].allone = (tr[lc].allone && tr[rc].allone);
    tr[d].sum = tr[lc].sum + tr[rc].sum;
}

ll query(int d, int l, int r){
    if(tr[d].lz == 0){
        if(tr[d].allone) return (long long)(r-l+1);
    }
    if(tr[d].l == l && tr[d].r == r)
        return tr[d].sum;

    int mid = (tr[d].l + tr[d].r)>>1, lc=d<<1, rc=d<<1|1;

    if(tr[d].lz != 0){
        tr[lc].lz += tr[d].lz;
        tr[rc].lz += tr[d].lz;
        tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[d].lz;
        tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[d].lz;
        tr[d].lz = 0;
        tr[lc].allone = false;
        tr[rc].allone = false;
    }

    if(r <= mid) return query(lc, l, r);
    else if (l > mid) return query(rc, l, r);
    else return query(lc, l, mid) + query(rc, mid+1, r);
}

void pt(){
    for (int i = 0; i < 10; i++){
        cout << endl;
        cout << "i = " << i << endl;
        cout << "\t l = " << tr[i].l << "/ r = " << tr[i].r << endl;
        cout << "\t sum = " << tr[i].sum << endl;
        cout << "\t lz = " << tr[i].lz << endl;
        cout << "\t allone = " << tr[i].allone << endl;
        cout << endl;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
        }
        build(1, 1, n);
        //pt();
        while(m--){
            scanf("%d", &k);
            if(k == 1){
                scanf("%d%d%d", &x, &y, &z);
                if(x > y) swap(x, y);
                update1(1, x, y, z);
            }
            else if(k == 2){
                scanf("%d%d", &x, &y);
                if(x > y) swap(x, y);
                update2(1, x, y);
            }
            else if(k == 3){
                scanf("%d%d", &x, &y);
                if(x > y) swap(x, y);
                ll res = query(1, x, y);
                printf("%lld\n", res);
            }
            //pt();
        }
    }
    return 0;
}
