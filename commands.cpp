#include <iostream>
#include <map>
#include <set>

int main() {
   std::size_t count;
   std::cin >> count;
   std::map<std::set<std::string>, std::size_t> commands;
   std::string name;
   std::size_t max_value = 1;
   for (std::size_t i = 0; i < count; i++) {
       std::set<std::string> tmp;
        for(std::size_t j = 0; j < 3; j++){
            std::cin >> name;
            tmp.insert(name);
        }
        auto it = commands.find(tmp);
        if(it!=commands.end()){
            max_value = it->second + 1;
            it->second++;
        } else {
            commands[tmp] = 1;
        }
   }
//   for(auto it =  commands.begin(); it!=commands.end(); it++) {
//       if(it->second > max_value) {
//           max_value = it->second;
//       }
//   }
   std::cout<<max_value;
}
