#inlcude <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char he[110];
void add(char* a, char* b){
    int lena = strlen(a);
    int lenb = strlen(b);
    int jinwei = 0;
    int ia = lena-1, ib = lenb-1;
    int chang = max(lena, lenb);
    he[chang+1] = '\0';
    while(ia>=0 && ib>=0 && chang >= 0){
        int zong = a[ia]-'0' + b[ib]-'0' + jinwei;
        int sheng = zong % 10;
        jinwei = zong / 10;
        he[chang] = sheng + '0';
        chang--;ia--;ib--;
    }
    while(ia >= 0){
        int zong = a[ia]-'0'+jinwei;
        int sheng = zong % 10;
        jinwei = zong / 10;
        he[chang] = sheng + '0';
        chang--;ia--;
    }
    while(ib >= 0){
        int zong = b[ib]-'0' + jinwei;
        int sheng = zong % 10;
        jinwei = zong / 10;
        he[chang] = sheng + '0';
        chang--;ib--;
    }
    he[chang] = jinwei+'0';
}

int numtostring_jinzhi(int shu, char* str, int jinzhi){
    int mod = jinzhi, i = 0;
    while(shu){
         str[i++] = (shu % mod) + '0';
         shu /= jinzhi;
    }
    for (int j = i-1, k = 0; j > k; j--, k++){
        int tmp = str[j];
        str[j] = str[k];
        str[k] = tmp;
    }
    str[i] = '\0';
    return i;
}

int numtoarray(int num, int* ret){
    memset(ret, 0, sizeof(ret));
    if(num == 0) return 1;
    int i;
    for (i = 0; num != 0; i++){
        ret[i] = num % 10;
        num /= 10;
    }
    for(int j = 0, k = i - 1; j < k; j++, k--){
        int temp = ret[j];
        ret[j] = ret[k];
        ret[k] = temp;
    }
    return i;
}

int cntwei(int num){
    if(num == 0) return 1;
    int i;
    for (i = 0; num != 0; i++){
        num /= 10;
    }
    return i;
}

int arraytonum(int* ret, int wei){
    int ans = 0;
    for (int i = 0; i < wei; i++){
        ans *= 10;
        ans += ret[i];
    }
    return ans;
}

int main(){
    return 0;
}
