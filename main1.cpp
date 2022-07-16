#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

bool cmp(std::pair<int, int>& a, std::pair<int, int>& b){
    return a.second < b.second;
}
int main() {
    std::size_t size; // размер массива
    std::size_t count; //размер множества
    std::cin >> size >> count;
    std::vector<int> elements(size, 0);
    std::vector<std::pair<int, int>> mapping_elements;
    for (std::size_t i = 0; i < size; i++) {
        std::cin >> elements[i];
        mapping_elements[i] = std::make_pair(i, elements[i]);
    }

    //sort map


    for (std::size_t i = 0; i < size; i++) {
        std::vector<int> tmp(size - 1, 0);
        int tmp_ind = 0;
        int curr = elements[i];
        for (size_t j = 0; j < size; j++) {
            if (j == i) {
                continue;
            } else {
                int diff = abs(curr - elements[j]);
                tmp[tmp_ind] = diff;
                tmp_ind++;
            }
        }
        std::sort(mapping_elements.begin(), mapping_elements.end(), cmp);
        int ans = 0;
        for (std::size_t m = 0; m < count; m++) {
            ans = ans + tmp[m];
        }
        std::cout << ans << " ";
    }
}