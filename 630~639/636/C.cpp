#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi ar(n);
		for (auto &i:ar) cin>>i;
		int sg=0,cur=0;
		ll ans=0;
		for (int i=0;i<n;i++) {
			if (ar[i]>0) {
				if (!sg) cur=ar[i];
				else if (sg==1) cur=max(cur,ar[i]);
				else ans+=cur,cur=ar[i];
				sg=1;
			} 
			else {
				if (!sg) cur=ar[i];
				else if (sg==-1) cur=max(cur,ar[i]);
				else ans+=cur,cur=ar[i];
				sg=-1;
			}
		}
		ans+=cur;
		cout<<ans<<endl;
	}
}

