#include <iostream>

int main() {
    size_t count;
    size_t first;
    size_t prev;
    size_t curr;
    std::cin >> count;
    std::cin >> prev;
    first = prev;
    if(count == 1) {
        std::cout << 0;
        return 0;
    }
    for (size_t i = 1; i < count; i++){
        std::cin >> curr;
        if(prev > curr) {
            std::cout << -1;
            return 0;
        }
        prev = curr;
        if(i == count-1){
            std::cout << curr - first;
        }
    }
    return 0;
}
