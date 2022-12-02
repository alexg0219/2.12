#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

double f(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input)
    {
        cout << "error";
        return 0;
    }

    int n,n1,n2,n3;
    double x,max=0;
    vector <int> arr;

    input >> n;

    for (int i = 0; i < n; i++)
    {
        input >> x;
        arr.push_back(x);
    }

    for (int i = 0; i < n-2; i++)
        for (int j = 1; j < n-1; j++)
            for (int k = j+1; k < n; k++)
            {
                if (f(arr[i], arr[j], arr[k]) > max)
                {
                    max = f(arr[i], arr[j], arr[k]);
                    n1 = i+1;
                    n2 = j+1;
                    n3 = k+1;
                }
            }
    if (max == 0)
        output << "-1";
    else
        output << max << endl << n1 << " " << n2 << " " << n3;

    input.close();
    output.close();
}
