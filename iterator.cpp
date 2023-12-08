#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    cout << "\nvaish karle" << endl;
    map<string, int> statePopulations;
    statePopulations["Maharashtra"] = 318754162;
    statePopulations["Bihar"] = 754862301;
    statePopulations["M.P."] = 12457621;
    statePopulations["Goa"] = 2154683;
    statePopulations["U.P"] = 56748211;

    cout << "Enter the name of state:";
    string userInput;
    getline(cin, userInput);

    map<string, int>::iterator it; // Declaration of the iterator 'it'

    it = statePopulations.find(userInput);
    if (it != statePopulations.end()) {
        cout << "Population of " << userInput << ": " << it->second << endl;
    } else {
        cout << "State not found in the map.\n";
    }
    return 0;
}

