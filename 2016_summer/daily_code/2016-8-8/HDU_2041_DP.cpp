#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
ll dp[55];
int t;
int main()
{
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 40; i++){
		dp[i] = dp[i-1] + dp[i-2];//从i-1级跨一个台阶，从i-2级跨2个台阶
	}
	int n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}