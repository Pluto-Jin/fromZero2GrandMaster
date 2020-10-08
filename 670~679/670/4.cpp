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

const int N=1e5+5;
ll a[N],dif[N],ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		dif[i]=a[i]-a[i-1];
		if (i>1 and dif[i]>0) ans+=dif[i];
	}
	int q; cin>>q;
	cout<<max((a[1]+ans)/2,a[1]+ans-(a[1]+ans)/2)<<endl;
	for (int i=0;i<q;i++) {
		int l,r,x; cin>>l>>r>>x;
		if (l==1) a[1]+=x;
		else {
			ll pre=dif[l],cur=(dif[l]+=x);
			if (pre>0) ans-=pre;
			if (cur>0) ans+=cur;
		}
		if (r!=n) {
			ll pre=dif[r+1],cur=(dif[r+1]-=x);
			if (pre>0) ans-=pre;
			if (cur>0) ans+=cur;
		}
		cout<<max((a[1]+ans)/2,a[1]+ans-(a[1]+ans)/2)<<endl;
	}
}
