#include<stdlib.h>
#include<iostream>
using namespace std;
#include "Histogram.h"
#include<math.h>
#include<bits/stdc++.h>

Histogram :: Histogram(int n)
{
    bins = n;
    bin_values = new double[n+1];
    bin_frequencies = new double[n];
}

Histogram :: ~Histogram()
{
}

// Histogram :: Histogram(const Histogram &H)
// {  
//     bins = H.bins;
//     bin_values = H.bin_values;
//     bin_frequencies = H.bin_frequencies;
// }

void Histogram :: setBinValues(double *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        bin_values[i] = arr[i];
    }
}

void Histogram :: setBinFrequency(double *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        bin_frequencies[i] = arr[i];
    }
}

void Histogram :: setBins(int n)
{
    bins = n;
}

double *Histogram :: getBinValues()
{
    return bin_values;
}

double *Histogram :: getBinFrequencies()
{
    return bin_frequencies;
}

int Histogram :: getBins()
{
    return bins;
}

double Manhattan_Dist(double vectx[], double vecty[], int n) //Function to calculate Manhattan Distance
{
    double man_dist = 0;

    for (int i=0; i<n; i++)
    {
        man_dist = man_dist + fabs(vectx[i] - vecty[i]);
    }
    
    return floor((floor(man_dist*1e5)*1e-5+1e-5)*1e4)*1e-4;
}

double Euclidean_Dist(double vectx[], double vecty[], int n) //Function to calculate Euclidean Distance
{
    double euc_dist = 0;

    for (int i=0; i<n; i++)
    {
        euc_dist = euc_dist + pow((vectx[i]- vecty[i]), 2);
    }

    euc_dist = sqrt(euc_dist);

    return floor((floor(euc_dist*1e5)*1e-5+1e-5)*1e4)*1e-4;
}

double Chebyshev_Dist(double vectx[], double vecty[], int n) //Function to calculate Chebysev Distance
{
    double che_dist = 0;

    for (int i=0; i<n; i++)
    {
        if (che_dist < fabs(vectx[i] - vecty[i]))
        {
            che_dist = fabs(vectx[i] - vecty[i]);
        }        
    }

    return floor((floor(che_dist*1e5)*1e-5+1e-5)*1e4)*1e-4;    
}

double KL_Divergence(double vectx[], double vecty[], int n) //Function to calculate KL Divergence
{
    double div = 0;

    for (int i=0; i<n; i++)
    {
        div = div + (vectx[i]*log(vectx[i]/vecty[i]));
    }
    
    return div;
}

double KL_Dist(double vectx[], double vecty[], int n) //Function to calculate KL Distance
{
    return floor((floor((KL_Divergence(vectx, vecty, n) + KL_Divergence(vecty, vectx, n))*1e5)*1e-5+1e-5)*1e4)*1e-4;
}

double JS_Divergence(double vectx[], double vecty[], int n) //Function to calculate JS Divergence
{
    double avg[n];

    for (int i=0; i<n; i++)
    {
        avg[i] = (vectx[i] + vecty[i])/2;
    }

    return (KL_Divergence(vectx, avg, n) + KL_Divergence(vecty, avg, n))/2;   
}

double JS_Dist(double vectx[], double vecty[], int n) //Function to calculate JS Distance
{
    double div = JS_Divergence(vectx, vecty, n);

    return floor((floor(sqrt(div)*1e5)*1e-5+1e-5)*1e4)*1e-4;
}

void distance(Histogram H1, Histogram H2)
{   
    std :: cout.precision(4);
    std :: cout << std :: fixed;

    std::cout << Manhattan_Dist(H1.getarr(), H2.getarr(), H1.getBins()) << " ";
    std::cout << Euclidean_Dist(H1.getarr(), H2.getarr(), H1.getBins()) << " ";
    std::cout << Chebyshev_Dist(H1.getarr(), H2.getarr(), H1.getBins()) << " ";
    std::cout << KL_Dist(H1.getarr(), H2.getarr(), H1.getBins()) << " ";
    std::cout << JS_Dist(H1.getarr(), H2.getarr(), H1.getBins());
}