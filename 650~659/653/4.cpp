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
		map<int,int> dic;
		int ma=1,id=1e9;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			if (x%k) {
				if (++dic[x%k]>ma) ma=dic[x%k],id=x%k;
				else if (dic[x%k]==ma) id=min(id,x%k);
			}
		}	
		cout<<(id==1e9?0:1ll*(ma-1)*k+(k-id)%k+1)<<endl;
	}
}

