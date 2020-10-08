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
		int n=s.size();
		vi cnt1(n),cnt0(n);
		for (int i=0;i<n;i++) {
			if (s[i]=='1') cnt1[i]=1;
			if (i) cnt1[i]+=cnt1[i-1];	
			cnt0[i]=i+1-cnt1[i];
		}
		int ans=10000;
		for (int i=0;i<n;i++) ans=min(ans,cnt1[i]+cnt0[n-1]-cnt0[i]),ans=min(ans,cnt0[i]+cnt1[n-1]-cnt1[i]);
		cout<<ans<<endl;
	}
}

