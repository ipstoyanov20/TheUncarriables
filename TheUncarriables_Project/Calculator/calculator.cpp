#include<iostream>

using namespace std;

void Speed()
{
    double V = 0, S = 0, t = 0; //Initialize parameters
    char x;

    system("clear"); //clear the console

    cout << "What do you want to find?" << endl;
    cout << "S / V / t" << endl;
    cin >> x; //Enter what to find

    system("clear");

    if (x == 'V') //This is for speed
    {
        cout << "The formula is: V = S / t" << endl;

        cout << "[Kilometers]   S = ";
        cin >> S;
        cout << "[Hours]   t = ";
        cin >> t;
        if (t == 0)
        {
            cout << "Not valid input!";  //You cannot divide any number by 0
            cout << "Try again: ";
            cin >> t;
            if (t == 0)
            {
                Speed();
            }
        }
        cout << endl;
        V = S / t;
        cout << "V = " << V << " km/h";
    }
    else if (x == 'S') //This is for distance
    {
        cout << "The formula is: S = V . t" << endl;

        cout << "[Kilometers per hour]   V = ";
        cin >> V;
        cout << "[Hours]   t = ";
        cin >> t;
        cout << endl;
        S = V * t;
        cout << "S = " << S << " km";
    }
    else if (x == 't') //This is for time
    {
        cout << "The formula is: t = S / V" << endl;

        cout << "[Kilometers]   S = ";
        cin >> S;
        cout << "[Kilometers per hour]   V = ";
        cin >> V;
        if (V == 0)
        {
            cout << "Not valid input!" << endl;
            cout << "Try again: ";
            cin >> V;
            if (V == 0)
            {
                Speed();
            }
        }
        cout << endl;
        t = S / V;
        cout << "t = " << t << " hours";
    }
    else
    {
        cout << "Not valid input!" << endl;
        Speed();
    }

}
void Pressure()
{
    double P, F, S;
    char x;
    system("clear");
    cout << "What do you want to find?" << endl;
    cout << "P / F / S" << endl;
    cin >> x;
    system("clear");
    if (x == 'P')
    {
        cout << endl << "The formula is: P = F / S" << endl;   //Finds Pressure

        cout << "[Nutons]   F = ";
        cin >> F;
        cout << "[m2]   S = ";
        cin >> S;
        if (S == 0)
        {
            cout << "Not valid input!";
            cout << "Try again: ";
            cin >> S;
            if (S == 0)
            {
                Pressure();
            }
        }
        cout << endl;
        P = F / S;
        cout << "P = " << P << " Pa";

    }
    else if (x == 'F')      //Finds Force
    {
        cout << endl << "The formula is: F = P . S" << endl;

        cout << "[Pascal]   P = ";
        cin >> P;
        cout << "[m2]   S = ";
        cin >> S;
        cout << endl;
        F = P * S;
        cout << "F = " << F << " N";
    }
    else if (x == 'S') //Finds the Area
    {
        cout << endl << "The formula is: S = F / P" << endl;

        cout << "[Nutons]   F = ";
        cin >> F;
        cout << "[Pascal]   P = ";
        cin >> P;
        if (P == 0)
        {
            cout << "Not valid input!";
            cout << "Try again: ";
            cin >> P;
            if (P == 0)
            {
                Pressure();
            }
        }
    }
    cout << endl;
    S = F / P;
    cout << "S = " << S << " m2";
}
void Density()
{
    double p, m, V;
    char x;
    cout << "What do you want to find?" << endl;
    cout << "p / m / V" << endl;
    cin >> x;

    if (x == 'p')    //Finds Density
    {
        cout << endl << "The formula is: p = m / V" << endl;  

        cout << "[Kilograms]   m = ";
        cin >> m;
        cout << "[m3]   V = ";
        cin >> V;
        if (V == 0)
        {
            cout << "Not valid input!";
            cout << "Try again: ";
            cin >> V;
            if (V == 0)
            {
                Density();
            }
        }
        cout << endl;
        p = m / V;
        cout << "p = " << p << " kg/m3";

    }
    else if (x == 'm') //Finds mass
    {
        cout << endl << "The formula is: m = p . V" << endl;

        cout << "[kg/m3]   p = ";
        cin >> p;
        cout << "[m3]   V = ";
        cin >> V;
        cout << endl;
        m = p * V;
        cout << "m = " << m << " kg";
    }
    else if (x == 'V')     //Finds Volume
    {
        cout << endl << "The formula is: V = m / p" << endl;

        cout << "[Kilograms]   m = ";
        cin >> m;
        cout << "[kg/m3]   p = ";
        cin >> p;
        if (p == 0)
        {
            cout << "Not valid input!";
            cout << "Try again: ";
            cin >> p;
            if (p == 0)
            {
                Density();
            }
        }
        cout << endl;
        V = m / p;
        cout << "V = " << V << " m3";
    }
}


void SelectFormula()
{

    int FormulaSelect;

    system("clear");

    cout << "1 - Speed" << endl;
    cout << "2 - Pressure" << endl;
    cout << "3 - Density" << endl;
    cout << "4 - Electric current - In Progress" << endl << endl;

    cin >> FormulaSelect; //Select formula

    if (FormulaSelect == 1)
    {
        Speed(); // Start Speed() function
    }

}

int main()
{
    bool retry = 1;
    char x;

    while (retry)
    {
        SelectFormula();
        cout << endl << endl;
        cout << "Do you want to exit? ";

        while (true) //Use the calculator again
        {
            cin >> x;
            if (x == 'Y')
            {
                retry = 0;
                break;
            }
            else if (x == 'N')
            {
                retry = 1;
                break;
            }

        }
    }
}