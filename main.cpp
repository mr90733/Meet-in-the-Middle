#include <iostream>

#include "src/meet.hpp"

using namespace std;

int main()

{
    cout << "Enter the filename: ";

    string filename; cin >> filename;

    DataSet ds(filename);

    // Median and Bubble Sort

    ds.bubbleSort();

    cout << "Median: " << median(ds) << endl;

    // Mean
    cout << "Mean: " << mean(ds) << endl;

    // Mode
    cout << "Mode: " << mode(ds) << endl;

    return 0;
}
