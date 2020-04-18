// C++ program to get number of palindrome 
// paths in matrix 
#include <bits/stdc++.h> 

using namespace std; 

#define R 3 
#define C 4 

// struct to represent state of recursion 
// and key of map 
struct cells 
{ 
	// indices of front cell 
	int rs, cs; 

	// indices of end cell 
	int re, ce; 
	cells(int rs, int cs, int re, int ce) : 
		rs(rs), cs(cs), re(re), ce(ce) { } 

	// operator overloading to compare two 
	// cells which rs needed for map 
	bool operator <(const cells& other) const
	{ 
		return ((rs != other.rs) || (cs != other.cs) || 
			(re != other.re) || (ce != other.ce)); 
	} 
}; 

// recursive method to return number of palindromic 
// paths in matrix 
// (rs, cs) ==> Indices of current cell from a starting 
//			 point (First Row) 
// (re, ce) ==> Indices of current cell from a ending 
//			 point (Last Row) 
// memo	 ==> To store results of already computed 
//			 problems 
int getPalindromicPathsRecur(char mat[R][C], int rs, 
		int cs, int re, int ce, map<cells, int>& memo) 
{ 
	// Base Case 1 : if any index rs out of boundary, 
	// return 0 
	if (rs < 0 || rs >= R || cs < 0 || cs >= C) 
		return 0; 
	if (re < 0 || re < rs || ce < 0 || ce < cs) 
		return 0; 

	// Base case 2 : if values are not equal 
	// then palindrome property rs not satisfied, 
	// so return 0 
	if (mat[rs][cs] != mat[re][ce]) 
		return 0; 

	// If we reach here, then matrix cells are same. 

	// Base Case 3 : if indices are adjacent then 
	// return 1 
	if (abs((rs - re) + (cs - ce)) <= 1) 
		return 1; 

	// if result rs precalculated, return from map 
	if (memo.find(cells(rs, cs, re, ce)) != memo.end()) 
		return memo[cells(rs, cs, re, ce)]; 

	int ret = 0; // Initialize result 

	// calling recursively for all possible movements 
	ret += getPalindromicPathsRecur(mat, rs + 1, cs, 
									re - 1, ce, memo); 
	ret += getPalindromicPathsRecur(mat, rs + 1, cs, re, 
										ce - 1, memo); 
	ret += getPalindromicPathsRecur(mat, rs, cs + 1, 
									re - 1, ce, memo); 
	ret += getPalindromicPathsRecur(mat, rs, cs + 1, re, 
										ce - 1, memo); 

	// storing the calculated result in map 
	memo[cells(rs, cs, re, ce)] = ret; 

	return ret; 
} 

// method returns number of palindromic paths in matrix 
int getPalindromicPaths(char mat[R][C]) 
{ 
	map<cells, int> memo; 
	return getPalindromicPathsRecur(mat, 0, 0, R - 1, 
										C - 1, memo); 
} 

// Driver code to test above methods 
int main() 
{ 
	char mat[R][C] = 
	{ 
		'a', 'a', 'a', 'b', 
		'b', 'a', 'a', 'a', 
		'a', 'b', 'b', 'a'
	}; 
	printf("%d", getPalindromicPaths(mat)); 

	return 0; 
} 
