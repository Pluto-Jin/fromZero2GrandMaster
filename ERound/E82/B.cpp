#include "bits/stdc++.h"
using namespace std;

int main()
{
	int T;
	cin>>T;
	while (T--) {
		int n,g,b;
		cin>>n>>g>>b;
		if (g>=b or n<=2*g) cout<<n<<endl;
		else {
			long long gg=n/2+n%2;
			long long bb=n-gg;
			long long tmp=max(ceil(gg*1.0/g),ceil(bb*1.0/b));
			if (ceil(gg*1.0/g)>ceil(bb*1.0/b)) 
				cout<<(tmp-1)*(g+b)+gg-(tmp-1)*g<<endl;
			else
				cout<<(tmp-1)*(g+b)+bb-(tmp-1)*b+gg-(tmp-1)*g<<endl;
		}
	}
}
