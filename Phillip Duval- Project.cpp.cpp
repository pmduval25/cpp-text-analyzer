#include <iostream>
#include <string>
using namespace std;

/* Define your functions here. */

void printMenu() {
   cout << "MENU" << endl; 
   cout << "c - Number of non-whitespace characters" << endl; 
   cout << "w - Number of words" << endl; 
   cout << "f - Find text" << endl; 
   cout << "r - Replace all !'s" << endl;
   cout << "s - Shorten spaces" << endl;
   cout << "q - Quit" << endl; 
} 

int GetNumOfNonWSCharacters(const string& words) {
   int count = 0;

   for (int i = 0; i < words.size(); i++) {
      if (words.at(i) != ' ' && words.at(i) != '\t' && words.at(i) != '\n') {
         count++;
      }
   }
   return count;
}

int GetNumOfWords(const string& words) {
   int count = 0;
   bool inWords = false;

   for (int i = 0; i < words.size(); i++) {
      if (words.at(i) != ' ' && words.at(i) != '\t') {
         if (!inWords) {
            count++;
            inWords = true;
         }
      }
      else {
         inWords = false; 
      }
   }

   return count;
}

int FindText (string find, string words) {
   int count = 0;
   int position = 0;

   while (words.find(find, position) != string::npos) {
      count++;
      position = words.find(find, position) + find.size();
   }
   return count;
}

void ReplaceExclamation(string& words) {

   for (int i = 0; i < words.size(); i++) {
      if (words.at(i) == '!') {
         words.at(i) = '.';
      }
   }
}

void ShortenSpace(string& words) {
      string result = "";
      bool space = false;

      for (int i = 0; i < words.size(); i++) {
         if (words.at(i) == ' ') {
            if (!space) {
               result += ' '; 
               space = true;
            }
         }
         else {
            result += words.at(i);
            space = false;
         }
      }

      words = result; 

   }

void executeMenu(char letter,string& words) {
   if (letter == 'q') {
      return;
   }
   if (letter == 'c') {
      cout << "number of non-whitespace characters: " << GetNumOfNonWSCharacters(words) << endl;
   }
   if (letter == 'w') {
      cout << "number of words: " << GetNumOfWords(words) << endl; 
   }
   if (letter == 'f') {
      string find;

      cout << "Enter a word or phrase to be found: " << endl;
      getline (cin >> ws, find);

      cout << "\"" << find << "\" instances: " << FindText(find, words) << endl;
   }
   if (letter == 'r') {
      ReplaceExclamation(words); 
      cout << "Edited text: " << words << endl; 
   }
   if (letter == 's') {
      ShortenSpace(words);
      cout << "Edited text: " << words << endl;
   }
}

int main() {
   string words;
   char letter = ' '; 

   

   cout << "Enter a sample text:" << endl;
   
   getline(cin, words);

   cout << endl; 
   cout << "you entered: " << words << endl; 
   cout << endl;

   while (letter != 'q') {
   printMenu();

   cout << endl; 
   cout << "Choose an option:" << endl; 
   cin >> letter;

   while (letter != 'c' && letter != 'w' && letter != 'f' && letter != 'r' && letter != 's' && letter != 'q') {
      cout << "Choose an option:" << endl;
      cin >> letter;
   }

   executeMenu(letter, words); 

   if (letter != 'q') {
      cout << endl; 
   }
}
    



   return 0;
}