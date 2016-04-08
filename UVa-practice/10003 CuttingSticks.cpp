//接下来要在哪里cut的问题

#include <iostream>
using namespace std;

int minf(int a, int b) {
	return a <= b ? a : b;
}

void cutting_func() {
	int stick_l;      // < 1000
	while (cin >> stick_l) {
		if (stick_l == 0) { break; }
		int num_cut;      // < 50
		cin >> num_cut;

		int n = num_cut + 2;
		int arr[60];
		int i = 0;
		for (i = 1; i < n - 1; i++) {
			cin >> arr[i];
		}
		arr[0] = 0;
		arr[n - 1] = stick_l;

		int cost[60][60];
		int min = 0x3f3f3f3f;

		for (int d = 0; d < n; d++) {          //first columns then rows
			for (int a = 0; a < n; a++) {
				int b = a + d;
				if (b >= n) { break; }
				min = 0x3f3f3f3f;
				for (int c = a + 1; c < b; c++) {
					min = minf(min, cost[a][c] + cost[c][b]);
				}
				if (b - a <= 1) {
					cost[a][b] = 0;
				}
				else {
					cost[a][b] = min + arr[b] - arr[a];
				}
			}
		}
		cout << "The minimum cutting is " << cost[0][n - 1] <<"."<< endl;
	}
}


//int cut_recur(int left_ind,int right_ind,int arr[],int l){
//    int i = 0;
//    int leftcost = 0,rightcost = 0;
//    for(i = left_ind;i < right_ind;i++){
//        leftcost = cut_recur(left_ind, i, arr,l) + arr[i];
//        rightcost = cut_recur(i, right_ind, arr,l) + (l - arr[i]);
//        
//    }
//    
//}
//
//int abs(int a){
//    return a >=0 ? a : 0 - a;
//}

int main(void) {
	cutting_func();

	return 0;
}
