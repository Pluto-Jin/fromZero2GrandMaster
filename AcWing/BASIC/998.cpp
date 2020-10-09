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

const int N=1e5;
int ar[N];
bitset<30> b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=0;i<n;i++) {
		string s; cin>>s;
		ar[i]=s[0];
		int t; cin>>t;
		b[i]=bitset<30>(t);
	}
	int ans=0,flg=0;
	for (int i=29;~i;i--) {
		int a[2]={0,1},tmp=m>>i&1;
		for (int k=0;k<=1;k++) for (int j=0;j<n;j++) {
			if (ar[j]=='A') a[k]&=b[j][i];
			if (ar[j]=='O') a[k]|=b[j][i];
			if (ar[j]=='X') a[k]^=b[j][i];
 	    }
		if (a[0] or a[1] and flg|tmp) ans+=1<<i;
		if (a[0]>=a[1] and tmp) flg=1;
	}
	cout<<ans<<endl;

	return 0;
}
