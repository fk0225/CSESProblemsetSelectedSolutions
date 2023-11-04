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
#define N 100010
#define LC 262144
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

vi adj[N];
bool visited[N], onRecStack[N];
int parent[N], cycleRoot=-1;
int n,m;

bool directedCycleDFS(int src, int p){
    visited[src]=onRecStack[src]=true;
    parent[src]=p;
    bool cycleExists=false;
    for(int v: adj[src]) {
        if(visited[v]) {
            if(onRecStack[v]) {
                parent[v]=src;
                cycleRoot=v;
                return true;
            }
        } else cycleExists=directedCycleDFS(v,src);
        if(cycleExists) return true;
    }
    onRecStack[src]=false;
    return false;
}


int cycleSize() {
    int size=1;
    int start=parent[cycleRoot];
    while(start!=cycleRoot) {
        size++;
        start=parent[start];
    }
    return size;
}

int main() {
    n=getchar_pos_int(),m=getchar_pos_int();
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1;
        adj[a].pb(b);
    }
    bool cycleExists=false;
    fr(i,n) {
        if(!visited[i]) {
            cycleExists=directedCycleDFS(i,-1);
            if(cycleExists) break;
        }
    }
    if(cycleExists) {
        printf("%d\n",1+cycleSize());
        vi cycle;
        int start=parent[cycleRoot];
        while(start!=cycleRoot) {
            cycle.pb(1+start);
            start=parent[start];
        }
        cycle.pb(1+cycleRoot);
        reverse(cycle.begin(),cycle.end());
        for(int v: cycle) {
            printf("%d ",v);
        }
        printf("%d\n",1+cycleRoot);
    } else puts("IMPOSSIBLE");

    return 0;
}