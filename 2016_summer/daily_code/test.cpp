#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
#define CL(a) memset(a, 0, sizeof(a))

using namespace std;

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;
const int maxn = 1e6+7;

ll po[100];

int main()
{
    po[0] = 1;
    for(int i = 1; i <= 33; i ++){
        po[i] = po[i-1] * 2;
    }
    ll n;
    scanf("%lld", &n);
    bool flag = false;
    for(int i = 0; i < 33; i++){
        if(po[i] == n-1){
            flag = true;
            break;
        }
    }
    if(flag){
        for(int i = 0; po[i] < n; i ++){
            if(i)
                printf(" ");
            printf("%lld", po[i]);
        }
        printf("\n");
    }
    else{
        printf("1\n");
    }

	return 0;
}
