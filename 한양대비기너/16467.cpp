#include <iostream>
#include <vector>

using namespace std;


vector<pair<int,bool> > egg;

int t,k;
int now =1;
int num_of_chicken=1;



int arr[11];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>k;
        for(int i=1;i<=100;i++)
        {
            for(int j=0;j<egg.size();j++)
            {
                if(egg[j].first==now && egg[j].second==true)
                {
                    egg[j].second=false;
                    num_of_chicken++;
                }
            }
            cout<<num_of_chicken<<" ";
            for(int j=1;j<=num_of_chicken;j++) egg.push_back({now+k+1,true});
            now++;
        }
    }
    return 0;
}