#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 100010
#define maxm 5010

int n, m;
int a, b, c;
int num[maxn], numcpy[maxn];
int sum[maxn<<5], lc[maxn<<5], rc[maxn<<5], val[maxn<<5];
int tr[maxm], tot, trcnt;

void init(){
    tot = 0;
    trcnt = 0;
    memset(lc, -1, sizeof lc);
    memset(rc, -1, sizeof rc);
	memset(val, -1, sizeof val);
}

void maintain(int o, int l, int r){
    int mid = (l+r)>>1;
    sum[o] = sum[lc[o]] + sum[rc[o]];
	val[o] = val[rc[o]];
	if(val[o] == -1)
		val[o] = val[lc[o]];
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
int build_tree(int l, int r){
    int root = tot++;
    tr[trcnt++] = root;
    build(root, l, r);
    return root;
}

int y1, y2, p, q;
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
int update_tree(int l, int r){
    int root = tot++;
    tr[trcnt++] = root;
    update(root, l, r, tr[trcnt - 2]);
    return root;
}

int query(int o, int l, int r, int ltree, int rk){
	// cout << "o = " << o << " ltree = " << ltree << endl;
	// cout << "\t l = " << l << endl;
	// cout << "\t r = " << r << endl;
    int mid = (l+r)>>1;
    //int tmp = sum[lc[o]] - sum[lc[ltree]];
	// cout << "\t tmp = " << tmp << endl;
	// cout << "\t rk = " << rk << endl;
    if(l == r){
        //rk -= tmp;
		// cout << "bian jie return\n";
        return val[o];
    }
    else{
		int tmp = sum[lc[o]] - sum[lc[ltree]];
        if(tmp >= rk) return query(lc[o], l, mid, lc[ltree], rk);
        return query(rc[o], mid+1, r, rc[ltree], rk-tmp);
		// cout << "zheng chang return\n";
        // return ans1;
    }
}
int query_tree(int l, int r, int rk){
	int o = tr[y2];
	int ltree = tr[y1-1];
	return query(o, l, r, ltree, rk);
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
    while(~scanf("%d%d", &n, &m)){
		init();
		build_tree(1, n);
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		memcpy(numcpy, num, sizeof(num));
		sort(numcpy, numcpy + n);
		int len = unique(numcpy, numcpy + n) - numcpy;
		for (int i = 0; i < n; i++){
			q = i, p = lower_bound(numcpy, numcpy+len, num[i]) - numcpy;
			p++;
			update_tree(1, n);
		}
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &a, &b, &c);
			y1 = a, y2 = b;
			printf("%d\n", num[query_tree(1, n, c)]);
		}
	}
    return 0;
}
