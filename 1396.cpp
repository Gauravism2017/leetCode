#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> checkout;
    unordered_map<int, pair<string,int>> checkin;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& in = checkin[id];
        string route = in.first + '_' + stationName;
        checkout[route].first += t - in.second;
        checkout[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + '_' + endStation;
        auto& out = checkout[route];
        return (double) out.first / out.second;
    }
};



int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    return 0;
}