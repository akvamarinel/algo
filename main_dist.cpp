#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

bool cmp(std::pair<int, int>& a, std::pair<int, int>& b){
    return a.second < b.second;
}
int main() {
    std::size_t size; // размер массива
    std::size_t count; //размер множества

    std::cin >> size >> count;
    std::multiset<int> sorted_elem;
    std::map<int, int> have_printed;
    std::vector<int> elements(size, 0);

    for (std::size_t i = 0; i < size; i++) {
        std::cin >> elements[i];
        sorted_elem.insert(elements[i]);
    }

    for (std::size_t i = 0; i < size; i++) {
        int tmp_diff = 0;
        int tmp_count = count;
        auto pos_right = sorted_elem.find(elements[i]); //находим позицию текущего элемента среди отсортированных элементов
        auto pos_left = pos_right;

        if (have_printed.find(elements[i]) != have_printed.end()) {
            std::cout << have_printed[elements[i]] << " "; //если значения повторялись, мы сразу выведем их результат
            continue;
        }
        while (tmp_count > 0) {
            if (pos_left != sorted_elem.begin() && pos_right != (--(sorted_elem.end()))) {
                //сравниваем, кто даст меньшую разницу: элемент справа или слева (при этом обе позиции сдвигаются)
                int left_diff = abs(elements[i] - (*(--pos_left)));
                int right_diff = abs(elements[i] - (*(++pos_right)));
                if (left_diff <= right_diff) { //если левая разница меньше, то возвращаем правую позицию
                    tmp_diff = left_diff + tmp_diff;
                    tmp_count--;
                    --pos_right;
                } else {
                    tmp_diff = right_diff + tmp_diff;
                    tmp_count--;
                    ++pos_left;
                }
            } else if (pos_left == sorted_elem.begin()) { //если мы дошли до начала сета, то тупо подряд берем из правой части значения
                int tmp = 0;
                for(std::size_t j=0; j < tmp_count; j++){
                    ++pos_right;
                    tmp = tmp + (*pos_right);
                }
                tmp_diff = tmp_diff + abs(tmp_count * elements[i] - tmp);
                have_printed[elements[i]] = tmp_diff;
                tmp_count = 0;
                continue;
            } else if (pos_right == (--(sorted_elem.end()))) { //аналогично началу
                int tmp = 0;
                for(std::size_t j=0; j < tmp_count; j++){
                    --pos_left;
                    tmp = tmp + (*pos_left);
                }
                tmp_diff = tmp_diff + abs(tmp_count * elements[i] - tmp);
                have_printed[elements[i]] = tmp_diff;
                tmp_count=0;
                continue;
            }
        }
        have_printed[elements[i]] = tmp_diff;
        std::cout << tmp_diff << " ";
    }
}
