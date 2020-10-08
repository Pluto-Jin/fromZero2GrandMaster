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
		int l=0,r=n-1;
		vi ans;
		for (int i=n-1;i>=0;i--) {
			if ((n-1-i)%2) {
				if (a[r--]!=b[i]) ans.pb(0);
				ans.pb(i);
			} else {
				if (a[l++]==b[i]) ans.pb(0);
				ans.pb(i);
			}
		}
		cout<<ans.size()<<' ';
		for (auto i:ans) cout<<i+1<<' ';
		cout<<endl;
	}
}

