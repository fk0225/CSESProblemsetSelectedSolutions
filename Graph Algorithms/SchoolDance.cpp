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
#define N 1005
#define LC 262144
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

int n, m, k, parent[N], adjSize;
llu capacity[N][N], maxFlow=0;
bool alreadyProcessed[N][N];
vi adj[N];
queue<pair<llu,int>> q;

void constructResidual() {
    fr(i,k) {
        int a=getchar_pos_int(),b=n+getchar_pos_int();
        if(alreadyProcessed[a][b]) continue;
        alreadyProcessed[a][b]= true;
        adj[a].pb(b); adj[b].pb(a);
        capacity[a][b]=1;
    }
    for(int i=1;i<=n;i++) {
        adj[0].pb(i);
        capacity[0][i]=1;
    }
    for(int i=n+1;i<=n+m;i++) {
        adj[i].pb(adjSize-1);
        capacity[i][adjSize-1]=1;
    }
}

void updateFlow(llu currFlow) {
    int u=adjSize-1;
    while(u>0) {
        capacity[parent[u]][u]-=currFlow;
        capacity[u][parent[u]]+=currFlow;
        u=parent[u];
    }
}

llu choosePathAndIncreaseFlowEK() {
    q.push({INT64_MAX,0});
    while(!q.empty()) {
        auto curr=q.front(); q.pop();
        if(curr.second==adjSize-1) {
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
        fr(i,adjSize) parent[i]=-1;
    }
}

int main() {
    n=getchar_pos_int(), m=getchar_pos_int(), k=getchar_pos_int();
    adjSize=n+m+2;
    constructResidual();
    fr(i,adjSize) parent[i]=-1;
    FordFulkersonEK();
    printf("%llu\n",maxFlow);
    for(int i=1;i<=n;i++) {
        for(int v: adj[i]) {
            if(!capacity[i][v]) {
                printf("%d %d\n",i,v-n);
            }
        }
    }
    return 0;
}