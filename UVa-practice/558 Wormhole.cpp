#include<iostream>
using namespace std;

int main(void) {
    int kase;
    cin >> kase;
    while(kase--){
    int num_vertices,num_edges;
    cin >> num_vertices >> num_edges;
    int i,j;
    int x[2005]={0},y[2005]={0},t[2005]={0};
    for(i = 0;i < num_edges;i++){
        cin >> x[i] >> y[i] >> t[i];
    }
    int vertices[1005];
    for(i = 0;i < 1005;i++){
        vertices[i] = 0x3f3f3f3f;
    }
    vertices[0] = 0;
    int verIndex;
    int gap[1005]={0},pregap;

    int flag1 = 0;
    int flag2 = 0;
    
    while(1){
        flag1 = 0;
        for(i = 0;i < num_vertices;i++){
            
            for(j = 0;j < num_edges;j++){
                if(i == x[j]){
                    verIndex = y[j];
                    if (vertices[i] + t[j] < vertices[verIndex]){
                        pregap = gap[verIndex];
                        gap[verIndex] = vertices[verIndex] - (vertices[i] + t[j]);
                        if (gap[verIndex] == pregap && gap[verIndex] !=0){
                            flag2 = 1;
                        }
                        
                        vertices[verIndex] = vertices[i] + t[j];
                        flag1 = 1;
                    }
                }
            }
            
        }
        if (!flag1){
            cout << "not possible" << endl;
            break;
        }
        if (flag2){
            cout << "possible" << endl;
            break;
        }
    }
    
    }

    return 0;
}


