#include <stdio.h>
#include <conio.h>


int linear_search( int arr[3][3], int key , int n){
	    int i, j;
	    for(i=0; i<n; i++){
		for(j=0; j<n; j++){
		    if (arr[i][j] == key)
		     {printf("element found in row  %d & in column %d" , i,j);
		     return 1;
		     }
		}
	    }
return -1;
}


int main()
{
    int key, result;
    int n = 3;
    int arr[3][3] = {
		      { 12, 45, 67 },
		      { 34, 56, 78 },
		      { 89, 34, 65 },
		    };

	printf("please enter value to find : ");
	scanf("%d" , &key);

	result = linear_search(arr, key , n);

	 if( result ==-1){
		 printf("element not found !");
	 }

   getch();
   clrscr();
   return 0;
}