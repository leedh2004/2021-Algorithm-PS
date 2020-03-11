#include <string>
#include <iostream>
using namespace std;

int lcs[101][101][101]; // lcs[i][j][k] = if(a[i] == .. ) lis[i-1][j-1][k-1] + 1
                        // lcs[i][j][k] max(lcs[i-1][j][k], lcs[])..
int main(){
    string a, b, c;
    cin >> a >> b >> c;
    for(int i=1; i <= a.size(); i++){
        for(int j=1; j <= b.size(); j++){
            for(int k=1; k <= c.size(); k++){
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
                    lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
                }
                else{
                    lcs[i][j][k] = max(lcs[i-1][j][k], max(lcs[i][j-1][k], lcs[i][j][k-1]));
                }
            }
        }
    }
    cout << lcs[a.size()][b.size()][c.size()];
    return 0;
}