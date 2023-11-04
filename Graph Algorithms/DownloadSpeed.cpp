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
llu capacity[N][N], maxFlow=0;
bool isEdgeBetween[N][N];
vi adj[N];
queue<pair<llu,int>> q;

void constructResidual() {
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1, c=getchar_pos_int();
        if(!isEdgeBetween[a][b]) {
            adj[a].pb(b); adj[b].pb(a);
            isEdgeBetween[a][b]=isEdgeBetween[b][a]=true;
        }
        capacity[a][b]+=c;
    }
}

void updateFlow(llu currFlow) {
    int u=n-1;
    while(u>0) {
        capacity[u][parent[u]]+=currFlow;
        capacity[parent[u]][u]-=currFlow;
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

int main() {
    n=getchar_pos_int(), m=getchar_pos_int();
    constructResidual();
    fr(i,n) parent[i]=-1;
    FordFulkersonEK();
    printf("%llu\n",maxFlow);
    return 0;
}