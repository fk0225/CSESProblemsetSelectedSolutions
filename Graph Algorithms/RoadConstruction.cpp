#include <bits/stdc++.h>
#define ll long long
#define llu long long unsigned
#define ld long double
#define fr(i,n) for(int i=0;i<n;i++)
#define watch(x) cout<<(#x)<<"=="<<(x)<<endl
#define ft first
#define sc second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define P 1000000007llu
#define N 200005
#define LC 262144
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

vi adj[N];
int n, m, maxCCSize=1, nCCs;
int subtreeSize[N], parent[N];

int findWithPathComp(int v) {
    if(parent[v]==v) return v;
    parent[v]=findWithPathComp(parent[v]);
    return parent[v];
}

void unionBySize(int a, int b) {
    a=findWithPathComp(a);
    b=findWithPathComp(b);
    if(a==b) {
        printf("%d %d\n", nCCs, maxCCSize);
        return;
    }
    if(subtreeSize[a]<subtreeSize[b]) {
        subtreeSize[b]+=subtreeSize[a];
        maxCCSize=max(maxCCSize,subtreeSize[b]);
        parent[a]=b;
    } else {
        subtreeSize[a]+=subtreeSize[b];
        maxCCSize=max(maxCCSize,subtreeSize[a]);
        parent[b]=a;
    }
    nCCs--;
    printf("%d %d\n", nCCs, maxCCSize);
}

int main() {
    n=getchar_pos_int(),m=getchar_pos_int();
    nCCs=n;
    fr(i,n) {
        parent[i]=i;
        subtreeSize[i]=1;
    }
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1;
        unionBySize(a,b);
    }
    return 0;
}