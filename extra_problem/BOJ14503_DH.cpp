//삼성기출문제 BFS DFS
#include <iostream>
using namespace std;

int arr[51][51];
//방문한 경우 2
int ans;
int r, c;

// 0 북, 1 동, 2 서, 3 남
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0 , -1 };


void go(int y, int x, int d) {

	if (arr[y][x] == 0) {
		arr[y][x] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++) {
		d = (d + 3) % 4;
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny >= 0 && nx >= 0 && ny < r && nx < c && arr[ny][nx] == 0)
			return go(ny, nx, d);
	}

	int ny = y - dy[d];
	int nx = x - dx[d];
	if (ny >= 0 && nx >= 0 && ny < r && nx < c && arr[ny][nx] != 1)
		return go(ny, nx, d);

}

int main() {
	
	cin >> r >> c;
	int y, x, d;
	cin >> y >> x >> d;
	// d = 0 북쪽
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	go(y, x, d);
	cout << ans;
	return 0;
}