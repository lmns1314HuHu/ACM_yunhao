#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 100010

int cs, n, m;
int s, t, k;
int num[maxn], numc[maxn];
int sum[maxn<<5], lc[maxn<<5], rc[maxn<<5];
int tr[maxn], tot, trcnt;

void init(){
    memset(lc, -1, sizeof lc);
    memset(rc, -1, sizeof rc);
    tot = 0;
    trcnt = 0;
}

void maintain(int o, int l, int r){
    sum[o] = sum[lc[o]] + sum[rc[o]];
}

int build(int o, int l, int r){
    tot++;
    if(l == r) sum[o] = 0;
    else{
        int mid = (l+r)>>1;
        lc[o] = build(tot, l, mid);
        rc[o] = build(tot, mid+1, r);
        maintain(o, l, r);
    }
    return o;
}

int y1, y2, p;
int update(int o, int l, int r, int ltree){
    tot++;
    if(l == r) sum[o]++;
    else{
        int mid = (l+r)>>1;
        if(p <= mid){
            lc[o] = update(tot, l, mid, lc[ltree]);
            rc[o] = rc[ltree];
        }
        else{
            lc[o] = lc[ltree];
            rc[o] = update(tot, mid+1, r, rc[ltree]);
        }
        maintain(o, l, r);
    }
    return o;
}

int query(int o, int l, int r, int ltree, int rk){
    if(l == r) return l;
    else{
        int mid = (l+r)>>1;
        int tmp = sum[lc[o]] - sum[lc[ltree]];
        if(tmp >= rk) return query(lc[o], l, mid, lc[ltree], rk);
        else return query(rc[o], mid+1, r, rc[ltree], rk-tmp);
    }
}

void pt(){
    for (int i = 0; i < trcnt; i++){
        cout << tr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < tot; i++){
        cout << "i = " << i << endl;
        cout << "\tlc = " << lc[i] << "\trc = " << rc[i] << endl;
        cout << "\tsum = " << sum[i] << endl;
    }
}

int main()
{
	scanf("%d", &cs);
	while(cs--){
	    scanf("%d%d", &n, &m);
	    for (int i = 0; i < n; i++)
	        scanf("%d", &num[i]);
	    init();
	    memcpy(numc, num, sizeof num);
	    sort(numc, numc + n);
	    int len = unique(numc, numc + n) - numc;
	    tr[trcnt] = build(tot, 1, len);
	    trcnt++;
	    
	    for (int i = 0; i < n; i++){
	        p = lower_bound(numc, numc + len, num[i]) - numc;
	        p++;
	        tr[trcnt] = update(tot, 1, len, tr[trcnt-1]);
	        trcnt++;
	    }

	    for (int i = 0; i < m; i++){
	        scanf("%d%d%d", &s, &t, &k);
	        if(s > t) swap(s, t);
	        y1 = s, y2 = t;
	        printf("%d\n", numc[query(tr[y2], 1, len, tr[y1-1], k) - 1]);
	    }
	}
	return 0;
}
