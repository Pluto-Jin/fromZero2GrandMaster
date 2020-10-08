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
		int n,k; cin>>n>>k;
		string s,s0; cin>>s;
		for (int i=0;i<k-1;i++) s0+="()";
		for (int i=0;i<n/2-k+1;i++) s0+='(';
		for (int i=0;i<n/2-k+1;i++) s0+=')';
		vii ans;
		for (int i=0,p=0;i<n;i++) {
			if (p<i) p=i;
			if (s[i]!=s0[i]) {
				while (s[p]!=s0[i]) p++;
				ans.pb(mp(i,p));
				s[p]='('+')'-s[p];	
			}
		}
		cout<<ans.size()<<endl;
		for (auto [a,b]:ans) cout<<a+1<<' '<<b+1<<endl;
	}
}

