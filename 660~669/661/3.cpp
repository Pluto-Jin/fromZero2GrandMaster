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
		int ans=0;
		for (int i=2;i<=100;i++) {
			int p1=0,p2=n-1;
			int cur=0;
			while (p1<p2) {
				while (p1<p2 and ar[p1]+ar[p2]<i) p1++;
				while (p1<p2 and ar[p1]+ar[p2]>i) p2--;
				if (p1<p2 and ar[p1]+ar[p2]==i) cur++,p1++,p2--;
			}
			ans=max(ans,cur);
		}
		cout<<ans<<endl;

	}
}

