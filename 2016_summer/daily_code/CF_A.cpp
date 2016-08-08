#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, q;
int tp, x;
#define LEN 300010
int e[LEN];
int cnt[LEN];
int cntde[LEN];

struct node{
	int app, t;
};
queue<node> q;

int lowbit(int k){
	return k & -k;
}

void add(int k, int v){
    while(k < LEN){
        e[k] += v;
        k += lowbit(k);
    }
}

int sum(int k){
    int re = 0;
    while(k > 0){
        re += e[k];
        k -= lowbit(k);
    }
    return re;
}

int main()
{
	scanf("%d%d", &n, &q);
	int cur = 0;
	int jiacaozuo = 0;
	for (int i = 0; i < q; i++){
		scanf("%d%d", &tp, &x);
		node no;
		if(tp == 1){
			jiacaozuo++;
			add(x, 1);
			cnt[x]++;
			// stk[cur].app = x;
			no.app = x;
			no.t = jiacaozuo;
			q.push(no);
			// stk[cur++].t = jiacaozuo;
			printf("%d\n", sum(300005));
		}
		else if(tp == 2){
			add(x, cnt[x]*-1);
			cntde[x] = cnt[x];
			cnt[x] = 0;
			printf("%d\n", sum(300005));
		}
		else if(tp == 3){
			if(q.size() <= 0){
				printf("0\n");
			}
			else{
				while(q.front().t <= x){
					if(cntde[q.front().app])
					if(cnt[stk[cur-1].app] == 0){
						cur--;
					}
					else{
						cnt[stk[cur-1].app]--;
						cntde[stk[cur-1].app]++;
						add(stk[cur-1].app, -1);
						cur--;
					}
				}
			}
			printf("%d\n", sum(300005));
		}
		// for (int j = 0; j < jiacaozuo; j++){
			// cout << stk[j].app << " = " <<  stk[j].t << endl;
		// }
	}
	return 0;
}
