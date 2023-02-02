#include<iostream>


using namespace std;

int main(){
    int r,c,a[100][100], b[100][100], sum[100][100],i,j;
    cout << "enter row";
    cin >> r;
    cout << "colmn";
    cin >> c;
    cout << endl << "enter element 1 matrix" << endl;
    for(i=0; i <r;++i){
        for(j = 0; j < c;++j){
            cout << "enter element a" << i + 1 << j +1 << ":";
            cin >> a[i][j];
        }

    }
    cout << endl << "enter element 2 matrix" << endl;
    for(i = 0; i < r; ++i){
        for(j=0;j<c;++j){
            cout << "enter element b" << i + 1 << j + 1 << ":";
            cin >> b[i][j];
        }
    }
    for(i=0;i<r;++i){
        for(j=0;j<c;++j){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    cout << endl << "sum" << endl;
    for(i=0;i<r;++i){
        for(j=0;j<c;++j){
            cout << sum[i][j] << "";
            if(j == c-1){
                cout << endl;
            }
        }
    }

    return 0;
}