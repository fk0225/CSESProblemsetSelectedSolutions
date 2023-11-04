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

int n, m, dp[N];
vi adj[N];

int countDagPaths(int src) {
    if(dp[src]==-1) {
        dp[src]=0;
        for(int v: adj[src]) {
            int vCount=countDagPaths(v);
            dp[src]+=vCount;
            dp[src]%=P;
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
    printf("%d\n",countDagPaths(0));
    return 0;
}