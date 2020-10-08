#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m,a,b; cin>>n>>m>>a>>b;
		if (n*a!=m*b) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			int ar[50][50]={0};
			for (int i=0,bg=0;i<m;i++,bg+=b) 
				for (int j=0;j<b;j++) ar[(j+bg)%n][i]=1;
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++) cout<<ar[i][j]; cout<<endl;
				}
		}
	}
}


