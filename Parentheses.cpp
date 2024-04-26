#include <iostream>

using namespace std;

bool IsValid(char* Combination,int n){
    int sum=0;
    for(int i=0;i<2*n;++i){
        if(Combination[i]=='('){
            sum++;
        }else if(Combination[i]==')'){
            sum--;
        }
        if(sum<0){
            return false;
        }
    }
    return sum == 0;
}
void PrintAll(char* Combination,int n,int idx){
    if(idx==2*n){
        if(IsValid(Combination,n)){
            for(int i=0;i<2*n;++i){
                cout << Combination[i];
            }
            cout<<endl;
            return;
        }else{
            return;
        }
    }
    Combination[idx]='(';
    PrintAll(Combination,n,idx+1);
    Combination[idx]=')';
    PrintAll(Combination,n,idx+1);
}

int main(){
    int n;
    cin >> n;
    char Combination[2*n+1];
    Combination[2*n] = '\0';
    PrintAll(Combination,n,0);
    return 0;
}