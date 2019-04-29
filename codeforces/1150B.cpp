#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	vector<string> board(n);
	for(int i = 0; i < n; ++i) cin>>board[i];
	for(int i = 1; i < n-1; ++i)
	{
		for(int j = 1; j < n-1; ++j)
		{
			if(board[i][j] == '.' && board[i-1][j] == '.' && board[i+1][j] == '.'
					&& board[i][j-1] == '.' && board[i][j+1] == '.')
			{
				board[i][j] = '#';
				board[i+1][j] = '#';
				board[i-1][j] = '#';
				board[i][j+1] = '#';
				board[i][j-1] = '#';
			}
		}
	}
	bool ok = true;
	for(int i = 0; i < n && ok; ++i)
	{
		for(int j = 0; j < n && ok; ++j)
		{
			if(board[i][j] == '.') ok = false;
		}
	}
	cout<<(ok?"YES":"NO")<<endl;
	return 0;
}
