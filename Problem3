/*
This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

*/
#include <bits/stdc++.h>
using namespace std;

int n_ways(int n){
	
	if(n == 0 || n == 1){
		return 1;
	}
	
	return n_ways(n-1) + n_ways(n-2);
}

// in case of generalization .... say k steps can be climbed at the most
int n_ways_k(int n, int k){
	
	if(n == 0 || n == 1){
		return 1;
	}
	
	int ans = 0;
	for(int i = 1; i <= min(k,n); i++){
		ans += n_ways_k(n-i,k);	
	}
	
	return ans;
}

int n_ways_k_BU(int n, int k)
{
	if(n == 0 || n == 1){
		return 1;
	}
	
	int memo[n+1];
	memo[0] = memo[1] = 1;
	
	for(int i = 2; i <= n; i++)
	{
		int ans = 0;
		for(int j = 1; j <= min(k,i); j++){
			ans += memo[i-j];
		}
		memo[i] = ans;
	}
	return memo[n];
}

int memo[100000];
int n_ways_k_TD(int n, int k){
	
	if(n == 0 || n== 1)
	{
		return 1;
	}
	
	if(memo[n] != -1){
		
		return memo[n];
	}
	
	int ans = 0;
	for(int i = 1; i <= min(k,n); i++){
		ans += n_ways_k_TD(n-i,k);
	}
	memo[n] = ans;
	return memo[n];
}
int main() {
	// your code goes here
	memset(memo,-1,sizeof(memo));
	cout << n_ways_k(4,2) << endl;
	cout << n_ways_k_TD(4,2) << endl;
	cout << n_ways_k_BU(4,2);
	return 0;
}
