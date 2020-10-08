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
		vi ar(n),br(n);
		for (auto &i:ar) cin>>i;
		for (auto &i:br) cin>>i;
		if (n%2 and ar[n/2]!=br[n/2]) cout<<"No"<<endl;
		else {
			map<pii,int> dic;
			for (int i=0;i<n/2;i++) {
				if (ar[i]>ar[n-1-i]) swap(ar[i],ar[n-1-i]);
				dic[mp(ar[i],ar[n-1-i])]++;
			}
			int ok=1;
			for (int i=0;i<n/2;i++) {
				if (br[i]>br[n-1-i]) swap(br[i],br[n-1-i]);
				if (!dic[mp(br[i],br[n-1-i])]) {ok=0; break;}
				dic[mp(br[i],br[n-1-i])]--;
			}
			cout<<(ok?"Yes":"No")<<endl;
		}
	}
}

