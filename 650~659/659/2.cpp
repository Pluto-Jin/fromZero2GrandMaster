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
		int n,k,l; cin>>n>>k>>l;
		vi h(n),safe;
		safe.pb(-1);
		int ok=1;
		for (int i=0;i<n;i++) {
			cin>>h[i];
			if (h[i]+k<=l) safe.pb(i);
			if (h[i]>l) ok=0;
		}
		safe.pb(n);
		for (int i=0;ok and safe[i]<n-1;i++) {
			int cur=l-h[safe[i]+1];
			if (cur<0) ok=0;
			for (int j=safe[i]+2;ok and j<safe[i+1];j++) {
				cur=min(cur-1,l-h[j]);
				if (cur<0 and h[j]-cur>l) ok=0; 
			} 
		}
		cout<<(ok?"Yes":"No")<<endl;
	}
}

