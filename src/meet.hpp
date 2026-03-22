#pragma once

#include <iostream>

#include <fstream>

#include <sstream>

#include <string>

#include <cmath>

using namespace std;

class DataSet

{

private:

    int* data;

    size_t size;

    double med;

public:

    explicit DataSet(const string& filename) : data(nullptr), size(0), med(0.0)

    {
        ifstream file(filename);

        if (!file) { cerr << "Not valid\n"; return; }

        string line; getline(file, line);

        stringstream ss(line); string token;

        while (getline(ss, token, ',')) size++;

        data = new int[size];

        ss.clear(); ss.str(line);

        for (size_t i = 0; i < size; ++i) { getline(ss, token, ','); data[i] = stoi(token); }

        if (size % 2 == 1) med = data[size/2];

        else med = (data[size/2 -1] + data[size/2]) / 2.0;
    }

    ~DataSet() { delete[] data; }

    friend double median(const DataSet& ds) { return ds.med; }
};
