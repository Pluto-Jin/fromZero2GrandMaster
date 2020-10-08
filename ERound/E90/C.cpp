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
		string s; cin>>s;
		int cur=0,mi=0;
		ll ans=0;
		for (int i=0;i<s.size();i++) {
			if (s[i]=='+') cur++;
			else cur--;
			if (cur==-1 and i==s.size()-1) ans+=i+1;
			if (cur==-1 or i==s.size()-1) ans+=i+1,cur=0; 
		}
		cout<<ans<<endl;
	}
}

