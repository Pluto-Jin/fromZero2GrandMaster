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
	vi ar;
	ar.pb(2);
	for (int i=1;i<1e5;i++) {
		int tmp=ar.back();
		tmp+=3*i+2;
		ar.pb(tmp);
		if (tmp>1e9) break;
	}
	while (t--) {
		int n,p,ans=0; cin>>n;
		for (int i=0;i<ar.size();i++) {
			if (ar[i]>n) {
				p=i;
				break;
			}
		}
		while (1) {
			while (p>=0 and ar[p]>n) p--;
			if (p<0) break; 
			n-=ar[p];
			ans++;
		}
		cout<<ans<<endl;
	}
}

