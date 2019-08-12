#include<bits/stdc++.h>
using namespace std;
const int N = 10;
struct row {
	int h, zeros;
}Row[N];
int a[N][N],ans[N][N],v[3][N][N],b[82],maxx,ok;

int getScore(int i, int j) {
	if(i == 1 || j == 1 || i == 9 || j == 9) return 6;
	if(i == 2 || j == 2 || i == 8 || j == 8) return 7;
	if(i == 3 || j == 3 || i == 7 || j == 7) return 8;
	if(i == 4 || j == 4 || i == 6 || j == 6) return 9;
	return 10;
}

int calc(){
	int sum = 0;
	for(int i = 1; i < 10; i++) {
		for(int j = 1; j < 10; j++){
			sum += ans[i][j] * getScore(i, j);
		}
	}
	return sum;
}

void dfs(int pos){
	if(pos == 82){
		//¼ÆËãmaxx 
		ok = 1;
		maxx = max(maxx, calc());
		return;
	}
	int x = b[pos]/9 + 1, y = b[pos]%9 + 1;
	//cout << x << " " << y << endl;
	if(a[x][y] == 0) {
		for(int i = 1; i < 10; i++) {
			int g = (x-1)/3*3+(y-1)/3+1;
			if(!v[0][x][i]&&!v[1][y][i]&&!v[2][g][i]){
				ans[x][y] = i;
				v[0][x][i] = 1; v[1][y][i] = 1; v[2][g][i] = 1;
				dfs(pos+1);
				v[0][x][i] = 0; v[1][y][i] = 0; v[2][g][i] = 0;
			}
		}
	}else dfs(pos+1);
}

int main()
{	
	for(int i = 1; i < 10; i++){
		Row[i].h = i;
		Row[i].zeros = 0;
		for(int j = 1; j < 10; j++){
			cin >> a[i][j];
			if(a[i][j] == 0) Row[i].zeros++;
			else {
				int g = (i-1)/3*3 + (j-1)/3 + 1;
				//cout << "i " << i << " j " << j << " g " << g << endl;
				int val = a[i][j];
				ans[i][j] = val;
				v[0][i][val] = 1; v[1][j][val] = 1; v[2][g][val] = 1;
			}
		}
		//cout << Row[i].zeros << endl;
	}
	sort(Row+1, Row+1+9, [](row r1, row r2) {
		return r1.zeros < r2.zeros;
	});
	//cout << Row[1].zeros << endl;
	int num = 0;
	for(int i = 1; i < 10; i++) {
		for(int j = 1; j < 10; j++){
			int x = Row[i].h - 1, y = j - 1;
			num++;
			b[num] = x*9+y;
		}
	} 
	//cout << num << endl;
	dfs(1);
	//cout << ok << endl;
	if(ok == 1) {
		cout << maxx <<endl;
	}else {
		cout << "-1" << endl;
	}
	return 0;
}







