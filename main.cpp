#include <iostream>

#include "src/meet.hpp"

using namespace std;

int main()

{
    cout << "Enter the filename: ";

    string filename; cin >> filename;

    DataSet ds(filename);

    cout << "The median of the dataset is " << median(ds) << endl;
}