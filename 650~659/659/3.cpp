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
		set<int> ar[20];
		string a,b; cin>>a>>b;
		int ok=1;
		for (int i=0;i<n;i++) {
			if (a[i]==b[i]) continue;
			if (a[i]>b[i]) ok=0;
			ar[a[i]-'a'].insert(b[i]-'a');
		}
		if (!ok) {cout<<-1<<endl;continue;}
		int ans=0;
		for (int i=0;i<20;i++) {
			if (ar[i].empty()) continue;
			int mi=20;
			for (auto j:ar[i]) mi=min(j,mi);
			for (auto j:ar[i]) if (j!=mi) ar[mi].insert(j);
			ans++;
		}
		cout<<ans<<endl;
	}
}

