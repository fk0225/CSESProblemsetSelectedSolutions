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

int n,m;
vi adj[N], topSort;
bool visited[N], onRecStack[N];

bool containsCycleDFS(int src) {
    visited[src]=onRecStack[src]=true;
    for(int v: adj[src]) {
        if(onRecStack[v]) return true;
        if(!visited[v]&&containsCycleDFS(v)) return true;
    }
    onRecStack[src]=false;
    return false;
}

void topSortDFS(int src) {
    visited[src]=true;
    for(int v: adj[src]) {
        if(!visited[v]) topSortDFS(v);
    }
    topSort.pb(src);
}

int main() {
    n=getchar_pos_int(),m=getchar_pos_int();
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1;
        adj[a].pb(b);
    }
    fr(i,n) {
        if(!visited[i]&&containsCycleDFS(i)) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    fr(i,n) visited[i]=false;
    fr(i,n) {
        if(!visited[i]) topSortDFS(i);
    }
    reverse(topSort.begin(),topSort.end());
    fr(i,n) printf("%d ",1+topSort[i]);
    puts("");
    return 0;
}