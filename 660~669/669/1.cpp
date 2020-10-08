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
		vi ar(n);
		int cnt=0;
		for (auto &i:ar) {
			cin>>i;
			if (i) cnt++;
		}
		if (cnt<=n/2) {
			cout<<n-cnt<<endl;
			for (int i=0;i<n-cnt;i++) cout<<0<<' '; cout<<endl;
		} else {
			cout<<cnt-cnt%2<<endl;
			for (int i=0;i<cnt-cnt%2;i++) cout<<1<<' '; cout<<endl;
		}
	}
}
