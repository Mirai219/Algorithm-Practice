#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    char a[100];
    char b[100];
    cin>>a;
    cin>>b;

    int d[100][100];

    for(int i=0;i<99;++i){
        d[0][i]=i;
        d[i][0]=i;
    }

    for(int i=1;i<100;++i){
        for(int j=1;j<100;++j){
            if (a[i-1]==b[j-1]){
                d[i][j]=d[i-1][j-1];
            }

            else{
                d[i][j]= min(min(d[i-1][j],d[i][j-1]),d[i-1][j-1])+1;
            }
        }
    }

    cout<<d[strlen(a)][strlen(b)];

    return 0;
}