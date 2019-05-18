#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
    int commands_count;
    cin >> commands_count;
    map<vector<string>, int> bus_route_to_number;
    for (int i = 0; i < commands_count; ++i){
        int stops_count;
        cin >> stops_count;
        vector<string> bus_route;
        for (int j = 0; j < stops_count; ++j){
            string stop_name;
            cin >> stop_name;
            bus_route.push_back(stop_name);
        }
        if (bus_route_to_number.count(bus_route) == 0){
            int new_route_number = bus_route_to_number.size() + 1;
            bus_route_to_number[bus_route] = new_route_number;
            cout << "New bus " << bus_route_to_number[bus_route] << endl;  
        } else {
            cout << "Already exists for " << bus_route_to_number[bus_route] << endl;  
        }
    }
    return 0;
}
