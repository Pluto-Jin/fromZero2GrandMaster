#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int ok=0,ar[5001]={0};
		for (int i=1;i<=n;i++) {
			int tmp; cin>>tmp;
			if (!ar[tmp]) ar[tmp]=i;
			if (ar[tmp]<i-1) ok=1;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}
