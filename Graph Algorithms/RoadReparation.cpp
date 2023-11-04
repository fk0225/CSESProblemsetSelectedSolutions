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

vector<pii> adj[N];
vector<pair<int,pii>> edges;
int n, m, parent[N], subtreeRank[N];
llu mstWeight=0;
bool visited[N];

int findWithPathComp(int v) {
    if(parent[v]==v) return v;
    parent[v]=findWithPathComp(parent[v]);
    return parent[v];
}

bool unionByRank(int a, int b) {
    a=findWithPathComp(a), b=findWithPathComp(b);
    if(a==b) return false;
    if(subtreeRank[a]<subtreeRank[b]) {
        parent[a]=b;
    } else {
        if(subtreeRank[a]==subtreeRank[b]) subtreeRank[a]++;
        parent[b]=a;
    }
    return true;
}

void dfs(int src) {
    visited[src]=true;
    for(auto v: adj[src]) {
        if(!visited[v.second]) dfs(v.second);
    }
}

int main() {
    n=getchar_pos_int(),m=getchar_pos_int();
    fr(i,m) {
        int a=getchar_pos_int()-1, b=getchar_pos_int()-1, w=getchar_pos_int();
        adj[a].pb({w,b}); adj[b].pb({w,a});
        edges.pb({w,{a,b}});
    }
    dfs(0);
    for(int i=1;i<n;i++) {
        if(!visited[i]) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    fr(i,n) {
        subtreeRank[i]=1;
        parent[i]=i;
    }
    sort(edges.begin(),edges.end());
    for(auto edge: edges) {
        if(unionByRank(edge.second.first,edge.second.second)) {
            mstWeight+=(llu)edge.first;
        }
    }
    printf("%llu\n",mstWeight);
    return 0;
}