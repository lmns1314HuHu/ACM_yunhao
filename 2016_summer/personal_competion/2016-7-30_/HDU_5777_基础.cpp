#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, k, t;
int num[1000010];

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        ll sum = n;
        for (int i = 0; i < n-1; i++){
            scanf("%d", &num[i]);
        }
        sort(num, num + n - 1);
        for (int i = 0; i < n-k; i++){
            sum += num[i];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
