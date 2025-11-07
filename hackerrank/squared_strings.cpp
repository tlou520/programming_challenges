#include <iostream>
#include <string>

using namespace std;
class SquareStrings {

private:
   unsigned mSmallestInteger;
   unsigned l_sizeString;
   string mLine;

   void transformingStringtoSubstringN(){
      
   }

   void padWithAscii11() {
      if (mLine.size() < mSmallestInteger) {
         mLine.append(mSmallestInteger - mLine.size(), static_cast<char>(11));
      }
   }

   void smallestInteger(){
      mSmallestInteger = 1;
      while (mSmallestInteger >= l_sizeString) {
         if ((mSmallestInteger * mSmallestInteger) >= l_sizeString) {
            break;
         }
         mSmallestInteger++;
      }
      return;
   }

public:
    // Reads an entire line (including spaces)
   void readLine(const string& line) {
      mLine = line;  
      l_sizeString = static_cast<unsigned>(line.size());
      smallestInteger();
      padWithAscii11();
   }

   unsigned getSizeString() const {
        return l_sizeString;
    }

   unsigned getSmallestInteger() const {
        return mSmallestInteger;
    }

};

int main() 
{
   SquareStrings ss;
   string input = "abcdefghijklmnop";
   ss.readLine(input);
   std::cout << "You entered: " << input << std::endl;
   return 0;
}