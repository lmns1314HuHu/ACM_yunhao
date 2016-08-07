/*
用Trie判断字符串是否在给定字符串集合中,字符串只包含小写字母
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

const int maxnode = 1e5+10;
const int sigma   = 26;
int ch[maxnode][sigma],v[maxnode],sz;
struct trie{
    trie(){sz=1;memset(v,0,sizeof v);memset(ch[0],0,sizeof ch[0]);}
    int idx(char c){
        return c-'a';
    }
    void insert(char* s){
        int l =strlen(s),u=0;
        for(int i=0;i<l;i++){
            int c = idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof ch[sz]);
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        v[u] = 1;
    }

    int query(char *s){
        int l=strlen(s),u=0;
        for(int i=0;i<l;i++){
            int c = idx(s[i]);
            if(!ch[u][c]) return 0;
            u = ch[u][c];
        }
        return v[u];
    }
}T;

int n,m;
char c[1000];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",c);
        T.insert(c);
    }
    for(int i=0;i<m;i++){
        scanf("%s",c);
        if(T.query(c)){
            puts("EXISTS");
        }else{
            puts("NOT EXISTS");
        }
    }
    return 0;
}