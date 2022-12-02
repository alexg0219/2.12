#include <iostream>
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

    int n, k,a=0;
    input >> n >> k;
    a = 1 + (n - 1) * k;
    for (int i = 0; i < k; i++)
    {
        a = a + i*(n-2);
    }
    
    output << a;

    input.close();
    output.close();
}

