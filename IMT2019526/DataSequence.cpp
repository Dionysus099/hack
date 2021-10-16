#include<stdlib.h>
#include<iostream>
using namespace std;
#include "DataSequence.h"
#include "FiveNumberSummary.h"

DataSequence :: DataSequence(float *arr, int n)
{
    this->n = n;
    arr_new = new float[n];
    fns = new FiveNumberSummary();

    for(int i=0; i<n; i++)
    {
        arr_new[i] = arr[i];
    }
    FNS();
}

DataSequence :: DataSequence(const DataSequence &DS)
{
    int n;
    n = DS.n;
    arr_new = new float[DS.n];

    for(int i=0; i<DS.n; i++)
    {
        arr_new[i] = DS.arr_new[i];
    }

    Sort_Array(arr_new, n);
    FNS();
}

DataSequence :: ~DataSequence()
{
    // delete []arr_new;
}


void DataSequence :: Sort_Array(float *arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                float tempo = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tempo;
            }
        }
    }
}


float DataSequence :: getMean(float *arr, int n)
{
    float Array_Sum = 0;
    float Mean;

    for(int i=0; i<n; i++)
    {
        Array_Sum += arr[i];
    }

    Mean = Array_Sum/n;
    return Mean;
}

float DataSequence :: getMedian(float *arr, int n)
{
    Sort_Array(arr, n);
    float Median;

    if(n%2 != 0)
    {
        Median = arr[n/2];
        return Median;
    }

    else
    {
        Median = (arr[n/2-1] + arr[n/2])/2;
        return Median;
    }
}

float DataSequence :: getMinimum(float *arr, int n)
{
    Sort_Array(arr, n);
    float Minimum;

    Minimum = arr[0];
    return Minimum;
}

float DataSequence :: getMaximum(float *arr, int n)
{
    Sort_Array(arr, n);
    float Maximum;

    Maximum = arr[n-1];
    return Maximum;
}

void DataSequence :: bin_values(Histogram &H, float *arr, int n, int bins)
{
    float min = getMinimum(arr, n);

    float max = getMaximum(arr, n);

    if(n == 1)
    {
        min = arr[0] - 0.5;
        max = arr[0] + 0.5;
    }

    float size = (max - min)/bins;
    
    float *tempo = new float[bins+1];
    
    tempo[0] = min;

    for(int i=1; i<bins+1; i++)
    {
        tempo[i] = tempo[i-1] + size;
    }

    H.setBinValues(tempo, bins+1);
}

void DataSequence :: bin_frequencies(Histogram &H, float *arr, int n, int bins)
{
    float *tempo = new float[bins]; 
    
    for(int i=0; i<bins; i++)
    {
        tempo[i] = 0;
    }
    

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<bins; j++)
        {
            if(arr[i] >= H.getBinValues()[j] && arr[i] < H.getBinValues()[j+1])
            {
                tempo[j]++;
            }

            if(arr[i] == H.getBinValues()[j+1] && j == bins-1)
            {
                tempo[j]++;
            }
        }
    }

    H.setBinFrequency(tempo, bins);

}

void DataSequence :: Histo(Histogram &H, float *arr, int n, int bins)
{
    bin_values(H, arr, n, bins);
    bin_frequencies(H, arr, n, bins);
}

void DataSequence :: FNS()
{
    fns->sets_min(getMinimum(arr_new, n));
	fns->sets_max(getMaximum(arr_new, n));
	fns->setmed(getMedian(arr_new, n));

	if(n%2 == 0){
		fns->setlq(getMedian(arr_new, n/2));
		fns->setuq(getMedian(arr_new + n/2, n/2));
	}
	else{
		fns->setlq(getMedian(arr_new, n/2+1));
		fns->setuq(getMedian(arr_new + n/2, n/2+1));
	}
}

void DataSequence :: addValue(float value, Histogram &H){
	n += 1;
    float * arr = new float[n];
    for(int i=0;i<n-1;i++)arr[i] = arr_new[i];
    arr[n-1] = value;
	delete[] arr_new;
    // arr_new = new float[n];
    // arr_new[n-1] = value;
    arr_new = arr;
	Sort_Array(arr_new, n);
	FNS();
	Histo(H, arr_new, n, H.getBins());
}

ostream &operator<<(ostream &out, DataSequence &dataSequence){
	out<<*(dataSequence.fns);
	return out;
}