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
		int cnt[3]={0};
		for (auto c:s) 
			if (c=='R') cnt[0]++; 
			else if (c=='P') cnt[1]++; 
			else cnt[2]++;
		int ans=max(max(cnt[0],cnt[1]),cnt[2]);	
		char ch;
		if (cnt[0]==ans) ch='P';
		else if (cnt[1]==ans) ch='S';
		else ch='R';
		for (int i=0;i<s.size();i++) cout<<ch;
		cout<<endl;
	}
}

