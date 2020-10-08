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
		string s; cin>>s;
		int m; cin>>m;
		vi ans(m),ar(m);
		for (auto &i:ar) cin>>i;

		int cnt[26]={0},cur=25;
		for (int i=0;i<s.size();i++) cnt[s[i]-'a']++;
		vi tmp;
		while (tmp.size()<m) {
			vi ttmp;
			for (int i=0;i<m;i++) {
				int res=0,vis=0;
				for (auto j:tmp) {
					if (j==i) vis=1; 
					res+=abs(j-i);
				}
				if (vis or res!=ar[i]) continue;
				ttmp.pb(i);
			}
			while (cnt[cur]<ttmp.size()) cur--;
			for (auto i:ttmp) tmp.pb(i),ans[i]=cur;
			cur--;
		}
		for (auto i:ans) cout<<char(i+'a'); cout<<endl;
	}
}

