#include <iostream>
#include <vector>
#include <string>

using namespace std;

int worry_count(const vector<bool>& queue){
	int worry_count = 0;
	for(int i = 0; i < queue.size(); ++i){
                worry_count += (int)queue[i];
        }
	return worry_count;
}

void come(vector<bool>& queue, int come_count){
	if(come_count > 0){
		for(int i = 0; i < come_count; ++i){
			queue.push_back(false);
		}
	} else if(come_count < 0){
		for(int i = 0; i < -come_count; ++i){
                        queue.pop_back();
                }
	}
}

void worry(vector<bool>& queue, int i){
	queue[i] = true;
}

void quiet(vector<bool>& queue, int i){
	queue[i] = false;
}

int main(){
	int commands_count;
	cin >> commands_count;
	string command;
	int command_arg;
	vector<bool> queue;
	for (int i = 0; i < commands_count; ++i){
		cin >> command;
		if (command == "WORRY_COUNT"){
			cout << worry_count(queue) << endl;
		} else {
			cin >> command_arg;
			if (command == "COME"){
				come(queue, command_arg);
			} else  if (command == "WORRY"){
				worry(queue, command_arg);
                        } else if (command == "QUIET"){
				quiet(queue, command_arg);
                        }
		}
	}
}
