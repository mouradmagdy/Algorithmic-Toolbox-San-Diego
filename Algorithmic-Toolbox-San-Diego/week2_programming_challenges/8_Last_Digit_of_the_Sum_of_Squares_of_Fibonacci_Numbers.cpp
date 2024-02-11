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


int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;
    long long pisano_period = find_pisano_period(10);
    long long remainder = n % pisano_period;
    long long arr[remainder + 10];

    arr[0] = 0;
    arr[1] = 1;
    long long ans = 0;
    for (long long i = 2; i <= remainder + 1; ++i) {
        arr[i] = ((arr[i - 2] % 10) + (arr[i - 1] % 10))%10;
    }

    ans = arr[remainder % pisano_period] * arr[remainder % pisano_period + 1];
    return ans % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
