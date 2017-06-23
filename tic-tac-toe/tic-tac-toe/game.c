#include <stdio.h>


//denote the user and computer
enum status{
	UNSET,
	COMPUTER,
	USER
};
//#define COMPUTER 1   
//#define USER 2
//define ROW 1
//#define COLOUMN 2

//to denote whether we are checking for win or near win status in rows, coloums , diagonal or left diagonal
enum location{
	ROW=1,
	COLOUMN,
	DIAGONAL,
	OPP_DIAGONAL
};

int board[3][3];
int p[2];


void printMove(int posi,int posj){
	  printf("\nmove :%d %d",posi,posj);

}

int checkwin(int mark){
    int i,j,count;
	//check if any row has 3 marked boxes
	for(i=0;i<3;i++){
		count=0;
		for(j=0;j<3;j++){
			if(board[i][j]==mark){
				count++;
			}
		}
		// row has 3 marked boxes
		if(count==3){
				return 1;
			}

	}
	// check if any coloums have 3 marked boxes
	for(j=0;j<3;j++){
		count=0;
		for(i=0;i<3;i++){
			if(board[i][j]==mark){
				count++;
			}

		}
		// coloumn has 3 marked boxes
		if(count==3){
			return 1;
		}

	}
	//check diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][i]==mark)
			count++;
	}
	if(count==3){
		return 1;
	
	}

	//check anti diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][2-i]==mark)
			count++;
	}
	if(count==3){
		return 1;
	
	}

    return 0;
}



int checkCompAboutTowin(mark){
	int i,j,count;
	for(i=0;i<3;i++){
		count=0;
		for(j=0;j<3;j++){
			if(board[i][j]==mark){
				count++;
			}

		}
		if(count==2){
			for(j=0;j<3;j++){
				if(board[i][j]==UNSET){
					board[i][j]=mark;
						printMove(i,j);
					return 1;
					}

				}
				

		}
	}

for(j=0;j<3;j++){
		count=0;
		for(i=0;i<3;i++){
			if(board[i][j]==mark){
				count++;
			}

		}
		if(count==2){
			for(i=0;i<3;i++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
						printMove(i,j);
				return 1;
				}
				
			}

		}
	}

	count=0;
	for(i=0;i<3;i++){
		if(board[i][i]==mark){
			count++;
		}
	}
	if(count==2){
		for(i=0;i<3;i++){
			if(board[i][i]==UNSET){
				board[i][i]=COMPUTER;
					printMove(i,i);
				return 1;
			}
		}
	}

	count=0;
	for(i=0;i<3;i++){
		if(board[i][2-i]==mark){
			count++;
		
		}
	}
	if(count==2){
		for(i=0;i<3;i++){
			if(board[i][2-i]==UNSET){
				board[i][2-i]=COMPUTER;
					printMove(i,2-i);
				return 1;
			}
		}

	}

	return 0;
}


//to make move on behalf of the computer
int  moveComputer(int mark){
    
    int i,j,posi,posj,count,winStatus;

	//need to block

winStatus=checkCompAboutTowin(COMPUTER);
if(winStatus){

	return 1;
}

	for(i=0;i<3;i++){
		count=0;
		for(j=0;j<3;j++){
			if(board[i][j]==mark){
				count++;
			}
		}
		// row has 2 marked boxes
		if(count==2){

			for(j=0;j<3;j++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
					printMove(i,j);
					return 1;
				}

			}
			

		}
			

	}
	// check if any coloums have to be blocked
	for(j=0;j<3;j++){
		count=0;
		for(i=0;i<3;i++){
			if(board[i][j]==mark){
				count++;
			}

		}
		// coloumn has 2 marked boxes
		if(count==2){
			for(i=0;i<3;i++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
					printMove(i,j);
					return 1;
				}

			}
			
	
		}

	}
	//check diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][i]==mark)
			count++;
	}
	if(count==2){
		for(i=0;i<3;i++){
			if(board[i][i]==UNSET){
				board[i][i]=COMPUTER;
				printMove(i,i);
				return 1;
			}
		}
		
	
	}

	//check anti diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][2-i]==mark)
			count++;
	}
	if(count==2){
			for(i=0;i<3;i++){
				if(board[i][2-i]==UNSET){
					board[i][2-i]=COMPUTER;
					printMove(i,2-i);
					return 1;
				}
			}
	
		}

    
	if(board[1][1]==UNSET){
        board[1][1]=COMPUTER;
		printMove(1,1);
		return 1;

	}

	if(board[0][0]==UNSET){
		board[0][0]=COMPUTER;
		printMove(0,0);
		return 1;

	}

	if(board[0][2]==UNSET){
		board[0][2]=COMPUTER;
		printMove(0,2);
		return 1;

	}
	if(board[2][0]==UNSET){
		board[2][0]=COMPUTER;
		printMove(2,0);
		return 1;

	}
	if(board[2][2]==UNSET){
		board[2][2]=COMPUTER;
		printMove(2,2);
		return 1;
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==UNSET){
				board[i][j]=COMPUTER;
				printMove(i,j);
				return 1;
			}
			

		}
	}
  
    return 0;
}


void movePlayer(){
	int posi,posj;
	printf("\nenter indexes:");
	scanf("%d%d",&posi,&posj);
	printf("\nplayer move :%d %d",posi,posj);
    board[posi][posj]=2;
}

int checkEnd()
{
    int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==0){
				return 0;
			}

		}

	}
	return 1;
}

                    
int main(){

	int i,j,result;
    int moveStatus;
	int opt=1;
	 int counter=0;
	while(opt==1){
       
        
		 //status 0 if game going on else 1
		int status=0;
		int endResult=0;
       
        //while(counter<9||status==0){


        
			//set all boxes as 0. 1 set to denote the computer and 2 to denote the player

			for( i=0;i<3;i++){
				for(j=0;j<3;j++)
					board[i][j]=0;

			}

			//computer and player alternatively start the game

			if(counter%2==0){
				//status denotes the game isnt over yet.
				while(status==0){

					//computer makes move first. then player. checks for win after each move
					moveStatus=moveComputer(USER);
					if(!moveStatus){
						status=1;
						break;
					}
					result=checkwin(COMPUTER);
					if(result==1){
						printf("you lose");
						status=1;
						break;
					}
					else{
						endResult=checkEnd();
						if(endResult){
							status=1;
							break;

						}
                    }
					movePlayer();
					result=checkwin(USER);
					if(result==1){
						printf("you win");
						status=1;
						break;
					}
					else{
						endResult=checkEnd();
						if(endResult){
							status=1;
							break;

						}
                    }
			}
        }
                    
			else{
                
				//player first then computer. checks for win after each move
				while(status==0){
					movePlayer();
					result=checkwin(USER);
					if(result==1){
						printf("\nyou win");
						status=1;
						break;
					}
					else{
						endResult=checkEnd();
						if(endResult){
							status=1;
							break;

						}
					}
                    moveStatus=moveComputer(USER);
					if(!moveStatus){
						status=1;
						break;
					}
					result=checkwin(COMPUTER);
					if(result==1){
						printf("\nyou lose");
						status=1;
						break;
					}
					else{
						endResult=checkEnd();
						if(endResult){
							status=1;
							break;

						}
					
				}

			}
			

		}

if(endResult==1){
				printf("its a tie");
	}
	printf("\nplay again?(1/0)");
		scanf("%d",&opt);
		counter++;
	}

	return 0;
}
