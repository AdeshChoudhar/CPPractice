//
// Created by adeshchoudhar on 24/04/22.
//

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> travel;
    unordered_map <string, pair<double, int>> route;

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        travel[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        auto x = travel[id];
        travel.erase(id);
        string rid = x.first + "_" + stationName;
        route[rid].first += t - x.second;
        route[rid].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string rid = startStation + "_" + endStation;
        auto x = route[rid];
        double ans = x.first / x.second;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
