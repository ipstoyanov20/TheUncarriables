#include <iostream>

using namespace std;

void SelectFormula()
{
  
  int FormulaSelect;

  system("clear");

  cout << "1 - Speed - In progress" << endl;
  cout << "2 - Pressure - In Progress" << endl;
  cout << "3 - Density - In Progress" << endl;
  cout << "4 - Electric current - In Progress" << endl << endl;

  cin >> FormulaSelect;

}

int main()
{
  bool retry = 1;
  char x;

  while(retry)
  {
    SelectFormula();
    cout << endl << endl;
    cout << "Do you want to exit? ";

    while(true)
    {
      cin >> x;
      if(x == 'Y')
      {
        retry = 0;
        break;
      }
      else if(x == 'N')
      {
        retry = 1;
        break;
      }
        
      }
    }
}