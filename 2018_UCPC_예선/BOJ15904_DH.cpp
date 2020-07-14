#include <iostream>
#include <string>
#include <cstdio>

bool a, b, c, d;

using namespace std;
int main(){
    string s;
    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'U') a = true;
        if(s[i] == 'C' && a) b = true;
        if(s[i] == 'P' && b) c = true;
        if(s[i] == 'C' && c){
            cout << "I love UCPC";
            return 0;
        } 
    }
    cout << "I hate UCPC";
    return 0;
}