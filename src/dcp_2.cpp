/*
DISCLAIMER : I don't own the problem, I only own the solution
//------------------------------------------------------------------------------
//                                  PROBLEM
//------------------------------------------------------------------------------
Daily Coding Problem: Problem #2
Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at 
index i of the new array is the product of all the numbers in the original 
array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be 
[120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be
[2, 3, 6].

Follow-up: what if you can't use division?
*/
/* 
//------------------------------------------------------------------------------
//                                  SOLUTION
//------------------------------------------------------------------------------
AUTH  : Sayan Bhattacharjee (aerosayan)
EMAIL : aero.sayan@gmail.com
*/

// HINT : This is the product of array puzzle from geeksforgeeks.com
#include<iostream>

using namespace std;
#define watchc(a_,n_) {cout<<(#a_)<<"\t:\t";for(int i=0;i<n-1;i++){cout<<a_[i]<<" ";}cout<<a_[n-1]<<endl;}

void solve(int arr[], int n)
{
	// Prinit the original input
	cout<<"INF :: Original array..."<<endl;
	watchc(arr,n);

	// Create temporary array left
	// Such that left[i] contains product of all elements on the left of arr[i]
	// exluding arr[i] i.e left[i] = left[i-1]*arr[i-1] for i=[1,n)
	int left[n];
	left[0] = 1;
	for(int i=1;i<n;i++){
		left[i] = left[i-1]*arr[i-1];
	}
	cout<<"INF :: Temporary arrays left and right..."<<endl;
	watchc(left,n);

	// Create temporary array right
	// Such that right[i] contains product of all elements on the right of arr[i]
	// excluding arr[i] i.e right[i] = right[i+1]*arr[i*1] for i=[n-2,0]
	int right[n];
	right[n-1] = 1;
	for(int i=n-2;i>=0;i--){
		right[i] = right[i+1]*arr[i+1];
	}
	watchc(right,n);


	// Finally compute the product result = left * right
	int res[n];
	for(int i=0;i<n;i++){
		res[i] = left[i]*right[i];
	}
	// Print the final resultant product
	cout<<"INF :: Final product array..."<<endl;
	watchc(res,n);
	cout<<"-----------------------------"<<endl;

}


int main()
{
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {3,2,1};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);

	solve(arr1,n1);
	solve(arr2,n2);
	return 0;
}
