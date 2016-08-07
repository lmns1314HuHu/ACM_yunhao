#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, seq[15], dp[1<<15];
//int num[20];
//int cnt;

//bool is(int k){
//    if(num[k] + num[k + 1] > num[k + 2]){
//        return true;
//    }
//    return false;
//}

int main()
{
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++){
            scanf("%d", &seq[i]);
        }
        int lengt = 1 << n;
        for(int s = 0; s < lengt; s++)
        {
            int id[15], cnt = 0;
            for(int i = 0; i < n; i++){
                if(s & (1 << i))
                    id[cnt++] = i;
            }
            if(cnt >= 3){
                for(int i = 0; i <= cnt-1; i++){
                    for(int j = i + 1; j < cnt; j++){
                        for(int k = j + 1; k < cnt; k++)
                        {
                            int zhong = 1;
                            int t2 = id[j];
                            int t3 = id[k];
                            int t1 = id[i];
                            if((seq[t1] + seq[t2] <= seq[t3])|| (seq[t1] + seq[t3] <= seq[t2]) || (seq[t2] + seq[t3] <= seq[t1]))
                                zhong = 0;
                            dp[s] = max(dp[s], zhong + dp[s^(1<<t1)^(1<<t2)^(1<<t3)]);
                        }
                    }
                }
            }
        }
        int res = dp[(1<<n)- 1];
        printf("%d\n", res);
    }
    return 0;
}

