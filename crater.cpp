#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// Using Squares that are 5 km to improve accuracy

#define WIDTH 100
#define	HEIGHT 100
#define Not_Hit 0
#define In_Radius 1
#define center 2


//Functions
void printCrater(int[HEIGHT][WIDTH]);
void ImpactRing(int[HEIGHT][WIDTH], int row, int col);
void ClearCrater(int[HEIGHT][WIDTH],int row, int col);
void CheckCrater(int[HEIGHT][WIDTH],int row, int col);
int CraterCount(int[HEIGHT][WIDTH]);
double 	 IsSaturated(int currentCraters, int DoubleTimeCraters);

int main(){

// Needed for rand generator
srand (time(NULL));

//Init of matrix and initial Saturation of 0
int CraterZone [HEIGHT][WIDTH];
int IS = 0;
int Years = 0;
int OldAmountCraters = 100;


// Init Every zone to the int 1
for(int i = 0;i<HEIGHT;i++){
	for(int j = 0; j<WIDTH;j++){
		CraterZone[i][j] = Not_Hit;
	}
}





while(IS < 95){

Years += 1000;

int row = rand() % 95 + 5;
int col = rand() % 95 + 5;


cout << "Row: " << row << " Col: " << col <<  endl;

CheckCrater(CraterZone,row,col);

//printCrater(CraterZone);


int before = CraterCount(CraterZone);

for(int i = Years; i < (Years*2);i += 1000){

	if( before > OldAmountCraters){

	IS = IsSaturated(before,OldAmountCraters);
	OldAmountCraters = CraterCount(CraterZone);
}
else{
	OldAmountCraters = CraterCount(CraterZone);
}






cout << "After "<< Years << " amount of years the amount of craters is: "<< CraterCount(CraterZone)<< endl;

cout << "Old Amount of Craters Before: " << OldAmountCraters<< endl;


cout << "IS is: " << IS << " "<< "Old Amount of Craters: " << OldAmountCraters<< endl;



}

}

return 0;
}

void printCrater(int CraterZone[HEIGHT][WIDTH]){

	for(int i = 0;i < HEIGHT;i++){	
		for(int j=0; j< WIDTH;j++){
			if(j == 99){
			cout<< CraterZone[i][j] << endl;
			}
		else{
		cout << CraterZone[i][j];
		}

		}
	}
}
double IsSaturated(int currentCraters, int OldAmountCraters){

	return double(double(OldAmountCraters)/double(currentCraters))*100;
	
}

int CraterCount(int CraterZone[HEIGHT][WIDTH]){

	int count =0;

	for(int i = 0;i<HEIGHT;i++){
	for(int j = 0; j<WIDTH;j++){
		if(CraterZone[i][j]==2) count += 1;	
}
}
return count;
}
void CheckCrater(int CraterZone[HEIGHT][WIDTH],int row, int col){
	

	for(int r = row+1;r < (row+6) ; r++){
		if(CraterZone[r][col]==center){
			ClearCrater(CraterZone,r,col);
			ImpactRing(CraterZone,row,col);
		}
	}
	for(int t = row-1;t > (row-6) ; t--){
		if(CraterZone[t][col]==center){
			ClearCrater(CraterZone,t,col);
			ImpactRing(CraterZone,row,col);
		}
	}
	 
	for(int c = col+1; c < (col+6) ; c++){
		if(CraterZone[row][c]==center){
			ClearCrater(CraterZone,row,c);
			ImpactRing(CraterZone,row,col);
		}
	}
	for(int d = col-1;d > (col-6) ; d--){
		if(CraterZone[row][d]==center){
			ClearCrater(CraterZone,row,d);
			ImpactRing(CraterZone,row,col);
		}
	}
	for (int r = row-1;r > row-4;r--){
		if(CraterZone[r][col+1]==center){
			ClearCrater(CraterZone,r,col+1);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col+2]==center){
			ClearCrater(CraterZone,r,col+2);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col+3]==center){
			ClearCrater(CraterZone,r,col+3);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col-1]==center){
			ClearCrater(CraterZone,r,col-1);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col-2]==center){
			ClearCrater(CraterZone,r,col-2);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col-3]==center){
			ClearCrater(CraterZone,r,col-3);
			ImpactRing(CraterZone,row,col);
		}
	}
	for (int r = row+1;r < row+4;r++){
	if(CraterZone[r][col+1]==center){
			ClearCrater(CraterZone,r,col+1);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col+2]==center){
			ClearCrater(CraterZone,r,col+2);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col+3]==center){
			ClearCrater(CraterZone,r,col+3);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col-1]==center){
			ClearCrater(CraterZone,r,col-1);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col-2]==center){
			ClearCrater(CraterZone,r,col-2);
			ImpactRing(CraterZone,row,col);
		}
		if(CraterZone[r][col-3]==center){
			ClearCrater(CraterZone,r,col-3);
			ImpactRing(CraterZone,row,col);
		}
	}

	ImpactRing(CraterZone,row,col);
}
void ImpactRing(int CraterZone[HEIGHT][WIDTH],int row, int col){

	CraterZone[row][col] = center;

	// For top 5 and bottom 5 since they are 5 km each
	for(int r = row+1;r < (row+6) ; r++){
		CraterZone[r][col] = In_Radius;
	}
	for(int t = row-1;t > (row-6) ; t--){
		CraterZone[t][col] = In_Radius;
	}
	// For 5 to the left/right since each is 5 km 
	for(int c = col+1; c < (col+6) ; c++){
		CraterZone[row][c] = In_Radius;
	}
	for(int d = col-1;d > (col-6) ; d--){CraterZone[row][d] = In_Radius;}
	// For top left/right part of crater
	for (int r = row-1;r > row-4;r--){
	CraterZone[r][col+1]= In_Radius;
	CraterZone[r][col+2]= In_Radius;
	CraterZone[r][col+3]= In_Radius;

	CraterZone[r][col-1]= In_Radius;
	CraterZone[r][col-2]= In_Radius;
	CraterZone[r][col-3]= In_Radius;
	}
	//For bottom left/right of crater
	for (int r = row+1;r < row+4;r++){
	CraterZone[r][col+1]= In_Radius;
	CraterZone[r][col+2]= In_Radius;
	CraterZone[r][col+3]= In_Radius;

	CraterZone[r][col-1]= In_Radius;
	CraterZone[r][col-2]= In_Radius;
	CraterZone[r][col-3]= In_Radius;
	}
}

void ClearCrater(int CraterZone[HEIGHT][WIDTH],int row, int col){

	CraterZone[row][col] = Not_Hit;

	// For top 5 and bottom 5 since they are 5 km each
	for(int r = row+1;r < (row+6) ; r++){
		CraterZone[r][col] = Not_Hit;
	}
	for(int t = row-1;t > (row-6) ; t--){
		CraterZone[t][col] = Not_Hit;
	}
	// For 5 to the left/right since each is 5 km 
	for(int c = col+1; c < (col+6) ; c++){
		CraterZone[row][c] = Not_Hit;
	}
	for(int d = col-1;d > (col-6) ; d--){
		CraterZone[row][d] = Not_Hit;
	}
	// For top left/right part of crater
	for (int r = row-1;r > row-4;r--){
	CraterZone[r][col+1]= Not_Hit;
	CraterZone[r][col+2]= Not_Hit;
	CraterZone[r][col+3]= Not_Hit;

	CraterZone[r][col-1]= Not_Hit;
	CraterZone[r][col-2]= Not_Hit;
	CraterZone[r][col-3]= Not_Hit;
	}
	//For bottom left/right of crater
	for (int r = row+1;r < row+4;r++){
	CraterZone[r][col+1]= Not_Hit;
	CraterZone[r][col+2]= Not_Hit;
	CraterZone[r][col+3]= Not_Hit;

	CraterZone[r][col-1]= Not_Hit;
	CraterZone[r][col-2]= Not_Hit;
	CraterZone[r][col-3]= Not_Hit;
	}
}
