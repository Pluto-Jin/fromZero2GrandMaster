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
		int ok=1,tmp[3]={0};
		for (int i=0;i<n;i++) {
			if (ar[i]<br[i]) {
				if (!tmp[2]) {ok=0;break;} 
			}
			if (ar[i]>br[i]) {
				if (!tmp[0]) {ok=0;break;}
			}
			tmp[ar[i]+1]=1;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}

