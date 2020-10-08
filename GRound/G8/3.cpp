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

	int n; cin>>n;
	cout<<7*n<<endl;
	for (int i=0;i<n*2+1;i++) cout<<i<<' '<<1<<endl; 
	for (int i=1;i<n*2+1;i+=2) cout<<i<<' '<<0<<endl<<i<<' '<<2<<endl;
	for (int i=1;i+2<n*2;i+=4) for (int j=0;j<3;j++) cout<<i+j<<' '<<3<<endl;
	for (int i=3;i+2<n*2;i+=4) for (int j=0;j<3;j++) cout<<i+j<<' '<<-1<<endl;
	if (n%2) cout<<0<<' '<<0<<endl<<2*n<<' '<<2<<endl;
	else cout<<0<<' '<<0<<endl<<2*n<<' '<<0<<endl;
}

