#include "myinclude.h"

void read(int A[], int n)
{
        int i;

        for (i = 0; i < n; i++)
                scanf("%d", &A[i]);
}

void print(int A[], int n)
{
        int i;

        for (i = 0; i < n; i++)
                printf("%d ", A[i]);
        printf("\n");
}

int max(int A[], int n)
{
        int i, max_value = A[0];

        for(i = 0; i < n; i++)
                if(A[i] > max_value){
                max_value = A[i];
                }        
        return max_value;
}

int min(int A[], int n)
{
        int i, min_value = A[0];

        for(i = 0; i < n; i++)
                if(A[i] < min_value){
                min_value = A[i];
                }      
        return min_value;
}

void copy(int A[], int n, int B[])
{
        int i;

        for(i = 0; i < n; i++)
                B[i] = A[i];
}

int find(int A[], int n, int x)
{
        int i, found = -1;

        for(i = 0; i < n; i++){
                if(A[i] == x){
                found = i;                                                      //found = -1 is initialized so if it fails to find the number,
                break;                                                          //it will return found (which is -1);
                }
        }
        return found;
}


        
int make_set(int A[], int n, int B[])
{
        int i, k, temp;

        for(i = 0; i < n; i++){                                                 //eliminate duplicates in A[] array, then copy A[] to B[];
                for(k = i + 1; k < n; k++){
                        if(A[i] == A[k]){
                                for(temp = k; temp < n - 1; temp++){
                                A[temp] = A[temp + 1];
                                }
                        n--;
                        k--;
                        }   
                }
        }

        for (i = 0; i < n; i++){
        B[i] = A[i];
        }
        return n;
}               
       

int union_set(int A[], int n, int B[], int m)
{
        int i, k, new_array[n + m], newsize, temp;
        newsize = n + m;                                                        //newsize is the combined size of array A[] and B[];
                                                                                //put the values array A[] and B[] into a new array,
        for(i = 0; i < n; i++){                                                 
        new_array[i] = A[i];
        }

        for(i = 0; i < m; i++){
        new_array[i + n] = B[i];       
        }

        for(i = 0; i < newsize; i++){                                           //then eliminate the duplicates in the new array "new_array[]";
                for(k = i + 1; k < newsize; k++){
                        if(new_array[i] == new_array[k]){
                                for(temp = k; temp < newsize - 1; temp++){
                                new_array[temp] = new_array[temp + 1];
                                }
                        newsize--;
                        k--;
                        }   
                }
        }

        for(i = 0; i < newsize; i++){                                           //put the content of new array back to A[];
        A[i] = new_array[i];
        }
        return newsize;
              
}

int intersection_set(int A[], int n, int B[], int m, int C[])
{       
        int i, k, j = 0, temp;

        for(i = 0; i < n; i++){
                for(k = 0; k < m; k++){
                        if(A[i] == B[k]){
                        C[j] = A[i];
                        j++;                                                    //incrementing j because j is the array size of C[];
                        }                                                       //as j increase the numbers in the array will go as listed;
                }
                
        }

        for(i = 0; i < j; i++){
                for(k = i + 1; k < j; k++){
                        if(C[i] == C[k]){
                                for(temp = k; temp < j - 1; temp++){
                                C[temp] = C[temp + 1];
                                }
                        j--;
                        k--;        
                        }
                }
        }
        return j;
        
}




