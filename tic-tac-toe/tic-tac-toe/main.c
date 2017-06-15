//
//  main.c
//  tic-tac-toe
//
//  Created by Sherin Ann Thomas on 15/06/17.
//  Copyright © 2017 Sherin Ann Thomas. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>

const int WIDTH=800,HEIGHT=800;

int main(int argc, const char * argv[]) {
    
    SDL_Surface* imageSurface= NULL;
    SDL_Surface* windowSurface =NULL;
    
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
    imageSurface = SDL_LoadBMP("tic.bmp");
    if(NULL==imageSurface){
        printf("image could not be loaded %s",SDL_GetError());
        
    }
    
    while (1) {
        if(SDL_PollEvent(& windowEvent)){
            
            if(SDL_QUIT==windowEvent.type){
                break;
            }
        }
        
        SDL_BlitSurface(imageSurface,NULL,windowSurface,NULL);
        SDL_UpdateWindowSurface(window);
    }
        
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(windowSurface);
    
    imageSurface=NULL;
    windowSurface=NULL;
        
        
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
