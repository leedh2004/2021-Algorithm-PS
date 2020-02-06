#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct p {int y; int x;};

vector<p> house; // 집의 좌표 배열
vector<p> chicken; // 치킨집 좌표 배열
int n, m;
int ans = 987654321;

int find_distance(p a, p b){
    return abs(a.y - b.y) + abs(a.x - b.x);
}

void solve(int cur, vector<p> selected){
    if(cur == chicken.size()+1) return;
    
    if(selected.size() == m){
        int sum = 0;
        for(int i=0; i<house.size(); i++){
            int distance = 987654321;
            for(int j=0; j<m; j++){
                distance = min(distance, find_distance(house[i], selected[j])) ;
            }
            sum += distance;
        }
        ans = min(ans, sum);
        return;
    }
    solve(cur+1, selected);
    selected.push_back(chicken[cur]);
    solve(cur+1, selected); // 이 곳을 선택함
    selected.pop_back();
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            if(temp == 1) {
                house.push_back({i, j});
            }else if(temp == 2){
                chicken.push_back({i, j});
            }
        }
    }
    vector<p> path;
    solve(0, path);
    cout << ans;
    return 0;
}