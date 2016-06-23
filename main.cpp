#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, char ** argv)
{
  int a(3);
  int b = 0;
  int c(0);
  string in_line;
  ifstream file(argv[1]);
  cout << "hello, it's me!" << endl;

  // ***********Read lines and parse from database.txt
  while(getline(file, in_line))
    {
      a = in_line.find("effets indÃ©sirables notoires",0);
      in_line = in_line.erase(a-1, 33);
      c = in_line.find(" et ", 0);
      if (c != -1) 
	in_line = in_line.replace(c, 4, ", ", 2);
      cout << " ligne " << ++b << " : " << in_line << " " << a << endl;
      //with all that done, we will find every ::, the string between pos 0 and :: will be the drug
      //after storing the drug, we cut the string
      //between every column, we will find an undesirable effect by taking the substring between the consecutive positions
      //if there is two comums following each other, there is no effect between them 
      //store all of them in the hashmap
      //the map will be declared unordered_map <string, vector<string>> (check in internet)
    }
  return 0;
}
