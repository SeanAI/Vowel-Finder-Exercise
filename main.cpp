#include <iostream>
#include <fstream>

using namespace std;

ifstream inputFile;

bool isVowel(char check);
int numVowels(string input);
string listVowels(string input);

int main(int argc, char* argv[]) {
   int vowelCount;
   string content, temp, vowels;
   content = temp = "";
   cout << endl;
   if (argc > 1) {
      inputFile.open(argv[1], fstream::in);
      while (getline(inputFile, temp)) {
         content += (temp + '\n');
      }
      inputFile.close();
      
      cout << content << endl << endl;
      vowels = listVowels(content);
      vowelCount = numVowels(content);
      
      if (vowelCount > 0) {
         cout << "There are " << numVowels(content) << " vowels.\nThey are " << vowels << endl;  
      } else {
         cout << "There are no vowels." << endl;
      }
   } else {
      cout << "No input file(s), exiting..." << endl;
   }
   cout << endl;
   return 0;
}