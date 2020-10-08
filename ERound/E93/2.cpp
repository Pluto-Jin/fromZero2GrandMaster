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
		s+='0';
		vi ar;
		for (int cur=0,i=0;i<s.size();i++) {
			if (s[i]=='1') cur++;
			else if (cur) ar.pb(cur),cur=0;
		}
		sort(ar.begin(),ar.end());
		int ans=0;
		for (int i=ar.size()-1;i>=0;i-=2) ans+=ar[i];
		cout<<ans<<endl;
	}
}

