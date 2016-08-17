#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

double h1, t1, h2, t2;

int main()
{
    while(~scanf("%lf%lf%lf%lf", &h1, &t1, &h2, &t2)){
        h1 = sqrt(h1);
        h2 = sqrt(h2);
        double ans = abs((h1*t2 - h2*t1) / (h2-h1));
        printf("%.6lf\n", ans);
    }
    return 0;
}
