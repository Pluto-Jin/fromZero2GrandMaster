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
		string a,b; cin>>a>>b;
		vi ans;
		for (int i=n-1;i>=0;i--) {
			if (a[i]==b[i]) continue;
			if (!i) {
				ans.pb(1);
			} else {
				if (a[i-1]!=b[i-1]) {
					if (a[i-1]==a[i]) ans.pb(i+1),ans.pb(2),ans.pb(i+1);
					else {
						if (i==1) ans.pb(1),ans.pb(2),ans.pb(1);
						else if (a[i-2]!=a[i-1]) ans.pb(i+1),ans.pb(1),ans.pb(3),ans.pb(i+1);
						else ans.pb(i+1),ans.pb(3),ans.pb(1),ans.pb(i+1);
					}
				}	
				else ans.pb(i+1),ans.pb(1),ans.pb(i+1);
				i--;
			}
		}
		cout<<ans.size()<<' ';
		for (auto i:ans) cout<<i<<' ';
		cout<<endl;
	}
}

