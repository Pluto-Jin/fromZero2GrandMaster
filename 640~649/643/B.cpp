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
		vi ar(n);
		for (auto &i:ar) cin>>i;
		sort(ar.begin(),ar.end());
		int p=0,ans=0;
		while (p<n) {
			int cur=1,tmp;
			while (p<n and cur<ar[p]) tmp=ar[p],p+=tmp-cur,cur=tmp;
			if (p<n) ans++,p++;
		}
		cout<<ans<<endl;
	}
}

