#include<stdio.h>
#include<stdlib.h>
#define MAX_TERM 100

typedef struct {
    int cof;
    int exp;
} term;

void inputPolynomial(term poly[], int *numberTerms)
{
    int i;
    printf("Enter number of terms in the polynomial:");
    scanf("%d", numberTerms);
    for (i=0;i<*numberTerms;i++)
    {
        printf("Enter the %d term's cofficient and exponent", i+1);
        scanf("%d %d",&poly[i].cof, &poly[i].exp);
    }
}

int addPolynomial(term poly1[], int numT1, term poly2[], int numT2, term result[])
{
    int i=0,j=0,k=0;
    while(i<numT1 && j<numT2)
    {
        if(poly1[i].exp == poly2[j].exp)
        {
            result[k].cof = poly1[i].cof + poly2[j].cof;
            result[k].exp = poly1[i].exp;
            i++;
            j++;
        }

        else if(poly1[i].exp > poly2[j].exp)
        {
            result[k] = poly1[i];
            i++;
        }
        else
        {
            result[k] = poly2[i];
            j++;
        }
        k++;
    }

    while(i< numT1)
    {
        result[k]= poly1[i];
        i++;
        k++;
    }

     while(j< numT2)
    {
        result[k]= poly1[j];
        j++;
        k++;
    }

    return k;
}

void displayPolynomial(term poly[], int numT)
{
    int i;
    printf("The sum of the polynomials is:\n");
    for(i=0;i<numT;i++)
    {
        printf("%dX^%d", poly[i].cof,poly[i].exp);
        if(poly[i+1].cof > 0 && i<numT-1)
        {
            printf(" + ");
        }
        else
         printf(" ");
    }
    printf("\n");
}

int main()
{
    term poly1[MAX_TERM], poly2[MAX_TERM], result[MAX_TERM];
    int pl1,pl2,res;

    printf("Enter the first polynomial:\n");
    inputPolynomial(poly1, &pl1);

    printf("Enter the second polynomial:\n");
    inputPolynomial(poly2, &pl2);

    res = addPolynomial(poly1, pl1, poly2, pl2, result);

    printf("The resulting polynomial after addition: ");
    displayPolynomial(result, res);


    
    return 0;

}