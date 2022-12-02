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

	int n,cn=0;
    vector <int> b = { 1,5,6,8,9,10,11,12};
	vector <int> a = { 2,3,4,7,13 };

	input >> n;

	if (n < 6)
		output << a[n - 1] << endl << b[n - 1];
	else
	{
		for (int i = 6; i < n+1; i++)
		{
			a.push_back(b[i - 2] + b[i - 4]);
			for (int j = a[i-2] + 1; j < b[i - 2] + b[i - 4]; j++)
			{
				b.push_back(j);
			}
		}

		output << a[n - 1] << endl << b[n-1];
	}

	input.close();
	output.close();
}

