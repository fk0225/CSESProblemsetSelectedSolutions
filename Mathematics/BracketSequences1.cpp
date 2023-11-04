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
#define N 2000005
#define LC 262144
#define vllu vector<llu>
#define vvllu vector<vllu>
using namespace std;

llu P=1000000007llu, f[N];

llu getchar_pos_int() {
    llu n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

llu fastPowModP(llu n, llu k) {
    if(k==0) return 1;
    if(k%2==0) return fastPowModP((n*n)%P,k/2);
    return (n*fastPowModP((n*n)%P,k/2))%P;
}

void getFactorials() {
    f[0]=f[1]=1; f[2]=2;
    for(int i=3;i<N;i++) {
        f[i]=(i*f[i-1])%P;
    }
}

llu binCoeff(llu a, llu b) {
    return (f[a]*fastPowModP((f[b]*f[a-b])%P,P-2))%P;
}

llu Cn(llu n) {
    return (binCoeff(n<<1,n)*fastPowModP(n+1,P-2))%P;
}

int main() {
    getFactorials();
    llu n=getchar_pos_int();
    if(n%2) {
        puts("0");
        return 0;
    }
    printf("%llu\n",Cn(n>>1));
    return 0;
}