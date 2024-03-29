#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool sorting_comparison(string s1,string s2){
    return(s1+s2<s2+s1);
}

string largest_number(vector<string> a) {

    string ans="";
    sort(a.begin(),a.end(), sorting_comparison);

    for(int i=a.size()-1;i>=0;i--){
        ans+=a[i];
    }
    return ans;

}
int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
