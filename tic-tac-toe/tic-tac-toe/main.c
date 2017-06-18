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


#define true 1
#define false 0

const int WIDTH=1000,HEIGHT=1000;

int quit=false;

int main(int argc, const char * argv[]) {
    
   
    
    SDL_Surface* playSurface= NULL;
    SDL_Surface* windowSurface =NULL;
    SDL_Surface* quitSurface= NULL;
    SDL_Surface* headSurface= NULL;
    SDL_Surface* boardSurface= NULL;
    
    SDL_Rect DestPlay;
    
    DestPlay.x = 750;
    DestPlay.y = 300;

    
    
    SDL_Rect DestQuit;
    
    DestQuit.x = 750;
    DestQuit.y = 500;
    
    SDL_Rect DestHead;
    
    DestHead.x = 5;
    DestHead.y = 10;
    DestHead.w = 100;
    DestHead.h = 100;

    
    
    SDL_Rect DestBoard;
    
    DestBoard.x = 50;
    DestBoard.y = 90;
    DestBoard.w = 300;
    DestBoard.h=400;
    
    
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
    
    
    
    headSurface=initialise("tictactoe.bmp");
    
    boardSurface=initialise("board.bmp");
    
    playSurface=initialise("play.bmp");
    
    quitSurface=initialise("quit.bmp");
    
    
    
    
    
    while (1) {
        
        SDL_FillRect( windowSurface, NULL, SDL_MapRGB( windowSurface->format, 0x66, 0x66, 0x99) );
        
        if(SDL_PollEvent(& windowEvent)){
            
            if(SDL_QUIT==windowEvent.type){
                break;
            }
        
        }
        
        
        //SDL_BlitScaled(headSurface,NULL,windowSurface,&Destnew);
        
        SDL_BlitSurface(headSurface,NULL,windowSurface,&DestHead);
        
        
        SDL_BlitSurface(playSurface,NULL,windowSurface,&DestPlay);
        
        
        SDL_BlitSurface(quitSurface,NULL,windowSurface,&DestQuit);
        
        
        SDL_BlitSurface(boardSurface,NULL,windowSurface,&DestBoard);
        
        
        SDL_UpdateWindowSurface(window);
    }
    
    SDL_FreeSurface(headSurface);
    SDL_FreeSurface(playSurface);
    SDL_FreeSurface(windowSurface);
    SDL_FreeSurface(quitSurface);
    SDL_FreeSurface(boardSurface);
    
    playSurface=NULL;
    windowSurface=NULL;
    quitSurface=NULL;
    headSurface=NULL;
    boardSurface=NULL;
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;

    }
