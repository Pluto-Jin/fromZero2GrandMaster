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
		string s; cin>>s;
		int cnt[26]={0};
		vi ar;
		for (auto i:s) cnt[i-'a']++; 
		for (auto i:cnt) if (i) ar.pb(i);
		int ans=0;
		for (int i=1;i<=min(n,k);i++) {
			if (k%i) continue;
			int lo=1,hi=n/i+1;
			while (lo<hi-1) {
				int mid=(lo+hi)/2,tmp=0;
				for (auto i:ar) tmp+=i/mid;
				if (tmp>=i) lo=mid;
				else hi=mid;
			}
			ans=max(ans,i*lo);
		} 
		cout<<ans<<endl;
	}
}

