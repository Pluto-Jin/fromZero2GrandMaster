#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		ll n,k; cin>>n>>k;
		string s(n,'a');
		for (ll i=1;i<n;i++) {
			ll tmp=i*(i+1)/2;
			if (k<=tmp) {
				ll x=k-(i*(i-1)/2);
				s[n-i-1]='b';
				s[n-x]='b';
				break;
			}
		}
		cout<<s<<endl;
	}
}

