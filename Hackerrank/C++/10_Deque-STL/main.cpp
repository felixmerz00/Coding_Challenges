#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    int start_idx = 0;
    int i;
    int max;
    while(n - start_idx >= k){   // Stop when the last subarrays has been reached
        for(i = start_idx; i - start_idx < k; i++){
            if(i == start_idx){    // If the deque is empty, add the first element
                max = arr[i];
            }else{  // Save the biggest element of the subarray at the front
                if(arr[i] > max){
                    max = arr[i];
                }
            }
        }
        cout << max << " "; // Print the maximum of the subarray
        start_idx++;    // The next subarray should start one index higher
    }
    cout << endl;
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
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}