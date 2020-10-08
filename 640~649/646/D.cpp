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

int query(int lo,int hi) {
	cout<<"? "<<hi-lo+1;
	for (int i=lo;i<=hi;i++) cout<<" "<<i;
	cout<<endl;
	cout.flush();
	int res; cin>>res;
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k; cin>>n>>k;
		vector<set<int>> ar;
		ar.resize(k);
		for (int i=0;i<k;i++) {
			int c; cin>>c;
			for (int j=0;j<c;j++) {
				int x; cin>>x;
				ar[i].insert(x);
			}
		}
		int mid,lo=1,hi=n,ma=query(1,n);
		while (lo<hi) {
			mid=(lo+hi)/2;
			int res=query(lo,mid);
			if (res==ma) hi=mid;
			if (res<ma) lo=mid+1;	
		}
		vi pwd;
		for (int i=0;i<k;i++) {
			if (ar[i].count(lo)) {
				cout<<"? "<<n-ar[i].size();
				for (int j=1;j<=n;j++) if (!ar[i].count(j)) cout<<" "<<j;
				cout<<endl;
				cout.flush();
				int res; cin>>res;
				pwd.pb(res);
			}
			else pwd.pb(ma);
		}
		cout<<"!";
		for (auto i:pwd) cout<<" "<<i;
		cout<<endl;
		cout.flush();
		string s; cin>>s;
	}
}

