#include <iostream>
#include <map>

int main() {
    std::size_t count, queries;
    std::string value;
    std::string query;
    std::size_t ind;
    std::map <std::string, std::size_t>  values;
    std::cin >> count >>  queries;
    for(size_t i = 0; i < count; i++) {
        std::cin >> value;
        values[value] = i+1;
    }
    for(size_t i = 0; i < queries; i++) {
        std::cin >> ind >> query;
        auto it  = values.lower_bound(query);
        if(it != values.end()) {
            for(size_t j = 0; j < ind-1; j++){
                if(it!=(values.end()--)) {
                    it++;
                } else {
                    std::cout<<"-1\n";
                    break;
                }
            }
            std::string curr_value;
            curr_value = it->first;
            if (query.find(curr_value) != std::string::npos || curr_value.find(query) != std::string::npos) {
                std::cout<<it->second<<"\n";
            } else {
                std::cout<<"-1\n";
            }
        } else {
            std::cout<<"-1\n";
        }

    }
}
