// map::lower_bound/upper_bound
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


// int main ()
// {
//   std::map<char,int> mymap;
//   std::map<char,int>::iterator itlow,itup;

//   mymap['b']=20;
//   mymap['c']=60;
//   mymap['d']=80;
//   mymap['e']=100;

//   itlow=mymap.lower_bound ('a');  // itlow points to b
//   itup=mymap.upper_bound ('a');   // itup points to e (not d!)
//   std::cout << itlow->first << '\n';
//   std::cout << itup->first << '\n';

//   mymap.erase(itlow,itup);        // erases [itlow,itup)

//   // print content:
//   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }


int main()
{
  std::string str = "wdkdaokdw";
  float a;

  std::stringstream ss(str);

  ss >> a;
  std::cout << a;
}