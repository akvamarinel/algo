#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
bool is_number(const std::string& s) {
    auto start = s.begin();
    if (s.at(0) == '-') start++;
    return !s.empty() && std::find_if(start,s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
int main() {
    string line;
    int lvl = 0;
    map<int, vector<string>> tmpElem;
    map<string, vector<int>> elements;
    while (cin >> line) {
        if (line.find('{') != string::npos) {
            lvl++;
            continue;
        }
        if (line.find('}') != string::npos) {
            int s = tmpElem[lvl].size();
            for (int i = 0; i < s; i++) {
                elements[tmpElem[lvl].back()].pop_back();
                tmpElem[lvl].pop_back();
            }
            tmpElem.erase(lvl);
            lvl--;
            continue;
        }
        string left, right;
        size_t pos = line.find('=');
        left = line.substr(0, pos++);
        right = line.substr(pos);
        if (is_number(right)) {
            elements[left].push_back(stoi(right));
            tmpElem[lvl].push_back(left);
        } else {
            if (elements.find(right) == elements.end()) {
                elements[right].push_back(0);
                tmpElem[lvl].push_back(right);
            }
            if (elements.find(left) == elements.end()) {
                elements[left].push_back(0);
                tmpElem[lvl].push_back(left);
            }
            elements[left].push_back(elements[right].back());
            tmpElem[lvl].push_back(left);
            cout << elements[left].back();
            cout << '\n';
        }
    }
}