#include<stdio.h>
#include<conio.h>


int binary_search( int arr[] , int key , int n){
  int s = 0;
  int e = n-1;
  int mid;
while(s<=e){
   mid = s + (e-s)/2;

   if (arr[mid] == key)
	    return mid;

   else if( arr[mid] > key)
	    e =mid -1;

    else if( arr[mid] < key )
	    s = mid+1;
}

return -1;
}

int main(){
    int arr[30];
    int i, key, result;
    int n= 5;
    for(i=0; i< 5; i++){
	printf("please enter sorted value : ");
	scanf("%d" , &arr[i]);
    }
     printf("please enter value to find : ");
     scanf("%d" , &key);

     result = binary_search(arr , key , n);
     printf("%d ", result);

     getch();
     clrscr();
     return 0;

}