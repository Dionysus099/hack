#ifndef HISTO_
#define HISTO_
#include <iostream>
using namespace std;

class Histogram
{
    private:
        double * bin_values,* bin_frequencies;
        int bins;
        double *arr;

    public : 
        Histogram(){}
        Histogram(int n);
        // Histogram(const Histogram &H);
        ~Histogram();

        void setBinValues(double *arr, int n);
        void setBinFrequency(double *arr, int n);
        void setBins(int n);
        double *getBinValues();
        double *getBinFrequencies();
        int getBins();

        double *getarr()
        {
            return arr;
        }

        void setarr(double *newarr, int n)
        {
            arr = new double[n];

            for (int i = 0; i < n; i++)
            {
                arr[i] = newarr[i];
            }            
        }

        friend double Manhattan_Dist(double, double, int);
        friend double Euclidean_Dist(double, double, int);
        friend double Chebysev_Dist(double, double, int);
        friend double KL_Divergence(double, double, int);
        friend double KL_Dist(double, double, int);
        friend double JS_Divergence(double, double, int);
        friend double JS_Dist(double, double, int);
        friend void distance(Histogram, Histogram);
};
#endif