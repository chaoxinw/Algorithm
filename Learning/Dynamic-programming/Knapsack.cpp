//
//  main.cpp
//  Knapsack
//
//  Created by Chaoxin on 16/3/26.
//  Copyright © 2016年 Chaoxin. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int maxweight = 0;
    cout << "Max weight available:";
    cin >> maxweight;
    
    int num = 0;
    cout << "Number of items:";
    cin >> num;
    
    int weight[100] = {0};
    int price[100] = {0};
    int i = 0;
    for(i = 0;i < num;i++){
        cin >> weight[i] >> price[i];
    }
    
    int j = 0;
    int arr[100][100] = {0};
    for(i = 1;i <= num;i++){
        for(j = 1;j <= maxweight;j++){
            if(j == weight[i]){
                arr[i][j] = price[i];
            }
            else if(j > weight[i]){
                arr[i][j] = (price[i] + arr[i-1][j - weight[i]]) > arr[i-1][j] ? (price[i]+arr[i-1][j - weight[i]]) : arr[i-1][j];
            }
        }
    }
    
    cout << "Max value: " << arr[num][maxweight] << endl;
    
    return 0;
}
