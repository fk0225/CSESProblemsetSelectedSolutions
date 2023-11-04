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

vvllu matrixProd(vvllu a, vvllu b) {
    vvllu res(n);
    fr(i,n) {
        vllu curr(n,0);
        res[i]=curr;
    }
    fr(i,n) {
        fr(j,n) {
            fr(k,n) {
                res[i][j]+=a[i][k]*b[k][j];
                res[i][j]%=P;
            }
        }
    }
    return res;
}

vvllu matrixFastPow(vvllu a, int k) {
    if(k==1) return a;
    if(k%2==0) return matrixFastPow(matrixProd(a,a),k/2);
    vvllu temp(n);
    fr(i,n) {
        vllu curr(n);
        temp[i]=curr;
        fr(j,n) {
            temp[i][j]=a[i][j];
        }
    }
    return matrixProd(temp, matrixFastPow(matrixProd(a,a),k/2));
}

int main() {
    n=getchar_pos_int(), m=getchar_pos_int(), len=getchar_pos_int();
    vvllu adj(n);
    fr(i,n) {
        vllu curr(n,0);
        adj[i]=curr;
    }
    fr(i,m) {
        int a=getchar_pos_int()-1,b=getchar_pos_int()-1;
        adj[a][b]++;
        adj[a][b]%=P;
    }
    auto M=matrixFastPow(adj,len);
    printf("%llu\n",M[0][n-1]);
    return 0;
}