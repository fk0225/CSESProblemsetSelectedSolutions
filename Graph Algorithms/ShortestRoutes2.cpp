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
#define N 505
#define LC 262144
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

int adj[N][N];
llu dist[N][N];
int n,m, q;

void shortestPathsFW() {
    fr(i,n) {
        fr(j,n) {
            if(adj[i][j]<INT32_MAX){
                dist[i][j]=(llu)adj[i][j];
            } else if(i!=j) dist[i][j]=INT64_MAX;
        }
    }
    fr(k,n) {
        fr(i,n) {
            fr(j,n) {
                if(dist[i][k]<INT64_MAX&&dist[k][j]<INT64_MAX) {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

int main() {
    n=getchar_pos_int(),m=getchar_pos_int(),q=getchar_pos_int();
    fr(i,n) {
        fr(j,n) {
            if(i==j) adj[i][j]=0;
            else adj[i][j]=INT32_MAX;
        }
    }
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1,w=getchar_pos_int();
        adj[a][b]=adj[b][a]=min(adj[a][b],w);
    }
    shortestPathsFW();
    fr(i,q) {
        int a=getchar_pos_int()-1, b=getchar_pos_int()-1;
        if(dist[a][b]<INT64_MAX) printf("%llu\n",dist[a][b]);
        else puts("-1");
    }
    return 0;
}