#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while(t--) {
		int n,x,cnt[201]={0}; cin>>n>>x;
		for (int i=0;i<n;i++) {
			int tmp; cin>>tmp;
			cnt[tmp]=1;
		}
		int i;
		for (i=1;i<201;i++) {
			if (cnt[i]) continue;
			if (x) x--;
			else break;
		}
		cout<<i-1<<endl;

	}
}

