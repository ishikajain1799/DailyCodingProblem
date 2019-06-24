/*
This problem was asked by Facebook.

Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2].

Try solving this without creating a copy of the list. How many swap or move operations do you need?
*/
#include <iostream>
using namespace std;


void left_rotate_array_1(int arr[], int n, int k){
	
	k = k%n;
	// time complexity --> O(n*k)
	for(int i = 0; i < k; i++){
		// rotate one by one k times
		int temp = arr[0];
		for(int j = 0; j < n-1; j++){
			arr[j] = arr[j+1];
		}
		arr[n-1] = temp;
	}
}

void left_rotate_array_2(int arr[], int n, int k){
	
	// reversal algorithm 
	// TC --> O(n)
	
	k = k%n;
	// reverse first k elements 
	for(int i = 0; i < k/2; i++){
		
		int temp = arr[i];
		arr[i] = arr[k-1-i];
		arr[k-1-i] = temp;
	}
	
	// reverse remaining elements
	for(int i = k; i < (n+k)/2; i++){
		
		int temp = arr[i];
		arr[i] = arr[n-1-i+k];
		arr[n-1-i+k] = temp;
	}
	
	// reverse the entire array 
	for(int i = 0; i < n/2; i++){
		
		int temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;
	}
}

void printArray(int arr[], int n){
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << "  ";
	}
	
	cout << endl;
}
int main() {
	// your code goes here
	
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	left_rotate_array_1(arr,5,2);
	printArray(arr,5);
	
	left_rotate_array_2(arr,5,2);
	printArray(arr,5);

	left_rotate_array_1(arr,5,6);
	printArray(arr,5);

	left_rotate_array_1(arr,5,6);
	printArray(arr,5);

	left_rotate_array_1(arr,5,5);
	printArray(arr,5);

	left_rotate_array_1(arr,5,5);
	printArray(arr,5);

	
	return 0;
}
