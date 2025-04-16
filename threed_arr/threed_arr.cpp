#include <iostream>
#include <windows.h>
using namespace std;

int partition(int arr[], int low, int high){ // dividing the array into 2 parts
	int pivot = arr[high];
	int i = low - 1;
	
	for(int j = low; j < high; j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	
	return i+1;
}//	

void quickSort(int arr[], int low, int high){ //quicksort
	if(low < high){
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot-1); // left
		quickSort(arr, pivot+1, high); // right
	}
}//

int three_massive(){
	int x, y, z;
	system("cls");
	cout << "Three-Dimensional Array(default)" << endl;
	cout << "Input x, y, z: " << endl;
	cin >> x >> y >> z;
	system("cls");
	cout << "Three-Dimensional Array(default)\n\n";
	
	int*** arr = new int**[x];	//memory allocation
	for(int i = 0; i < x; i++){
		arr[i] = new int*[y];
		for(int j = 0; j < y; j++){
			arr[i][j] = new int[z];
		}
	}//
	
	for(int i = 0; i < x; i++){	//filling
		for(int j = 0; j < y; j++){
			for(int k = 0; k < z; k++){
				arr[i][j][k] = i * y * z + j * z + k;
			}
		}
	}//
	
	for(int i = 0; i < x; i++){	//output
		cout << "Layer " << i << ":\n";
		for(int j = 0; j < y; j++){
			for(int k = 0; k < z; k++){
				cout << arr[i][j][k] << " ";
			}
			cout << endl;
		}
		cout  << endl;
	}//	
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			delete[] arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
    return 0;
}

int rand_three_arr_sort(){
	int x, y, z;
	system("cls");
	cout << "Three-Dimensional Array(random 'N') with Sort" << endl;
	cout << "Input x, y, z: " << endl;
	cin >> x >> y >> z;
	system("cls");
	cout << "Three-Dimensional Array(random 'N') with Sort\n\n";
	
	int*** arr = new int** [x];
	for(int i = 0; i < x; i++){	//filling in and initializing
		arr[i] = new int*[y];
		for(int j = 0; j < y; j++){
			arr[i][j] = new int[z];
			for(int k = 0; k < z; k++){
				arr[i][j][k] = rand()%100;
			}
		}
	}//
	
	for(int i = 0; i < x; i++){ //output of an unsorted arr
		cout << "Layer " << i << ":\n";
		for(int j = 0; j < y; j++){
			for(int k = 0; k < z; k++){
				cout << arr[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}//
	
	cout << "Sorting.." << endl;//"waiting" is designed to view the current state of the entire array. 
	Sleep(5000);
	system("cls");//
	
	int* flatArr = new int[x * y * z]; //three-dimensional arr => one-dimensional
	int index = 0;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			for(int k = 0; k < z; k++){
				flatArr[index++] = arr[i][j][k]; 		
			}
		}
	}//
	
	quickSort(flatArr, 0, x * y * z - 1); 	//sorting a one-dimensional array //
	index = 0; 	//I'm returning sorted data to a three-dimensional array.
	
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			for(int k = 0; k < z; k++){
				arr[i][j][k] = flatArr[index++]; //
			}
		}
	}
	
	for(int i = 0; i < x; i++){	//output of sorted arr
		cout << "Layer " << i << ":\n";
		for(int j = 0; j < y; j++){
			for(int k = 0; k < z; k++){
				cout << arr[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}//
	
	delete[] flatArr;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			delete[] arr[i][j];
		}
	}
	delete[] arr;
	
	return 0;
}

int main() {
	int a;
	cout << "Creating Three-Dimensional Array\n";
	cout << "Select the action:\n";
	cout << "1. Three-Dimensional Array(default)\n2. Three-Dimensional Array(random 'N') with Sort" << endl;
	cin >> a;
	switch(a){
		case 1:
			three_massive();
			break;
		case 2:
			rand_three_arr_sort();
			break;
	}	
}
