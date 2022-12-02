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

    int R, r, h, b;

    input >> R >> r >> h >> b;
    
    if (R >= sqrt(pow(h + r - b, 2) + pow(r, 2)))
        output << "YES";
    else
        output << "NO";

    input.close();
    output.close();
}

