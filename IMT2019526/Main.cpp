#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
#include <vector>
#include "DataSequence.h"
#include "Histogram.h"
#include "FiveNumberSummary.h"

int main()
{
    string input;
    vector<DataSequence> DaSe;
    vector<Histogram> Hiss;

    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
    {
        // cout<<input[i];   

        if (input[i] == 'A')
        {
            i+=2;

            int temp = i;

            while (input[i] != ',')
            {
                i++;
            }
            int n = stoi(input.substr(temp, i-temp));
            // cout<<n<<endl;

            i++;

            temp = i;

            while (input[i] != ' ')
            {
                i++;
            }

            float f = stof(input.substr(temp, i-temp));
            // cout<<f<<endl;

            DaSe[n].addValue(f, Hiss[n]);
            // if(i+3 == input.length()-1)break;
            if(i+3 < input.length())
            i+=3;
            else break;
        }

        else if(input[i] == 'N')
        {
            i+=2;

            int temp = i;

            while (input[i] != ' ')
            {
                i++;
            }
            
            int n = stoi(input.substr(temp, i-temp));

            i++;

            float Arr[n];

            for (int j = 0; j < n; j++)
            {
                if (j == n-1)
                {
                    temp = i;
                    while (input[i] != ' ')
                    {
                        i++;
                    }

                    float f = stof(input.substr(temp, i-temp));

                    Arr[j] = f;
                    break;                
                }                
                temp = i;
                while (input[i] != ',')
                {
                    i++;
                }

                float f = stof(input.substr(temp, i-temp));
                i++;


                Arr[j] = f;
            }

            DataSequence DSE(Arr, n);
            DaSe.push_back(DSE);

            Histogram HSG(n);
            DSE.Histo(HSG, Arr, n, 10);
            Hiss.push_back(HSG);

            if(i+3<input.length())
            i+=3;
            else break;
        }

        else
        {
            std::cout<< "-1";
            return 0;
        }       
    }

    for(auto x : DaSe)
    {
        std::cout<< x;
    }

    for(auto x : Hiss)
    {
        std::cout<< x;
    }

    return 0;
}