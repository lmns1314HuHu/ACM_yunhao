#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;


bool visit[11000];
int num[11000];
int main()
{
    memset(visit, 0, sizeof visit);
    for (int i = 1; i < 100; i++){
        if(!visit[i]){
            visit[i] = true;
            visit[2*i] = true;
            num[i] = 1;
            num[2*i] = 2;
        }
    }
    for (int i = 1; i < 100; i++){
        if(num[i] == 1 && i%2==0)
            cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i < 50; i++){
        if(num[i] == 2)
            cout << i << " ";
    }
    return 0;
}
