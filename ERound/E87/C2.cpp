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

#define PI 3.1415926535

double cal(double deg,double len) {
	return 2*sin(0.75*PI-deg)*len;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	cout<<setprecision(8)<<fixed;
	while (t--) {
		int n; cin>>n;
		double deg=PI/n,len=0.5/sin(deg/2),ans=0;
		for (int i=1;deg*i<PI/2;i++) ans=max(ans,cal(deg*i,len));
		cout<<ans<<endl;
	}
}

