#include<stdio.h>
#include<stdlib.h>

int main(){
    int r1,r2,c1,c2,i,j,k;
    int **p;
    int **q;
    int **mul;
    printf("Enter number of rows of 1st matrix: ");
    scanf("%d",&r1);
    printf("Enter number of columns of 1st matrix: ");
    scanf("%d",&c1);
    printf("Enter number of rows of 2nd matrix: ");
    scanf("%d",&r2);
    printf("Enter number of columns of 2nd matrix: ");
    scanf("%d",&c2);

    if(c1 != r2){
        printf("The matrices can not be multiplied\n");
    } 
    else{
        p= (int **)malloc(r1 * sizeof(int *));
        for(i=0;i<r1;i++){
            p[i]= (int *)malloc(c1 * sizeof(int));
        }
        printf("Enter values in the first matrix\n");
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                scanf("%d", &p[i][j]);
            }
        } 

         q= (int **)malloc(r2 * sizeof(int *));
        for(i=0;i<r2;i++){
            q[i]= (int *)malloc(c2 * sizeof(int));
        }
        printf("Enter values in the second matrix\n");
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                scanf("%d", &q[i][j]);
            }
        } 

        printf("\n values in the matices \n");

        printf("The first matrix is \n ");
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                printf("%d  ", p[i][j]);
            }
            printf("\n");
        } 

        printf("The second matrix is \n ");
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                printf("%d  ", q[i][j]);
            }
              printf("\n");
        } 
        
        printf("The resultant matrix is \n");
        mul=(int **)malloc(r1*sizeof(int *));
        for(i=0;i<c2;i++){
            mul[i]=(int *)malloc(c2 * sizeof(int));
        }

        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                mul[i][j]=0;
                for(k=0;k<c1;k++){
                    mul[i][j] += p[i][k] * q[k][j];
                }

            }
        } 

        printf("The resultant matrix is \n ");
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                printf("%d  ", mul[i][j]);
            }
              printf("\n");
        } 
        
    }
    free(p);
    free(q);
    free(mul);
    


    return 0;
}
