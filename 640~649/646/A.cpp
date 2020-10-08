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
		int od=0,ev=0;
		for (int i=0;i<n;i++) {
			int tmp; cin>>tmp;
			if (tmp%2) od++; 
			else ev++;
		}
		if (od and (x<=ev or (x-ev)%2 or ev and x<n)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;	

	}
}

