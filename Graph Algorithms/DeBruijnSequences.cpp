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
#define MAXSIZE 65536
#define LC 262144
using namespace std;

int n, graphSize, outDeg[MAXSIZE];
vi adj[MAXSIZE],path;
bool visited[MAXSIZE];
string seq="";

void buildGraph() {
    graphSize=1<<(n-1);
    fr(i,graphSize) {
        outDeg[i]=2;
        int withZeroAppended=((i<<1)%graphSize);
        adj[i].pb(withZeroAppended);
        adj[i].pb(withZeroAppended+1);
    }
}

void buildSeq(int src) {
    while(outDeg[src]) {
        buildSeq(adj[src][--outDeg[src]]);
    }
    seq+=('0'+(src%2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    if(n==1) {
        cout<<"10\n";
        return 0;
    }
    buildGraph();
    buildSeq(0);
    fr(i,n-2)seq+="0";
    cout<<seq<<'\n';
    return 0;
}