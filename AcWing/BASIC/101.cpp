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

const int N=1e5+1;
int ar[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,p,h,m; cin>>n>>p>>h>>m;
	set<pii> s;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		if (x>y) swap(x,y);
		if (s.count(mp(x,y))) continue;
		s.insert(mp(x,y));
	}
	for (auto [x,y]:s) ar[x+1]--,ar[y]++;
	for (int i=1;i<=n;i++) cout<<(ar[i]+=ar[i-1])+h<<endl;
}
