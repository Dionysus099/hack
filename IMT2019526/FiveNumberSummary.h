#ifndef FNS_
#define FNS_

class FiveNumberSummary
{
    private:
        float s_min, s_max, med, lq, uq;

    public:

        FiveNumberSummary();
        ~FiveNumberSummary();
        
        float gets_min(){
            return s_min;
        }
        float gets_max(){
            return s_max;
        }
        float getmed(){
            return med;
        }
        float getlq(){
            return lq;
        }
        float getuq(){
            return uq;
        }

        void sets_min(float s_min){
            this->s_min = s_min;
        }
        void sets_max(float s_max){
            this->s_max = s_max;
        }
        void setmed(float med){
            this->med = med;
        }
        void setlq(float lq){
            this->lq = lq;
        }
        void setuq(float uq){
            this->uq = uq;
        }

		friend ostream &operator<<(ostream &out, FiveNumberSummary &fns);
        
};

#endif