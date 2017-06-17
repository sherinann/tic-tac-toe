//
//  interface.c
//  tic-tac-toe
//
//  Created by Sherin Ann Thomas on 15/06/17.
//  Copyright © 2017 Sherin Ann Thomas. All rights reserved.
//

#include  <SDL/SDL.h>
#include "interface.h"

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
