#include <iostream>
#include <deque> 
using namespace std;

int get_max_index(int arr[], int start_i, int k){
    int max_i;
    for(int i = start_i; i - start_i < k; i++){
        if(i == start_i){    // If the deque is empty, add the first element
            max_i = i;
        }else{  // Save the biggest element of the subarray at the front
            if(arr[i] >= arr[max_i]){
                max_i = i;
            }
        }
    }
    return max_i;
}

void printKMax(int arr[], int n, int k){
	//Write your code here.
    int start_idx = 0;
    int max_idx = -1;
    while(n - start_idx >= k){  // Stop when the last subarrays has been reached
        if(max_idx < start_idx){    // Did the max go out of range?
            max_idx = get_max_index(arr, start_idx, k);
        }
        else if(arr[start_idx + k - 1] >= arr[max_idx]){    // Is the new element greater than the current max
            max_idx = start_idx + k - 1;
        }
        printf("%d ", arr[max_idx]);    // Print the maximum of the subarray
        start_idx++;    // The next subarray should start one index higher
    }
    printf("\n");
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
            scanf("%d", &arr[i]);
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}