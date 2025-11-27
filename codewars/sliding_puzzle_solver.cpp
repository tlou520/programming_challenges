#include <iostream>
#include <vector>


class Solver {

public:
    Solver(const std::vector<std::vector<int>>& input)
        : mGrid(input)
    {}


   void print() const {
      for (const auto& row : mGrid) {
         for (int value : row) {
               std::cout << value << ' ';
         }
         std::cout << '\n';
      }
   }


   void solve() {
      // Solve method implementation
   }
private:
   std::vector<std::vector<int>> mGrid;

};

std::vector<int> slide_puzzle(const std::vector<std::vector<int>> &arr)
{
   Solver s(arr);
   s.print();
   return std::vector<int>();
}



int main() {
   
   std::vector<std::vector<int>> grid{
      { 1, 2, 3, 4 },
      { 5, 0, 6, 8 },
      { 9,10, 7,11 },
      {13,14,15,12 }
   };

   slide_puzzle(grid);

}