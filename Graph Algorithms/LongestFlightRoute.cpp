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
#define P 1000000007
#define N 100005
#define LC 262144
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

int n, m, dp[N], maxNeighbor[N];
vi adj[N];

int longestDagPath(int src) {
    if(src==n-1) return 1;
    if(dp[src]==-1) {
        dp[src]=INT32_MIN;
        for(int v: adj[src]) {
            int vMax=1+longestDagPath(v);
            if(vMax>dp[src]) {
                dp[src]=vMax;
                maxNeighbor[src]=v;
            }
        }
    }
    return dp[src];
}

int main() {
    n=getchar_pos_int(),m=getchar_pos_int();
    fr(i,n-1) dp[i]=-1;
    dp[n-1]=1;
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1;
        adj[a].pb(b);
    }
    int res=longestDagPath(0);
    if(res>=0){
        printf("%d\n",res);
        int v=0;
        while(v!=n-1) {
            printf("%d ",v+1);
            v=maxNeighbor[v];
        }
        printf("%d\n",n);
    } else puts("IMPOSSIBLE");
    return 0;
}