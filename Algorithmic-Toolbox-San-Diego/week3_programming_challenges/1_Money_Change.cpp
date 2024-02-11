#include <iostream>

long long get_change(long long m) {
    return m/10 + m%10/5 + m%5;
}

int main() {
    long long m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
