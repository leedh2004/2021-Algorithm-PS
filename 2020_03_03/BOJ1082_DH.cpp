#include <iostream>
#include <string>

using namespace std;
int price[10];

int main(){
    int n;
    cin >> n;
    int min = 987654321;
    int minNumber = -1;
    for(int i=0; i<n; i++){
        cin >> price[i];
        if(price[i] <= min){ // 등호로 후에 선택한 숫자로 갱신
            min = price[i];
            minNumber = i;
        }
    }
    string ans="";
    int cost; cin >> cost;
    while(cost - min >= 0){
        ans += minNumber +'0';
        cost -= min;
    }
    //현재 가장 긴 글자를 만들었을 때 남아있는 돈 cost
    
    bool flag = true;
    for(int i=0; i<ans.size() && flag == true; i++){
        flag = false;
        for(int j=n-1; j>minNumber; j--){
            if(cost + min - price[j] >= 0){
                ans[i] = j + '0';
                cost = cost + min - price[j];
                flag = true;
                break;
            }
        }
    }
    if(ans == "0"){
        cout << '0';
        return 0;
    }
    if(ans[0] == '0'){ // 0000이 출력된 경우임.
        while(ans[0] == '0'){
            int s = ans.size();
            cost += min;
            ans = ans.substr(1, ans.size()-1);
            bool flag = true;
            for(int i=0; i<ans.size() && flag == true; i++){
                flag = false;
                for(int j=n-1; j>minNumber; j--){
                    if(cost + min - price[j] >= 0){
                        ans[i] = j + '0';
                        cost = cost + min - price[j];
                        flag = true;
                        break;
                    }
                }
            }
            if(ans.size() == 1 && ans[0] == '0') cout << '0';
        }
        cout << ans;
    }else
        cout << ans;
    return 0;
}