#include<stdlib.h>
#include<iostream>
using namespace std;
#include "Histogram.h"

Histogram :: Histogram(int n)
{
    bins = n;
    bin_values = new float[n+1];
    bin_frequencies = new float[n];
}

Histogram :: ~Histogram()
{
}

Histogram :: Histogram(const Histogram &H)
{  
    bins = H.bins;
    bin_values = H.bin_values;
    bin_frequencies = H.bin_frequencies;
}

void Histogram :: setBinValues(float *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        bin_values[i] = arr[i];
    }
}

void Histogram :: setBinFrequency(float *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        bin_frequencies[i] = arr[i];
    }
}

float *Histogram :: getBinValues()
{
    return bin_values;
}

float *Histogram :: getBinFrequencies()
{
    return bin_frequencies;
}

int Histogram :: getBins()
{
    return bins;
}

ostream &operator<<(ostream &out, Histogram &hist){
	for (int i = 0; i < hist.getBins() + 1; i++)
    {
        out << hist.getBinValues()[i] << ",";
    }

    for (int i = 0; i < hist.getBins(); i++)
    {
        out << hist.getBinFrequencies()[i] << ",";
    }
    
	return out;
}