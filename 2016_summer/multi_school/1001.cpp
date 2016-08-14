#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    for (int i = 73; i <= 1000000000; i++){
        if(i % 73 == 0 && i % 137 == 0)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
