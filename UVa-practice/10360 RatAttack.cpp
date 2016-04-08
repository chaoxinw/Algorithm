
/*
#include <iostream>
#include <stdio.h>
using namespace std;
struct Rat{
    int x;
    int y;
    int pop;
};

int abs(int a){
    return a >= 0 ? a : 0 - a;
}

int max(int a,int b){
    return a > b ? a : b;
}

void init(){
    int d;
    cin >> d;
    int num_rat;
    cin >> num_rat;
    struct Rat rat[num_rat];
    int i = 0,j = 0,k = 0;
    int sum = 0;
    int maxi = 0;
    int x = 0, y = 0;
    int flag = 0, flag2 = 0;
    for (i = 0;i < num_rat;i++){
        cin >> rat[i].x >> rat[i].y>>rat[i].pop;
    }
    
    fflush(stdin);
    
    for(i = 0;i <= 1024;i++){
//        flag = 0;
//        for (k = 0;k < num_rat;k++){
//            if (abs(i - rat[k].x) <= d){
//                flag = 1;
//                
//            }
//        }
//        if(flag == 0){continue;}
        
        for (j = 0;j <= 1024;j++){
//            flag2 = 0;
//            for (k = 0;k < num_rat;k++){
//                if (abs(j - rat[k].y) <= d){
//                    flag2 = 1;
//                }
//            }
//            if(flag2 == 0){continue;}
            
            sum = 0;
            for (k = 0;k < num_rat;k++){
                if(max(abs(i-rat[k].x),abs(j-rat[k].y)) <= d){
                    sum += rat[k].pop;
                }
            }
            if (sum > maxi){
                maxi = sum;
                x = i;
                y = j;
            }
        }
    }
    
    cout << x <<" "<< y <<" "<< maxi << endl;
    fflush(stdout);
    return;
}

int main(void) {
    int kase;
    cin >> kase;
    while (kase--){
        init();
    }
    
    return 0;
}
 */

#include <iostream>
using namespace std;
#define MAX 1025

struct Rat{
    int x;
    int y;
    int pop;
};

//int arr[MAX][MAX];
int surrounding[] = {-1,0,1};

void init(){
    int arr[MAX][MAX] = {0};
    int d;
    cin >> d;
    int num_rat;
    cin >> num_rat;
    struct Rat rat[num_rat];
    int i = 0,j = 0,k = 0;
    int maxi = 0;
    int row = 0, col = 0;
    int row1 = 0,col1 = 0;
    int x = 0,y = 0;

    for (i = 0;i < num_rat;i++){
        cin >> rat[i].x >> rat[i].y>>rat[i].pop;
//        arr[rat[i].x][rat[i].y] += rat[i].pop;
        
        row = surrounding[0] * d + rat[i].x;
        col = surrounding[0] * d + rat[i].y;
//        cout << "row: "<<row << " col: "<<col<<endl;
        j = row + 2*d;
        k = col + 2*d;
        for(row1 = row;row1 <= j;row1++){
            if (row1 < 0 || row1 > 1024){continue;}
            for(col1 = col;col1 <= k;col1++){
                if (col1 < 0 || col1 > 1024){continue;}
                arr[row1][col1] += rat[i].pop;
//                cout << "arr[row][col]: "<<arr[row1][col1]<<endl;
                if (arr[row1][col1] > maxi){
                    maxi = arr[row1][col1];
                    x = row1;
                    y = col1;
//                    cout << "max: "<<maxi<<endl;
                }
            }
        }
    }
    
    cout << x<<" "<<y<<" "<<maxi << endl;
    
}

int main(void){
    int kase;
    cin >> kase;
    while(kase--){
        init();
    }
    return 0;
}
