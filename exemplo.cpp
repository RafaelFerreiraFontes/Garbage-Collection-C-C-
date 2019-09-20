#include <iostream>

using namespace std;

#include "memoria.hpp"

int main()
{
  GCtype<int> a;
  GCtype<int> b;

  a.malloc2(1);

  a.atribuir2(10);

  b.atribuir(a.ed);
  
  Dump();

  b.malloc2(10);
  
  cout << endl;

  for(int i = 0; i < 10; i++)
  {
    b.ed[i] = i*10; 
  }

  Dump();
  
  cout << endl;
 
  b.atribuir(NULL);
  a.atribuir(NULL);

  Dump();

  cout << endl;
}
