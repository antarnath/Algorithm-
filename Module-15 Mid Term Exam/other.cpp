
#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#define in_range(x, y, r, c) (x < r && y < c && x >= 0 && y >= 0)
using namespace std;

char mat[51][51];
int r, c, dis[51][51];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j, int dist){

	dis[i][j] = dist+1;

    for(int l=0;l<8;l++){
        int x = i + dx[l];
        int y = j + dy[l];

        if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		    dfs(x, y, dis[i][j]);
	    }
    }
	
	
}

int main(){
	
	int max, tc=0;
	
	while(true){
		scanf("%d%d", &r, &c);
		if(!r && !c)
			break;
		tc++;
		for(int i=0;i<r;i++){
			scanf("%s", mat[i]);
			for(int j=0;j<c;j++)
				dis[i][j] = 0;
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(mat[i][j] == 'A' && dis[i][j] == 0)
					dfs(i, j, 0);
			}
		}
		max = dis[0][0];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				if(max < dis[i][j])
					max = dis[i][j];
		}
		printf("Case %d: %d\n", tc, max);
	}
    return 0;
}