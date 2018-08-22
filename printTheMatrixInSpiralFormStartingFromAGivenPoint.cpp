/* The code given here https://www.geeksforgeeks.org/print-matrix-spiral-form-starting-point/ doesn’t pass all test cases */

/* The below code does */
// C++ program to print a matrix in spiral
// form.
#include
using namespace std;

const int MAX = 100;

void printSpiral(int mat[][MAX], int r, int c)
{

int i, a = 3, b = 3,j,flag=1;

int low_row = a;
int low_column =b;
int high_row =a+1;
int high_column =b+1;

while (flag) {

flag=0;
i=low_row;
if(low_row>=0)
{
flag=1;
for (j= max(low_column,0); j<= high_column && j<c; ++j)
cout << mat[i][j] << " ";

}
low_row –;

j=high_column;
if(j<c)
{
flag=1;
for (i = max(low_row + 2,0); i <= high_row && i < r; ++i)
cout << mat[i][j] << " ";

}
high_column++;;

i=high_row;
if(i= low_column -1 &&	j>= 0;j–)
cout << mat[i][j] <=0)
{
flag=1;
for (i =min( high_row – 2,r-1); i>=(low_row+1) && i >= 0 ; –i)
cout << mat[i][j] << " ";

}
low_column–;
}
cout << endl;
}

// Driver code
int main()
{
int mat[][MAX] = { { 1, 2, 3,4 }, { 5, 6,7,8 }, { 9,10,11,12 },{13,14,15,16} };
int r = 4, c = 4;

printSpiral(mat, r, c);
}
