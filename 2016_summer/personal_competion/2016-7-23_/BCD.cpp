#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool prime[10000005];
int cnt[10000005];
int t;
int a, b, k;

void shai(){
    memset(prime, false, sizeof(prime));
    memset(cnt, 0, sizeof(cnt));
    prime[0] = prime[1] = true;
    cnt[0] = cnt[1] = 1;
    for (int i = 2; i < 10000005; i++){
        if(prime[i]) continue;
        cnt++;
        for (int j = 2*i; j < 10000005; j+=i){
            prime[j] = true;
            cnt[j]++;
        }
    }
}

int main()
{
    
    return 0;
}
