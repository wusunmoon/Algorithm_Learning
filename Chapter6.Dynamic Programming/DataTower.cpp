#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5;
int d[N][N] = {
	8,0,0,0,0,
	12,15,0,0,0,
	3,9,6,0,0,
	8,10,5,12,0,
	16,4,18,10,9
};
int Recu_DataTower(int d[][N], int i, int j);
int DP_DataTower(int d[][N]);
int main()
{
	cout << Recu_DataTower(d,0,0) << endl;
	cout << DP_DataTower(d) << endl;
	return 0;
}

int Recu_DataTower(int d[][N], int i, int j)
{
	if(i == N - 1)
		return d[i][j];
	else{
		return d[i][j] + max(Recu_DataTower(d,i+1,j),Recu_DataTower(d,i+1,j+1));
	}
}
int DP_DataTower(int d[][N])
{
	int maxAdd[N][N] = {0};
	int path[N][N] = {0};
	for(int i = N-1,j = 0; j < N; ++j)
		maxAdd[i][j] = d[i][j];
	for(int i = N-2; i >= 0; --i){
		for(int j = 0; j <= i; ++j){
			maxAdd[i][j] = d[i][j] + max(maxAdd[i+1][j],maxAdd[i+1][j+1]);
			if(maxAdd[i+1][j] > maxAdd[i+1][j+1])
				path[i][j] = j;
			else
				path[i][j] = j+1;
		}
	}
	
	cout << "Path:" ;
	for(int i = 0,j = 0; i < N; ++i){
		cout << d[i][j];
		if(i < N - 1)
			cout << "->";
		else
			cout << ":";
		j = path[i][j];		
	}
	return maxAdd[0][0];
}
