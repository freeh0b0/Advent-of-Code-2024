#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector<int> llist;
    vector<int> rlist;
    map<int, int> frequency;

    string inps;
    ifstream inpf{"../Inputs/day1.txt"};

    while (!inpf.eof() && getline(inpf, inps)) {    
        size_t pos = inps.find("   "); // Find the position of three blanks
        if (pos != string::npos) {
            string first = inps.substr(0, pos);
            string second = inps.substr(pos + 3);
            
            llist.push_back(stoi(first));  
            rlist.push_back(stoi(second));
            frequency[stoi(second)]++;
        }
    }
    inpf.close();

    sort(llist.begin(), llist.end());
    sort(rlist.begin(), rlist.end());
    int i = 0;
    int length = llist.size();
    int result1, result2;
    for (i = 0; i < length; i ++){
        int a = llist[i];
        int b = rlist[i];
        
        result1 += abs(a - b);
        result2 += a * frequency[a];
    }

    cout << result1 << endl;
    cout << result2 << endl;
    return 0;
}