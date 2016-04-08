/*
#include <iostream>
#include <math.h>
using namespace std;


int isitprime(long long n){
    long long i = 2;
    int flag = 1;
    if (n == 2 || n == 3){
        flag = 1;
    }
    else {
        for(i = 2;i <= sqrt(n);i++){
            if (n % i == 0){
                flag = 0;
                return flag;
            }
        }
    }
    return flag;
}


int main(){
    
    long long a,b;
    while (cin >> a >> b){
        
        
        long long arr[1000000] = {0};
        long long i = 0;
        long long j = 0;
        long long k = 0;
        
        for(i = a;i <= b;i+=2){
            
            if (isitprime(i)){
                j++;
                arr[j-1] = i;
            }
            
            if (i % 2 == 0){
                i = i-1;
            }
        }
        
        
        long long q = arr[0], w = arr[1], e=0, r=0;
        long long min = arr[1] - arr[0];
        long long max = arr[1] - arr[0];
        for (i = 1,k = 2;k < j;k++,i++){
            if ((arr[k] - arr[i]) < min){
                min = (arr[k] - arr[i]);
                q = arr[i];
                w = arr[k];
            }
            if ((arr[k] - arr[i]) > max){
                max = (arr[k] - arr[i]);
                e = arr[i];
                r = arr[k];
            }
        }
        
        if (q == 0 || w == 0|| e == 0|| r ==0){
            cout <<"There are no adjacent primes."<<endl;
        }
        else{
            cout << q <<","<<w<<" are closest, "<<e<<","<<r<< " are most distant." <<endl;
        }
    }
    
    return 0;
}
 */


#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned long ul;
ul primes[1000000];
bool arrbool[46344];
bool arrbool2[1000001];
int qcnt;
int p_num;
ul pprimes[1000001];
int ccc;

/*
void FilterPrime(int n){
    bool* isPrimes = new bool[n];
    for(int i=2;i<=n;++i){
        isPrimes[i] = true;
    }
    isPrimes[2] = true;
    for(int j=2;j<=n;++j){
        if(isPrimes[j]==true){
            for(int m=2;j*m<=n;++m){
                isPrimes[j*m] = false;
            }
        }
    }
    for(int k=2;k<=n;++k){
        if(isPrimes[k]==true){
            cout<<k<<"是素数"<<endl;
        }
    }
    delete [] isPrimes;
}
*/


void sieve_era(ul a,ul b,ul upper){
    if (b <= 1){return;}
    ul i = 0,m = 0;
    int k = 0;
    ul sqr = sqrt(b);
    sieve_era(a, sqr,upper);
    k = 0;
    for (i = a;i <= sqr;i++){
        if(arrbool[i] == 1){
            continue;
        }
        for(m = 2;m*i <= sqr;m++){
            if (arrbool[m*i] == 1){continue;}
            else {arrbool[m*i] = 1;}
        }
        
        if (primes[k] == i){
            k++;
        }
        else {
            primes[k] = i;
            k++;
//            cout << primes[k-1]<<" ";
        }
    }
    if (sqr == (ul)sqrt(upper)){
        p_num = k;
    }
}

void fp(ul a,ul b){
    int i = 0;
    ul j = 0;
    int cnt = 0;
    int flag = 1;
    
    if(b < 46341 && a < 46341){
        for (i = 0;;i++){
            if (primes[i] < a){continue;}
            if (primes[i] > b){break;}
            if(primes[i] >= a && primes[i] <= b){
                pprimes[cnt] = primes[i];
                cnt++;
            }
        }
        ccc =cnt;
    }
    else if (a < 46341 && b > 46341){
        fp(a,46340);
        cnt = ccc;
        for(j = 46341;j <= b;j++){
            flag = 1;
            for (i = 0;i < p_num;i++){
                if(j % primes[i] == 0){//j not prime
                    flag = 0;
                    break;
                }
            }
            
            if (flag){
                pprimes[cnt] = j;
                cnt++;
            }
        }
        ccc = cnt;
    }
    
    else if (a >= 46341 && b > 46341){
        for(j = a;j <= b;j++){
            flag = 1;
            for (i = 0;i < p_num;i++){
                if(j % primes[i] == 0){//j not prime
                    flag = 0;
                    break;
                }
            }
            
            if (flag){
                pprimes[cnt] = j;
                cnt++;
            }
        }
        ccc = cnt;
    }
}


//        for(m = 2; m*primes[i] <= b;m++){
//            if(m*primes[i] < a){continue;}
//            if (arrbool2[m*primes[i]-a] == 1){continue;}
//            else {arrbool2[m*primes[i]-a] = 1;}
//        }
//    }
//}
/*
void find_prime(ul a,ul b){
    ul i = 0,j = 0;
    int ind = 0,flag = 0;
    for(i = a;i <= b;i++){
        flag = 0;
        for(j = 2;j <= sqrt(b);j++){
            if(arrbool[j] == 1){continue;}
            else if(i % j == 0 && i != j){
                flag = 1;
            }
        }
        if (flag == 0){
            primes[ind] = i;
            ind++;
        }
    }
    p_num = ind;
}
*/
/*
void findprime(ul lower,ul upper){
    int i = 0,m = 0;
    ul a = 0;
    int flag = 1;
    int cnt = 0;
    ul sqr = sqrt(upper);
    bool arrbool[sqr];
    for(i=2;i <= sqr;++i){
        arrbool[i] = true;
    }

    for(i = 2;i <= sqr;i++){
        if(arrbool[i] == false){
            continue;
        }
        
        flag = 1;
//        for (j = 2;j < sqrt(i);j++){
//            if (i % j == 0){
//                flag = 0;
//            }
//        }
        if (flag){
            for(m = 2;m*i < sqr;m++){
                arrbool[m*i] = false;
            }
        }
        
        if (flag){
            cnt = 0;
            for(a = lower;a <= upper;a++){
                if(a == i){cnt++;continue;}
                if (a % i == 0){
                    arr[cnt] = 0;
                }
                cnt++;
            }
        }
    }
}

*/
/*
void init(ul lower,ul upper){
    ul i = 0;
    qcnt = 0;
    for (i = lower;i <= upper;i++){
        arr[qcnt] = i;
        qcnt++;
    }
}
*/
void find(ul a,ul b){
    ul min = 1000000;
    ul max = 0;
    ul num;
//    int cnt = 0;
    int i = 0;
    ul q = 0,w = 0,e = 0,t = 0;
//    ul pprimes[1000000];
    
//    for(i = 0;i < 1000001;i++){
//        if(arrbool2[i] == 1){continue;}
//        if (arrbool2[i] == 0){
//            pprimes[cnt] = (i+a);
//            cnt++;
//        }
//    }
    
    /*
    ul r[1000000];
    
    
    for(i = 0;i < qcnt;i++){
        if (arr[i] != 0){
            r[cnt] = arr[i];
            cnt++;
        }
    }
    */
    for(i = 0;i < ccc-1;i++){
        num = pprimes[i+1] - pprimes[i];
        if (num < min){
            min = num;
            q = pprimes[i];
            w = pprimes[i+1];
        }
        if (num > max){
            max = num;
            e = pprimes[i];
            t = pprimes[i+1];
        }
    }
    if (ccc <= 1){
        cout << "There are no adjacent primes."<<endl;
    }
    else {
        cout << q<<","<<w<<" are closest, "<<e<<","<<t<<" are most distant."<<endl;
//        printf("%ld,%ld are closest, %ld,%ld are most distant.\n",q,w,e,t);
    }
}



int main(void){
    ul a,b;
    arrbool[2] = 0;
    sieve_era(2, 2147483647, 2147483647);
    while(cin >>a){
        if (a == EOF){break;}
        cin >> b;
        fp(a,b);
        find(a,b);
//        cout << p_num << endl;
    }
    
    return 0;
}
