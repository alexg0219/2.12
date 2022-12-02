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

    int n, k,p,c=0;
    input >> n >> k;
    vector <int> a;
    vector <int> na;
    a.clear();
    na.clear();
    for (int i = 1; i < n+1; i++)
    {
        a.push_back(i);
    }
   
    
    while (a.size() != 1)
    {
        auto t = a.cbegin();
        if (a.size() % k != 0)
        {
            while (a.size() % k != 0 && a.size() >=k)
            {
                for (int j = 0; j < a.size() % k; j++)
                {
                    na.push_back(a[j + (a.size() / k) * k]);
                    a.erase(t + j + (a.size() / k) * k);
                }

            }
        }

        for (int i = 1; i < a.size() + 1; i++)
        {
            if (i % k != 0)
            {
                na.push_back(a[i - 1]);
            }
        }
        
        a.clear();
        if (na.size() > k - 1)
        {
            for (int j = 0; j < na.size(); j++)
                a.push_back(na[j]);
        }
        else
        {
            for (int j = 0; j < na.size(); j++)
            {
                for (int i = 0; i < na.size(); i++)
                    a.push_back(na[i]);
            }
            while (a.size() != 1)
            {
                
                p = a[k - 1];
                for (int i = 0; i < a.size(); i++)
                    if (a[i] == p)
                        a.erase(a.cbegin() + i);
                if (a.size() == k-1)
                {
                    for (int j = 0; j < k - 2; j++)
                    {
                        a.erase(a.cbegin());
                    }
                }
            }

        }
        na.clear();
    }
    for (auto i : a)
        output << i << " ";
    input.close();
    output.close()
}
