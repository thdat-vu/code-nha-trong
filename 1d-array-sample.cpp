#include<stdio.h>	//1-D array demonstration
#include<stdlib.h>
#define MAXN 100
//get user choice

int menu(){
	printf("\nOne-Dimensional Array of Integers");
	printf("\n1 - Add a value");
	printf("\n2 - Search a value");
	printf("\n3 - Remove the first existence of a value");
	printf("\n4 - Remove all existences of a value");
	printf("\n5 - Print out the array");
	printf("\n6 - Print out the array in ascending order");
	printf("\n7 - Print out the array in descending order");
	printf("\nOther - Quit");
	printf("\nSelect: ");
	int choice;
	scanf("%d", &choice);
	return choice;
}
//Testing whether an array is full or not
int isFull (int*a, int n){
	return n == MAXN;
}
//Testing whether an array is empty or not
int isEmpty (int* a, int n){
	return n == 0;
}
//adding an elemnet ot the end of array will increase number of elements

void add(int value, int* a, int* pn){
	a[*pn] = value;
	(*pn)++;
}
//Find the first existence of x in the array - Linear searching
int search(int x, int *a, int n){
	int i;
	for (i = 0; i < n; i++){
		if ( a [i] == x){
			return i;
		}
	}
	return -1;
}

/*Removing the element at a postion in an array will decrease 
number of elements 
return 1: remove successfully, 0: remove fail*/

int removeOne (int pos, int *a, int *pn){
	if (pos < 0 || pos >= *pn){
		return 0;
	}
	int i;
	for (i = pos; i < *pn - 1; i++){
		a[i] = a[i + 1];	//*(a + i) = *(a + (i + 1)) 
	}
	(*pn)--;	//decrease number of elements
	return 1;	//successfully
}
//Removing all existences of a value from the array. Return 1: success, 0: fail
int removeAll(int x, int *a, int *pn){
	int result = 0;
	//Remove from the end of the array. So, no value is missed
	int i, j;
	for (i = (*pn) - 1; i >= 0; i--){
		if (a[i] == x){
			//shift up all elements after the position i
			result = 1;
			for (j = i; j < (*pn) - 1; j++){
				a[j] = a[j + 1];
			}
			(*pn)--;
		}
	}
	return result;
}
//Print the array in ascending order, position of elements are preserved
void printAsc (int *a, int n){
	//get addresses of elements
	int** adds = (int**)calloc(n, sizeof(int*));
	int i, j;
	for (i = 0; i < n; i++){
		adds[i] = &a[i];	//a+i
	}
	//Asc Sort addresses based on values of elements
	int* t;
	for (i = 0; i < n - 1; i++){
		for (j = n - 1; j > i; j--){
			if (*adds[j] < *adds[j - 1]){
				t = adds[j];
				adds[j] = adds[j - 1];
				adds[j - 1] = t;
			}
		}
	}
	for (i = 0; i < n; i++){
		printf("%d ", *adds[i]);
	}
	free(adds);	//de-allocate memory
}
//print the array in the descending ordet, positions of elements are preserved
void printDesc(int* a, int n){
	//get addresses of elements
	int** adds = (int**)calloc(n, sizeof(int*));
	int i, j;
	for (i = 0; i < n; i++){
		adds[i] = &a[i];
	}
	//Desc Sort addresses based on values of elements
	int* t;
	for (i = 0; i < n - 1; i++){
		for ( j = n - 1; j > i; j--){
			if (*adds[j] > *adds[j - 1]){
				t = adds[j];
				adds[j] = adds[j - 1];
				adds[j - 1] = t;
			}
		}
	}
	//print elements based on it's pointer
	for (i = 0; i < n; i++){
		printf("%d ", *adds[i]);
	}
	free(adds);	//de-allocate memory
}

//Print elements of the arrays
void print(int *a, int n){
	int i;
	for (i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

int main(){
	int a[MAXN];	//array of integers
	int n = 0;		//Initial number of elements
	int value;		//added / searched / removed value
	int userChoice;
	do{
		userChoice = menu();
		switch(userChoice){
			case 1:
				if (isFull(a, n)){
					printf("\nSorry! The array is full.\n");
				}else{
					printf("Input an added value: ");
					scanf("%d", &value);
					add(value, a, &n);
					printf("Added\n");
				}
				break;
			case 2: 
				if (isEmpty(a, n)){
					printf("\nSorry! The array is full.\n");
				}else{
					printf("Input the searched value:");
					int pos = search(value, a, n);
					if (pos < 0){
						printf("Not found!\n");
					}else{
						printf("Position is found: %d\n", pos);
					}
				}
				break;
			case 3: 
				if (isEmpty(a, n)){
					printf("\nSorry! The array is empty.\n");
				}else{
					printf("Input the removed value: ");
					scanf("%d", &value);
					int pos = search(value, a , n);
					if (pos < 0){
						printf("Not found!\n");
					}else{
						removeOne(pos, a, &n);
						printf("Removed!\n");
					}
				}
				break;
			case 4:
				if (isEmpty(a, n)){
					printf("Sorry! The array is empty.\n");
				}else{
					printf("Input a value that will be remove all: ");
					scanf("%d", &value);
					if (removeAll(value, a, &n) == 0){
						printf("Not found! \n");
					}else{
						printf("Removed!\n");
					}
				}
				break;
			case 5:
				print(a, n);
				break;
			case 6:
				printAsc(a, n);
				break;
			case 7: 
				printDesc(a, n);
				break;
			default: 
				printf("\nGoodbye.\n");
		}
	}while (userChoice > 0 && userChoice < 8);
	getchar();
	return 0;
}
