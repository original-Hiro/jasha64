#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int chengfang(int a,int b)
{
	int i,s(1);
	for (i=0;i<b;i++) s*=a;
	return s;
}
int stoi(string &s)
{
	int i(0);
	int k;
	for (k=0;k<s.size();k++)
	{
		if (s[k]<48||s[k]>57) break;
		else i+=(s[k]-48)*chengfang(10,s.size()-k-2);
	}
	return i;
}
int main()
{
	string s,s1;
	int p1(0),p2(0),i,j(0),k,n(0),a[1005],f[1005],num(0),c;
	bool first_num(1),skip[1005]={0},end(0);
	while (getline(cin,s))
	{
		s+=" ";
		for (i=0;i<s.size();i++)
			if (s[i]==' ')
			{
				if (first_num==1)
				{
					s1=s.substr(0,i);
					s1+=" ";
					first_num=0;
					a[j]=stoi(s1);
					f[j]=1;
					j++;
					p1=i;
				}
				else
				{
					p2=p1;
					p1=i;
					s1=s.substr(p2+1,i-p2);
					a[j]=stoi(s1);
					f[j]=1;
					j++;
				}
			}
		for (i=1;i<j;i++)
			for (k=0;k<i;k++)
				if (a[k]>a[i]) 
				{
					f[i]=max(f[i],f[k]+1);
					skip[i]=1;
				}
		for (i=0;i<j;i++)
			if (f[i]>num)
			{
				num=f[i];
				skip[i]=1;
			}
		while (end==0)
		{
			n++;
			for (i=0;i<j;i++)
			{
				f[i]=1;
				if (skip[i]==1) a[i]=0x7ffffff;
				skip[i]=0;
			}
			for (i=0;i<j;i++)
				for (k=1;k<=j-i;k++)
					if (a[i]==0x7ffffff)
						if (a[i+k]!=0x7ffffff)
						{
							a[i]=a[i+k];
							a[i+k]=0x7ffffff;
							break;
						}
			for (i=0;i<j;i++)
				if (a[i]==0x7ffffff)
				{
					j=i;
					break;
				}
			for (i=1;i<j;i++)
				for (k=0;k<i;k++)
					if (a[k]>a[i]) 
						f[i]=max(f[i],f[k]+1);
			c=0;
			for (i=0;i<j;i++)
				if (f[i]>c)
				{
					c=f[i];
					skip[i]=1;
				}
			if (j==0) end=1;
		}
		cout<<num<<endl<<n<<endl;
	}
	return 0;
}

