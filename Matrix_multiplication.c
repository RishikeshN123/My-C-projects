//Following code is not ai written
//If you think so I can explain every line
//of code.Can you?
//matrix multipication of any order with
//dynamic 2d arrays
#include <stdio.h>
#include <stdlib.h>

// Function to perform matrix multiplication
void multiply(int r1,int c1,int r2,int c2)
{
    int i,j;

    // Display the order of matrix 1
    printf("Order of Matrix:%d × %d",r1,c1);

    // Dynamically allocate memory for matrix 1 (arr1)
    int **arr1=malloc(sizeof(int *)*r1);
    for(i=0;i<r1;i++)
    {
        arr1[i]=calloc(sizeof(int),c1); // Allocate and initialize to 0
        if(arr1[i]==NULL)
        {
            printf("Matrix creation failed!");
            system("exit");
        }
    }

    // Input elements for matrix 1
    printf("\nEnter matrix 1 elements:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("Enter a%d%d:",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }

    // Dynamically allocate memory for matrix 2 (arr2)
    int **arr2=malloc(sizeof(int *)*r2);
    for(i=0;i<r2;i++)
    {
        arr2[i]=calloc(sizeof(int),c2); // Allocate and initialize to 0
        if(arr2[i]==NULL)
        {
            printf("Matrix creation failed!");
            system("exit");
        }
    }

    // Input elements for matrix 2
    printf("\nEnter matrix 2 elements:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("Enter a%d%d:",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }

    // Display matrix 1
    printf("\nArray1:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%4d",arr1[i][j]);
        }
        printf("\n");
    }

    // Display matrix 2
    printf("\nArray2:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%4d",arr2[i][j]);
        }
        printf("\n");
    }

    // Allocate memory for result matrix
    int **res=malloc(sizeof(int *)*r1);
    for(i=0;i<r1;i++)
        res[i]=calloc(sizeof(int),c2); // Allocate and initialize to 0

    // Perform matrix multiplication
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(int y=0;y<c2;y++)
            {
                res[i][j]+=arr1[i][y]*arr2[y][j];
            }
        }
    }

    // Display the result matrix
    printf("\nResult:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%4d",res[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for(i=0;i<r1;i++)
    {
        free(arr1[i]);
        arr1[i]=NULL;
    }
    for(i=0;i<r2;i++)
    {
        free(arr2[i]);
        arr2[i]=NULL;
    }
    for(i=0;i<r1;i++)
    {
        free(res[i]);
        res[i]=NULL;
    }
    free(arr1);
    free(arr2);
    free(res);
    arr1=NULL;
    arr2=NULL;
    res=NULL;
}

int main()
{
    int r1,c1,r2,c2;

    // Input order of matrix 1
    printf("Enter number of rows of matrix1:");
    scanf("%d",&r1);
    printf("Enter number of columns of matrix1:");
    scanf("%d",&c1);
    printf("Matrix1 order:%d×%d\n",r1,c1);

    // Input order of matrix 2
    printf("Enter number of rows of matrix2:");
    scanf("%d",&r2);
    printf("Enter number of columns of matrix2:");
    scanf("%d",&c2);
    printf("Matrix2 order:%d×%d\n",r2,c2);

    // Check matrix multiplication compatibility
    if(c1!=r2)
    {
        printf("\nThe matricies cannot be multipled\n");
        exit(0);
    }
    else
    {
        printf("Result matrix order:%d×%d\n",r1,c2);
    }

    // Call the matrix multiplication function
    multiply(r1,c1,r2,c2);

    return 0;
}
