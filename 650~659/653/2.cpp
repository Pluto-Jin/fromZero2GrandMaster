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
		int cnt2=0,cnt3=0;
		while (n%2==0) n/=2,cnt2++;
		while (n%3==0) n/=3,cnt3++;
		if (n!=1 or cnt2>cnt3) cout<<-1<<endl;
		else cout<<cnt3-cnt2+cnt3<<endl;
	}
}

