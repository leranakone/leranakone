#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
  Stack st;
  st.push(6);
  st.push(60);
  st.push(40);
  //st.show();
  Stack s(st);
  s.show();
  Stack ss = s;
  ss.show();
  return 0;
}