#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
#include "DataSequence.h"
#include "Histogram.h"

int main()
{
    int size;
    std::cin >> size;

    int p1, p2;

    std::cin >> p1;
    if (p1 != -1)
    {
        std::cout << "-1" ;
        return 0;
    }

    float seq_val[size];
    char c;

    for (int i=0; i<size-1; i++)
    {
        std::cin >> seq_val[i];
        std::cin >> c;

        if (c != ',' || seq_val[i] <= 0)
        {
            std::cout << "-1" ;
            return 0;
        }
        
    }

    std::cin >> seq_val[size-1];
    if (seq_val[size-1] <= 0)
    {
        std::cout << "-1" ;
        return 0;
    }
    
    std::cin >> p2;
    if (p2 != -1)
    {
        std::cout << "-1" ;
        return 0;
    }

    int Nb;
    std::cin >> Nb;
    // if(Nb <= 0)
    // {
    //     std::cout << "-1";
    // }

    char arr[5];
    fgets(arr, 5, stdin);
    
    if(arr[1] != '-' || arr[2] != '1') 
    {
        std::cout << "-1" ;
        return 0;
    }

    DataSequence DS(seq_val,size);
    Histogram H(size);

    std :: cout.precision(4);
    std :: cout << std :: fixed;
    
    std :: cout << floor((floor(DS.getMinimum(seq_val, size)*1e5)*1e-5+1e-5)*1e4)*1e-4 << " -1 " << floor((floor(DS.getMean(seq_val, size)*1e5)*1e-5+1e-5)*1e4)*1e-4 << " -1 " << floor((floor(DS.getMedian(seq_val, size)*1e5)*1e-5+1e-5)*1e4)*1e-4 << " -1 " << floor((floor(DS.getMaximum(seq_val, size)*1e5)*1e-5+1e-5)*1e4)*1e-4 << " -1 ";
    
    H = DS.Histo(seq_val, size, Nb);
    
    float *f1 = H.getBinValues();
    float *f2 = H.getBinFrequencies();
    
    for(int i=0; i<Nb; i++)
    {
        std :: cout << floor((floor((f1[i])*1e5)*1e-5+1e-5)*1e4)*1e-4 << ",";
    }

    std :: cout << floor((floor((f1[Nb])*1e5)*1e-5+1e-5)*1e4)*1e-4 << " -1 ";
    
    for(int i=0; i<Nb-1; i++)
    {
        std :: cout << (int)f2[i] << ",";
    }
    
    std :: cout << (int)f2[Nb-1] << " -1 ";

    return 0;
}