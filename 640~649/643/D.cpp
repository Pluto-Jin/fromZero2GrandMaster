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

	int n,s; cin>>n>>s;
	if (s<2*n) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		for (int i=1;i<n;i++) cout<<2<<' ';
		cout<<s-(2*n)+2<<endl<<1<<endl;
	}
}

