/* main.cc */

#include "heading.h"

// prototype of bison-generated parser function
int yyparse();

int main(int argc, char **argv)
{
  if ((argc > 1) && (freopen(argv[1], "r", stdin) == NULL))
  {
    cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
    exit(1);
  }
  
  yyparse();
  extern vector<string> superBuff;
  extern bool if_err;
  bool if_main = false;

  for (unsigned int i = 0; i < superBuff.size(); i++){
    if (superBuff.at(i).find("main") != string::npos){
      if_main = true;
      break;
    }
  }
  if(!if_main){
    cout << "ERROR: no main function declared";
    return 1;
  }
  else if (if_err){
    return 1;
  }
  else{
    for (unsigned int i = 0; i < superBuff.size(); i++){
      cout << superBuff.at(i);
    }
  }
  return 0;
}

