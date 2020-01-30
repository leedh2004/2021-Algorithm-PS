#include <iostream>
using namespace std;
int map[50][50];
int w, h;
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

void dfs(int y, int x){
	map[y][x] = -1;
	for(int i=0; i<8; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny >= 0 && ny < h && nx >=0 && nx < w && map[ny][nx] == 1){
			dfs(ny, nx);
		}
	}
}

int main(){
	cin >> w >> h;
	while(w!=0 && h!=0){
		int ans = 0;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin >> map[i][j];
			}
		}
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(map[i][j] == 1){
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << endl;
		cin >> w >> h;
	}
	return 0;
}