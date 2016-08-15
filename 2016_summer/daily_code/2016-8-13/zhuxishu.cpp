#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100001

int v[N], t[N], n, m;
int tot, Ro[N];

struct Tr {
    int c, ls, rs;
}tr[N*30];

void init() {
     tot = 0;
     memcpy(t, v, sizeof(v));
     sort(t, t+n);
}

int build(int l , int r) {
    int root = tot++, mid = l+r>>1;
    tr[root].c = 0;
    if (l < r)
    {
       tr[root].ls = build(l, mid);
       tr[root].rs = build(mid+1, r);
    }
    return root;
}

int update(int l, int r, int val, int root) {
    int nr = tot++, mid = l+r>>1;
    tr[nr].c = tr[root].c+1;
    if (l != r) {
       if (val <= mid) {
          tr[nr].ls = update(l, mid, val, tr[root].ls);
          tr[nr].rs = tr[root].rs;
       }else {
           tr[nr].rs = update(mid+1, r, val, tr[root].rs);
           tr[nr].ls = tr[root].ls;
       }
    }
    return nr;
}

int query(int Rroot, int Lroot, int d, int l, int r) {
    int mid = l+r>>1;
    if (l == r) return l;
    int sum = tr[tr[Rroot].ls].c-tr[tr[Lroot].ls].c;
    if (d <= sum) return query(tr[Rroot].ls, tr[Lroot].ls, d, l, mid);
    else return query(tr[Rroot].rs, tr[Lroot].rs, d-sum, mid+1, r);
}

int main() {
    int i, j, L, R, d;
    while (~scanf("%d%d", &n, &m)) {
          for (i = 0;i < n;i++) scanf("%d", &v[i]);
          init();
          int r = unique(t, t+n)-t;
          Ro[0] = build(0, r-1);
          for (i = 0;i < n;i++)
              Ro[i+1] = update(0, r-1, lower_bound(t, t+r, v[i])-t, Ro[i]);
          while (m--) {
                scanf("%d%d%d", &L, &R, &d);
                printf("%d\n", t[query(Ro[R], Ro[L-1], d, 0, r-1)]);
          }
    }
}
