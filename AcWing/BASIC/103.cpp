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

const int N=2e5+1;
map<int,int> cnt;
int b[N],c[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		cnt[x]++;
	}
	int m; cin>>m;
	for (int i=0;i<m;i++) cin>>b[i];
	for (int i=0;i<m;i++) cin>>c[i];
	int ma=-1,ans;
	for (int i=0;i<m;i++) if (cnt[b[i]]>ma) ma=cnt[b[i]];
	for (int i=0,tmp=-1;i<m;i++) if (cnt[b[i]]==ma and cnt[c[i]]>tmp) tmp=cnt[c[i]],ans=i;
	cout<<ans+1<<endl;
}
