#ifndef BD_
#define BD_
#include "Histogram.h"

class BinomialDistribution : public Histogram
{
    private:
        int n;
        double p;

    public:
        BinomialDistribution(){}

        BinomialDistribution(int n, double p)
        {
            this->n = n;
            this->p = p;

            makeArray();
        }

        BinomialDistribution(const BinomialDistribution &BD)
        {
            n = BD.n;
            p = BD.p;
        }

        ~BinomialDistribution(){}

        void makeArray();
        double NCI(int, int);
};
#endif