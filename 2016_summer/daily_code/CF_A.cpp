// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <vector>

// using namespace std;
// typedef long long ll;

// int n;

// int main()
// {
	// scanf("%d", &n);
	// for (int i = 0; i < n; i++){
		// if(i % 2 == 0){
			// printf("I hate ");
		// }
		// else{
			// printf("I love ");
		// }
		// if(i != n-1)
			// printf("that ");
		// else printf("it\n");
	// }
	// return 0;
// }

// #include <iostream>
// #include <cstdio>
// #include <cstring>

// using namespace std;

// int n;
// int num;
// int sg[1000];
// bool visit[1000];

// void getsg(){
	// sg[1] = 0;
	// sg[0] = 0;
	// for (int i = 2; i < 1000; i++){
		// memset(visit, 0, sizeof visit);
		// for (int j = 1; j < i; j++){
			// int k = i - j;
			// int tmp = (sg[j] ^ sg[k]);
			// visit[tmp] = true;
		// }
		// for (int j = 0; true; j++){
			// if(!visit[j]){
				// sg[i] = j;
				// break;
			// }
		// }
	// }
	// for (int i = 0; i < 100; i++){
		// cout << "i = " << i << " " << sg[i] << endl;
	// }
// }

// int main()
// {
	// scanf("%d", &n);
	// int res = 0;
	// for (int i = 0; i < n; i++){
		// scanf("%d", &num);
		// int tmp;
		// if(num % 2 == 0)tmp = 1;
		// else tmp = 0;
		// res ^= tmp;
		// if(res != 0) printf("1\n");
		// else printf("2\n");
	// }
	// return 0;
// }


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