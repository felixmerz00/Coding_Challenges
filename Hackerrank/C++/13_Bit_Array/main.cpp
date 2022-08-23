/* Task
You are given four integers: n, s, p, q. You will use them in order to create the sequence a with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)

Your task is to calculate the number of distinct integers in the sequence a.*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int LomutoPartition(int A[], int l, int r)
{
    int pivot = A[r];
    int i = (l - 1);
    for (int j = l; j <= r- 1; j++){
        if (A[j] <= pivot){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return (i + 1);
}

void QuickSort(int A[], int l, int r)
{
    if (l < r){
        int pi = LomutoPartition(A, l, r);
        QuickSort(A, l, pi - 1);
        QuickSort(A, pi + 1, r);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, s, p, q;
    scanf("%d %d %d %d", &n, &s, &p, &q);
    int a[n];
    a[0] = s;   
    while(a[0] > pow(2, 31)){   // Ersatz für Modulo
        a[0] -= pow(2, 32);
    }
    for(int i = 1; i < n; i++){
        a[i] = a[i-1] * p + q;
        while(a[i] > pow(2, 31)){   // Ersatz für Modulo
            a[i] -= pow(2, 32);
        }
    }
    QuickSort(a, n, n-1);   // Array wird uebergeben nach Referenz
    // Check for duplicates
    int d = 0;  // Number of duplicates
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            d++;
        }
    }
    int distinct_vals = n-d; 
    printf("%d\n", distinct_vals);
    return 0;
}