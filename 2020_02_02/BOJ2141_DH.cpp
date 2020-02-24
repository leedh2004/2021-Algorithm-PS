#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{

    int n, i;
    cin >> n;
    ll sum = 0;
    vector<pair<int, int>> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second; //first 위치, second 사람 수
        sum += v[i].second;
    }
    sort(v.begin(), v.end());
    ll left = 0;                  // 왼쪽에 있는 사람 수
    ll right = sum; // 오른쪽에 있는 사람 수
    for (i = 0; v.size(); i++)
    {
        left += v[i].second;
        right -= v[i].second;
        if (left >= right)
            break;
    }
    cout << v[i].first;
    return 0;
}