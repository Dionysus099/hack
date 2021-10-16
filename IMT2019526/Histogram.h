#ifndef HISTO_
#define HISTO_

class Histogram
{
    private:
        float * bin_values,* bin_frequencies;
        int bins;

    public : 
        Histogram();
        Histogram(int n);
        Histogram(const Histogram &H);
        ~Histogram();

        void setBinValues(float *arr, int n);
        void setBinFrequency(float *arr, int n);
        float *getBinValues();
        float *getBinFrequencies();
        int getBins();
};
#endif