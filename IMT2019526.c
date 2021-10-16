#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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

int main()
{
    int n; //size of vectors
    scanf("%d",&n);

    int p1, p2; //to detect "-1"

    char c; //to detect ","
    double vectx[n]; //Array of first-vectors
    double vecty[n]; //Array of second-vectors
    
    scanf("%d",&p1);
    if(p1 != -1)
    {
        printf("-1\n");
        return 0;
    }

    for(int i=0; i<n-1; i++)
    {
        scanf("%lf%c",&vectx[i],&c);

        if(c != ',' || vectx[i] <= 0) //detecting "," and sign of vectors
        {
            printf("-1\n");
            return 0;
        }
    }

    scanf("%lf",&vectx[n-1]);
    if(vectx[n-1] <= 0)
    {
        printf("-1\n");
        return 0;
    }

    scanf("%d",&p2);
    if(p2 != -1)
    {
        printf("-1\n");
        return 0;
    }

    for(int j=0; j<n-1; j++)
    {
        scanf("%lf%c",&vecty[j],&c);
        if(c != ',' || vecty[j] <= 0) //detecting "," and sign of vectors
        {
            printf("-1\n");
            return 0;
        }
    }

    scanf("%lf",&vecty[n-1]);
    if(vecty[n-1] <= 0)
    {
        printf("-1\n");
        return 0;
    }

    char arr[5]; // to detect last "-1" as a delimiter
    fgets(arr, 5, stdin);
    
    if(arr[1] != '-' || arr[2] != '1') // checking characters separately
    {
        printf("-1\n");
        return 0;
    }

    double sumx = 0, sumy = 0;

    for (int i=0; i<n; i++) //Sums for Normalisation
    {
        sumx = sumx + vectx[i];
        sumy = sumy + vecty[i];
    }
    
    for (int i=0; i<n; i++) //Vectors after Normalisation
    {
        vectx[i] = vectx[i]/sumx;
        vecty[i] = vecty[i]/sumy;
    }

    printf("%.4lf,%.4lf,%.4lf,%.4lf,%.4lf\n", Manhattan_Dist(vectx, vecty, n), Euclidean_Dist(vectx, vecty, n), Chebyshev_Dist(vectx, vecty, n), KL_Dist(vectx, vecty, n), JS_Dist(vectx, vecty, n));
    
    return 0;
}