#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[35];

//杨辉三角dp版
int main()
{
	int n;
	while(~scanf("%d", &n)){
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		printf("1\n");
		for (int i = 1; i < n; i++){
			for (int j = i; j > 0; j--){
				dp[j] += dp[j-1];
			}
			printf("1");
			for (int j = 1; j <= i; j++)
				printf(" %d", dp[j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}