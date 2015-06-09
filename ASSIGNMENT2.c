/*      	IPC Project 2
	NAME:                     KAREDIA NOORSIL
	
STUDENT OATH:
I declare that the attached assignment is wholly my
own work in accordance with Seneca Academic Policy.  No part of this
assignment has been copied manually or electronically from any
other source (including web sites) or distributed to other students.

Name : KAREDIA NOORSIL 
*/

#include<stdio.h>
void spacebeforeflooringableandflat(int spacebeforefloor,char rooftype);
void totalspace1(int totalspace);
void windowheight(int fwidth);
void floorheight1(int floorheight,int totalspace,int spacebeforefloor,char rooftype);
void doorheight();
void spaceafterdoor(int fwidth,int fspace);
void floorheightwithdoor(int fspace,int fwidth,int floorheight,int totalspace,int numwindow,int spacebeforefloor,char rooftype);
void rooftype(int totalspace,int spacebeforefloor,char roof);
void floor1(int fspace,int fwidth,int totalspace,int floorheight,int fheight,int numwindow,int spacebeforefloor,char rooftype);
void doorfloor(int fspace,int fwidth,int totalspace,int floorheight,int fheight,int numwindow,int spacebeforefloor,char rooftype);
void drawchar(char symbol,int number);
int main(void)
{
        int width;
        int height;
        int space;
        int maxnumberofwindow,numberofwindow,totalspaceinfloor;
        int numberofheightoffloor;
        int story,i;
        char roof;
        int spacebeforefloor = 2;
        printf("\t\t\tIPC ASCII HOUSE GENERATOR\n");
        printf("----------------------------------------------------------------------\n");
        printf("Enter width of the window:\n");
        printf("Please enter a value (5 - 10):");
        scanf("%d",&width);
        while(width<5||width>10){
                printf("Value must be between 5 and 10 (inclusive)\n");
                printf("Please enter a value (5 - 10):");
                scanf("%d",&width);
        }
        printf("Enter height of the window:\n");
        printf("Please enter a value (3 - 5):");
        scanf("%d",&height);
        while(height<3||height>5){
                printf("Value must be between 3 and 5 (inclusive)\n");
                printf("Please enter a value (3 - 5):");
                scanf("%d",&height);
        }
        printf("Enter spacing between windows:\n");
        printf("Please enter a value (3 - 10):");
        scanf("%d",&space);
        while(space<3||space>10){
                printf("Value must be between 3 and 10 (inclusive)\n");
                printf("Please enter a value (3 - 10):");
                scanf("%d",&space);
        }
        maxnumberofwindow=60/(width+space);
        printf("Enter the maximum number of windows per floor:\n");
        printf("Please enter a value (1 - %d):",maxnumberofwindow);
        scanf("%d",&numberofwindow);
        while(numberofwindow<1||numberofwindow>maxnumberofwindow){
                printf("Value must be between 1 and %d (inclusive)\n",maxnumberofwindow);
                printf("Please enter a value (1 - %d):",maxnumberofwindow);
                scanf("%d",&numberofwindow);
        }
        printf("Enter the number of stories in the building:\n");
        printf("Please enter a value (1 - 6):");
        scanf("%d",&story);
        while(story<1||story>6){
                printf("Value must be between 1 and 6 (inclusive)\n");
                printf("Please enter a value (1 - 6):");
                scanf("%d",&story);
        }
        printf("Enter the type of roof (f)lat, (g)able, or (p)itch:");
        scanf(" %c", &roof);
        while(roof!='f'&&roof!='g'&&roof!='p'){
                printf("Please enter (f) or (g) or (p) (Inclusive)\n");
                printf("Enter the type of roof (f)lat, (g)able, or (p)itch:");
                scanf(" %c", &roof);
        }
	printf("\n\n");
        numberofheightoffloor=7-(height+1);             //   remaining height of floor
        totalspaceinfloor=numberofwindow*width + numberofwindow*space + space;
        while((totalspaceinfloor+spacebeforefloor*2)%6!=2&&(totalspaceinfloor+spacebeforefloor*2)%6!=3){      
		                                                                 // calculates space before floor
                spacebeforefloor++;                                             // that should be in pitch type roof
        }

        rooftype(totalspaceinfloor,spacebeforefloor,roof);
        for(i=1;i<=story-1;i++){
                floor1(space,width,totalspaceinfloor,numberofheightoffloor,height,numberofwindow,spacebeforefloor,roof);
        }
        doorfloor(space,width,totalspaceinfloor,numberofheightoffloor,height,numberofwindow,spacebeforefloor,roof);
        return 0;
}

        void spacebeforeflooringableandflat(int spacebeforefloor,char rooftype)
	{
		int i;
		if(rooftype == 'f' || rooftype == 'g'){			//  this function prints
        								//  space before the floor
                	printf("  ");					//  according to the roof type
        	}							//  flat, gable or pitch
		else{							
		
			for(i=2;i<=spacebeforefloor;i++){
			
				printf(" ");
			}
		}
	}
	void drawchar(char symbol,int number)
	{
		int i;
		for(i=1;i<=number;i++){
			printf("%c",symbol);
		}
	}
        void totalspace1(int totalspace)
        {
                printf("|");
		drawchar(' ',totalspace);
                printf("|");
        }
        void windowheight(int fwidth)
        {
                int i;
		printf("|");
                for(i=1;i<fwidth-1;i++){					// this function prints
										//       |    |
		printf(" ");
		}
		printf("|");
		
	}
	void floorheight1(int floorheight,int totalspace,int spacebeforefloor,char rooftype)
	{
		int i,j;
		for(j=1;j<=floorheight;j++){						//  this function prints
											//  the remaining height
			spacebeforeflooringableandflat(spacebeforefloor,rooftype);	//  of the floor after printing 
			printf("|");
			drawchar(' ',totalspace);					//  the window height
			printf("|\n");
		}
	}		
	void doorheight()
	{
		printf("|");
		drawchar(' ',3);
		printf("|");
	}
	void spaceafterdoor(int fwidth,int fspace)
	{								//this prints the space
		int space=(fwidth-5)+fspace;				//after door and before first window
		drawchar(' ',space);
	}
        void floorheightwithdoor(int fspace,int fwidth,int floorheight,int totalspace,int numwindow,int spacebeforefloor,char rooftype)
        {
                int i,j,numberwindow=numwindow-1;
       		int spaceafterdr=(fwidth-5)+fspace;
		int totalspace1=fwidth*numberwindow+fspace*numberwindow+spaceafterdr;
                for(i=1;i<=floorheight;i++){						// this prints remaining height
                									// of the floor that has door in it
                        spacebeforeflooringableandflat(spacebeforefloor,rooftype);	// ie.
                        printf("|");							// | space |door|    remaining space    |
                        drawchar(' ',fspace);						// |       |    |                       |
                        doorheight(); 
                        for(j=1;j<=totalspace1;j++){
                        
                                printf(" ");
                        }
                        printf("|\n");
                }
        }

void rooftype(int totalspace,int spacebeforefloor,char roof)
{
	int i,j,k,l;
	int totalwidth=totalspace+spacebeforefloor*2;
	int height=totalwidth/6;
	if(roof=='f'){
	
		drawchar('=',totalspace+6);
		printf("\n");
	}
	else if(roof=='g'){
	
	       	
		printf("    ");
		drawchar('_',totalspace-2);
	        printf("\n   /");
		drawchar(' ',totalspace-2);
	        printf("\\\n  /");
		drawchar(' ',totalspace);
	        printf("\\\n /");
		drawchar(' ',totalspace+2);
	        printf("\\\n/");
		drawchar(' ',totalspace+4);
	        printf("\\\n");
		drawchar('=',totalspace+6);
		printf("\n");
	}
	else{           //pitch type roof
	
		
		if(totalwidth%2==0){
		
			l=2;
			for(i=1;i<=height;i++){
			
				printf("   ");
			}
			printf("/\\\n");
		}						// height in this function
		else{						// means height of pitch type
								// roof
			l=3;
			drawchar(' ',totalwidth/2);
			printf("*");
			printf("\n");
       			for(k=1;k<=height;k++){
			
				printf("   ");
			}
			printf("/ \\\n");
		}
		for(i=1;i<=height;i++){
		
			for(j=height;j>i;j--){
			
				printf("   ");
			}
			printf("/--");
			drawchar(' ',l);
			l=l+6;
			printf("--\\");
			printf("\n");
		}
		drawchar('=',totalwidth);
		printf("\n");
	}
}

void floor1(int fspace,int fwidth,int totalspace,int floorheight,int fheight,int numwindow,int spacebeforefloor,char rooftype)
{
	int i,j,k,l,m;
	spacebeforeflooringableandflat(spacebeforefloor,rooftype);
	totalspace1(totalspace);
	printf("\n");
	spacebeforeflooringableandflat(spacebeforefloor,rooftype);
	printf("|");
	for(i=1;i<=numwindow;i++){
		
		drawchar(' ',fspace);
		drawchar('-',fwidth);
	}
	drawchar(' ',fspace);
	printf("|\n");
	for(k=2;k<fheight;k++){          // window height
	
		spacebeforeflooringableandflat(spacebeforefloor,rooftype);
		printf("|");
		for(j=1;j<=numwindow;j++){
		
			drawchar(' ',fspace);
			windowheight(fwidth);
		}
		drawchar(' ',fspace);
		printf("|\n");
	}
	spacebeforeflooringableandflat(spacebeforefloor,rooftype);
        printf("|");
        for(i=1;i<=numwindow;i++){
        
                drawchar(' ',fspace);
               	drawchar('-',fwidth);
        }
        drawchar(' ',fspace);
        printf("|\n");
	floorheight1(floorheight,totalspace,spacebeforefloor,rooftype);
	spacebeforeflooringableandflat(spacebeforefloor,rooftype);
	drawchar('-',totalspace+2);	
	printf("\n");	
}
void doorfloor(int fspace,int fwidth,int totalspace,int floorheight,int fheight,int numwindow,int spacebeforefloor,char rooftype) // prints ground floor ie. with door
{
	int i,j,k,l,m,n,o,p;
	spacebeforeflooringableandflat(spacebeforefloor,rooftype);       
	totalspace1(totalspace);                                                                              
	printf("\n");                                                      
	spacebeforeflooringableandflat(spacebeforefloor,rooftype);
	printf("|");
	drawchar(' ',fspace);      
	drawchar(' ',5);                                               //prints
	spaceafterdoor(fwidth,fspace);				       // |                                            |
	for(p=1;p<=numwindow-1;p++){
	
		drawchar('-',fwidth);
		drawchar(' ',fspace);
	}								
	printf("|\n");							//-----------------------------------------------------------------------
	if(fheight==3){
	
		spacebeforeflooringableandflat(spacebeforefloor,rooftype);
		printf("|");
		drawchar(' ',fspace);
		drawchar('-',5);						// prints height with 3
		spaceafterdoor(fwidth,fspace);				// |     -----       |     |      |     |      |
		for(k=1;k<=numwindow-1;k++){				//                   according to No. window
		
			windowheight(fwidth);
			drawchar(' ',fspace);
		}
		printf("|\n");						//-----------------------------------------------------------------------
	}
	else{ 
	
                spacebeforeflooringableandflat(spacebeforefloor,rooftype);	
                printf("|");
                drawchar(' ',fspace);
                drawchar('-',5);
                spaceafterdoor(fwidth,fspace);				 
                for(k=1;k<=numwindow-1;k++){				
                				        
                        windowheight(fwidth);		
                        drawchar(' ',fspace);
                }
		printf("|\n");
		for(m=3;m<fheight;m++){                         // number of height of window to be printed if height is 4 or 5
		
                	spacebeforeflooringableandflat(spacebeforefloor,rooftype);
                	printf("|");
                	drawchar(' ',fspace);                 
			doorheight();
			spaceafterdoor(fwidth,fspace);
                	for(l=1;l<=numwindow-1;l++){
                	
               		        windowheight(fwidth);
                	        drawchar(' ',fspace);
                	}
                	printf("|\n");                          //-------------------------------------------------------------
		}					
	}
	spacebeforeflooringableandflat(spacebeforefloor,rooftype);  
        printf("|");
        drawchar(' ',fspace);                    			// prints window
        doorheight();							// ie. 
        spaceafterdoor(fwidth,fspace);					// |    |    |      ------      ------       |
        for(p=1;p<=numwindow-1;p++){					
        
                drawchar('-',fwidth);
                drawchar(' ',fspace);
        }
        printf("|");
	printf("\n");
        floorheightwithdoor(fspace,fwidth,floorheight,totalspace,numwindow,spacebeforefloor,rooftype); // prints remaining floor height
        spacebeforeflooringableandflat(spacebeforefloor,rooftype);                                     // |space|door|  remaining space  |
        drawchar('-',totalspace+2);								       // |     |    |                   |
	printf("\n");
}

