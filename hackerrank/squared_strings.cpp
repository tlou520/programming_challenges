#include <iostream>
#include <string>


using namespace std;
class SquareStrings {

private:
   unsigned mSmallestInteger;
   unsigned l_sizeString;
   string mLine;
   string mTransformedLine; //string has already \n inserted


   void reverseEachSubstring() {
    std::size_t stride = mSmallestInteger + 1; // includes '\n'
    for (std::size_t i = 0; i < mTransformedLine.size(); i += stride) {
        std::reverse(mTransformedLine.begin() + i, mTransformedLine.begin() + i + mSmallestInteger);
    }
   }


   void mirrorMainDiagonal() {
      std::size_t stride = mSmallestInteger + 1; // +1 because of '\n'
      for (std::size_t i = 0; i < mSmallestInteger; ++i) {
         for (std::size_t j = i + 1; j < mSmallestInteger; ++j) {
               std::swap(mTransformedLine[i * stride + j], mTransformedLine[j * stride + i]);
         }
      }
   }

   void transformingStringtoSquareStringgN()
   {
      mTransformedLine.clear();
      mTransformedLine.reserve(mLine.size() + mLine.size() / mSmallestInteger); // reserve to minimize reallocations

      for (std::size_t i = 0; i < mLine.size(); ++i) {
         mTransformedLine += mLine[i];
         if ((i + 1) % mSmallestInteger == 0 && i + 1 != mLine.size()) {
            mTransformedLine += '\n';
         }
      }
      return;
   }

   void padWithAscii11() {
      if (mLine.size() < mSmallestInteger * mSmallestInteger) {
         mLine.append(mSmallestInteger * mSmallestInteger - mLine.size(), static_cast<char>(11));
      }
   }

   void smallestInteger(){
      mSmallestInteger = 1;
      while (mSmallestInteger < l_sizeString) {
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
      transformingStringtoSquareStringgN();
      mirrorMainDiagonal();
      reverseEachSubstring();
      string input2 = "abcdefghijklmnop";
      std::cout << input2 << std::endl;
      std::cout << mTransformedLine << std::endl;
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
   string input = "I.was.going.fishing.that.morning.at.ten.o'clock";
   ss.readLine(input);
   return 0;
}