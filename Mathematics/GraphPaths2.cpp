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
#define N 110
#define LC 262144
#define vllu vector<llu>
#define vvllu vector<vllu>
using namespace std;

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

int n, m, len;

/**
 * The main idea is to solve the problem analogously to Graph Paths I, with matrix multiplication adequately overloaded.
 */

vvllu matrixMinProd(vvllu a, vvllu b) {
    vvllu res(n);
    fr(i,n) {
        vllu curr(n,INT64_MAX);
        res[i]=curr;
    }
    fr(i,n) {
        fr(j,n) {
            fr(k,n) {
                if(a[i][k]!=INT64_MAX&&b[k][j]!=INT64_MAX){
                    res[i][j]=min(res[i][j],a[i][k]+b[k][j]);
                }
            }
        }
    }
    return res;
}

vvllu matrixFastPow(vvllu a, int k) {
    if(k==1) return a;
    if(k%2==0) return matrixFastPow(matrixMinProd(a,a),k/2);
    vvllu temp(n);
    fr(i,n) {
        vllu curr(n);
        temp[i]=curr;
        fr(j,n) {
            temp[i][j]=a[i][j];
        }
    }
    return matrixMinProd(temp, matrixFastPow(matrixMinProd(a,a),k/2));
}

int main() {
    n=getchar_pos_int(), m=getchar_pos_int(), len=getchar_pos_int();
    vvllu adj(n);
    fr(i,n) {
        vllu curr(n,0);
        adj[i]=curr;
    }
    fr(i,n) {
        fr(j,n) {
            adj[i][j]=INT64_MAX;
        }
    }
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1;
        llu c=(llu)getchar_pos_int();
        adj[a][b]=min(adj[a][b],c);
    }
    auto M=matrixFastPow(adj,len);
    if(M[0][n-1]==INT64_MAX) puts("-1");
    else printf("%llu\n",M[0][n-1]);
    return 0;
}