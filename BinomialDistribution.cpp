#include<iostream>
#include "BinomialDistribution.h"
#include<math.h>

void BinomialDistribution :: makeArray()
{
    double another_arr[n+1];

    for (int i = 0; i < n+1; i++)
    {
        another_arr[i] = NCI(n, i) * pow(p, i) * pow(1-p, n-i);
    }

    Histogram :: setBins(n+1);
    Histogram :: setarr(another_arr, n+1); 
}

double BinomialDistribution :: NCI(int n, int r)
{
    double temp1 = 1, temp2 = 1;

    for (int i = 0; i < r; i++)
    {
        temp1 *= (n-i);
        temp2 *= (r-i);
    }

    return temp1/temp2;    
}