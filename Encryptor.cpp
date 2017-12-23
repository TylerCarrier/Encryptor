#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void caesarShift(vector<string> &input, int change){

  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for(int i = 0; i < input.size(); ++i){
    for(int j = 0; j < input.at(i).size(); ++j){
      int alphabetLoc;
      for(int k = 0; k < alphabet.size(); ++k){
        if(alphabet.at(k) == input.at(i).at(j)){
          alphabetLoc = alphabet.at(k);
        }
      }
      input.at(i).at(j) = alphabet.at((alphabetLoc + change) % 26);
    }
  }
}


int main(){

  string fileName;
  string word;
  string choice;
  string cipherType;
  int shift;
  vector<string> fileWords;

  cout << "Would you like to encrypt or decrypt?" << endl;
  cin >> choice;
  cout << "What is the name of the file?" << endl;
  cin >> fileName;

  ifstream inFile(fileName);
  ofstream outFile("Result.txt");

  if(inFile.fail()){
    cout << "There was an error opening the file." << endl;
    return 1;
  }

  if(choice == "encrypt"){

    cout << "What type of cipher would you like to use?" << endl;
    cout << "Options: Caesar, Morse" << endl;
    cin >> cipherType;
    if(cipherType == "Caesar"){
      cout << "How many places would you like to shift the result?" << endl;
      cin >> shift;
      shift = shift % 26;
      cout << "Creating encrypted file please wait..." << endl;

      while(inFile >> word){
        fileWords.push_back(word);
      }

      caesarShift(fileWords,shift);

      for(int w = 0; w < fileWords.size(); ++w){
        outFile << fileWords.at(w) << endl;
      }
    }
    if(cipherType == "Morse"){

    }
  }



  if(choice == "decrypt"){
    cout << "What type of cipher was used?" << endl;
    cout << "Options: Caesar, Morse" << endl;
    cin >> cipherType;

    if(cipherType == "Caesar"){
      cout << "How many places was the file shifted?" << endl;
      cin >> shift;

      cout << "ayyy we made it" << endl;
    }

  }



outFile.close();
inFile.close();
cout << "Done!" << endl;
system("PAUSE");
return 0;

}
