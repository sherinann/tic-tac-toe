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
    return 0;
}



//this function is to find out if any of the rows , columns or diagonals have 2 boxes marked by computer or player
//blocked(which player sending request )
int blocked(int mark){
    int check,i,count,j;
	//p[0] denote row/coloumn  p[1] to denote row or coloumn number
	p[0]=0;
	p[1]=0;
	if(mark==COMPUTER)
		check=2;
	else
		check=1;
	//checking if any row has 2 marked boxes. if yes then it has to be blocked
	for(i=0;i<3;i++){
		count=0;
		for(j=0;j<3;j++){
			if(board[i][j]==check){
				count++;
			}
		}
		// row has 2 marked boxes
		if(count==2){

			p[0]=ROW;
			p[1]=i;
			return 1;

		}
			

	}
	// check if any coloums have to be blocked
	for(j=0;j<3;j++){
		count=0;
		for(i=0;i<3;i++){
			if(board[i][j]==check){
				count++;
			}

		}
		// coloumn has 2 marked boxes
		if(count==2){
			p[0]=COLOUMN;
			p[1]=j;
			return 1;
	
		}

	}
	//check diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][i]==check)
			count++;
	}
	if(count==2){
		p[0]=DIAGONAL;
		return 1;
	
	}

	//check anti diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][2-i]==check)
			count++;
	}
	if(count==2){
			p[0]=OPP_DIAGONAL;
			return 1;
	
		}

	return 0;
}


//to make move on behalf of the computer
void moveComputer(){
    int i,j;
	//nee to block
	if(blocked(COMPUTER)){
		//mark unmarked box in the row
		if(p[0]==ROW){
			p[1]=i;
			for(j=0;j<3;j++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
				}
			}
		}
		else if(p[0]==COLOUMN){
			//mark unmarked box in the coloumn
			p[1]=j;
			for(i=0;i<3;i++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
				}

			}
		}
		else if(p[0]==DIAGONAL){
			//mark unmarked box in the diagonal
			for(i=0;i<3;i++){
				if(board[i][i]==UNSET){
					board[i][i]=COMPUTER;
				}

			}
		}
		else{
			//mark unmarked box in the  anti-diagonal
			for(i=0;i<3;i++){
				if(board[i][2-i]==UNSET){
					board[i][i]=COMPUTER;
				}
            }
        }
        
    }
    
	else if(board[1][1]==UNSET){
            board[1][1]=1;
	}
	else{


	}
    
    int win_lose=checkwin(COMPUTER);
    if(win_lose){
        printf("you lose");
    }
}


                    
int main(){

	int counter=0,i,j;
	char opt='y';

	while(opt=='y'){
        //status 0 if game going on else 1
        int status=0;
		//set all boxes as 0. 1 set to denote the computer and 2 to denote the player

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)
				board[i][j]=0;

		}

		//computer and player alternatively start the game

		if(counter%2==0){
			//status denotes the game isnt over yet.
			while(status==0){

				//computer makes move first. then player. checks for win after each move
				moveComputer();
				checkwin(COMPUTER);
				movePlayer();
				checkwin(USER);
			}
		}
		else{
			//player first then computer. checks for win after each move
			while(status==0){
				movePlayer();
				checkwin(USER);
				moveComputer();
				checkwin(COMPUTER);
				
			}

		}
		printf("play again?(y/n)");
		scanf("%c",&opt);
		counter++;

	}

	return 0;
}
