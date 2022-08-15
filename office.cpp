#include <iostream>

int main() {
    int x1_1, y1_1, x2_1, y2_1;
    int x1_2, y1_2, x2_2, y2_2;
    std::cin>>x1_1>>y1_1>>x2_1>>y2_1;
    std::cin>>x1_2>>y1_2>>x2_2>>y2_2;
    int max_x = 0;
    int max_y = 0;
    x2_1 > x2_2 ? max_x = abs(x2_1 - x1_2) : max_x = abs(x2_2 - x1_1);
    max_y = abs(y2_2 - y2_1);
    max_x > max_y ? std::cout << max_x*max_x : std::cout << max_y*max_y;
}
