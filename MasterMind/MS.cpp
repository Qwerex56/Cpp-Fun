#include <iostream>
#include <time.h>
#include <random>

#include <chrono>
#include <fstream>
//#define COLLECT_TIME

#define WORD_SIZE 4

int main() {
  std::chrono::time_point start = std::chrono::high_resolution_clock::now();
  srand(time(nullptr));

  uint8_t badPlacement = 0;
  char word[WORD_SIZE + 1] {'A', 'B', 'C', 'D', '\0'};  // +1 because cpp needs one null character

  for (uint8_t i = 0; i < WORD_SIZE; i++) { // Randomly swap word chars
    uint8_t ch1 = rand() % WORD_SIZE;
    uint8_t ch2 = rand() % WORD_SIZE;

    // This two lines executes at the same speed //

    //*(word + ch2) = (*(word + ch2) + *(word + ch1)) - (*(word + ch1) = *(word + ch2));
    word[ch2] = (word[ch2] + word[ch1]) - (word[ch1] = word[ch2]);
  }
  std::cout << word << std::endl;

  char user[WORD_SIZE + 1] {'A', 'B', 'C', 'D', '\0'}; // store user guess
  NEXT_GUESS:

#ifndef COLLECT_TIME
  std::cin.get(user, WORD_SIZE + 1, '\0'); // Get user guess
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif

#ifdef COLLECT_TIME
  for (uint8_t i = 0; i < WORD_SIZE; i++) { // Randomly swap word chars
    uint8_t ch1 = rand() % WORD_SIZE;
    uint8_t ch2 = rand() % WORD_SIZE;

    // This two lines executes at the same speed //

    //*(word + ch2) = (*(word + ch2) + *(word + ch1)) - (*(word + ch1) = *(word + ch2));
    user[ch2] = (user[ch2] + user[ch1]) - (user[ch1] = user[ch2]);
  }
#endif

  badPlacement = 0;
  for (uint8_t i = 0; i < WORD_SIZE; i++) { // Count all bad placements
    if (word[i] == user[i]) continue;
    badPlacement++;
  }

#ifndef COLLECT_TIME
  std::cout << WORD_SIZE - badPlacement << std::endl;
#endif

  if (badPlacement != 0)
    goto NEXT_GUESS;

  std::chrono::time_point end = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

#ifdef COLLECT_TIME
  std::fstream file;
  file.open("execTimes.txt", std::fstream::ios_base::app | std::fstream::ios_base::out);

  file << (end - start).count() << '\n';
  file.close();
#endif
  return 0;
}