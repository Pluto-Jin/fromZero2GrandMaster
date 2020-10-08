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

	int n; cin>>n;
	vi a(n),ans(n);
	for (auto &i:a) cin>>i;
	sort(a.begin(),a.end());
	int p1=0,p2=n-1,cnt=0;
	for (int i=0;i<n;i+=2) ans[i]=a[p2--];
	if (n%2==0) ans[n-1]=a[p2--];
	for (int i=1;i<n;i+=2) {
		if (!ans[i]) ans[i]=a[p2--];
		if (i<n-1 and ans[i]<ans[i-1] and ans[i]<ans[i+1]) cnt++;
	}
	cout<<cnt<<endl;
	for (auto i:ans) cout<<i<<' ';	
	cout<<endl;
}
