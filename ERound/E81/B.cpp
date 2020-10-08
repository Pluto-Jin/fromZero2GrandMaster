#include "bits/stdc++.h"
using namespace std;

int t,n,x,i;
int sum,mi,ma,tmp;
string s;
map<int,int> dict;
vector<int> ans;

int main()
{
	cin>>t;
	while (t--)
	{
		dict.clear();
		sum=0;
		mi=pow(10,9);
		ma=-pow(10,9);
		cin>>n>>x;
		cin>>s;
		for (i=0;i<n;i++)
		{
			if (int(s[i])-int('0'))
				sum--;
			else
				sum++;
			mi=(sum<mi)?sum:mi;
			ma=(sum>ma)?sum:ma;
			if (dict.count(sum))
				dict[sum]++;
			else
				dict.insert(pair<int,int>(sum,1));
		}
		tmp=x==0;
		while (1)
		{
			if (mi<=x and x<=ma)
			{
				if (sum==0)
				{
					ans.push_back(-1);
					break;
				}
				else
				{
					tmp+=dict[x];
					x-=sum;
				}
			}
			else
			{
				x-=sum;
				if (sum>=0 and x<=0 or sum<=0 and x>=0)
				{
					ans.push_back(tmp);
					break;
				}
				if (x>ma)
					x-=ceil(1.0*(x-ma)/sum)*sum;
				if (x<mi)
					x-=ceil(1.0*(x-mi)/sum)*sum;

			}
		}
	}

	for (auto i:ans)
		cout<<i<<endl;
}
