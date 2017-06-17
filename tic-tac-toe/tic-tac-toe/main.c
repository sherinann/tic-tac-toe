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
    
    SDL_Rect DestPlay;
    
    DestPlay.x = 300;
    DestPlay.y = 600;
    
    
    SDL_Rect DestQuit;
    
    DestQuit.x = 500;
    DestQuit.y = 600;
    
    SDL_Rect DestHead;
    
    DestHead.x = 10;
    DestHead.y = 100;
    
    
    
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
    
    playSurface=initialise("play.bmp");
    
    quitSurface=initialise("quit.bmp");
    
    
    while (1) {
        
        SDL_FillRect( windowSurface, NULL, SDL_MapRGB( windowSurface->format, 0x66, 0x66, 0x99) );
        
        if(SDL_PollEvent(& windowEvent)){
            
            if(SDL_QUIT==windowEvent.type){
                break;
            }
        
        }
        
        
        SDL_BlitSurface(headSurface,NULL,windowSurface,&DestHead);
        
        SDL_BlitSurface(playSurface,NULL,windowSurface,&DestPlay);
        
        
        SDL_BlitSurface(quitSurface,NULL,windowSurface,&DestQuit);
        
        SDL_UpdateWindowSurface(window);
    }
    
    SDL_FreeSurface(headSurface);
    SDL_FreeSurface(playSurface);
    SDL_FreeSurface(windowSurface);
    SDL_FreeSurface(quitSurface);
    
    playSurface=NULL;
    windowSurface=NULL;
    quitSurface=NULL;
    headSurface=NULL;
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;

    }
