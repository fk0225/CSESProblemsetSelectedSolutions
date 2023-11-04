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
#define N 100005
#define LC 262144
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

vector<pii> adj[N];
llu dist[N];
priority_queue<pair<llu,int>,vector<pair<llu,int>>,greater<>> pq;
int n,m;

void shortestPathsDijkstra(int src) {
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()) {
        auto curr=pq.top();
        pq.pop();
        if(curr.first>dist[curr.second]) continue;
        for(auto v: adj[curr.second]) {
            if(v.first+dist[curr.second]<dist[v.second]) {
                dist[v.second]=v.first+dist[curr.second];
                pq.push({dist[v.second],v.second});
            }
        }
    }
}

int main() {
    n=getchar_pos_int(),m=getchar_pos_int();
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1,w=getchar_pos_int();
        adj[a].pb({w,b});
    }
    fr(i,n) dist[i]=INT64_MAX;
    shortestPathsDijkstra(0);
    fr(i,n-1) printf("%llu ",dist[i]);
    printf("%llu\n",dist[n-1]);
    return 0;
}