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
#include<ctime>
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
		ll mi[6]={1},ma[6]={1};
		for (int i=1;i<=5;i++) mi[i]=1e18,ma[i]=-1e18;
		for (int i=0;i<n;i++) {
			ll x; cin>>x;
			for (int k=5;k;k--) if (mi[k-1]!=1e18) {
				ll a=x*mi[k-1],b=x*ma[k-1];
				mi[k]=min(mi[k],min(a,b));
				ma[k]=max(ma[k],max(a,b));
			}
		}
		cout<<ma[5]<<endl;
	}
}
