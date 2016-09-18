/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
 | Date: 
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int dp [10000];

int main()
{
    int k = 0;
    dp[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0, p7 = 0;
    for (int i = 1; i <= 5842; i++){
        while(dp[p2]*2 <= dp[i-1]) p2++;
        while(dp[p3]*3 <= dp[i-1]) p3++;
        while(dp[p5]*5 <= dp[i-1]) p5++;
        while(dp[p7]*7 <= dp[i-1]) p7++;
        int tmp = dp[p2]*2;
        if(dp[p3]*3 < tmp) tmp = dp[p3]*3;
        if(dp[p5]*5 < tmp) tmp = dp[p5]*5;
        if(dp[p7]*7 < tmp) tmp = dp[p7]*7;
        dp[i] = tmp;
    }
    //for (int i = 0; i < 5200;i++){
        //cout << dp[i] << endl;
    //}
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int l = 0, r = 5200;
        while(l < r){
            int mid = (l+r)>>1;
            if(dp[mid] < n) l = mid+1;
            else r = mid;
        }
        int res = dp[l];
        printf("%d\n", res);
    }
    return 0;
}
