#include <stdio.h>
#include <conio.h>


int leanear_search( int arr[5][5], int key , int n){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if (arr[i][j] == key)
                     {printf("element found in row  %d & in column %d" , i,j);
                     return 1;}
                }
            }
return -1;
}


int main()
{
    int key, result;
    int n = 5;
    int arr[5][5] = { 
                      { 12, 45, 67, 89, 23 },
                      { 34, 56, 78, 90, 12 },
                      { 89, 34, 65, 43, 21 },
                      { 22, 78, 91, 30, 56 },
                      { 10, 44, 88, 77, 33 },
                      
                    };
    
    printf("please enter value to find : ");
    scanf("%d" , &key);

    result = leanear_search(arr, key , n);

   if( result ==-1){
    printf("element not found !");
   }


        return 0;
}