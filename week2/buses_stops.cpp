#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	map<string, vector<string>> bus_to_stops;
	map<string, vector<string>> stop_to_buses;
	for (int i = 0; i < n; ++i){
		string command;
		cin >> command;
		if (command == "NEW_BUS"){
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			for (int j = 0; j < stop_count; ++j){
				string stop;
				cin >> stop;
				bus_to_stops[bus].push_back(stop);
				stop_to_buses[stop].push_back(bus);
			}
		} else if (command == "BUSES_FOR_STOP"){
			string stop;
			cin >> stop;
        	        if (stop_to_buses.count(stop) > 0){
				for(const auto& bus: stop_to_buses[stop]){
					cout << bus << ' ';
				}
				cout << endl;
			} else {
				cout << "No stop" << endl;
			}
		} else if (command == "STOPS_FOR_BUS"){
			string bus;
			cin >> bus;
			if (bus_to_stops.count(bus) > 0){
                                for (const auto& stop: bus_to_stops[bus]){
					cout << "Stop " << stop << ": ";
					int count = 0;
					for (const auto& stop_bus: stop_to_buses[stop]){
        	                                if (bus != stop_bus){
							cout << stop_bus << ' ';
							++count;
						}
					}
					if (count > 0){
						cout << endl;
					} else {
						cout << "no interchange" << endl;
					}
				}
                        } else {
                                cout << "No bus" << endl;
                        }
                } else if (command == "ALL_BUSES"){
			if (bus_to_stops.size() > 0){
				for (const auto& item : bus_to_stops){
					string bus = item.first;
					cout << "Bus " << bus << ": ";
					for (const auto& stop : bus_to_stops[bus]){
						cout << stop << ' ';
					}
					cout << endl;
				}
			} else {
				cout << "No buses" << endl;
			}
                }
	}
	return 0;
}
