#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;
	while (t--) {
		int n,k;
		cin>>n>>k;
		vector<ll> ar;
		ar.resize(n);
		for (auto &i:ar) cin>>i;

		vector<vector<int>> br;
		br.resize(n);
		int ok=1,mlen=0;
		for (int i=0;i<n;i++) {
			while (ar[i]) {if(ar[i]%k!=1 and ar[i]%k!=0) {ok=0;break;} br[i].pb(ar[i]%k);ar[i]/=k;}
			if (!ok) break;
			int tmp=br[i].size();
			mlen=max(mlen,tmp);
		}
		if (!ok) cout<<"NO"<<endl;
		else {
			for (int i=0;i<mlen;i++) {
				int sum=0;
				for (int j=0;j<n;j++) {
					if (br[j].size()<=i) continue;
					sum+=br[j][i];
					if (sum>1) {ok=0;break;}
				}
				if (!ok) break;
			}
			if (!ok) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
}
