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
#define N 1000005
#define LC 262144
#define vllu vector<llu>
#define vvllu vector<vllu>
using namespace std;

llu P=1000000007llu;

llu getchar_pos_int() {
    llu n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

llu fastPowMod(llu n, llu k, llu mod) {
    if(k==0) return 1;
    if(k%2==0) return fastPowMod((n*n)%P,k/2,mod);
    return (n*fastPowMod((n*n)%P,k/2,mod))%P;
}

/**
 * The main idea of the solution to this problem is to apply Burnside's lemma using the information about the number of
 * grids fixed by every element of the D4 group of rotations of a square.
 */
llu countGrids(llu n) {
    llu res=0,
            n0=n*n, /// all grids fixed by the identity rotation.
    n90=(n/2)*(n/2), /// number of grids fixed by rotation by 90 degrees.
    n180=n*(n/2), /// and by 180.
    n270;
    if(n&1) {
        llu sideRemainder=(n+1)/2;
        n90+=sideRemainder;
        n180+=sideRemainder;
    } /// separate consideration of odd degree rotations generating extra fixed points.
    n270=n90;
    res=(res+fastPowMod(2,n0,P))%P;
    res=(res+fastPowMod(2,n90,P))%P;
    res=(res+fastPowMod(2,n180,P))%P;
    res=(res+fastPowMod(2,n270,P))%P; ///each used as an exponent to reflect deciding if given grid is black or white.
    res=(res*fastPowMod(4,P-2,P))%P;
    return res;
}

int main() {
    llu n=getchar_pos_int();
    printf("%llu\n",countGrids(n));
    return 0;
}