#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
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
	vector<ll> ar(n); 
	for (auto &i:ar) cin>>i;
	if (n==1) {
		cout<<1<<' '<<1<<endl<<-ar[0]<<endl;
		for (int i=0;i<2;i++) cout<<1<<' '<<1<<endl<<0<<endl;
		return 0;
	}
	cout<<1<<' '<<n-1<<endl;
	for (int i=0;i<n-1;i++) {
		ll tmp=ar[i]*(n-1);
		cout<<tmp<<' ';
		ar[i]+=tmp;
	}
	cout<<endl;
	cout<<2<<' '<<n<<endl;
	for (int i=0;i<n-2;i++) cout<<0<<' ';
	cout<<ar[n-1]*(n-1)<<endl;
	ar[n-1]+=ar[n-1]*(n-1);
	cout<<1<<' '<<n<<endl;
	for (int i=0;i<n;i++) cout<<-ar[i]<<' '; cout<<endl;
}
