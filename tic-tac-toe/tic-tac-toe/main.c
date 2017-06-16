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

const int WIDTH=800,HEIGHT=800;

int quit=false;

int main(int argc, const char * argv[]) {
    
   
    
    SDL_Surface* playSurface= NULL;
    SDL_Surface* windowSurface =NULL;
    SDL_Surface* quitSurface= NULL;
    
    SDL_Rect DestPlay;
    
    DestPlay.x = 200;
    DestPlay.y = 500;
    
    
    SDL_Rect DestQuit;
    
    DestQuit.x = 400;
    DestQuit.y = 500;
    
    
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
    
    
    
    
    playSurface = SDL_LoadBMP("play.bmp");
   if(NULL==playSurface){
       printf("image could not be loaded %s",SDL_GetError());
        
   }
    
    quitSurface= SDL_LoadBMP("quit.bmp");
    if(NULL==quitSurface){
        printf("image could not be loaded %s",SDL_GetError());
        
    }
    
    while (1) {
        
        SDL_FillRect( windowSurface, NULL, SDL_MapRGB( windowSurface->format, 0xFF, 0x44, 0x44 ) );
        
        if(SDL_PollEvent(& windowEvent)){
            
            if(SDL_QUIT==windowEvent.type){
                break;
            }
        
        }
        
        
        
        SDL_BlitSurface(playSurface,NULL,windowSurface,&DestPlay);
        
        
        SDL_BlitSurface(quitSurface,NULL,windowSurface,&DestQuit);
        
        SDL_UpdateWindowSurface(window);
    }
    
    SDL_FreeSurface(playSurface);
    SDL_FreeSurface(windowSurface);
     SDL_FreeSurface(quitSurface);
    
    playSurface=NULL;
    windowSurface=NULL;
     quitSurface=NULL;
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;

    }
