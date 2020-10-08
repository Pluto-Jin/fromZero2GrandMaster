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

	int n,m,x,y; cin>>n>>m>>x>>y;
	cout<<x<<' '<<y<<endl<<1<<' '<<y<<endl;
	for (int i=1;i<=n;i++) {
		if (i%2) for (int j=1;j<=m;j++) {
			if (i==x and j==y or i==1 and j==y) continue;
			cout<<i<<' '<<j<<endl;
			
		} else for (int j=m;j>=1;j--) {
			if (i==x and j==y or i==1 and j==y) continue;
			cout<<i<<' '<<j<<endl;
		}
	}
}

