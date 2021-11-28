#include<iostream>

using namespace std;

void Speed()
{
  double V = 0, S = 0, t = 0; //Initialize parameters
  int FormulaSelect;
  char x;

  system("clear"); //clear the console

  cout << "What do you want to find?" << endl;
  cout << "S / V / t" << endl;
  cin >> x; //Enter what to find

  system("clear");

    if(x == 'V') //This is for speed
    {
      cout <<"The formula is: V = S / t" << endl;
      
      cout << "[Kilometers]   S = ";
      cin >> S;
      cout << "[Hours]   t = ";
      cin >> t;
      if(t == 0)
      {
        cout << "Not valid input!";  //You cannot divide any number by 0
        cout << "Try again: ";
        cin >> t;
        if(t == 0)
        {
          Speed();
        }
      }
      cout <<  endl;
      V = S / t;
      cout << "V = " << V << " km/h";
    }
    else if(x == 'S') //This is for distance
    {
      cout << "The formula is: S = V . t" << endl;
      
      cout << "[Kilometers per hour]   V = ";
      cin >> V;
      cout << "[Hours]   t = ";
      cin >> t;
      cout <<  endl;
      S = V * t;
      cout << "S = " << S << " km";
    }
    else if(x == 't') //This is for time
    {
      cout << "The formula is: t = S / V" << endl;
      
      cout << "[Kilometers]   S = ";
      cin >> S;
      cout << "[Kilometers per hour]   V = ";
      cin >> V;
      if(V == 0)
      {
        cout << "Not valid input!" << endl;
        cout << "Try again: ";
        cin >> V;
        if(V == 0)
        {
          Speed();
        }
      }
      cout <<  endl;
      t = S / V;
      cout << "t = " << t << " hours";
    }
    else
    {
      cout << "Not valid input!" << endl;
      Speed();
    }

}

void SelectFormula()
{
  
  int FormulaSelect;

  system("clear");

  cout << "1 - Speed" << endl;
  cout << "2 - Pressure - In Progress" << endl;
  cout << "3 - Density - In Progress" << endl;
  cout << "4 - Electric current - In Progress" << endl << endl;

  cin >> FormulaSelect; //Select formula

  if(FormulaSelect == 1)
  {
    Speed(); // Start Speed() function
  }

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

    while(true) //Use the calculator again
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