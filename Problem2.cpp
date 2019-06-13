/*

This problem was asked by Amazon.

Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].
*/

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void func(int arr[], int n, int x)
{
	int ls = -1;
	int gt = n;
	for(int i = 0; i < min(n,gt); )
	{
		if(arr[i] < x)
		{
			swap(arr[ls+1], arr[i]);
			ls++;
			i++;
		}
		else if(arr[i] == x)
		{
			swap(arr[ls+1], arr[i]);
			i++;
		}
		else
		{
			swap(arr[gt-1], arr[i]);
			gt--;
		}
	}
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
	
	int x;
	cin >> x;
	
	func(arr,n,x);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	
	
	return 0;
}
