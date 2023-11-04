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

llu fastPowModP(llu n, int k) {
    if(k==0) return 1;
    if(k%2==0) return fastPowModP((n*n)%P,k/2);
    return (n*fastPowModP((n*n)%P,k/2))%P;
}

llu nColorings(int n, int m) {
    llu res=0;
    for(int i=0;i<n;i++) {
        res+=fastPowModP((llu)m,__gcd(n,i));
        res%=P;
    }
    return (res*fastPowModP(n,((int)P)-2))%P;
}

int main() {
    int n=getchar_pos_int(), m=getchar_pos_int();
    printf("%llu\n",nColorings(n,m));
    return 0;
}