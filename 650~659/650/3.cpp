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
		int cnt=0,pre=-1,ans=0;
		for (int i=0;i<n and s[i]!='1';i++) cnt++,pre=i;
		if (cnt==n) cout<<(n-1)/(k+1)+1<<endl;
		else {
			pre++;
			ans+=cnt/(k+1);
			for (int i=pre+1;i<n;i++) if (s[i]=='1') ans+=(i-pre)/(k+1)-1,pre=i;	
			ans+=(n-pre-1)/(k+1);
			cout<<ans<<endl;
		}
	}
}

