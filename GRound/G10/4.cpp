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
		vi ar(n);
		for (int i=0;i<n;i++) if (s[(i-1+n)%n]==s[i] and s[i]==s[(i+1)%n]) ar[i]=1;
		int c=0;
		vi cr;
		if (ar[0] and ar.back()) c=1;
		int cur=0;
		for (auto i:ar) {
			if (i) cur++;
			else if (cur) cr.pb(cur),cur=0;
		}
		if (cur and c and cr.size()) cr[0]+=cur;
		else if (cur) cr.pb(cur);
		int ans=0;
		for (auto i:cr) ans+=(i+2)/3;
		cout<<ans<<endl;
	}
}

