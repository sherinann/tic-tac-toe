#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>


enum {
    UNSET,
    COMPUTER,
    USER
};

int HEIGHT= 750;
int  WIDTH =750;

int board1[3][3];


struct board{
    int value;
    SDL_Rect DestEntity;
}e[8];

void computer(){
    
    
    
}

void set(int mark,int position){
    e[position].value=mark;
    switch(position){
        case 0: e[position].DestEntity.x=0*250;
                e[position].DestEntity.y=0*250;
                break;
        case 1: e[position].DestEntity.x=0*250;
            e[position].DestEntity.y=1*250;
            break;
        case 2: e[position].DestEntity.x=0*250;
            e[position].DestEntity.y=2*250;
            break;
        case 3: e[position].DestEntity.x=1*250;
            e[position].DestEntity.y=0*250;
            break;
        case 4: e[position].DestEntity.x=1*250;
            e[position].DestEntity.y=1*250;
            break;
        case 5: e[position].DestEntity.x=1*250;
            e[position].DestEntity.y=2*250;
            break;
        case 6: e[position].DestEntity.x=2*250;
            e[position].DestEntity.y=0*250;
            break;
        case 7: e[position].DestEntity.x=2*250;
            e[position].DestEntity.y=1*250;
            break;
        case 8: e[position].DestEntity.x=2*250;
            e[position].DestEntity.y=2*250;
            break;

            
        default:break;
    }
    
}




int main(int argc,const char * argv[]){
    
    SDL_Surface* window=NULL;
    SDL_Surface* board=NULL;
    SDL_Surface* x=NULL;
    SDL_Surface* circle=NULL;
    
    
    SDL_Rect Destboard;
    Destboard.x=0;
    Destboard.y=0;
    
    
    if( SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf("error %s",SDL_GetError());
    }
    
    
    SDL_Window *newWindow= SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
     window= SDL_GetWindowSurface(newWindow);
    
    
    if(NULL==window){
        printf("error %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_Event windowEvent;
    
    
    srand((unsigned int)(time(NULL)));
    int no=rand();
    int counter=no%9;
    
    while(1)
    {
        SDL_FillRect( window, NULL, SDL_MapRGB( window->format, 0x66, 0x66, 0x99) );
        
        if(SDL_PollEvent(& windowEvent)){
            
            if(SDL_QUIT==windowEvent.type){
                break;
            }
            
        }
        
        
      


       board=SDL_LoadBMP("board.bmp");
        circle=SDL_LoadBMP("c15.bmp");
        x=SDL_LoadBMP("x3.bmp");
        
         SDL_BlitSurface(board,NULL,window,&Destboard);
        
        
        
        for(int i=0;i<9;i++){
            if(e[i].value==USER){
                SDL_BlitSurface(circle,NULL,window,&e[i].DestEntity);
            }
            else if(e[i].value==COMPUTER){
                   SDL_BlitSurface(x,NULL,window,&e[i].DestEntity);
                
            }
            else
                continue;
        }
        
        SDL_UpdateWindowSurface(newWindow);
        
        int x,y;
         if(SDL_MOUSEBUTTONDOWN && SDL_GetMouseState(&x,&y)){
             if(x>0&& x<=250){
                 if(y>0 && y<=250){
                     
                     set(USER,0);
                 }
                 else if(y>250 && y<=500){
                      set(USER,1);
                 }
                 else{
                      set(USER,2);
                     
                 }
                 
             }
             else if(x>250 && x<=500){
                 if(y>0 && y<=250){
                     set(USER,3);
                 }
                 else if(y>250 && y<=500){
                     set(USER,4);
                 }
                 else{
                     set(USER,5);
                     
                 }
             }
             else{
                 if(y>0 && y<=250){
                     set(USER,6);
                 }
                 else if(y>250 && y<=500){
                     set(USER,7);
                 }
                 else{
                     set(USER,8);
                     
                 }
                 
             }

             
        
         }
    
    }
    
    
    
}
