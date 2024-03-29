#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values,int n) {
    vector<pair<double,double>>ans(weights.size());

    double value = 0.0;
    for (int i = 0; i < weights.size(); ++i) {
        double x=double(values[i])/weights[i];
        ans[i].first=x;
        ans[i].second=i;
    }
    sort(ans.rbegin(),ans.rend());
    for (unsigned int i=0;i<n;i++){
        if(capacity==0){
            return value;
        }
        int a=ans[i].second;
        int x=min(weights[a],capacity);
        value+=x*ans[i].first;
        weights[a]-=x;
        capacity-=x;
    }
  return value;
}

int main() {
  int capacity;
  int n;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values,n);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}
