
/*
This problem was asked by Facebook.

Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.

For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.

Follow-up: Can you do this in linear time and constant space?

*/

#include <iostream>
using namespace std;

void find(int arr[], int n)
{
  int xor1 = 0;
  for(int i = 0; i < n; i++)
  {
  	xor1 = xor1^arr[i];
  }
  
  // find the rightmost set bit in the xor
  int i = 0;
  int temp = xor1;
  while(temp)
  {
  	if(temp&1)
  	{
  		break;
  	}
  	i++;
  	temp = temp>>1;
  }
  
  int xor2 = 0;
  int mask = 1 << i;
  for(int i = 0; i < n; i++)
  {
  	if(arr[i]&mask)
  	{
  		xor2 = xor2^arr[i];
  	}
  }
  cout << "first num is " << xor2 << endl;
  cout << "second num is " << (xor2^xor1) << endl;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	find(arr,n);
	return 0;
}
