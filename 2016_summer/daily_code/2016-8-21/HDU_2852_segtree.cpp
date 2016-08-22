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

#define maxn 100010

int m;
int sum[maxn*4];

void build(){
    memset(sum, 0, sizeof sum);
}

void maintain(int o){
    int lc=o<<1, rc=o<<1|1;
    sum[o] = sum[lc] + sum[rc];
}

bool update(int o, int l, int r, int pos, int val){
    if(l == r){
        if(sum[o] == 0 && val < 0) return false;
        sum[o] += val;
        return true;
    }
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    bool res = false;
    if(pos <= mid) res = update(lc, l, mid, pos, val);
    else res = update(rc, mid+1, r, pos, val);
    maintain(o);
    return res;
}

int query(int o, int l, int r, int pos, int rk){
    if(sum[o] < rk) return 0;
    if(l == r) return l;
    int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(pos <= mid){
        int 
    }
    else{
        
    }
    if(sum[lc] >= rk) return query(lc, l, mid, pos, rk);
    else return query(rc, mid+1, r, pos, rk-sum[lc]);
}

int main()
{
    while(~scanf("%d", &m)){
        build();
        for (int i = 0; i < m; i++){
            int op1, op2, op3;
            scanf("%d%d", &op1, &op2);
            if(op1 == 0){
                update(1, 1, 100000, op2, 1);
            }
            else if(op1 == 1){
                if(update(1, 1, 100000, op2, -1) == false){
                    printf("No Elment!\n");
                }
            }
            else if(op1 == 2){
                scanf("%d", &op3);
                int res = (1, 1, 100000, op2, op3);
                if(res == 0) printf("Not Find!\n");
                else printf("%d\n", res);
            }
        }
    }
    return 0;
}
