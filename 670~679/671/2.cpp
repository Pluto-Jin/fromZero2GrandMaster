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
	vector<ll> a;
	for (ll cur=1;cur<=(1ll<<31);cur=cur*2+1) a.pb(cur*(cur+1)/2);
	while (t--) {
		ll x; cin>>x;
		int ans=0;
		for (int i=0;i<a.size();i++) {
			if (x>=a[i]) x-=a[i],ans++;
		}
		cout<<ans<<endl;
	}
}
