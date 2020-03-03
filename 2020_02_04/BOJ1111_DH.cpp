#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (n == 1)
    {
        cout << 'A';
        return 0;
    }

    if (n == 2)
    {
        if (v[0] == v[1])
            cout << v[0];
        else
            cout << 'A';
        return 0;
    }

    int a = 0, b = 0;

    int x = v[1] - v[0];
    int y = v[2] - v[1];
    if (x != 0)
    {
        a = y / x;
        b = v[1] - v[0] * a;
    }
    else
    {
        if (y == 0)
        {
            for (int i = 1; i < n; i++)
            {
                if (v[i] != v[i - 1])
                {
                    cout << 'B';
                    return 0;
                }
            }
            cout << v[0];
            return 0;
        }
        else
        {
            cout << 'B';
            return 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1]*a + b)
        {
            cout << 'B';
            return 0;
        }
    }
    cout << v[n-1]*a+b;

    return 0;
}