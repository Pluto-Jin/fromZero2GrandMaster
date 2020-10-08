#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int N=2e5+1;
ll mod=998244353;

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b%2) res=res*a%mod;
		b/=2;
		a=a*a%mod;
	}
	return res;
} 
ll solve(int n) {
	if (n==1) return 10;
	return (180*fpow(10,n-2)%mod+81*fpow(10,n-2)*(n-2)%mod)%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=n;i>=1;i--) {
		cout<<solve(i)<<' ';
	}
	cout<<endl;
}

