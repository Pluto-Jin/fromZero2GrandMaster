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
		int n,k; cin>>n>>k;
		string s; cin>>s;
		vi ar;
		for (int i=0;i<n;i++) ar.pb(s[i]-'a');
		sort(ar.begin(),ar.end());
		if (ar[k-1]!=ar[0]) cout<<char('a'+ar[k-1]);
		else {
			cout<<char('a'+ar[0]);
			if (ar[n-1]==ar[k]) for (int i=1;i<n/k+(n%k!=0);i++) cout<<char('a'+ar[k]);
			else for (int i=k;i<n;i++) cout<<char('a'+ar[i]);
		}
		cout<<endl;
	}
}


