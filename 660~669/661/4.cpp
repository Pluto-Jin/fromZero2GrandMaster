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
		string s; cin>>s;
		stack<int> q0,q1;
		int cur=0;
		vi ans;
		for (auto i:s) {
			int tmp;
			if (i=='0') {
				if (q1.empty()) q0.push(tmp=++cur);
				else tmp=q1.top(),q1.pop(),q0.push(tmp);
			} else {
				if (q0.empty()) q1.push(tmp=++cur);
				else tmp=q0.top(),q0.pop(),q1.push(tmp);
			}
			ans.pb(tmp);
		}
		cout<<cur<<endl;
		for (auto i:ans) cout<<i<<' ';
		cout<<endl;
	}
}

