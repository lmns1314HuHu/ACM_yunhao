#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
#define inf 

int ql, qr, p, v;
int minv[maxn<<2];

void build(int o, int l, int r){
    int m = (l+r)>>1;
    if(l == r){
        minv[o] = 
    }
    build(o<<1, l, m);
    build(o<<1|1, m+1, r);
}

int query(int o, int l, int r){
    int m = (l+r)>>1, ans = inf;
    if(ql <= l && r <= qr) return minv[o];
    if(ql <= m) ans = min(ans, query(o<<1, l, m));
    if(m < qr) ans = min(ans, query(o<<1|1, m+1, r));
    return ans;
}

void update(int o, int l, int r){
    int m = (l+r)>>1;
    if(l == r) minv[o] = v;
    else{
        if(p <= m) update(o<<1, l, m);
        else update(o<<1|1, m+1, r);
        minv[o] = min(minv[o<<1], minv[o<<1|1]);
    }
}



int main()
{
    
    return 0;
}
