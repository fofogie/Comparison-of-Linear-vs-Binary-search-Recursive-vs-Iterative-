#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include "searchAlgorithm.h"

using namespace std;
using namespace std::chrono;

int main() {
    //makes the input size
    int testSizes[] = {10, 100, 500, 1000, 2500, 5000, 7500, 10000};

    //opens the data 
    string filename = "10000 Sales Records.csv";

    cout << "Search Order ID: ";
    long long target;
    cin >> target;

    for (int n : testSizes)
    {
        //uses the data
        vector<long long> ids;
        ifstream file(filename);
        string line;
        getline(file, line);

        // CHecking & Sorting the list
        for (int i = 0; i < n && getline(file, line); i++)
        {
            size_t pos = 0;
            for(int col = 0; col < 6; col++)
                pos = line.find(',', pos) + 1;

            ids.push_back(stoll(line.substr(pos, line.find(',', pos) - pos)));
        }
        sort(ids.begin(), ids.end());

        cout << " Size n = " << n << endl;
        if (binaryIterative(ids, target, 0, (int)ids.size() - 1))
            cout << "found" << endl;
        else
            cout << " no no found" << endl;

        // This handles and counts the running time
        auto start = high_resolution_clock::now();
        linearIterative(ids, target);
        double t1 = duration<double, milli>(high_resolution_clock::now() - start).count();

        start = high_resolution_clock::now();
        linearRecursive(ids, target, 0);
        double t2 = duration<double, milli>(high_resolution_clock::now() - start).count();

        start = high_resolution_clock::now();
        binaryIterative(ids, target, 0, (int)ids.size() - 1);
        double t3 = duration<double, milli>(high_resolution_clock::now() - start).count();

        start = high_resolution_clock::now();
        binaryRecursive(ids, target, 0, (int)ids.size() - 1);
        double t4 = duration<double, milli>(high_resolution_clock::now() - start).count();

        cout << fixed << setprecision(6);
        cout << "Linear Iterative: " << t1 << " ms" << endl;
        cout << "Linear Recursive: " << t2 << " ms" << endl;
        cout << "Binary Iterative: " << t3 << " ms" << endl;
        cout << "Binary Recursive: " << t4 << " ms" << endl;

        cin.get();
    }

    return 0;
}
