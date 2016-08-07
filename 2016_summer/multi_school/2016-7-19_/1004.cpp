#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define maxn 100010
int a[maxn];
int cnt;
int t, n, qn, l, r;
queue<int> q;

int gcd(int a, int b){
    while(b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

struct node{
	int l, r, _gcd;
}tr[maxn*4];

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    // tr[d].lz = 0;
    if(l == r){
        tr[d]._gcd = a[l];
        return ;
    }
    int mid = (l+r)/2;
    int lc = d*2;
    int rc = d*2+1;
    build(lc, l, mid);
    build(rc, mid+1, r);
	tr[d]._gcd = gcd(tr[lc]._gcd, tr[rc]._gcd );
}

int query(int d, int l, int r){
    if(tr[d].l == l && tr[d].r == r){
        return tr[d]._gcd;
    }
    int mid = (tr[d].l + tr[d].r) / 2;
    int lc = 2*d;
    int rc = 2*d+1;

    //lazy push down
    // if(tr[d].lz != 0){
        // tr[lc].lz += tr[d].lz;
        // tr[rc].lz += tr[d].lz;
        // tr[d].sum += (long long)((tr[d].r-tr[d].l+1) * tr[d].lz);
        // tr[d].lz = 0;
    // }
	
    //go to child
    if(r <= mid) return query(lc, l, r);
    else if(l > mid) return query(rc, l, r);
    else return gcd( query(lc, l, mid), query(rc, mid+1, r));
}

int calc(int mubiao){
	while( q.size() ) q.pop();
	int len = 0, curgcd = 0, cnt = 0;
	for(int i = 1; i <= n; i++  ){
		if( len == 0 ){
			q.push( a[i] );
			if( a[i] == mubiao ) cnt++;
			len++;
			curgcd = q.front();
		}
		
		else if( curgcd > mubiao ){
			for(int j = 0; j < len; j++ ){
				int tmp = q.front();
				q.front();
				tmp = gcd( tmp, a[i] );
				q.push( tmp );
				if(tmp == mubiao )cnt++;
			}
			q.push( a[i] );
			if( a[i] == mubiao ) cnt++;
			len++;
			curgcd = q.front();
		}
		
		else if( curgcd == mubiao ){
			for ( int j = 0; j < len; j++ ){
				int tmp = q.front();
				q.pop();
				tmp = gcd( tmp, a[i] );
				q.push( tmp );
				if(tmp == mubiao )cnt++;
			}
			q.push( a[i] );
			if( a[i] == mubiao ) cnt++;
			len++;
			curgcd = q.front();
		}
		
		else if( curgcd < mubiao ){
			q.pop();
			len--;
			for( int j = 0; j < len; j++ ){
				int tmp = q.front();
				q.pop();
				tmp = gcd( tmp, a[i] );
				q.push( tmp );
				if(tmp == mubiao )cnt++;
			}
			q.push( a[i] );
			if( a[i] == mubiao ) cnt++;
			len++;
			curgcd = q.front();
		}
		
		
	}
	
	return cnt;
}

int main()
{
	scanf("%d", &t);
	for ( int w = 1; w <= t; w++ ){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++ ){
			scanf("%d", &a[i] );
		}
		build( 1, 1, n );
		scanf("%d", &qn );
		printf( "Case #%d:\n", w );
		for (int i = 0; i < qn; i++ ){
			scanf("%d%d", &l, &r );
			cnt = 0;
			int res = query( 1, l, r );
			printf( "%d ", res );
			// dfs( 1, res );
			cnt = calc( res );
			printf( "%d\n", cnt );
		}
	}
	return 0;
}