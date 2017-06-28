//
//  main.c
//  tic-tac-toe
//
//  Created by Sherin Ann Thomas on 15/06/17.
//  Copyright © 2017 Sherin Ann Thomas. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include "interface.h"
#include "game.h"
#include <stdlib.h>
#include <time.h>


struct entity{
    int value;
    SDL_Rect DestEntity;

};

#define true 1
#define false 0

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


const int WIDTH=750,HEIGHT=750;

int quit=false;

 int no=0;


SDL_Surface* boardSurface;
SDL_Surface* windowSurface;

SDL_Window *window;

void displaySet(struct entity e,int x,int y, int mark){
   
    e.DestEntity.x=x;
    e.DestEntity.y=y;
    if(mark==1){
        e.value=COMPUTER;
    }
    else{
        e.value=USER;
    }
    
    
   // SDL_UpdateWindowSurface(window);
    
    
}

void playerChoice(struct entity e,int choice){
    
    //check for availability
    //
    //
    //
    //
    
    //if yed then
    set(choice);
    
    switch (choice) {
        case 0:
            
            displaySet(e,0*250, 0*250,USER);
            break;
        case 1:
             displaySet(e,0*250, 1*250,USER);
        
            break;
        case 2:
             displaySet(e,0*250, 2*250,USER);
         
            break;
        case 3:
             displaySet(e,1*250, 0*250,USER);
        
            break;
        case 4:
             displaySet(e,1*250, 1*250,USER);
          
            break;
        case 5:
             displaySet(e,1*250, 2*250,USER);
       
            break;
        case 6:
             displaySet(e,2*250, 0*250,USER);
           
            break;
        case 7:
             displaySet(e,2*250, 1*250,USER);
         
            break;
        case 8:
             displaySet(e,2*250, 2*250,USER);
        
            break;
            
        default:
            break;
    }
    
    
    
    //printf("\nenter indexes:");
    //scanf("%d%d",&posi,&posj);
    //if(board[posi][posj]==UNSET){
        
      //  printf("\nplayer move :%d %d",posi,posj);
       // board[posi][posj]=USER;
   // }
    //else{
      //  printf("select another");
   // }
}




int main(int argc, const char * argv[]) {
    
    struct entity e[9];
   
    
    SDL_Surface* boardSurface=NULL;
    SDL_Surface* windowSurface=NULL;
    SDL_Surface* xSurface=NULL;
    SDL_Surface* circleSurface=NULL;
   // SDL_Surface* playSurface= NULL;
   
   // SDL_Surface* quitSurface= NULL;
    //SDL_Surface* headSurface= NULL;

    
    /*SDL_Rect DestPlay;
    
    DestPlay.x = 750;
    DestPlay.y = 300;
    SDL_Rect DestQuit;
    DestQuit.x = 750;
    DestQuit.y = 500;
    SDL_Rect DestHead;
    DestHead.x = 5;
    DestHead.y = 10;
    DestHead.w = 100;
    DestHead.h = 100;*/
    SDL_Rect DestBoard;
    DestBoard.x = 0;
    DestBoard.y = 0;
    //DestBoard.w = 300;
    //DestBoard.h=400;
   // SDL_Rect Destnew;
    //DestBoard.x = 10;
    //DestBoard.y = 10;
    if( SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf("error %s",SDL_GetError());
    }
    
    SDL_Window *window= SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    
    windowSurface= SDL_GetWindowSurface(window);
    
    if(NULL==window){
        printf("error %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_Event windowEvent;

    
    //headSurface=initialise("tictactoe.bmp");

    boardSurface=initialise("board.bmp");
    
    xSurface=initialise("x3.bmp");
    
    circleSurface= initialise("c15.bmp");
    
    //playSurface=initialise("play.bmp");
    
    //quitSurface=initialise("quit.bmp");

    
   while (1) {
        
        SDL_FillRect( windowSurface, NULL, SDL_MapRGB( windowSurface->format, 0x66, 0x66, 0x99) );
        
        if(SDL_PollEvent(& windowEvent)){
            
        if(SDL_QUIT==windowEvent.type){
              break;
        }
        
        }
        //SDL_BlitSurface(headSurface,NULL,windowSurface,&DestHead);
        //SDL_BlitSurface(playSurface,NULL,windowSurface,&DestPlay);
        //SDL_BlitSurface(quitSurface,NULL,windowSurface,&DestQuit);
        
        SDL_BlitSurface(boardSurface,NULL,windowSurface,&DestBoard);
       
       for(int i=0;i<=9;i++){
           
           if(e[i].value==COMPUTER){
                     SDL_BlitSurface(circleSurface,NULL,windowSurface,&e[i].DestEntity);
           }
           else if(e[i].value==USER){
          
               SDL_BlitSurface(xSurface,NULL,windowSurface,&e[i].DestEntity);
           }
           else
               continue;
       }
       
       
        SDL_UpdateWindowSurface(window);
       
        int i,j,board[3][3],counter,location ,choiceP ,returnStatus[3];
                
                //status 0 if game going on else 1
                int status=0;
                //while(counter<9||status==0){
                //set all boxes as 0. 1 set to denote the computer and 2 to denote the player
                
                for( i=0;i<3;i++){
                    for(j=0;j<3;j++)
                        board[i][j]=0;
                    
                }
                //computer and player alternatively start the game
                
                srand((unsigned int)(time(NULL)));
                int num=rand();
            counter=num%2;;
        
       while(status==0){
      
            if(counter==0){
                printf("1\n");
                location=moveComputer(returnStatus);
                printf("\nlocation %d",location);
                if(location==0){
                    status=1;
                    break;
                }
                else{
                  
                    printf("%d%d\n",returnStatus[1],returnStatus[2]);
                    
                    
                    displaySet(e[no],returnStatus[1]*250, returnStatus[2]*250,COMPUTER);
                    no++;
                    
                    
                }
                counter++;
                status=checkEnd();
            }
            else{
                printf("2\n");
                choiceP=movePlayer();
                if(choiceP==-1){
                    status=1;
                    break;
                }
                else{
                    playerChoice(e[no],choiceP);
                    no++;
                }
               
                status=checkEnd();
                
                
                
                
            }
           
       }
       
       
   }
    
    //SDL_FreeSurface(headSurface);
    //SDL_FreeSurface(playSurface);
    SDL_FreeSurface(windowSurface);
    //SDL_FreeSurface(quitSurface);
    SDL_FreeSurface(boardSurface);
   // SDL_FreeSurface(circleSurface);
    //SDL_FreeSurface(xSurface);
    
    //playSurface=NULL;
    windowSurface=NULL;
    //quitSurface=NULL;
    //headSurface=NULL;
    boardSurface=NULL;
    //circleSurface=NULL;
    //xSurface=NULL;
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;

    }
