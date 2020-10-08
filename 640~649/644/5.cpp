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
		int n; cin>>n;
		vector<string> ar(n);
		for (auto &i:ar) cin>>i;
		int ok=1;
		for (int i=0;i<n-1;i++) {
			for (int j=0;j<n-1;j++) 
				if (ar[i][j]=='1' and ar[i+1][j]=='0' and ar[i][j+1]=='0')
					ok=0;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}


