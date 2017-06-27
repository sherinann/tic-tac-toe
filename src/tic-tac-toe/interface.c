//
//  interface.c
//  tic-tac-toe
//
//  Created by Sherin Ann Thomas on 15/06/17.
//  Copyright © 2017 Sherin Ann Thomas. All rights reserved.
//

#include  <SDL2/SDL.h>
#include "interface.h"


//SDL_Surface* boardSurface;
//SDL_Surface* windowSurface;

//SDL_Window *window;






SDL_Surface* initialise(char* image){
    SDL_Surface* imageSurface=NULL;
    
    imageSurface= SDL_LoadBMP(image);
    if(NULL==imageSurface){
        printf("image could not be loaded %s",SDL_GetError());
        
    }
    else{
        
    }

    
    return imageSurface;
}


int movePlayer(){
    
    int x,y;
    
    if(SDL_MOUSEBUTTONDOWN && SDL_GetMouseState(&x,&y)){
        if(x>0&& x<=250){
            if(y>0 && y<=250){
                
                return 0;
            }
            else if(y>250 && y<=500){
                return 1;
            }
            else{
                return 2;
                
            }
            
        }
        else if(x>250 && x<=500){
            if(y>0 && y<=250){
                return 3;
            }
            else if(y>250 && y<=500){
                return 4;
            }
            else{
                return 5;
                
            }
        }
        else{
            if(y>0 && y<=250){
                return 6;
            }
            else if(y>250 && y<=500){
                return 7;
            }
            else{
                return 8;
                
            }
            
        }
    }
    
    
    return -1;
    
}

