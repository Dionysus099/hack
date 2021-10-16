#include <iostream>
#include <cstring>
using namespace std;
#include "BinomialDistribution.h"
#include "Histogram.h"

double conditionchecker1(string s)
{
    int count=0;

    for(int i=0; i<s.length(); i++)
    {
        if((int)s[i]>=48 && (int)s[i]<=57)
        {

        }
        else if(s[i]=='.')
        {
            count++;
        }

        else
        {
            return 0.0;
        }  
    }

    if(count != 1)
    {
        return 0;
    }

    double d = stod(s);
    
    if(d<=0 || d>=1)
    {
        return 0.0;
    }
    
    return d;
}

int conditionchecker(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if((int)s[i]>=48 && (int)s[i]<=57)
        {

        }

        else
        {
            return 0;
        }
        
    }

    int n = stoi(s);
    return n;
}

int checker(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == ' ' || str[i]=='.')
        {

        }

        else if((int)str[i] >= 48 && (int)str[i] <= 57)
        {

        }

        else
        {
            return 0;
        }
        
    }
    return 1;
}

void split(string substrs[], string str, char c)
{
    string word = "";

    int i = 0;
    
    for (auto x : str)
    {
        if (x == c)
        {
            substrs[i++] = word;
            word = "";
        }
    
        else
        {
            word = word + x;
        }
    }

    substrs[i] = word;
}

int main()
{
    string str;

    int n;
    
    if(checker(str) == 0)
    {
        std::cout<< "-1";
        return 0;
    }
    
    double p1;
    double p2;
    
    getline(cin, str);
    
    string spacestrs[4];
    
    split(spacestrs, str, ' ');
    
    if(spacestrs[2] == "\0")
    {
        std::cout<< "-1";
        return 0;
    }
    
    if(spacestrs[3] != "\0")
    {
        std::cout<< "-1";
        return 0;
    }
    
    if(conditionchecker(spacestrs[0]) == 0)
    {
        std::cout<< "-1";
        return 0;
    }
    
    else
    {
        n = conditionchecker(spacestrs[0]);
    }
    
    if(conditionchecker1(spacestrs[1]) == 0)
    {
        std::cout<< "-1";
        return 0;
    }
    
    else
    {
        p1 = conditionchecker1(spacestrs[1]);
    }
    
    if(conditionchecker1(spacestrs[2]) == 0)
    {
        std::cout<< "-1";
        return 0;
    }
    
    else
    {
        p2 = conditionchecker1(spacestrs[2]);
    }
    
    BinomialDistribution *BiDi1 = new BinomialDistribution(n, p1);
    BinomialDistribution *BiDi2 = new BinomialDistribution(n, p2);

    Histogram *H1 = BiDi1;
    Histogram *H2 = BiDi2;

    distance(*H1, *H2);

    return 0;
}