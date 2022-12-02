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

	int k, n, m, d, s;

	input >> k >> n >> m >> d;

	s = ((k * n * m * d) / (k * n * m - k * n - k * m - n * m));

	if (s > 0)
		output << s;
	else
		output << "-1";

	input.close();
	output.close();
}