#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::fstream file;
  std::vector<int> time;
  file.open("execTimes.txt", std::fstream::ios_base::in);

  while (!file.eof()) {
    int getTime;
    file >> getTime;

    if (file.fail()) {
      break;
    }

    time.push_back(getTime);
  }

  uint64_t sum = 0;
  for (auto&& t : time) {
    sum += t;
  }

  std::cout << (sum / time.size()) << std::endl;
  file.close();

  return 0;
}