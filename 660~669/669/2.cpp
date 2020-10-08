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
		int cnt[1001]={0},ma=0;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			cnt[x]++;
			ma=max(x,ma);
		}
		vi mul[1001];
		for	(int i=2;i<=ma;i++) 
			for (int j=i;j<=ma;j+=i) if (cnt[j]) mul[i].pb(j);
		int cur=ma;
		while (1) {
			for (auto i:mul[cur]) {
				for (int k=0;k<cnt[i];k++) cout<<i<<' ';
				cnt[i]=0;
			}
			int ok=1;
			for (int i=cur/2;ok and i>1;i--) if (cur%i==0) {
				for (auto j:mul[i]) if (cnt[j]) {
					cur=i; ok=0;
					break;
				}
			}
			if (ok) break;
		}
		for (int i=1;i<=ma;i++) for (int j=0;j<cnt[i];j++) cout<<i<<' ';
		cout<<endl;
	}
}
