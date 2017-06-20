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



//this function is to find out if any of the rows , columns or diagonals have 2 boxes marked by computer or player
//blocked(which player sending request )
int blocked(int mark){
    int i,count,j;
	//p[0] denote row/coloumn  p[1] to denote row or coloumn number
	
	//checking if any row has 2 marked boxes. if yes then it has to be blocked
	for(i=0;i<3;i++){
		count=0;
		for(j=0;j<3;j++){
			if(board[i][j]==mark){
				count++;
			}
		}
		// row has 2 marked boxes
		if(count==2){

			p[0]=ROW;
			p[1]=i;
				printf("row problem %d",i);
			return 1;

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
			p[0]=COLOUMN;
			p[1]=j;
			printf("\ncoloumn problem %d",j);
			return 1;
	
		}

	}
	//check diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][i]==mark)
			count++;
	}
	if(count==2){
		p[0]=DIAGONAL;
		printf("\ndiagonal problem" );
		return 1;
	
	}

	//check anti diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][2-i]==mark)
			count++;
	}
	if(count==2){
			p[0]=OPP_DIAGONAL;
			printf("\nanti-diagonal problem");
			return 1;
	
		}

	return 0;
}


//to make move on behalf of the computer
void moveComputer(){
    
    int i,j,posi,posj;
	//need to block
	if(blocked(USER)>0){
		printf("\nblock");
		//mark unmarked box in the row
		if(p[0]==ROW){
			p[1]=i;
			for(j=0;j<3;j++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
					posi=i;
					posj=j;

				}
			}
		}
		else if(p[0]==COLOUMN){
			//mark unmarked box in the coloumn
			p[1]=j;
			for(i=0;i<3;i++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
					posi=i;
					posj=j;

				}

			}
		}
		else if(p[0]==DIAGONAL){
			//mark unmarked box in the diagonal
			for(i=0;i<3;i++){
				if(board[i][i]==UNSET){
					board[i][i]=COMPUTER;
					posi=i;
					posj=i;

				}

			}
		}

		else{
			//mark unmarked box in the  anti-diagonal
			for(i=0;i<3;i++){
				if(board[i][2-i]==UNSET){
					board[i][2-i]=COMPUTER;
					posi=i;
					posj=2-i;

				}
            }
        }
        
    }
    
	else if(board[1][1]==UNSET){
        board[1][1]=COMPUTER;
        posi=1;
		posj=1;

	}
	else if(board[0][0]==UNSET){
		board[0][0]=COMPUTER;
		posi=0;
		posj=0;

	}
	else if(board[0][2]==UNSET){
		board[0][2]=COMPUTER;
		posi=0;
		posj=2;
	}
	else if(board[2][0]==UNSET){
		board[2][0]=COMPUTER;
		posi=2;
		posj=0;

	}
	else if(board[2][2]==UNSET){
		board[2][2]=COMPUTER;
		posi=2;
		posj=2;
	}
    else{
    	for(i=0;i<3;i++){
    		for(j=0;j<3;j++){
    			board[i][j]=COMPUTER;
    			posi=i;
				posj=j;

    		}
    	}

    }
    printf("move :%d %d",posi,posj);
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
	char opt='y';

	while(opt=='y'){
        int counter=0;
        
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
					moveComputer();
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
					moveComputer();
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
			if(endResult==1){
				printf("its a tie");
			}

		}

	printf("\nplay again?(y/n)");
		scanf("%c",&opt);
		counter++;
	}

	return 0;
}
