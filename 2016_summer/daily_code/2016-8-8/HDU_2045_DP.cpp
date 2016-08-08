#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll dp[55];//长度为i的长条能涂颜色的方案数
int n;

int main()
{
	dp[0] = 0;
	dp[1] = 3;
	dp[2] = 6;
	dp[3] = 6;
	for (int i = 4; i <= 50; i++){
		dp[i] = dp[i-2]*2 + dp[i-1];//首尾颜色相同时，最后以为有两种选择，收尾不同时，只有一种选择
	}
	while(~scanf("%d", &n)){
		printf("%lld\n", dp[n]);
	}
	return 0;
}