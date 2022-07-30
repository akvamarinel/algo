#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
//ваще реально пробить tl 16?

bool myfunction (int i,int j) { return (i<j); }
int main() {
    std::size_t size; // размер массива
    std::size_t count; //размер множества

    std::cin >> size >> count;
    std::map<int, int> have_printed;
    std::vector<int> sorted_elements(size, 0);
    std::vector<int> elements(size, 0);
    for (std::size_t i = 0; i < size; i++) {
        std::cin >> elements[i];
        sorted_elements[i] = elements[i];
    }
    int left = 0;
    int right = count;
    std::sort(sorted_elements.begin(), sorted_elements.end(), myfunction);
   for(std::size_t i = 0; i < size; i++) {
       int tmp = 0;
       if (i==0){
           for(std::size_t j = 0; j < count; j++){
               tmp = tmp + abs(sorted_elements[i]-sorted_elements[j+1]);
           }
          have_printed[sorted_elements[i]] =  tmp;
           continue;
       }
       if (have_printed.find(sorted_elements[i]) != have_printed.end()) {
           continue;
       }
       if(right < i ){
           left++;
           right++;
       }
       for(int j = left; j <= right; j++) {
           if(j == i) {
               continue;
           }
           tmp = tmp + abs(sorted_elements[i] - sorted_elements[j]);
       }

       int tmp_left = left;
       int tmp_right = right;
       while(tmp_left != i && tmp_right!=size-1){
           int tmp_one_left_value = abs(sorted_elements[i] - sorted_elements[left]);
           int tmp_tmp = tmp - tmp_one_left_value;
           int tmp_one_right_value = abs(sorted_elements[i] - sorted_elements[tmp_right+1]);
           tmp_tmp = tmp_tmp + tmp_one_right_value;
           if(tmp_tmp < tmp){
               tmp = tmp_tmp;
               left = tmp_left+1;
               right = tmp_right+1;

           }
           tmp_left++;
           tmp_right++;
       }
       have_printed[sorted_elements[i]] = tmp;
   }
   for(int i = 0; i<size; i++){
       std::cout<<have_printed[elements[i]]<<" ";
   }
}

