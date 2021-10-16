#ifndef DATA_
#define DATA_
#include "Histogram.h"

class DataSequence{
    private:
        float *arr_new;
        int n;

    public:
        DataSequence();
        DataSequence(float *arr, int n); 
        DataSequence(const DataSequence &DS);
        ~DataSequence();
        
        void Sort_Array(float *arr, int n);
        float getMedian(float *arr, int n); 
        float getMean(float *arr, int n);
        float getMinimum(float *arr, int n);
        float getMaximum(float * arr, int n);
        void bin_values(Histogram H, float *arr, int n, int w);
        void bin_frequencies(Histogram H, float * arr, int n, int w);
        
        Histogram Histo(float *arr, int n, int w);
};
#endif