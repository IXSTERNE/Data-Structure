#include "my_qsort.h"

/*
  quicksort эрэмбэлэх аргын цааш хуваагдах ёсгүй хэмжээ
*/
#ifndef CUTOFF
#define CUTOFF 10
#endif

static int init_seed = 0;  // Random seed 1 удаа эхлүүлнэ

static void insertion_sort(int a[], int lo, int hi)
{
        int i, j, k;
        for(i = lo + 1; i < hi; i++){
        k = a[i];
        j = i - 1;

                while(j >= lo && a[j] > k){
                       a[j + 1] = a[j];
                       j--;
                }
                a[j + 1] = k;
        }
}


static void swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}


static int partition(int a[], int lo, int hi)
{
        int pivot_value = a[hi];
        int i = lo - 1;

        for(int j = lo; j < hi; j++){
                if(a[j] <= pivot_value){
                        i++;
                        swap(&a[j], &a[i]);  
                }
        }
        swap(&a[i + 1], &a[hi]);
        return i + 1;
}


static int three_way_partition(int a[], int lo, int hi, int* left_pivot_index)
{
        if(a[lo] > a[hi]){
                swap(&a[lo], &a[hi]);
        }
        int j = lo + 1;
        int k = hi - 1;
        int l = j;
        int left_pivot = a[lo];
        int right_pivot = a[hi];

        while(l <= k){
                if(a[l] < left_pivot){
                        swap(&a[l], &a[j]);
                        j++;
                }
                else if(a[l] >= right_pivot){
                        while(a[k] > right_pivot && l < k){
                                k--;
                        }
                        swap(&a[l], &a[k]);
                        k--;

                        if(a[l] < left_pivot){
                                swap(&a[l], &a[j]);
                                j++;
                        }
                }
                l++;
        }
        j--;
        k++;
        swap(&a[lo], &a[j]);
        swap(&a[hi], &a[k]);

        *left_pivot_index = j;

        return k;
}





static void random_shuffle(int a[], int lo, int hi)
{
        if (init_seed == 0) {
                srand(time(NULL));
                init_seed = 1;
        }
        int i, j;
        for (i = lo; i <= hi; i++) {
                j = rand() % (hi - lo) + lo;
                swap(&a[i], &a[j]);
        }
}


static void _single_pivot_qsort(int a[], int lo, int hi)
{
        if(lo < hi){
                int pivot_index = partition(a, lo, hi);
                _single_pivot_qsort(a, lo, pivot_index - 1);
                _single_pivot_qsort(a, pivot_index + 1, hi);
        }
        if(hi - lo <= CUTOFF){
                insertion_sort(a, lo, hi);
                return;
        }
       
}


void single_pivot_qsort(int a[], int lo, int hi)
{
        random_shuffle(a, lo, hi);
        _single_pivot_qsort(a, lo, hi);
}

static void _dual_pivot_qsort(int a[], int lo, int hi)
{       
        if(lo < hi){
                int left_pivot_index, right_pivot_index;
                right_pivot_index = three_way_partition(a, lo, hi, &left_pivot_index);
                _dual_pivot_qsort(a, lo, left_pivot_index - 1);
                _dual_pivot_qsort(a, left_pivot_index + 1, right_pivot_index - 1);
                _dual_pivot_qsort(a, right_pivot_index + 1, hi);
        }
        
        if(hi - lo <= CUTOFF){
                insertion_sort(a, lo, hi);
                return;
        }
        
}

void dual_pivot_qsort(int a[], int lo, int hi)
{
        random_shuffle(a, lo, hi);
        _dual_pivot_qsort(a, lo, hi);
}

