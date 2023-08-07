#include <cassert>
#include <iostream>
#include <vector>

template<class T, std::size_t N>
constexpr std::size_t array_size(T(&)[N]) noexcept {
  return N;
}

int main(int argc, char** argv) {
  const int arr[] = {1, 2, 3};
  const char charr[] = "abcdefg";
  std::cout << "array size: " <<  array_size(arr) << std::endl;
  std::cout << "array size: " <<  array_size(charr) << std::endl;
  return 0;
}
