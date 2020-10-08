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

int query(ll x) {cout<<x<<endl<<flush;int tmp;cin>>tmp;if (!tmp) exit(0);return tmp-1;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll ar[3],br[3];
	for (int i=0;i<3;i++) cin>>ar[i],br[i]=ar[i];
	sort(br,br+3);
	cout<<"First"<<endl;
	ll x=br[0],y=br[1],z=br[2];
	int tmp=query(z-y+z-x);
	if (ar[tmp]==x) query(z-y);
	if (ar[tmp]==y) query(z-x);
	if (ar[tmp]==z) {
		z=3*z-x-y;
		tmp=query(z-y+z-x);
		if (ar[tmp]==x) query(z-y);
		if (ar[tmp]==y) query(z-x);
	}
}

