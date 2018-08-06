/*
DISCLAIMER : I don't own the problem, I only own the solution
//------------------------------------------------------------------------------
//                                  PROBLEM
//------------------------------------------------------------------------------
Daily Coding Problem: Problem #4

Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear
time and constant space. In other words, find the lowest positive integer that
does not exist in the array. The array can contain duplicates and negative 
numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] 
should give 3.

You can modify the input array in-place.
*/
/* 
//------------------------------------------------------------------------------
//                                  SOLUTION
//------------------------------------------------------------------------------
AUTH  : Sayan Bhattacharjee (aerosayan)
EMAIL : aero.sayan@gmail.com
*/
// HINT : XOR to find missing number
/*
  1) XOR all the array elements, let the result of XOR be X1.
  2) XOR all numbers from 1 to n, let XOR be X2.
  3) XOR of X1 and X2 gives the missing number

  BE CAREFUL :: We have to do some tricky negative number handling
   */
#include<iostream>
#include<set> // to remove duplicates

using namespace std;
#define watchc(a_,n_) {cout<<(#a_)<<"\t:\t";for(int i=0;i<n_-1;i++){cout<<a_[i]<<" ";}cout<<a_[n_-1]<<endl;}

void solve(int arr[],int n)
{
	// Number of positive integers
	int pnum = 0;
	// The maximum and minimum numbers encountered
	int maxnum = 0;
	int minnum = 0;

	// The varialbes to store the results of the XOR operations
	int x1 = -99;
	int x2 = -99;

	// Set used to store data without taking in duplicates
	set<int> datand;

	// Insert data into set to remove any duplicates
	for(int i=0;i<n;i++)
		datand.insert(arr[i]);

	// Iterator for the set data structure 
	set<int>::iterator it;

	// Find xor for all the positive numbers in the array
	// While keeping track of the maximum and minimum positive numbers
	for(it=datand.begin();it != datand.end();it++){
		if(*it>0){ // we don't want to handle negative numbers
			pnum++;
			maxnum = max(maxnum,*it);
			minnum = min(minnum,*it);
			// If we have not found the first positive number yet
			if(x1 == -99)
				x1 = *it;
			else // we xor every other positive number
				x1 = x1^(*it);
		}
	}

	// Find xor of the numbers from minnum to maxnum
	for(int i=minnum;i<=maxnum;i++){
		// If we have not found the first positive number
		if(x2 == -99)
			x2 = i;
		else
			x2 = x2^i;
	}

	// Finally the missing number is
	int missing = x1^x2;

	cout<<"INF :: For given array : ";
	watchc(arr,n);
	cout<<"INF :: Missing number is\t:\t"<<missing<<endl;

	cout<<"---------------------------"<<endl;

}

int main()
{
	int arr1[] = {3,4,-1,1};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	solve(arr1,n1);

	// For arr2 dataset : They tell that the answer should be 3
	// What ? How? it is not a missing number.
	// I can only assume that if the result turns out to be zero,
	// i.e if we have conitgous set of given numbers then to set the result 
	// to be maxnum+1 . 
	// I shall not do it!
	int arr2[] = {1,2,0};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	solve(arr2,n2);

	int arr3[] = {1,3,2,-2,3,5,-1,6};
	int n3 = sizeof(arr3)/sizeof(arr3[0]);
	solve(arr3,n3);
	return 0;

}

