#pragma once

#include <iostream>

#include <fstream>

#include <string>

using namespace std;

class DataSet

{
private:

    int *data;

    size_t size;

    double med;

public:

    explicit DataSet(const string &filename);


    ~DataSet();

    // Median

    friend double median(const DataSet &ds);

    // Mean

    friend double mean(const DataSet &ds);

    // Mode

    friend int mode(const DataSet &ds);

    //
    // Bubble Sort
    void bubbleSort();
};