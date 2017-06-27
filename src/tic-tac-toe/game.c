#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "interface.h"


int COMPUTER=1;
int USER=2;
int UNSET=0;


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





//to make move on behalf of the computer
int moveComputer(int returnStatus[3]){
    
    int i,j,count;
    

    //need to block

    for(i=0;i<3;i++){
        count=0;
        for(j=0;j<3;j++){
            if(board[i][j]==COMPUTER){
                count++;
            }
            
        }
        
        if(count==2){
            for(j=0;j<3;j++){
                if(board[i][j]==UNSET){
                        board[i][j]=COMPUTER;
                    
                   
                    printf("here0");
                        returnStatus[0]=1;
                        returnStatus[1]=i;
                        returnStatus[2]=j;
                    
                    return 1;
                }
                
            }
            
            
        }
    }
    
    
    for(j=0;j<3;j++){
        count=0;
        for(i=0;i<3;i++){
            if(board[i][j]==COMPUTER){
                count++;
            }
            
        }
        if(count==2){
            for(i=0;i<3;i++){
                if(board[i][j]==UNSET){
                    board[i][j]=COMPUTER;
                    printf("here1");
                    returnStatus[0]=1;
                    returnStatus[1]=i;
                    returnStatus[2]=j;
                    
                    return 1;
                   
                }
                
            }
            
        }
    }
    
    
    count=0;
    for(i=0;i<3;i++){
        if(board[i][i]==COMPUTER){
            count++;
        }
    }
    if(count==2){
        for(i=0;i<3;i++){
            if(board[i][i]==UNSET){
                board[i][i]=COMPUTER;
            
                returnStatus[0]=1;
                returnStatus[1]=i;
                returnStatus[2]=j;
                  printf("here2");
                return 1;
            }
        }
    }
    
    count=0;
    for(i=0;i<3;i++){
        if(board[i][2-i]==COMPUTER){
            count++;
            
        }
    }
    if(count==2){
        for(i=0;i<3;i++){
            if(board[i][2-i]==UNSET){
                board[i][2-i]=COMPUTER;
             
                returnStatus[0]=1;
                returnStatus[1]=i;
                returnStatus[2]=j;
                  printf("here3");
                return 1;
            }
        }
        
    }



	for(i=0;i<3;i++){
		count=0;
		for(j=0;j<3;j++){
			if(board[i][j]==USER){
				count++;
			}
		}
		// row has 2 marked boxes
		if(count==2){

			for(j=0;j<3;j++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
				  printf("here4");
                    returnStatus[0]=1;
                    returnStatus[1]=i;
                    returnStatus[2]=j;
					return 1;
				}

			}
			

		}
			

	}
	// check if any coloums have to be blocked
	for(j=0;j<3;j++){
		count=0;
		for(i=0;i<3;i++){
			if(board[i][j]==USER){
				count++;
			}

		}
		// coloumn has 2 marked boxes
		if(count==2){
			for(i=0;i<3;i++){
				if(board[i][j]==UNSET){
					board[i][j]=COMPUTER;
				
                    returnStatus[0]=1;
                    returnStatus[1]=i;
                    returnStatus[2]=j;
                      printf("here5");
					return 1;
				}

			}
			
	
		}

	}
	//check diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][i]==USER)
			count++;
	}
	if(count==2){
		for(i=0;i<3;i++){
			if(board[i][i]==UNSET){
				board[i][i]=COMPUTER;
				
                returnStatus[0]=1;
                returnStatus[1]=i;
                returnStatus[2]=i;
                  printf("here6");
				return 1;
			}
		}
		
	
	}

	//check anti diagonal for need to block
	count=0;
	for(i=0;i<3;i++){
		if(board[i][2-i]==USER)
			count++;
	}
	if(count==2){
			for(i=0;i<3;i++){
				if(board[i][2-i]==UNSET){
					board[i][2-i]=COMPUTER;
				
                    returnStatus[0]=1;
                    returnStatus[1]=i;
                    returnStatus[2]=2-i;
                       printf("here7");
					return 1;
                   
				}
			}
	
		}

    
	if(board[1][1]==UNSET){
        board[1][1]=COMPUTER;
		
        returnStatus[0]=1;
        returnStatus[1]=1;
        returnStatus[2]=1;
           printf("here8");
		return 1;

	}

	if(board[0][0]==UNSET){
		board[0][0]=COMPUTER;
		
        returnStatus[0]=1;
        returnStatus[1]=0;
        returnStatus[2]=0;
           printf("here9");
		return 1;

	}

	if(board[0][2]==UNSET){
		board[0][2]=COMPUTER;
		
        returnStatus[0]=1;
        returnStatus[1]=0;
        returnStatus[2]=2;
           printf("here10");
		return 1;

	}
	if(board[2][0]==UNSET){
		board[2][0]=COMPUTER;
	
        returnStatus[0]=1;
        returnStatus[1]=2;
        returnStatus[2]=0;
           printf("here11");
		return 1;

	}
	if(board[2][2]==UNSET){
		board[2][2]=COMPUTER;
		
        returnStatus[0]=1;
        returnStatus[1]=2;
        returnStatus[2]=2;
           printf("here12");
		return 1;
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==UNSET){
				board[i][j]=COMPUTER;
        
                returnStatus[0]=1;
                returnStatus[1]=i;
                returnStatus[2]=j;
                   printf("here13");
				return 1;
			}
			

		}
	}
  
    
    return 0;
}
    


int checkEnd()
{
    int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==UNSET){
				return 0;
			}

		}

	}
	return 1;
}


void set(int x){
    int i,j;
    switch (x) {
        case 0:
            i=0;j=0;
            
            break;
            
        case 1:
            i=0;j=1;
            
            break;
            
        case 2:
            i=0;j=2;
            
            break;
        case 3:
            i=1;j=0;
            
            break;
        case 4:
            i=1;j=1;
            
            break;
        case 5:
            i=1;j=2;
            
            break;
        case 6:
            i=2;j=0;
            
            break;
        case 7:
            i=2;j=1;
            
            break;
        case 8:
            i=2;j=2;
            
            break;
            
        default:
            break;
    }
    
    board[i][j]=USER;
    
    
}

