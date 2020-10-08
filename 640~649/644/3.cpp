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
		int od=0,ev=0;
		for (auto &i:ar) {
			cin>>i;
			if (i%2) od++;
			else ev++;
		}
		sort(ar.begin(),ar.end());
		int ok=0;
		for (int i=1;i<n;i++) if (ar[i]-ar[i-1]==1) ok=1;
		cout<<(ok or od%2==0?"YES":"NO")<<endl;
	}
}


