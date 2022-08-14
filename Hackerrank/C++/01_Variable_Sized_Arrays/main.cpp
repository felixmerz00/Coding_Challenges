#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num_arrays, num_queries, len_array;
    cin >> num_arrays;
    cin >> num_queries;
    int* arrays[num_arrays];

    // Read arrays
    int i, j;
    for(i = 0; i < num_arrays; i++){
        cin >> len_array;
        int *a = (int*)malloc(sizeof(int)*len_array);
        for(j = 0; j< len_array; j++){
            cin >> a[j];
        }
        arrays[i] = a;
    }

    // Read queries and print output
    int ar, index;
    for(i = 0; i< num_queries; i++){
        cin >> ar >> index;
        cout << arrays[ar][index] << endl;
    }
    return 0;
}