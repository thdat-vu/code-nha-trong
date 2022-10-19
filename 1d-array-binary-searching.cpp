#include<stdio.h>
int binarySearch (int x, int a[], int n){
    int i=0, j= n-1, c ;
    while (i<=j){   c= (i+j)/2;
         if ( x== a[c] ) return c ;
         if (x < a[c] ) j = c-1;
         else i = c +1;
    }
    return -1;
}

int main(){
	int a[] = {1, 4, 8, 10, 12, 16, 22, 24};
	int n = 8, k1 = 22, k2 = 7;
	int pos1 = binarySearch(k1, a, n); 
	int pos2 = binarySearch(k2, a, n);
	if(pos1 >= 0){
		printf("\nPosotion of value %d is : %d", k1, pos1);
	}else{
		printf("\n%d does not exist!", k1);
	}
	if(pos2 >= 0){
		printf("\nPosotion of value %d is : %d", k2, pos2);
	}
	else{
		printf("\n%d does not exist", k2);
	}
	getchar();
}
