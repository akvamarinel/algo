#include <iostream>

int main() {
    std::size_t count;
    std::size_t max_follow = 0;
    std::size_t max_unfollow = 0;
    std::size_t min_value_follow = 0;
    std::size_t max_value_unfollow = 0;
    std::cin >> count;
    std::size_t curr_value;
    for(size_t i = 1; i <= count; i++) {
        std::cin >> curr_value;
        if(i%2 != 0) {
            if(i == 1){
                min_value_follow = curr_value;
            }
            if(min_value_follow > curr_value) {
                min_value_follow = curr_value;
            }
            max_follow += curr_value;
        } else {
            if(i == 2) {
                max_value_unfollow = curr_value;
            }
            if(max_value_unfollow < curr_value) {
                max_value_unfollow = curr_value;
            }
            max_unfollow += curr_value;
        }
    }
    if(max_value_unfollow > min_value_follow) {
        max_unfollow = max_unfollow - max_value_unfollow + min_value_follow;
        max_follow = max_follow - min_value_follow + max_value_unfollow;
    }
    std::cout<<max_follow - max_unfollow;
}
