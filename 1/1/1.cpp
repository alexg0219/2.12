#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input)
    {
        cout << "error";
        return 0;
    }

    int n,x,summ=0;
    double c = 0;
    input >> n;
    vector <int> a;
    a.clear();

    for (int i = 0; i < n; i++)
    {
        input >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n-1; i++)
    {
        if (a[i] == 10 && c <= 9)
        {
            summ = summ + a[i] + a[i + 1] + a[i + 2];
            c++;
        }
        else
        {
            if (a[i] + a[i + 1] == 10 && c <= 9)
            {
                summ = summ + a[i] + a[i + 1] + a[i + 2];
                i++;
                c++;
            }
            else
            {
                if (c <= 9)
                {
                    summ = summ + a[i] + a[i + 1];
                    c++;
                    i++;
                }
            }
        }
        
    }

    summ = summ + a[n - 1];
    
    if (a[n - 1] == 10)
        c++;
    else
        c = c + 0.5;
    
    if (c == 11)
        summ = summ - a[n - 1];

    if (c == 10.5)
        summ = summ - a[n - 1];

    output << summ;

    input.close();
    output.close();
}

