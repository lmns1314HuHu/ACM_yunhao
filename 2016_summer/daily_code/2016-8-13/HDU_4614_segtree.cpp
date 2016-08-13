#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 50010
int sum[maxn<<2], lz[maxn<<2];
int t, n, m;
int k, a, b;
void build(){
    memset(sum, 0, sizeof sum);
    memset(lz, -1, sizeof lz);
}

void maintain(int o, int l, int r){
    int lc=o<<1, rc=o<<1|1;
    sum[o] = sum[lc] + sum[rc];
}

void pushdown(int o, int l, int r){
    int m=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(lz[o] >= 0){
        lz[lc] = lz[o];
        sum[lc] = (m-l+1)*lz[o];
        lz[rc] = lz[o];
        sum[rc] = (r-m)*lz[o];
        lz[o] = -1;
    }
}

int y1, y2, p;
void update(int o, int l, int r){
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(y1 <= l && y2 >= r){
        lz[o] = p;
        sum[o] = (r-l+1)*p;
    }
    else{
        pushdown(o, l, r);
        if(y1 <= mid) update(lc, l, mid);
        if(y2 > mid)update(rc, mid+1, r);
        maintain(o, l, r);
    }
}

int query(int o, int l, int r){
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    int ans = 0;
    if(y1 <= l && y2 >= r){
        return sum[o];
    }
    else{
        pushdown(o, l, r);
        if(y1 <= mid) ans = ans + query(lc, l, mid);
        if(y2 > mid) ans = ans + query(rc, mid+1, r);
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        build();
        for (int i = 0; i < m; i++){
            scanf("%d%d%d", &k, &a, &b);
            if(k == 1){
                int stt = -1, ed = -1;
                a++;

                y1 = a, y2 = n;
                //cout << y1 <<"/" << y2 << endl;
                int tmp = query(1, 1, n);
                //cout << "tmp = " << tmp << endl;
                if(tmp >= n-a+1){
                    printf("Can not put any one.\n");
                    continue;
                }
                if(n-a+1-tmp < b) b = tmp;
                int lft = a, rit = n;
                while(lft <= rit){
                    //cout << "lft = " << lft << " rit = " << rit << endl;
                    int mid = (lft+rit)>>1;
                    y1 = lft, y2 = mid;
                    int ans = query(1, 1, n);
                    if(ans < mid - lft + 1) rit = mid-1;
                    else rit = mid+1;
                }
                stt = lft;
                //cout << "stt = " << stt << endl;

                rit = n;
                while(lft <= rit){
                    int mid=(lft+rit)>>1;
                    //cout << "lft = " << lft << " rit = " << rit << endl;
                    y1 = stt, y2 = mid;
                    int ans = mid - stt + 1 - query(1, 1, n);
                    if(ans < b) lft = mid+1;
                    else rit = mid-1;
                }
                ed = lft;
                //cout << "ed = " << ed << endl;

                printf("%d %d\n", stt-1, ed-1);
                y1 = stt, y2 = ed, p = 1;
                update(1, 1, n);
            }
            else if(k == 2){
                if(a > b) swap(a, b);
                a++, b++;
                y1 = a, y2 = b, p = 0;
                int res = query(1, 1, n);
                update(1, 1, n);
                printf("%d\n", res);
            }
        }
        printf("\n");
    }
    return 0;
}
