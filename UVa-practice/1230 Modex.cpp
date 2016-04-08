
    /*
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int x = 0,y = 0,z = 0;
    cin >> x >> y >> z;
    
    int buffer = 0;
    int i = 0;
    
    
    buffer = x;
    for(i = 0;i < y;i++){
        buffer = buffer * x;
        buffer = (buffer % z) < buffer ? (buffer&z) : buffer;
    }
    
    int product = 1;
//    product = buffer % z;
     
    
    
    
    cout << "Result: " << buffer << endl;
    */
/*
#include<iostream>
    using namespace std;
    typedef long long ll;
    ll x, y, n;
    
    ll power(ll a, ll b, ll m) {
        if (b == 1ll) return a%m;
        ll t = power(a, b/2, m);
        if (b%2ll) return (t*t)%m*a%m;
        return (t*t)%m;
    }
    
    int main(void) {
        int kase;
        cin >> kase;
        while (kase--) {
            cin >> x >> y >> n;
            cout << power(x, y, n) << endl;
        }
        
        return 0;
    }
    
*/
/*
#include <iostream>
using namespace std;
typedef unsigned long int ull;
ull result[32];
int binary_arr[32];
ull r[32];

void conversion(ull num){
    //ull mask = 1;
    int i = 0;
    for (i = 0;i <32;i++){
        if ((num & (1LL<<i)) == 0){
            binary_arr[i] = 0;
        }
        else {
            binary_arr[i] = 1;
        }
        
    }
    
}

void modu(ull x,ull m,ull index){
    if (index == 32){return;}
    if (index == 0){result[index] = x % m;}
    else {
        result[index] = (result[index-1] * result[index-1]) % m;
    }
    cout << result[index]<<" ";
    index++;
    modu(x,m,index);
}

ull func(ull x,ull y,ull m){
    int i;
    int cnt = 0,c = 0;
    ull product = 1;
    conversion(y);
    for (i =0;i < 32;i++){
        cout << binary_arr[i]<<" ";
        if (binary_arr[i] == 1){
            product *= result[i];
            cnt++;
            if (cnt % 2 == 0){
                r[c] = product % m;
                product = 1;
                c++;
            }
        }
    }
    return product%m;
}

ull calc(int c){
    ull product = 1;
    int cnt = 0;
    int i = 0,j=0;
    for (i = 0;i < c;i+=2){
        r[j] = r[i] * r[i+1];
        j++;
    }
}

int main(void){
//    int kase;
//    cin >> kase;
//    while(kase--){

        int i = 0;
        for(i = 0;i < 32;i++){
            result[i] = 0;
        }
        ull x,y,m;
        cin >> x>>y>>m;
        modu(x,m,0);
        cout << func(x,y,m)<<endl;
    

//    }


    return 0;
}
*/

#include <iostream>
using namespace std;
typedef unsigned long ul;

ul func(ul x,ul y,ul m){
    if (y == 1){return x%m;}
    ul res = 0;
    if ((y & 1) == 1){
        res = func(x,(y-1)/2,m);
        res = ((res*res)%m) * (x % m);
    }
    else if ((y & 1) == 0){
        res = func(x,y/2,m);
        res = (res * res)%m;
    }
    return res%m;
}


int main(void){
    int kase;
    cin >> kase;
    while(kase--){
        ul x,y,m;
        cin >> x>>y>>m;
        ul result = func(x,y,m);
        cout << result << endl;
    }
    return 0;
}


