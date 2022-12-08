#include <iostream>
#include <time.h>
#include <random>

#define WORD_SIZE 4

int main() {
  srand(time(nullptr));
  char word[WORD_SIZE + 1] {'A', 'B', 'C', 'D', '\0'};  // +1 because cpp needs one null character

  for (uint8_t i = 0; i < WORD_SIZE; i++) {
    uint8_t ch = rand() % WORD_SIZE;
    word[ch] = (word[ch] + word[(ch + ch) % WORD_SIZE]) - (word[(ch + ch) % WORD_SIZE] = word[ch]);
  }
                                                


  return 0;
}