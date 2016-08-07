#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;

typedef long long ll;

int gcd(int a, int b){
    while(b != 0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
bool prime[10005];

void shai(){
    for (int i = 0; i < 10005; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i < 10005; i++){
        if(!prime[i]) continue;
        for (int j = 2*i; j < 10005; j+= i){
            prime[j] = false;
        }
    }
}

int p, k, n;
ll dp[10005]={};

int main()
{
    scanf("%d", &p);
    //shai();
    //memset(dp, 0, sizeof dp);
    //for (int i = 1; i <= 10000; i++){
    //    dp[i] = dp[i-1];
    //    if(prime[i]){
    //        dp[i] += i-1;
    //        continue;
   //     }
    //    for (int j = 1; j < i; j++){
    //            int _g = gcd(i, j);
    //            if(_g == 1)
    //                dp[i]++;
   //     }
    //}
    //fstream fout;
    //fout.open("~/Haha.txt");
    //for (int i = 1; i <= 10000; i++){
    //    fout << dp[i] << ",";
    //}
    //fout.close();
    while(p--){
        scanf("%d%d", &k, &n);
        ll res = 0;
        //for (int i = 1; i <= 10000; i++){
        //    cout << dp[i]+2 <<",";
        //}
        printf("%d %lld\n", k,  dp[n]+2);
    }
    return 0;
}
