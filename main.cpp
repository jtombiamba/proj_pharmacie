#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>


using namespace std;


int main(int argc, char ** argv)
{
  int a(3);
  int b = 0;
  int c(0);
  int med(0);
  int ind(0), ind2(0);
  string in_line;

  unordered_map <string, vector<string>> Biblio;
  std::unordered_map <string, vector<string>>::iterator it;
  std::vector<string>::iterator it2;

  ifstream file(argv[1]);

  cout << "hello, it's me!" << endl;

  // ***********Read lines and parse from database.txt
  while(getline(file, in_line))
    {
      a = in_line.find("effets indÃ©sirables notoires",0);
      in_line = in_line.erase(a-1, 33);
      in_line = in_line.erase(in_line.size()-1,1);
      c = in_line.find(" et ", 0);
      if (c != -1) 
	in_line = in_line.replace(c, 4, ", ", 2);
      
      med = in_line.find(" :: ", 0);
      ind = in_line.find(", ", med+4);

      //start one insertion in hashmap
      if (c == -1)
      	{
	
      	  Biblio[in_line.substr(0, med)] = vector <string> (1, in_line.substr(med+4,in_line.size() - med - 4));
      	}
      //start multiple insertions in hashmap
      else
      	{
      	  Biblio[in_line.substr(0, med)] = vector <string> (1, in_line.substr(med+4,ind-med-4));

	  //find the new entry in the map 
	  it = Biblio.find(in_line.substr(0, med));
 
	  //cout << in_line.substr(ind2,ind-ind2) << endl;
	 
	  if(it!=Biblio.end())
	    { 
	      //add element in the vector while there are indesirable effects
	      while(ind!=-1)
		{
		  ind2 = ind + 2;
		  ind = in_line.find(", ", ind2);

		  it2 = it->second.end();
		  it->second.insert(it2, in_line.substr(ind2,ind-ind2));
		}
	    }
      	}

      cout << " ligne " << ++b << " : " << in_line << " " << endl;
      //with all that done, we will find every ::, the string between pos 0 and :: will be the drug
      //after storing the drug, we cut the string
      //between every column, we will find an undesirable effect by taking the substring between the consecutive positions
      //if there is two comums following each other, there is no effect between them 
      //store all of them in the hashmap
      //the map will be declared unordered_map <string, vector<string>> (check in internet)
    }
  cout << endl;

  for(it=Biblio.begin();it!=Biblio.end();++it)
    {
      cout << it->first << " ==> ";
      for (it2=it->second.begin();it2!=it->second.end();++it2)
	{
	  cout << *it2 << ", " ;
	}
      cout << it->second.size() << endl;
      //cout << it->first << " ==> " << it->second << endl;
    }
  return 0;
}
