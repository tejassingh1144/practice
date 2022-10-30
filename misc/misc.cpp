// stringstream::str
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
using namespace std;
int main () {
  string val;
  int iVal;
  getline(cin,val);
  iVal = stoi(val);
  cout << iVal << endl;
  return 0;
}