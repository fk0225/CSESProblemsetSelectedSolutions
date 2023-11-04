#include <bits/stdc++.h>
#define ll long long
#define llu long long unsigned
#define ld long double
#define fr(i,n) for(int i=0;i<n;i++)
#define watch(x) cerr<<(#x)<<"=="<<(x)<<endl
#define ft first
#define sc second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define P 1000000007llu
#define N 505
#define LC 262144
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

int n, m, parent[N];
llu capacity[N][N], residual[N][N], maxFlow=0;
vi adj[N];
bool reachable[N];
queue<pair<llu,int>> q;

void constructResidual() {
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1;
        adj[a].pb(b); adj[b].pb(a);
        capacity[a][b]=capacity[b][a]=1;
    }
}

void updateFlow(llu currFlow) {
    int u=n-1;
    while(u>0) {
        capacity[parent[u]][u]-=currFlow;
        residual[u][parent[u]]+=currFlow;
        u=parent[u];
    }
}

llu choosePathAndIncreaseFlowEK() {
    q.push({INT64_MAX,0});
    while(!q.empty()) {
        auto curr=q.front(); q.pop();
        if(curr.second==n-1) {
            updateFlow(curr.first);
            while(!q.empty()) q.pop();
            return curr.first;
        }
        for(int v: adj[curr.second]) {
            if(parent[v]!=-1||capacity[curr.second][v]==0) continue;
            parent[v]=curr.second;
            q.push({min(curr.first,capacity[curr.second][v]),v});
        }
    }
    return 0;
}

void FordFulkersonEK() {
    llu currFlow=INT64_MAX;
    while(currFlow>0) {
        currFlow=choosePathAndIncreaseFlowEK();
        maxFlow+=currFlow;
        fr(i,n) parent[i]=-1;
    }
}

void reachableDFS(int src) {
    reachable[src]= true;
    for(int v: adj[src]) {
        if(!reachable[v]&&(capacity[src][v]||residual[src][v])) reachableDFS(v);
    }
}

int main() {
    n=getchar_pos_int(), m=getchar_pos_int();
    constructResidual();
    fr(i,n) parent[i]=-1;
    FordFulkersonEK();
    printf("%llu\n",maxFlow);
    reachableDFS(0);
    fr(i,n) {
        if(reachable[i]) {
            for(int v: adj[i]) {
                if(!reachable[v]) {
                    printf("%d %d\n",1+i,1+v);
                }
            }
        }
    }
    return 0;
}