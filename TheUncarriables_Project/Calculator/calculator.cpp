#include<iostream>

using namespace std;

double Speed() //Formula for speed
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
        cout << "[Kilometers per hour]   V = ";
        return V;
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
        cout << "[Kilometers]   S = ";
        return S;
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
        cout << "[Hours]   t = ";
        return t;
    }
    else
    {
        cout << "Not valid input!" << endl;
        Speed();
        return 0;
    }

}

double Pressure() //Formula for pressure
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
        cout << "[Pascal]   P = ";
        return P;

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
        cout << "[Nutons]   F = ";
        return F;
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
        cout << endl;
        S = F / P;
        cout << "[m2]   S = ";
        return S;
    }
    else
    {
      cout << "Not valid input!" << endl;
      Pressure();
      return 0;
    }

}

double Density() //Formula for density
{
    double p, m, V;
    char x;
    
    system("clear");

    cout << "What do you want to find?" << endl;
    cout << "p / m / V" << endl;
    cin >> x;
    
    system("clear");

    if (x == 'p') //Finds Density
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
        cout << "[kg/m3]   p = ";
        return p;

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
        cout << "[Kilograms]   m = ";
        return m;
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
        cout << "[m3]   V = ";
        return V;
        
    }
    else
    {
        cout << "Not valid input!" << endl;
        Density();
        return 0;
    }
}


void displacementPositiveAcceleration()
{
    double v0 = 0, v = 0, t = 0, a = 0, sV = 0, s = 0;
    string x;

    system("cls");

    cout << "What do you want to find?" << endl;
    cout << "V0/ V / t / displacement with starting speed (sV) / s" << endl;
    cin >> x;

    system("cls");

    if (x == "sV") //Finds displacement with starting speed
    {
        cout << "The formula is: sV = V0 . t + a . t^2" << endl;

        cout << "[Meters per second]   V0 = ";
        cin >> v0;
        cout << "[Seconds]   t = ";
        cin >> t;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;

        cout << endl;
        sV = v0 * t + a * pow(t, 2);
        cout << "[Meters]   sV = " << sV;
    }
    else if (x == "s") //Finds displacement with no starting speed
    {
        cout << "The formula is: s = (a . t^2) / 2" << endl;

        cout << "[Meters per second, per second]   a = ";
        cin >> a;
        cout << "[Seconds]   t = ";
        cin >> t;

        cout << endl;
        s = (a * pow(t, 2)) / 2;
        cout << "[Meters]   s = " << s;
    }
    else if (x == "V0") //Finds starting speed
    {
        cout << "The formula is: V0 = V - a . t" << endl;

        cout << "[Meters per second]   V = ";
        cin >> v;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;
        cout << "[Seconds]   t = ";
        cin >> t;

        cout << endl;
        v0 = v - a * t;
        cout << "[Meters per second]   V0 = " << v0;

    }
    else if (x == "V") //Finds speed
    {
        cout << "The formula is: V = V0 + a . t" << endl;

        cout << "[Meters per second]   V0 = ";
        cin >> v0;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;
        cout << "[Seconds]   t = ";
        cin >> t;

        cout << endl;
        v = v0 + a * t;
        cout << "[Meters per second]   V = " << v;
    }
    else if (x == "t")     //Finds time
    {
        cout << "The formula is: t = (V - V0) / a" << endl;

        cout << "[Meters per second]   V = ";
        cin >> v;
        cout << "[Meters per second]   V0 = ";
        cin >> v0;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;

        if (a == 0)
        {
            cout << "Not valid input!";
            cout << "Try again: ";
            cin >> a;
            if (a == 0)
            {
                displacementPositiveAcceleration();
            }

        }
        cout << endl;
        t = (v - v0) / a;
        cout << "[Seconds]   t = " << t;

    }
    else
    {
        cout << "Not valid input!" << endl;
        displacementPositiveAcceleration();
    }
}

void displacementNegativeAcceleration()
{
    double v0 = 0, v = 0, t = 0, a = 0, sS = 0, s = 0, t0 = 0;
    string x;

    system("cls");

    cout << "What do you want to find?" << endl;
    cout << "V0/ V / t / stopping displacement (sS) / s / t0" << endl;
    cin >> x;

    system("cls");

    if (x == "sS") //Finds stopping displacement
    {
        cout << "The formula is: sS = V0^2 / (2 . a)" << endl;

        cout << "[Meters per second, per second]   a = ";
        cin >> a;
        cout << "[Meters per second]   V0 = ";
        cin >> v0;

        cout << endl;
        sS = pow(v0, 2) / (2 * a);
        cout << "[Meters]   sS = " << sS;
    }
    else if (x == "t0") //Finds time for stopping
    {
        cout << "The formula is: t0 = V0 / a" << endl;

        cout << "[Meters per second]   V0 = ";
        cin >> v0;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;

        cout << endl;
        t0 = v0 / a;
        cout << "[Seconds]   t0 = " << t0;
    }
    else if (x == "s") //Finds displacement
    {
        cout << "The formula is: s = V0 . t - (a . t^2) / 2" << endl;

        cout << "[Meters per second]   V0 = ";
        cin >> v0;
        cout << "[Seconds]   t = ";
        cin >> t;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;

        cout << endl;
        s = v0 * t - (a * pow(t, 2)) / 2;
        cout << "[Meters]   s = " << s;
    }
    else if (x == "V0") //Finds starting speed
    {
        cout << "The formula is: V0 = V - a . t" << endl;

        cout << "[Meters per second]   V = ";
        cin >> v;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;
        cout << "[Seconds]   t = ";
        cin >> t;

        cout << endl;
        v0 = v - a * t;
        cout << "[Meters per second]   V0 = " << v0;

    }
    else if (x == "V") //Finds speed
    {
        cout << "The formula is: V = V0 - a . t" << endl;

        cout << "[Meters per second]   V0 = ";
        cin >> v0;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;
        cout << "[Seconds]   t = ";
        cin >> t;

        cout << endl;
        v = v0 - a * t;
        cout << "[Meters per second]   V = " << v;
    }
    else if (x == "t")     //Finds time
    {
        cout << "The formula is: t = (V - V0) / a" << endl;

        cout << "[Meters per second]   V = ";
        cin >> v;
        cout << "[Meters per second]   V0 = ";
        cin >> v0;
        cout << "[Meters per second, per second]   a = ";
        cin >> a;

        if (a == 0)
        {
            cout << "Not valid input!";
            cout << "Try again: ";
            cin >> a;
            if (a == 0)
            {
                displacementPositiveAcceleration();
            }

        }
        cout << endl;
        t = (v - v0) / a;
        cout << "[Seconds]   t = " << t;

    }
    else
    {
        cout << "Not valid input!" << endl;
        displacementPositiveAcceleration();
    }
}



double SelectFormula()
{
    
    int FormulaSelect;

    system("clear");

    cout << "1 - Speed" << endl;
    cout << "2 - Displacement with positive acceleration" << endl;
    cout << "3 - Displacement with negative acceleration" << endl;
    cout << "4 - Pressure" << endl;
    cout << "5 - Density" << endl;
    cout << "6 - Electric currency - In Progress" << endl << endl;

    cin >> FormulaSelect; //Select formula

    if (FormulaSelect == 1)
    {
        return Speed(); //Starts Speed() function
    }
    else if (FormulaSelect == 2)
    {
        return displacementPositiveAcceleration(); //Starts displacementPositiveAcceleration() function
    }
    else if (FormulaSelect == 3)
    {
        return displacementNegativeAcceleration(); //Starts displacementNegativeAcceleration() function
    }
    else if(FormulaSelect == 4)
    {
      return Pressure(); //Starts Pressure() function
    }
    else if(FormulaSelect == 5)
    {
      return Density(); //Starts Density() function
    }
    else
    {
      return 0;
    }

}

int main()
{
    bool retry = 1;
    char x;

    while (retry)
    {
        cout << SelectFormula();
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