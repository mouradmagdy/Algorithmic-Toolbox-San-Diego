#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


void merge(vector<pair<long long,long long>>&x,vector<pair<long long,long long>>&arr1,vector<pair<long long,long long>>&arr2,bool sortX){

    int i,j,k,num1,num2;
    i=0,j=0,k=0;
    while(i<arr1.size()&&j<arr2.size()){
        if(sortX){
            num1=arr1[i].first;
            num2=arr2[j].first;
        }
        else{
            num1=arr1[i].second;
            num2=arr2[j].second;
        }
        if(num1<=num2){
            x[k]=arr1[i];
            i++;
        }else{
            x[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<arr1.size()){
        x[k]=arr1[i];
        i++;
        k++;
    }
    while(j<arr2.size()){
        x[k]=arr2[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<long long ,long long>>&x,bool sortX) {

    if(x.size()<2) return;
    long long mid = x.size()/2;
    vector<pair<long long,long long>>arr1,arr2;
    for (int i = 0; i < mid; ++i) {
        arr1.push_back({x[i].first,x[i].second});
    }
    for (int i = mid; i < x.size(); ++i) {
        arr2.push_back({x[i].first,x[i].second});
    }
    mergeSort(arr1 , sortX);
    mergeSort(arr2 , sortX);
    merge(x,arr1,arr2,sortX);


}



double Euclidean_distance(pair<long ,long>p1,pair<long,long>p2) {
    long long xsquared = p1.first - p2.first;
    xsquared *= xsquared;
    long long ysquared = p1.second - p2.second;
    ysquared *= ysquared;
    return sqrt(xsquared + ysquared);
}

double find_closest_strip(vector<pair<long long,long long>>strip,long long j,double d) {
//    sort(strip.begin(), strip.end(), sort_by_y_coordinates);
    mergeSort(strip,0);
    double min = d;
    long long size_of_strip = j;
    for (int i = 0; i < size_of_strip; ++i) {
        for (int k = i + 1; (k < size_of_strip) && (strip[k].second - strip[i].second < min); ++k) {
            if (Euclidean_distance(strip[i], strip[k]) < min) {
                min = Euclidean_distance(strip[i], strip[k]);

            }
        }

    }
    return min;
}

double minimal_distance(vector<pair<long long, long long>> &p, long long start, long long end) {
    long long n = end - start + 1;
    if (n == 2) return Euclidean_distance({p[0].first, p[0].second}, {p[1].first, p[1].second});
    if (n == 3)
        return min({Euclidean_distance({p[0].first, p[0].second}, {p[1].first, p[1].second}),
                    Euclidean_distance({p[0].first, p[0].second}, {p[2].first, p[2].second}),
                    Euclidean_distance({p[1].first, p[1].second}, {p[2].first, p[2].second})});


    long long mid1 = (start + end) / 2;
    long long mid = p[mid1].first;

    double l = minimal_distance(p, start, mid1);
    double r = minimal_distance(p, mid1 + 1, end);
    double d = min(l, r);
    vector<pair<long long, long long>> strip;

    for (int i = start; i <= end; ++i) {
        if (abs(p[i].first - mid) < d) {
            strip.push_back(p[i]);
        }
    }

    return min(d, find_closest_strip(strip, strip.size(), d));
}


int main() {
    long long n;
    std::cin >> n;
    vector<pair<long long, long long>> p(n);

    for (size_t i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        p[i].first = x;
        p[i].second = y;
    }
//        sort(p.begin(), p.end(), sort_by_x_coordinates);
    mergeSort(p,1);

    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(p, 0, n - 1) << "\n";
}
