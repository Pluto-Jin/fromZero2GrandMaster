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
		int n,x; cin>>n>>x;
		int sum=0,ok=0,sa=1;
		for (int i=0;i<n;i++) {
			int a; cin>>a;
			sum+=a;
			if (a==x) ok=1;
			else sa=0;
		}
		if (sa) cout<<0<<endl;
		else if (sum==x*n or ok) cout<<1<<endl;
		else cout<<2<<endl;
	}
}
