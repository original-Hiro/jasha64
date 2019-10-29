#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j(0),kase(0),x,y;
	bool fin(1);
	char puzzle[5][5],c;
	while (1)
	{
		for (i=0;i<5;i++)
			for (j=0;j<5;j++)
			{
				c=getchar();
				if (c=='\r'||c=='\n') {j--; continue;}
				puzzle[i][j]=c; 
				if (puzzle[0][0]=='Z') return 0;
				if (puzzle[i][j]==' ') {x=i; y=j;}
			}
		while (c=getchar())
			switch (c)
			{
				case 'A': if (x<1) {fin=0; break;}
						puzzle[x][y]=puzzle[x-1][y];
						puzzle[--x][y]=' '; break;
				case 'B': if (x>3) {fin=0; break;}
						puzzle[x][y]=puzzle[x+1][y];
						puzzle[++x][y]=' '; break;
				case 'R': if (y>3) {fin=0; break;}
						puzzle[x][y]=puzzle[x][y+1];
						puzzle[x][++y]=' '; break;
				case 'L': if (y<1) {fin=0; break;}
						puzzle[x][y]=puzzle[x][y-1];
						puzzle[x][--y]=' '; break;
				case '0': goto end;
				case '\r': case '\n': break;
				default: fin=0; break;
			}
end:	if (kase) cout<<endl;
		cout<<"Puzzle #"<<++kase<<':'<<endl;
		if (!fin) cout<<"This puzzle has no final configuration."<<endl;
		else for (i=0;i<5;i++)
			{
				for (j=0;j<5;j++)
				{
					if (j) cout<<' ';
					cout<<puzzle[i][j];
				}
				cout<<endl;
			}
		fin=1;
	}
	return 0;
}

