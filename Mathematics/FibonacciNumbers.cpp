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
#define P 1000000007
#define N 200005
#define LC 262144
using namespace std;

llu getchar_pos_int() {
    llu n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

llu F[2][2]={{1,1},{1,0}};

void getNth(llu n) {
    if(n==1) return;
    getNth(n/2);
    llu a=((F[0][0]*F[0][0])%P+(F[0][1]*F[1][0])%P)%P, b=((F[0][0]*F[0][1])%P+(F[0][1]*F[1][1])%P)%P,
            c=((F[0][0]*F[1][0])%P+(F[1][0]*F[1][1])%P)%P, d=((F[0][1]*F[1][0])%P+(F[1][1]*F[1][1])%P)%P;
    F[0][0]=a, F[0][1]=b, F[1][0]=c, F[1][1]=d;
    if(n%2) {
        F[0][0]+=b, F[0][0]%=P, F[0][1]=F[1][0]=a, F[1][1]=b;
    }
}

int main() {
    llu n=getchar_pos_int();
    if(n==0||n==1) {
        printf("%llu\n",n);
        return 0;
    }
    n--;
    getNth(n);
    printf("%llu\n",F[0][0]);
    return 0;
}