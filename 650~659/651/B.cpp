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
		vi odd,even;
		for (int i=0;i<2*n;i++) {
			int x; cin>>x;
			if (x%2) odd.pb(i+1);
			else even.pb(i+1);
		}
		int a=odd.size(),b=even.size();
		if (a%2) a--,b--;
		else if (a) a-=2;
		else b-=2;
		for (int i=0;i+1<a;i+=2) 
			cout<<odd[i]<<' '<<odd[i+1]<<endl;
		for (int i=0;i+1<b;i+=2) 
			cout<<even[i]<<' '<<even[i+1]<<endl;
	}
}

