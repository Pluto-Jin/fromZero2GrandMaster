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

	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> ar;
		ar.resize(n);
		for (auto &i:ar) cin>>i;
		int ok=0;
		int a1=0,a2=0;
		for (int i=0;i<n;i++) {
			if (ar[i]%2==0) {cout<<1<<endl<<i+1<<endl;ok=1;break;}
			else if (!a1) a1=i+1;
			else a2=i+1;
		}
		if (ok) continue;
		if (!a2) cout<<-1<<endl;
		else cout<<2<<endl<<a1<<' '<<a2<<endl;
	}
}
