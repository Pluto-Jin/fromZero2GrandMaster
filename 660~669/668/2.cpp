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
		vector<ll> ar(n);
		vi pos; 
		for (int i=0;i<n;i++) {
			cin>>ar[i];
			if (ar[i]>0) pos.pb(i);
		}
		ll cur=0,ans=0;
		for (auto i:ar) if (i) {
			if (i>0) cur+=i;
			else {
				ll tmp=-i;
				if (cur>tmp) cur-=tmp,tmp=0;
				else tmp-=cur,cur=0;
				ans+=tmp;
				while (tmp) {
					ll &ttmp=ar[pos.back()];
					if (ttmp<=tmp) tmp-=ttmp,ttmp=0,pos.ppb();
					else ttmp-=tmp,tmp=0;
				}	
			}
		}
		cout<<ans<<endl;
	}
}
