#include <graphics.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <dos.h>
#include <conio.h>
#include <windows.h>

using namespace std;  
const int size = 4;


class point{
public:
int grid[size][size];	
int generate[size][size];
int isAlive;


void Generate(){
	
	for(int i=0; i<size; i++){
	for(int j=0; j<size; j++){
		grid[i][j]=generate[i][j];
	}
}

for(int i=0; i<size; i++){
	for(int j=0; j<size; j++){
		isAlive=grid[i][j];
		drawLine(j,i);
		}
	}
}


void newstate(int sum, int i, int j){
	
	//Ola ta kelia pe8ainoun me panw apo 3 geitones 
	if (sum>3){
		generate[i][j]=0;
	//Me 2 geitones ola ta kelia diathroun thn katastash tous
	}else if(sum==2){
		if(grid[i][j]==1){
			generate[i][j]=1;
		}else{
			generate[i][j]=0;
		}
	//Me akribws 3 geitones ola ta kelia einai energa
	}else if(sum==3){
		generate[i][j]=1;
	//Me ligotero apo 2 geitones ola ta kelia pe8ainoun	
	}else{
		generate[i][j]=0;
	}
	
	
}

void neighbors(){
	int i,j, state,up,down, left, right, diagupleft, diagdownleft, diagupright, diagdownright;	
	

//Anagnwrish twn geitonwn stis 8 theseis
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
	//Ta kelia pou briskontai se akrianes theseis arxikopoioun tous feitones pou de dia8etoun se 0		
			if(i==0){
				if(j==0){
					left = 0;
					diagdownleft = 0;
					right = grid[i][j+1];
					diagdownright = grid[i+1][j+1];
				}else if(j==size-1){
					right = 0;
					diagdownright = 0;
					left = grid[i][j-1];
					diagdownleft = grid[i+1][j-1];
				}else{
					left = grid[i][j-1];
					right = grid[i][j+1];
					diagdownleft = grid[i+1][j-1];
					diagdownright = grid[i+1][j+1];
				}
				up = 0;
				diagupleft = 0;
				diagupright = 0;
				down = grid[i+1][j];
			}else if(i==size-1){
				if(j==0){
					left = 0;
					diagupleft = 0;
					diagupright = grid[i-1][j+1];
					right = grid[i][j+1];
				}else if(j==size-1){
					right = 0;
					diagupright = 0;
					left = grid[i][j-1];
					diagupleft = grid[i-1][j-1];
				}else{
					left = grid[i][j-1];
					right = grid[i][j+1];
					diagupleft = grid[i-1][j-1];
					diagupright = grid[i-1][j+1];
				}
				up = grid[i-1][j];
				down = 0;
				diagdownleft = 0;
				diagdownright = 0;
				
			}else{	
				if(j==0){
					left = 0;
					diagupleft = 0;
					diagdownleft = 0;
					right = grid[i][j+1];
					diagupright = grid[i-1][j+1];
					diagdownright = grid[i+1][j+1];
					
				}else if(j==size-1){
					right = 0;
					diagupright = 0;
					diagdownright = 0;
					left = grid[i][j-1];
					diagupleft = grid[i-1][j-1];
					diagdownleft = grid[i+1][j-1];
					
				}else{
					left = grid[i][j-1];
					right = grid[i][j+1];
					diagupleft = grid[i-1][j-1];
					diagdownleft = grid[i+1][j-1];
					diagupright = grid[i-1][j+1];
					diagdownright = grid[i+1][j+1];
				}
				up = grid[i-1][j];
				down = grid[i+1][j];
				
			}
		//Ypologismos tou plh8ous twn geitonwn
			int sum = up + down + left + right + diagupleft + diagdownleft + diagupright + diagdownright ;
			newstate(sum, i, j);
		
}
}
Generate();

}
void initiallization(){
	
	int k=200;
	int l=100; 
	
	
	for(int i=0; i<size; i++){
	for(int j=0; j<size; j++){
                grid[i][j]={rand()%2};
				cout<<grid[i][j]<<" ";
		}
		cout<<"\n";
}						 
	for(int i=0; i<size; i++){
	for(int j=0; j<size; j++){
                isAlive = grid[i][j];
				drawLine(j,i);
				
		}
}	
		
}


void drawLine(int x, int y){
	int l=7;
	if(isAlive==1)
        setcolor(15);
    else
        setcolor(0);
        
    
        for(int i=0; i<5; i++)
       line(x*l+20,y*l+i,x*l+25,y*l+i);
       
}

};

int main() 
{ 
   
    int gd = DETECT, gm;  
    int count=0;
    initgraph(&gd, &gm, ""); 
	
 	point a;
 	a.initiallization();
 	delay(200);
 	
 	for(;true;){
 		if(GetAsyncKeyState(VK_ESCAPE))
    {
        cout << "ESCAPE-PRESSED" << endl;
        Sleep(1000);
        return 0;
    }else{
    	a.neighbors();
		delay(100);
		
	}
		
	}
  
    getch(); 
    closegraph(); 
  
    return 0; 
} 

