#ifndef STLINE_H
#define STLINE_H

#include <iostream>
using namespace std;

class StLine
{
   public:
      int getLength( void );
      StLine(int len);         // simple constructor
      StLine(const StLine &obj);  // copy constructor
      ~StLine();                 // destructor

   private:
      int *ptr;
};

#endif
