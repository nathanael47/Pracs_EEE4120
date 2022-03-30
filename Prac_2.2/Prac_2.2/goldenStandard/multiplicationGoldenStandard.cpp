
//Author: Christopher Hill For the EEE4120F course at UCT

#include<stdio.h>
#include<iostream>

using namespace std;



//creates a square matrix of dimensions Size X Size, with the values being the column number
void createKnownSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = j + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
	

}


//creates a random square matrix of dimensions Size X Size, with values ranging from 1-100
void createRandomSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = rand() % 100 + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
	

}




int main(void){

	clock_t start, end;

	//New code for prac 2.2
	bool displayMatrices = true;
	int Size = 3;
	int countA = Size*Size;
	int matrixA[countA];
	createKnownSquareMatrix(Size,matrixA, displayMatrices);
	cout<<"Number of elements in matrix 1: "<<countA<<"\n";
	cout<<"Dimensions of matrix 1: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 1 pointer: "<<matrixA<<"\n";
	

	
	
	int countB = Size*Size;
	int matrixB[countB];
	createKnownSquareMatrix(Size, matrixB, displayMatrices);
	cout<<"Number of elements in matrix 2: "<<countB<<"\n";
	cout<<"Dimensions of matrix 2: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 2 pointer: "<<matrixB<<"\n";
	
	
	
	int output[countA];
	for(int c = 0;c < countA;c++){
		output[c] = 0;
	}
	
	//TODO: code your golden standard matrix multiplication here
	start = clock(); 
	for (int k = 0;k < Size;k++){
		for(int i = 0;i<Size;i++){
			for(int j = 0; j < Size;j++){
				output[i+Size*k] += matrixA[i+Size*k]*matrixB[j];
				// printf(" %i %i \t",output[i+Size*k],i+ i+Size*k);
			}	
		}
	} 
	end = clock();
	printf ("Run Time: %0.8f sec \n",((float) end - start)/CLOCKS_PER_SEC);	
	
	
	
	//This if statement will display the matrix in output	
	if(displayMatrices){
		printf("\nOutput in the output_buffer \n");
		for(int j=0; j<countA; j++) {
			printf("%i \t " ,output[j]);
			if(j%Size == (Size-1)){
				printf("\n");
			}
		}
	}
	
	return 0;
}