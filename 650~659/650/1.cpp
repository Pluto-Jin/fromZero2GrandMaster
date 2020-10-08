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
		string s,ans; cin>>s;
		for(int i=0;i<s.size();i+=2) ans+=s[i];
		ans+=s.back();
		cout<<ans<<endl;
	}
}

