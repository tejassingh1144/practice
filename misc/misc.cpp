// stringstream::str
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
using namespace std;
int main () {
  string val = "hello";
  bool iVal =  val[0] == 'h';
  cout << iVal << endl;
  return 0;
}