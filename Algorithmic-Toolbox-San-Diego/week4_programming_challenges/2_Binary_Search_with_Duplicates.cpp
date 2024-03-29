#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = a.size()-1;
    int index=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(a[mid]==x){
            index=mid;
            if(a[mid-1]==x){
                right=mid-1;
            }
            else{
                return index;
            }
        }
        else if(a[mid]<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return index;

}



int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        //replace with the call to binary_search when implemented
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
