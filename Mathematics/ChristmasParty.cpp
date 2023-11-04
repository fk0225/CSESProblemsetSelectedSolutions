#include <bits/stdc++.h>
#define ll long long
#define llu long long unsigned
#define ld long double
#define fr(i,n) for(int i=0;i<n;i++)
#define watch(x) cerr<<(#x)<<"=="<<(x)<<endl
#define ft first
#define sc second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define P 1000000007
#define N 200005
#define LC 262144
using namespace std;

ll getchar_pos_int() {
    ll n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

/**
 * Counting derangements using the Inclusion-Exclusion Principle.
 */
ll nDerangementsMod(ll n) {
    ll nFac=n%2+(n%2==0)*n, nDerangements=n%2==0;
    for(ll i=n-(n%2==0);i>1;i-=2) {
        nDerangements+=(i-1)*nFac, nDerangements%=P, nFac*=(i*(i-1))%P, nFac%=P;
    }
    return nDerangements;
}

int main() {
    ll n=getchar_pos_int();
    printf("%lld\n",nDerangementsMod(n));
    return 0;
}