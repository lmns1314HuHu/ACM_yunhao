/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
 | Date: 
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
#include <cmath>

using namespace std;
typedef long long ll;
#define maxn 10010

int t, n;
int fa[maxn], dep[maxn], siz[maxn], son[maxn];
int cnt;
int tp[maxn], w[maxn];

int ql, qr, pos, newval;
int mx[maxn<<2], val[maxn];

struct Edge{
    int to, next, val;
}edge[maxn*2];
int totedge, head[maxn];

void init_edge(){/*{{{*/
    totedge = 0;
    memset(head, -1, sizeof head);
}/*}}}*/

void add_edge(int u, int v, int zhi){/*{{{*/
    edge[totedge].to = v;
    edge[totedge].next = head[u];
    edge[totedge].val = zhi;
    head[u] = totedge++;
}/*}}}*/

void init_2dfs(){/*{{{*/
    cnt = 0;
    tp[1] = 1;
}/*}}}*/

void dfs1(int u, int ba, int depth){/*{{{*/
    dep[u] = depth;
    fa[u] = ba;
    int maxsiz = -1, maxsonedge = -1, totsiz = 0;
    for (int i = head[u]; i != -1; i = edge[i].next){
        int to = edge[i].to;
        if(to == ba) continue;
        dfs1(to, u, depth+1);
        totsiz += siz[to];
        if(siz[to] > maxsiz){
            maxsiz = siz[to];
            maxsonedge = i;
        }
    }
    siz[u] = totsiz + 1;
    son[u] = maxsonedge;
}/*}}}*/

void dfs2(int u, int ba, int edgenum){/*{{{*/
    w[u] = cnt++;
    val[w[u]] = edge[edgenum].val;
    if(son[u] != -1){
        int to = edge[son[u]].to;
        tp[to] = tp[u];
        dfs2(to, u, son[u]);
    }
    for (int i = head[u]; i != -1; i = edge[i].next){
        int to = edge[i].to;
        if(to == edge[son[u]].to || to == ba) continue;
        tp[to] = to;
        dfs2(to, u, i);
    }
}/*}}}*/

void maintain(int o){/*{{{*/
    int lc=o<<1, rc=o<<1|1;
    mx[o] = max(mx[lc], mx[rc]);
}/*}}}*/

void build_tree(int o, int l, int r){/*{{{*/
    int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(l >= r){
        mx[o] = val[l];
        return;
    }
    build_tree(lc, l, mid);
    build_tree(rc, mid+1, r);
    maintain(o);
}/*}}}*/

void update(int o, int l, int r){/*{{{*/
    if(l == r){
        mx[o] = newval;
        return;
    }
    int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(pos <= mid) update(lc, l, mid);
    if(pos > mid) update(rc, mid+1, r);
    maintain(o);
}/*}}}*/

int query(int o, int l, int r){/*{{{*/
    if(ql <= l && qr >= l)
        return mx[o];
    int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1, ans1, ans2;
    if(ql <= mid) ans1 = query(lc, l, mid);
    if(qr > mid) ans2 = query(rc, mid+1, r);
    return max(ans1, ans2);
}/*}}}*/

void ptu(){/*{{{*/
    for (int i = 1; i <= 14; i++){
        cout << "i = " << i << endl;
        for (int j = head[i]; j != -1; j = edge[j].next){
            cout << "\tto = " << edge[j].to << endl;
            cout << "\tval = " << edge[j].val << endl;
        }
    }
}/*}}}*/

void par(){ /*{{{*/
    cout << "fa = \n";
    for (int i = 1; i <= 14; i++)
        cout << fa[i] << " ";
    cout << endl;

    cout << "dep = \n";
    for (int i = 1; i <= 14; i++)
        cout << dep[i] << " ";
    cout << endl;

    cout << "siz = \n";
    for (int i = 1; i <= 14; i++)
        cout << siz[i] << " ";
    cout << endl;

    cout << "son = \n";
    for (int i = 1; i <= 14; i++)
        cout << son[i] << " ";
    cout << endl;

    cout << "w = \n";
    for (int i = 1; i <= 14; i++)
        cout << w[i] << " ";
    cout << endl;

    cout << "tp = \n";
    for (int i = 1; i <= 14; i++)
        cout << tp[i] << " ";
    cout << endl;
}/*}}}*/

void 

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        init_edge();
        for (int i = 0; i < n-1; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c);
            add_edge(b, a, c);
        }

        init_2dfs();
        dfs1(1, 1, 1);
        dfs2(1, 1, 0);

        par();

        build_tree(1, 1, n-1);

        char cmd[10];
        while(~scanf("%s", cmd)){
            if(cmd[0] == 'D') break;
            else if(cmd[0] == 'Q'){
                int a, b;
                scanf("%d%d", &a, &b);
                int fa1 = tp[a], fa2 = tp[b], ans = -1000000000;
                while(fa1 != fa2){
                    cout << "a = " << a << "\tfa1 = " << fa1 << endl;
                    cout << "b = " << b << "\tfa2 = " << fa2 << endl;
                    cout << "depfa1 = " << dep[fa1] << "\tdepfa2 = " << dep[fa2] << endl;
                    if(dep[fa1] > dep[fa2]){
                        cout << "fa1 dep than fa2\n";
                        if(fa1 == a){
                            cout << "qing bian\n";
                            ans = max(ans, val[w[fa1]]);
                        }
                        else{
                            cout << "zhong lian\n";
                            ql = w[a], qr = w[son[fa1]];
                            if(ql > qr) swap(ql, qr);
                            int tmp = query(1, 1, n-1);
                            ans = max(ans, tmp);
                        }
                        a = fa[fa1];
                    }
                    else{
                        cout << "fa2 dep than fa1\n";
                        if(fa2 == b){
                            cout << "qing bian\n";
                            ans = max(ans, val[w[fa2]]);
                        }
                        else{
                            cout << "zhong lian\n";
                            ql = w[b], qr = w[son[fa2]];
                            if(ql > qr) swap(ql, qr);
                            int tmp = query(1, 1, n-1);
                            ans = max(ans, tmp);
                        }
                        b = fa[fa2];
                    }
                    fa1 = tp[a];
                    fa2 = tp[b];
                    cout << endl;
                }
                if(fa[fa1] == fa2) ans = max(ans, val[w[fa1]]);
                else if(fa[fa2] == fa1) ans = max(ans, val[w[fa2]]);
                else if(dep[fa1] > dep[fa2]){
                    ql = w[fa1], qr = w[son[fa2]];
                    if(ql > qr) swap(ql, qr);
                    ans = max(ans, query(1, 1, n-1));
                }
                else{
                    ql = w[fa2], qr = w[son[fa1]];
                    if(ql > qr) swap(ql, qr);
                    ans = max(ans, query(1, 1, n-1));
                }
                printf("%d\n", ans);
            }
            else if(cmd[0] == 'C'){
                int a, b;
                scanf("%d%d", &a, &b);
                pos = a, newval = b;
                update(1, 1, n-1);
            }
        }
    }
    return 0;
}
