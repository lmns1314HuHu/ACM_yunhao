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

int m;
int val[maxn];

#define maxn 100010
int sum[maxn*30], lc[maxn*30], rc[maxn*30];
int tot, len, tr[maxn];

void ini(){
    tot = 0;
}

int build(int l, int r){
    int root = tot++;
    sum[root] = 0;
    if(l < r){
        int mid = (l+r)>>1;
        lc[root] = build(l, mid);
        rc[root] = build(mid+1, r);
    }
    return root;
}

int update(int Lroot, int l, int r, int val, int pos){
    int newroot = tot++;
    sum[newroot] = sum[Lroot] + val;
    if(l < r){
        int mid = (l+r)>>1;
        if(pos <= mid){
            lc[newroot] = update(lc[Lroot], l, mid, val, pos);
            rc[newroot] = rc[Lroot];
        }
        else{
            lc[newroot] = lc[Lroor];
            rc[newroot] = update(rc[Lroot], mid+1, r, val, pos);
        }
    }
    return newroot;
}

int main()
{
    while(~scanf("%d", &m)){
        ini();
        for (int i = 0; i < m; i++){
            int op1, op2;
            scanf("%d%d", &op1, &op2);
            update();
        }
    }
    return 0;
}
