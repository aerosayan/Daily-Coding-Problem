/*
DISCLAIMER : I don't own the problem, I only own the solution of the problem
//------------------------------------------------------------------------------
//                                  PROBLEM
//------------------------------------------------------------------------------

Daily Coding Problem: Problem #1

Good morning! Here's your coding interview problem for today.

Given a list of numbers, return whether any two sums to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

*/

/* 
//------------------------------------------------------------------------------
//                                  SOLUTION
//------------------------------------------------------------------------------
AUTH  : Sayan Bhattacharjee (aerosayan)
EMAIL : aero.sayan@gmail.com
*/
#include<iostream>
#include<unordered_map> // for unordered map
#include<utility> // for make_pair
#include<vector> 

using namespace std;
#define umap unordered_map
#define mpair make_pair
#define vec vector

#define watchc(a_,n_) {cout<<(#a_)<<" : ";for(int i=0;i<n;i++){cout<<a_[i]<<"\n"[i!=n-1];}}

bool issum(int n,int arr[],int k)
{
	// We are going to use hash maps to get the result
	// int first ak: the elements of arr - k
	// int second pos : the position of that element stored in arr
	umap<int, int > u;

	cout<<"INF :: N : "<<n<<endl;
	cout<<"INF :: k : "<<k<<endl;

	
	// The number of elements found which add up to k
	int count = 0;

	// Add all the elements into the map
	umap<int,int>::iterator it;
	for(int i=0;i<n;i++){
		u.insert(mpair(arr[i],i));// move insertion
	}

	// Find if items exist which sum up to k
	for(int i=0;i<n;i++){
		if(u.find(k-arr[i]) != u.end()){
			count++; // increase count when found
			cout<<"INF :: num :  "<<u.find(k-arr[i])->first<<" | at pos : "<<u.find(k-arr[i])->second<<endl;
		}
	}

	// If the number of occurances of such possible nos. which sum up to k >=2
	if(count>=2)
		return true;
	else 
		return false;
}


int main()
{
	// Total sum to be compared against
	int k = 17;
	// The array given to us
	int arr[] = {10,15,3,7};

	// The size of the array
	int n = sizeof(arr)/sizeof(arr[0]);

	// Print the given vector
	//cout<<"INF :: ";
	//watchc(arr,n);

	// Get the result from a helper function
	bool res = issum(n,arr,k);
	if(res)
		cout<<"RES :: TRUE"<<endl;
	else
		cout<<"RES :: FALSE"<<endl;
	return 0;
}
