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

int getchar_pos_int() {
    int n=0, c=getchar();
    while('0'<=c&&c<='9') {n=n*10+c-'0'; c=getchar();}
    return n;
}

int t,n;

int main() {
    t=getchar_pos_int();
    while(t--) {
        n=getchar_pos_int();
        int xXor=0;
        fr(i,n) {
            xXor^=getchar_pos_int();
        }
        if(xXor) puts("first");
        else puts("second");
    }
    return 0;
}