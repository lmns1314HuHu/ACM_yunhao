#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[1000];
int sg[1010];
bool visit[1010];

void calc_f(){
	f[0] = 1;
	f[1] = 2;
	for (int i = 2; true; i++){
		f[i] = f[i-1] + f[i-2];
		if(f[i] > 1000)
			break;
	}
}

void calc_sg(){
	memset(sg, 0, sizeof sg);
	sg[0] = 0;
	for (int i = 1; i <= 1010; i++){
		memset(visit, 0, sizeof visit);
		for (int j = 0; f[j] <= i; j++){
			visit[sg[i-f[j]]] = true;
		}
		for (int j = 0; true; j++){
			if(!visit[j]){
				sg[i] = j;
				break;
			}
		}
	}
	// for (int i = 0; i < 100; i++){
		// cout << "sg[" << i << "] = " << sg[i] << endl;
	// }
}

int main()
{
	calc_f();
	calc_sg();
	int m, n, p;
	while(~scanf("%d%d%d", &m, &n, &p)){
		if(m==0 && n==0 && p==0) break;
		if((sg[m]^sg[n]^sg[p])!=0)
			printf("Fibo\n");
		else printf("Nacci\n");
	}
	return 0;
}