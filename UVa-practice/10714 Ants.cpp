

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int casenum;
    cin >> casenum;
    while(casenum--){
    int len = 0, antsnum = 0;
    int mintime = 0;
    int i = 0;


    cin >> len >> antsnum;
    
    int arr[1000000];

    for(i = 0;i < antsnum;i++){
        cin >> arr[i];
    }
    
    double center = len / 2;
    int min = 0, dis = 0;
    int flag = 0;
    min = center;
    for(i = 0;i < antsnum;i++){
        if(arr[i] > center){
            dis = arr[i] - center;
            flag = 1;
        }
        else {
            dis = center - arr[i];
            flag = -1;
        }
        if (dis < min){
            min = dis;
            if(flag == 1){
                mintime = len - arr[i];
            }
            else if(flag == -1){
                mintime = arr[i];
            }
        }
    }
    
    sort(arr,arr+antsnum);
    int maxdis = 0;
    int sum = 0;
    maxdis = len - arr[antsnum-1];
    maxdis = maxdis > arr[0] ? maxdis : arr[0];
    
    for(i = 0;i < antsnum - 1;i++){
        sum = sum + (arr[i+1] - arr[i]);
    }
    sum = sum + maxdis;
    
    cout << mintime << " " << sum << endl;
    }

    return 0;
}
