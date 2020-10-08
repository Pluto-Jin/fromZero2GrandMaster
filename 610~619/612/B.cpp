#include "bits/stdc++.h"
using namespace std;

int n,k;
string tmp;
vector<string> ar;
map<string,int> dic;
int ans=0;

int main()
{
	cin>>n>>k;
	ar.resize(n);
	for (auto &i:ar) cin>>i;

	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			tmp="";
			for (int t=0;t<k;t++)
			{
				if (ar[i][t]==ar[j][t]) tmp+=ar[i][t];
				else tmp+='S'+'E'+'T'-ar[i][t]-ar[j][t];
			}
			if (dic.count(tmp)) ans+=dic[tmp];
		}
		dic[ar[i]]+=1;
	}
	cout<<ans<<endl;
}
