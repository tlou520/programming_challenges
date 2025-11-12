//A messy solution because wanted to solve it fast
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
class CodeSqStrings {

private:
   unsigned mSmallestInteger;
   unsigned l_sizeString;
   string mLine;
   string mTransformedLine; //string has already \n inserted


   void cleaningString() {
      // Remove padding characters (ASCII 11)
      mLine.erase(std::remove_if(mLine.begin(), mLine.end(), [](unsigned char c) {
         return c == '\v' || c == '\n';
      }), mLine.end());
   }

   void reverseEachSubstring() {
    std::size_t stride = mSmallestInteger + 1; // includes '\n'
    for (std::size_t i = 0; i < mTransformedLine.size(); i += stride) {
        std::reverse(mTransformedLine.begin() + i, mTransformedLine.begin() + i + mSmallestInteger);
    }
   }

   void takingmSmallestInteger() {
      unsigned int index = 0;
      while (index < mTransformedLine.size()) 
      {
         if (mTransformedLine[index] == '\n') 
         {
            break;
         }
         index++;
      }
      mSmallestInteger = index;
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

   void reverseLineOrder() {
      mLine = mTransformedLine;
      return;
      std::istringstream stream(mTransformedLine);
      std::vector<std::string> lines;
      std::string line;

      // Split by newline
      while (getline(stream, line))
         lines.push_back(line);

      // Reverse order
      reverse(lines.begin(), lines.end());

      // Join back together
      std::ostringstream result;
      for (std::size_t i = 0; i < lines.size(); ++i) {
         result << lines[i];
         if (i + 1 < lines.size())
               result << '\n';
      }

      mLine = result.str();
      cout << mLine << endl;
   }

public:

   CodeSqStrings(string mTransformedLine) : mTransformedLine(mTransformedLine) {
        // constructor body (can be empty or contain other code)
    }
    
   CodeSqStrings() = default;

    // Reads an entire line (including spaces)
   void readLine(const string& line) {
      mLine = line;  
      l_sizeString = static_cast<unsigned>(line.size());
      smallestInteger();
      padWithAscii11();
      transformingStringtoSquareStringgN();
      mirrorMainDiagonal();
      reverseEachSubstring();
   }

   unsigned getSizeString() const {
        return l_sizeString;
    }

   unsigned getSmallestInteger() const {
        return mSmallestInteger;
    }

    static string code(const string &strng)
    {
         CodeSqStrings ss;
         ss.readLine(strng);
         return ss.mTransformedLine;
    }

   static string decode(string &strng)
   {
      CodeSqStrings ss(strng);
      ss.takingmSmallestInteger();
      ss.reverseEachSubstring();
      ss.mirrorMainDiagonal();
      ss.reverseLineOrder();
      ss.cleaningString();
      std::cout << ss.mLine << std::endl;

      return ss.mLine;
   }
};

int main() 
{
   CodeSqStrings ss;
   //string input = "I.was.going.fishing.that.morning.at.ten.o'clock";
   string input = "abcdefghijklmnop";
   ss.code(input);
   string input2 = "fa  h ttrheI ilS\nitifakw   s'irdo\nc cotnihftivce m\neAereocaihree,we\n.n   wedroe . i \n\013dIdT , es t Sls\n\013 seoe t.eIaFola\n"
        "\013w s nIo   srm y\n\013oatso  Bwhtoee \n\013ulrautpuhoem nt\n\013lsuyghetold sdh\n\013doc hir  d wa e\n\013  tt niif ohyi \n\013sgihoksfawfa nw\n"
        "\013uroaf h vi ti o\n\013fent I iotd nfr";
   ss.decode(input2);
   return 0;
}