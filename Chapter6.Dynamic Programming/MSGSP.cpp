/*
	多段图的最短路径问题 
*/
#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

const int N = 10;
int arc[N][N];
void CreatGraph()
{
	memset(arc,-1,sizeof(arc));
	for(int i = 0; i < N; ++i)
		arc[i][i] = 0;
	int i,j,w;
	ifstream fp("MSG.txt",ifstream::in);
	string line;
	while(getline(fp,line)){
		stringstream liness(line);
		liness >> i >> j >> w;
		arc[i][j] = w;
	}
}
int BackPath()
{
	int cost[N];
	memset(cost,-1,sizeof(cost));
	int path[N];
	memset(cost,-1,sizeof(path));
	cost[0] = 0;
	path[0] = -1;
	for(int j = 1; j < N; ++j){
		for(int i = j - 1; i >= 0; --i){
			if(arc[i][j] != -1){
				if(cost[j] == -1){
					cost[j] = arc[i][j] + cost[i];
					path[j] = i;
				}
				else{
					if(arc[i][j] + cost[i] < cost[j]){
						cost[j] = arc[i][j] + cost[i];
						path[j] = i;					
					}
				}
			}
		}
	}
	cout << "path:";
	cout << N-1;
	int i = N-1;
	while(path[i] >= 0){
		cout << " <- " << path[i];
		i = path[i];
	}
	cout << ":";
	return cost[N-1];
}
int main()
{
	CreatGraph();
	cout << BackPath() << endl;
	return 0;
}
