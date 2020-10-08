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
		int n,x; cin>>n>>x;
		vi ar(n);
		for (auto &i:ar) cin>>i;
		sort(ar.begin(),ar.end());
		int pos=lower_bound(ar.begin(),ar.end(),x)-ar.begin(),ans=n-pos;
		for (int i=pos-1,cnt=1;i>=0;i--) {
			if (ar[i]*cnt>=x) ans++,cnt=1;
			else cnt++;	
		}
		cout<<ans<<endl;	
	}
}


