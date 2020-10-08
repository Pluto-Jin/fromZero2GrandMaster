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
		vii ar(n);
		for (int i=0;i<n;i++) {
			int tmp; cin>>tmp;
			ar[i]=mp(tmp,i);
		}
		stable_sort(ar.begin(),ar.end());

		int cur=1,ans=1;
		for (int i=1;i<n;i++) {
			if (ar[i].se>ar[i-1].se) cur++,ans=max(ans,cur);
			else cur=1;
		}
		cout<<n-ans<<endl;
	}
}

