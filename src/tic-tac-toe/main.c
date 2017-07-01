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


int xvalue[]={0,1,2,0,1,2,0,1,2,};
int yvalue[]={0,0,0,1,1,1,2,2,2,};

double lastTime;

double startTime;
double passedTime;
double unprocessedTime = 0;
int frames = 0;
double frameCounter = 0;


struct tile{
    int value;
    SDL_Rect DestEntity;
}e[9];

void set(int mark, int grid){
    
    e[grid].value=mark;
    e[grid].DestEntity.x=xvalue[grid]*250;
     e[grid].DestEntity.y=yvalue[grid]*250;
    
}


void playerMove(int x,int y){
    if(y>0 && y<=250){
        
        if(x>0 && x<=250){
            set(USER,0);
            
        }
        else if(x>250 && x<=500){
              set(USER,1);
        }
        else{
              set(USER,2);
        }
    }
    
    else if(y>250 && y<=500){
        
        if(x>0 && x<=250){
              set(USER,3);
        }
        else if(x>250 && x<=500){
              set(USER,4);
        }
        else{
              set(USER,5);
        }
    }
    
    else{
        
        if(x>0 && x<=250){
              set(USER,6);
        }
        else if(x>250 && x<=500){
              set(USER,7);
        }
        else{
           
              set(USER,8);
        }
    
        
    }
    
}



int main(int argc,const char * argv[]){
    
    
    SDL_Surface* window=NULL;
    SDL_Surface* boardSurface=NULL;
    SDL_Surface* xSurface=NULL;
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
    
    
   // srand((unsigned int)(time(NULL)));
    //int no=rand();
    //int counter=no%9;
    
    
   
    
    
    while(1)
    {
        SDL_FillRect( window, NULL, SDL_MapRGB( window->format, 0x66, 0x66, 0x99) );
        
        if(SDL_PollEvent(& windowEvent)){
            
            if(SDL_QUIT==windowEvent.type){
                break;
            }
            
        }
        
        
      


       boardSurface=SDL_LoadBMP("board.bmp");
        circle=SDL_LoadBMP("c15.bmp");
        xSurface=SDL_LoadBMP("x3.bmp");
        
         SDL_BlitSurface(boardSurface,NULL,window,&Destboard);
        
        
        
        for(int i=0;i<9;i++){
            if(e[i].value==USER){
                SDL_BlitSurface(circle,NULL,window,&e[i].DestEntity);
            }
            else if(e[i].value==COMPUTER){
                   SDL_BlitSurface(xSurface,NULL,window,&e[i].DestEntity);
                
            }
            else
                continue;
        }
        
        
        SDL_UpdateWindowSurface(newWindow);
        
        int a,b;
         if(SDL_MOUSEBUTTONDOWN && SDL_GetMouseState(&a,&b)){
            playerMove(a,b);
            lastTime = SDL_GetTicks();
             
             }
        
        startTime = SDL_GetTicks();
        //printf("%f",startTime);
        passedTime = startTime - lastTime;
        //printf("%f",lastTime);
        //printf("\n%f",passedTime);
        
        
        
        if (lastTime>0 && passedTime>=100.0){
            // computer();
            
        }

    }
    
    //SDL_FreeSurface(headSurface);
    //SDL_FreeSurface(playSurface);
    SDL_FreeSurface(window);
    //SDL_FreeSurface(quitSurface);
    SDL_FreeSurface(boardSurface);
    // SDL_FreeSurface(circleSurface);
    //SDL_FreeSurface(xSurface);
    
    //playSurface=NULL;
    window=NULL;
    //quitSurface=NULL;
    //headSurface=NULL;
    boardSurface=NULL;
    //circleSurface=NULL;
    //xSurface=NULL;
    
    
    SDL_DestroyWindow(newWindow);
    SDL_Quit();
    
    return EXIT_SUCCESS;
        
        
    
    }
    
    
    

