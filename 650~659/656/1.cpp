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
		vi ar(3);
		for (auto &i:ar) cin>>i;
		sort(ar.begin(),ar.end());
		if (ar[1]!=ar[2]) cout<<"NO"<<endl;
		else cout<<"YES"<<endl<<ar[1]<<' '<<ar[0]<<' '<<1<<endl;
	}
}

