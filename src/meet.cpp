#include "meet.hpp"

#include <iostream>

#include <fstream>

#include <sstream>

#include <string>

#include <cmath>


DataSet::DataSet(const string &filename)

{
    data = nullptr;

    size = 0;

    med = 0.0;

    ifstream file(filename);

    if (!file)

    {
        cerr << "Not valid\n";
        return;
    }

    string line;

    getline(file, line);

    if (line.empty())

    {
        cerr << "Empty file\n";
        return;
    }

    stringstream ss(line);

    string token;

    while (getline(ss, token, ','))

        size++;

    if (size == 0)

    {
        cerr << "No data\n";

        return;
    }

    data = new int[size];

    ss.clear();

    ss.str(line);

    for (size_t i = 0; i < size; ++i)

    {
        getline(ss, token, ',');

        data[i] = stoi(token);
    }

    // median

    if (size % 2 == 1)

        med = static_cast<double>(data[size / 2]);

    else

        med =
            (static_cast<double>(data[size / 2 - 1]) +

             static_cast<double>(data[size / 2])) /
            2.0;
}

// Destructor

DataSet::~DataSet()

{
    delete[] data;
}

// Median

double median(const DataSet &ds)

{
    return ds.med;
}

// Mean

double mean(const DataSet &ds)

{
    if (ds.size == 0)

        return 0;

    double sum = 0;

    for (size_t i = 0; i < ds.size; i++)

        sum += ds.data[i];

    return sum / (1.0 * ds.size);
}

// Mode

int mode(const DataSet &ds)

{
    if (ds.size == 0)

        return 0;

    int bestValue = ds.data[0];

    int bestCount = 0;

    for (size_t i = 0; i < ds.size; i++)

    {
        int count = 0;

        for (size_t j = 0; j < ds.size; j++)

        {
            if (ds.data[i] == ds.data[j])

                count++;
        }

        if (count > bestCount)

        {
            bestCount = count;

            bestValue = ds.data[i];
        }
    }

    return bestValue;
}

// Bubble Sort

void DataSet::bubbleSort()

{
    if (size == 0)

        return;

    for (size_t i = 0; i < size; i++)

    {
        for (size_t j = 0; j < size - 1; j++)

        {
            if (data[j] > data[j + 1])

            {
                int temp = data[j];

                data[j] = data[j + 1];

                data[j + 1] = temp;
            }
        }
    }

    // median recalculation

    if (size % 2 == 1)

        med = 1.0 * data[size / 2];

    else

        med =

            (1.0 * data[size / 2 - 1] +

             1.0 * data[size / 2]) / 2.0;
}