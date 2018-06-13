#include <iostream>
#include <sstream>

using namespace std;

bool isVowel(char check) {
   string vowels = "AaEeIiOoUu";
   for (unsigned count = 0; count < vowels.size(); count++) {
      if (check == vowels[count]) {
         return true;
      }
   }
   return false;
}

int numVowels(string input) {
   int vowelNum = 0;
   // for (int count = 0, vowelNum = 0; count < input.size(); count++) {
   for (unsigned count = 0; count < input.size(); count++) {
      if (isVowel(input[count])) {
         vowelNum++;
      }
   }
   return vowelNum;
}

string listVowels(string input) {
   stringstream vowels;
   for (unsigned count = 0; count < input.size(); count++) {
      if (isVowel(input[count])) {
         vowels << input[count] << ' ';
      }
   }
   return vowels.str();
}
