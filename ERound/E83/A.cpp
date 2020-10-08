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
		int n,m;
		cin>>n>>m;
		cout<<(n%m==0?"YES":"NO")<<endl;
	}
}
