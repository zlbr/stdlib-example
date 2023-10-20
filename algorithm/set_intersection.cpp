
/**
 * 取两个迭代器的交集
 */

namespace stdlib {
template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_intersection(
    InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
  while (first1 != last1 && first2 != last2) {
    if (*first1 < *first2) {
      ++first1;
    } else if (*first2 < *first1) {
      ++first2;
    } else {
      *result = *first1;
      ++result;
      ++first1;
      ++first2;
    }
  }
  return result;
}
}  // namespace stdlib

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int first[] = {5, 10, 15, 20, 25};
  int second[] = {50, 40, 30, 20, 10};
  std::vector<int> v(10);  // 0  0  0  0  0  0  0  0  0  0
  std::vector<int>::iterator it;

  std::sort(first, first + 5);    //  5 10 15 20 25
  std::sort(second, second + 5);  // 10 20 30 40 50

  it = stdlib::set_intersection(first, first + 5, second, second + 5, v.begin());
  // 10 20 0  0  0  0  0  0  0  0
  v.resize(it - v.begin());  // 10 20

  std::cout << "The intersection has " << (v.size()) << " elements:\n";
  for (it = v.begin(); it != v.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
  return 0;
}