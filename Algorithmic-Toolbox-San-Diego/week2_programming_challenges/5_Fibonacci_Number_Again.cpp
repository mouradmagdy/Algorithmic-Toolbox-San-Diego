#include <iostream>
using namespace std;

long long find_pisano_period(int m){
    long long pissano_period=0;
    long long previous=0;
    long long current=1;
    while(true){
        long long next=(previous%m+current%m)%m;
        previous=current;
        current=next;
        if(previous==0&&current==1)
            break;

        pissano_period++;
    }
    return ++pissano_period;


}


long long get_fibonacci_huge_naive(long long n, long long m) {
    long long pisano_period= find_pisano_period(m);
    long long remainder=n%pisano_period;
    long long arr[remainder+10];
    arr[0]=0;
    arr[1]=1;
    for (int i = 2; i <=remainder ; ++i) {
        arr[i]=(arr[i-1]%m+arr[i-2]%m)%m;
    }
    return arr[remainder];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
