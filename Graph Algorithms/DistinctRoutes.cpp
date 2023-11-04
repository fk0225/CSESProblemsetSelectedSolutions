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

int n, m, parent[N], maxFlow=0;
bool capacity[N][N], residualCapacity[N][N], isResidualOnly[N][N], permanentlyVisited[N][N];
vector<vi> paths;
vi adj[N];
queue<int> q;

void constructResidual() {
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1;
        if(b==0) continue;
        if(!isResidualOnly[a][b]) {
            adj[a].pb(b); adj[b].pb(a);
            isResidualOnly[b][a]=true;
        } else {
            isResidualOnly[a][b]=false;
        }
        capacity[a][b]=1;
        residualCapacity[b][a]=0;
    }
}

void updateFlow() {
    int u=n-1;
    while(u>0) {
        if(residualCapacity[parent[u]][u]==1) {
            residualCapacity[parent[u]][u]=0;
            capacity[u][parent[u]]=1;
        } else  {
            capacity[parent[u]][u]=0;
            residualCapacity[u][parent[u]]=1;
        }
        u=parent[u];
    }
}

int choosePathAndIncreaseFlowEK() {
    q.push(0);
    while(!q.empty()) {
        int curr=q.front(); q.pop();
        if(curr==n-1) {
            updateFlow();
            while(!q.empty()) q.pop();
            return 1;
        }
        for(int v: adj[curr]) {
            if(parent[v]==-1&&(residualCapacity[curr][v]==1||capacity[curr][v]==1)) {
                parent[v]=curr;
                q.push(v);
            }
        }
    }
    return 0;
}

void FordFulkersonEK() {
    int currFlow=INT32_MAX;
    while(currFlow>0) {
        currFlow=choosePathAndIncreaseFlowEK();
        maxFlow+=currFlow;
        fr(i,n) parent[i]=-1;
    }
}

/**
 * Setting up visits on edges to be avoided in path searching DFS after the max flow is found.
 */

void setUpPermanentVisits() {
    fr(i,n) permanentlyVisited[0][i]=permanentlyVisited[i][0]=true;
    fr(i,n) {
        fr(j,n) {
            if(isResidualOnly[i][j]||capacity[i][j]==1) {
                permanentlyVisited[i][j]=true;
            }
        }
    }
}

/**
 * Extracting paths using an iterative version of DFS along a single path.
 */

void getPath(int src, vi& path) {
    while(src!=n-1) {
        for(int v: adj[src]) {
            if(!permanentlyVisited[src][v]) {
                path.pb(1+src);
                permanentlyVisited[src][v]=permanentlyVisited[v][src]=true;
                src=v;
                break;
            }
        }
    }
    path.pb(n);
}

/**
 * Initializing path extractions from source.
 */

void getPaths() {
    for(int v:adj[0]) {
        if(capacity[0][v]==0) {
            vi path;
            path.pb(1);
            getPath(v,path);
            paths.pb(path);
        }
    }
}

int main() {
    n=getchar_pos_int(), m=getchar_pos_int();
    constructResidual();
    fr(i,n) parent[i]=-1;
    FordFulkersonEK();
    setUpPermanentVisits();
    printf("%d\n",maxFlow);
    getPaths();
    for(const auto& path: paths) {
        printf("%d\n",path.size());
        for(int v: path) printf("%d ", v);
        puts("");
    }
    return 0;
}