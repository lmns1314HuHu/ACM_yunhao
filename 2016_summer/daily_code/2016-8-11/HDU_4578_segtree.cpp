#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 100010
#define mod 10007

int myn, mym;
int myo, myx, myy, myc;

int sum1[maxn<<2], sum2[maxn<<2], sum3[maxn<<2];
int lz1[maxn<<2], lz2[maxn<<2], lz3[maxn<<2];

void build(){
    memset(sum1, 0, sizeof sum1);
    memset(sum2, 0, sizeof sum2);
    memset(sum3, 0, sizeof sum3);

    memset(lz1, 0, sizeof lz1);
    for (int i = 0; i <= maxn; i++) lz2[i] = 1;
    memset(lz3, 0, sizeof lz3);
}
//三种操作的优先级是 改>乘>加
void op1(int o, int l, int r, int val){//加操作的懒操作，在赋予一个区间懒操作的之后，立即对该区间的sum1，sum2，sum3进行更新。
    int len = (r-l+1)%mod;
    val %= mod;
    lz1[o] = (lz1[o] + val) % mod;//只对加操作有影响

    int a = sum3[o];
    int b = (((((len*val)%mod)*val)%mod)*val)%mod;//此题取摸的地方非常多，一定要细心！
    int c = (((3*sum2[o])%mod)*val)%mod;
    int d = (((((3*sum1[o])%mod)*val)%mod)*val)%mod;
    sum3[o] = (((((a+b)%mod)+c)%mod)+d)%mod;

    a = sum2[o];
    b = (((2*sum1[o])%mod)*val)%mod;
    c = (((len*val)%mod)*val)%mod;
    sum2[o] = (((a+b)%mod)+c)%mod;

    a = sum1[o];
    b = (len*val)%mod;
    sum1[o] = (a+b)%mod;
}

void op2(int o, int l, int r, int val){//乘操作的懒操作
    int len = (r-l+1)%mod;
    val %= mod;
    lz1[o] = (lz1[o] * val) % mod;//需要将该区间的加操作乘上此次懒操作的值，好让以后下放到子区间的时候，子区间每次都先进行乘，再进行加，不用担心因为同时存在乘操作和加操作的懒操作而纠结先算哪个。这点很重要。
    lz2[o] = (lz2[o] * val) % mod;

    sum3[o] = (((((val*val)%mod)*val)%mod)*sum3[o])%mod;
    sum2[o] = (((val*val)%mod)*sum2[o])%mod;
    sum1[o] = (val*sum1[o])%mod;
}

void op3(int o, int l, int r, int val){//改操作的懒操作
    int len = (r-l+1)%mod;
    val %= mod;
    lz1[o] = 0;//该区间的加、乘懒操作直接舍弃掉
    lz2[o] = 1;
    lz3[o] = val;

    sum1[o] = (val * len) % mod;
    sum2[o] = (((val * val) % mod) * len) % mod;
    sum3[o] = (((((val * val) % mod) * val) % mod) * len) % mod;
}

void pushdown3(int o, int l, int r){//改操作的pushdown
    if(l == r) return;
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(lz3[o] != 0){//不管子区间是否有加操作、乘操作，直接覆盖掉
        op3(lc, l, mid, lz3[o]);
        op3(rc, mid+1, r, lz3[o]);
        lz3[o] = 0;
    }
}

void pushdown1(int o, int l, int r){//加操作的pushdown
    if(l == r) return;
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(lz1[o] != 0){
        pushdown3(lc, l, mid);//如果子区间有改操作，需要先对改操作进行pushdown
        pushdown3(rc, mid+1, r);
        op1(lc, l, mid, lz1[o]);//然后在对子区间赋予父区间的lz操作
        op1(rc, mid+1, r, lz1[o]);
        lz1[o] = 0;
    }
}

void pushdown2(int o, int l, int r){//乘操作的pushdown
    if(l == r) return;
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(lz2[o] != 1){
        pushdown3(lc, l, mid);
        pushdown3(rc, mid+1, r);
        op2(lc, l, mid, lz2[o]);
        op2(rc, mid+1, r, lz2[o]);
        lz2[o] = 1;
    }
}

void maintain(int o, int l, int r){
    int lc=o<<1, rc=o<<1|1;
    sum1[o] = (sum1[lc] + sum1[rc]) % mod;//一定要注意取摸。
    sum2[o] = (sum2[lc] + sum2[rc]) % mod;
    sum3[o] = (sum3[lc] + sum3[rc]) % mod;
}

int y1, y2, p;
void update(int o, int l, int r, int kind){
    int m = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(y1 <= l && y2 >= r){//对该区间进行懒操作
        if(kind == 1) op1(o, l, r, p);
        else if(kind == 2) op2(o, l, r, p);
        else if(kind == 3) op3(o, l, r, p);
    }
    else{
        pushdown3(o, l, r);//注意pushdown的顺序，改懒操作和加乘懒操作不会同时并存的
        pushdown2(o, l, r);//先对子区间进行乘懒操作的赋予
        pushdown1(o, l, r);//再对子区间进行加懒操作的赋予
        if(y1 <= m) update(lc, l, m, kind);
        if(y2 > m) update(rc, m+1, r, kind);
        maintain(o, l, r);
    }
}

int which(int o, int kind){
    if(kind == 1) return sum1[o];
    else if(kind == 2) return sum2[o];
    else if(kind == 3) return sum3[o];
}

int query(int o, int l, int r, int kind){
    int m = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    int ans = 0;
    if(y1 <= l && y2 >= r){
        return which(o, kind);
    }
    else{
        pushdown3(o, l, r);
        pushdown2(o, l, r);
        pushdown1(o, l, r);
        if(y1 <= m) ans = (ans+query(lc, l, m, kind))%mod;
        if(y2 > m) ans = (ans+query(rc, m+1, r, kind))%mod;
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d", &myn, &mym) && myn && mym){
        build();
        for (int i = 0; i < mym; i++){
            scanf("%d%d%d%d", &myo, &myx, &myy, &myc);
            if(myx > myy) swap(myx, myy);
            if(myo == 1){
                y1 = myx, y2 = myy, p = myc;
                update(1, 1, myn, 1);
            }
            else if(myo == 2){
                y1 = myx, y2 = myy, p = myc;
                update(1, 1, myn, 2);
            }
            else if(myo == 3){
                y1 = myx, y2 = myy, p = myc;
                update(1, 1, myn, 3);
            }
            else if(myo == 4){
                y1 = myx, y2 = myy;
                int res = query(1, 1, myn, myc);
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
