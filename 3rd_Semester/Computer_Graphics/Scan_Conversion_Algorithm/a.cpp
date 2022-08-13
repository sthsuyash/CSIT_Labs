#include <iostream>
#include<graphics.h>
using namespace std;

int main(){
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"");
	
	while(true){
	
	for(int i=0; i<100; i++){
		setcolor(WHITE);
	//		line(100+i,100+i,200+i,200+i);
		circle(0+i, 100,6+i);
		circle(0+i, 100,6);
		delay(5);
//	setcolor(BLACK);
		clearviewport();
}
//	clearscreen();
	}	
	getch();
	closegraph;
	return 0;
}
