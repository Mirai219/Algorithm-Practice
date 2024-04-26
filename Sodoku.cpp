#include <iostream>

using namespace std;

void InputSodoku(int graph[9][9]){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cin >> graph[i][j];
        }
    }
}
void PrintSoduku(int graph[9][9]){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cout << graph[i][j]<<' ';
        }
        cout <<endl ;
    }
}

bool IsValid(int graph[9][9],int row,int col,int num){
    for(int i=0;i<9;++i){
        if(graph[row][i]==num){
            return false;
        }
        if(graph[i][col]==num){
            return false;
        }
    }
    int SubRow = row/3;
    int SubCol = col/3;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(graph[SubRow*3+i][SubCol*3+j]==num){
                return false;
            }
        }
    }
    return true;
}

bool SolveSodoku(int graph[9][9]){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(graph[i][j]==0){
                for(int num=1;num<=9;++num){
                    if(IsValid(graph,i,j,num)){
                        graph[i][j] =num;

                        if(SolveSodoku(graph)){
                        return true;
                        }
                        graph[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    int Graph[9][9];
    InputSodoku(Graph);

    if(SolveSodoku(Graph)){
        PrintSoduku(Graph);
    }else{
        cout << "No solution exists!"<<endl;
    }

    return 0;
}