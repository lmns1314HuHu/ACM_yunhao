#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
#define maxn 100010

int n, m;
int a, b, c;

int num[maxn], numcpy[maxn];// 存储原序列和sort、unique之后的序列
int sum[maxn<<5], lc[maxn<<5], rc[maxn<<5];//存储名次在l和r之间的数的个数、节点左孩子、节点右孩子
int tr[maxn], tot, trcnt;//存储第i次操作时，新的线段树的根；tot是总节点数，trcnt是线段树的棵树

void init(){
    tot = 0;
    trcnt = 0;
    //memset(lc, -1, sizeof lc);不能乱memset，否则容易MLE
    //memset(rc, -1, sizeof rc);
}

void maintain(int o, int l, int r){
    int mid = (l+r)>>1;
    sum[o] = sum[lc[o]] + sum[rc[o]];
}

int build(int o, int l, int r){
    tot++;
    int mid = (l+r)>>1;
    if(l == r) sum[o] = 0;
    else{
		lc[o] = build(tot, l, mid);
		rc[o] = build(tot, mid+1, r);
        maintain(o, l, r);
    }
	return o;
}

int y1, y2, p, q;
int update(int o, int l, int r, int ltree){//新增变量是ltree即上一棵树的对应的区间节点
    tot++;
    int mid = (l+r)>>1;
    if(l == r) sum[o]++;
    else{
        if(p <= mid){
			lc[o] = update(tot, l, mid, lc[ltree]);
            rc[o] = rc[ltree];
        }
        else {
            lc[o] = lc[ltree];
            rc[o] = update(tot, mid+1, r, rc[ltree]);
        }
        maintain(o, l, r);
    }
	return o;
}

int query(int o, int l, int r, int ltree, int rk){
    int mid = (l+r)>>1;
    if(l == r) return l;//返回在排好后（numcpy）中序列的位置
    else{
		int tmp = sum[lc[o]] - sum[lc[ltree]];//插入 第i个到第j个之间的数 时对应数 的名次在 l和r之间的数的个数
        if(tmp >= rk) return query(lc[o], l, mid, lc[ltree], rk);//如果tmp大于k，在左子找。
        else return query(rc[o], mid+1, r, rc[ltree], rk-tmp);//如果小于k，则在右子找第rk-tmp的数
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
		init();
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		
		memcpy(numcpy, num, sizeof(num));//考贝
		sort(numcpy, numcpy + n);
		int len = unique(numcpy, numcpy + n) - numcpy;//去重后的数列的长度
		tr[trcnt] = build(tot, 1, len);//新建线段树
		trcnt++;
		
		for (int i = 0; i < n; i++){
			p = lower_bound(numcpy, numcpy+len, num[i]) - numcpy;//找到第i个数在正常排列之后的出现的位置
			p++;
			tr[trcnt] = update(tot, 1, len, tr[trcnt - 1]);//每次更新都新建一颗线段树
			trcnt++;
		}
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &a, &b, &c);
			y1 = a, y2 = b;
			printf("%d\n", numcpy[query(tr[y2], 1, len, tr[y1-1], c)-1]);//查询y1到y2数中的第k小的数，返回的是y1到y2数中第k小的数在numcpy中出现的位置。
		}
	}
    return 0;
}
