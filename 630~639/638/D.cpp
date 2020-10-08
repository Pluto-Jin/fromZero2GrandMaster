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
		vi ans;
		for (int i=1;i<32;i++) {
			if (n<=(1<<i)-1) {
				n-=(1<<(i-1))-1;
				for (int j=0;j<i-1;j++) {
					if (n and 1<<j>=n) ans.pb(n),n=0;
					ans.pb(1<<j);
				}
				if (n) ans.pb(n);
				cout<<ans.size()-1<<endl;
				for (int j=1;j<ans.size();j++) cout<<ans[j]-ans[j-1]<<' ';
				cout<<endl;
				break;
			} 
		}
	}
}

