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



double lastTime;

double startTime;
double passedTime;
double unprocessedTime = 0;
int frames = 0;
double frameCounter = 0;


struct tile{
    int value;
    SDL_Rect DestEntity;
}e[8];




int main(int argc,const char * argv[]){
    
    int board[3][3];
    
    
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
    
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=UNSET;
        }
    }
    
    printf("\nmain before");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d",board[i][j]);
        }
    }
    
    
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
            printf("e %d ",e[i].value);
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
             
             printf("\nmain after1");
             for(int i=0;i<3;i++){
                 printf("\n");
                 for(int j=0;j<3;j++){
                     printf("%d ",board[i][j]);
                 }
             }
             if(a>0 && a<=250){
                 if(b>0 && b<=250){
                      printf("\ncalled 0");
                     set(USER,0,board);
                    
                 }
                 else if(b>250 && b<=500){
                       printf("\ncalled 1");
                      set(USER,1,board);
                   
                 }
                 else{
                      printf("\ncalled 2");
                      set(USER,2,board);
                    
                     
                 }
                 
             }
             else if(a>250 && a<=500){
                 if(b>0 && b<=250){
                      printf("\ncalled 3");
                     set(USER,3,board);
                    
                 }
                 else if(b>250 && b<=500){
                     printf("\ncalled 4");
                     set(USER,4,board);
                     
                 }
                 else{
                        printf("\ncalled 5");
                     set(USER,5,board);
                  
                     
                 }
             }
             else{
                 if(b>0 && b<=250){
                      printf("\ncalled 6");
                     set(USER,6,board);
                    
                 }
                 else if(b>250 && b<=500){
                            printf("\ncalled 7");
                     set(USER,7,board);
              
                 }
                 else{
                     printf("\ncalled 8");
                     set(USER,8,board);
                     
                 }
                 
             }
              lastTime = SDL_GetTicks();
             
        
         }
        
        
        startTime = SDL_GetTicks();
        //printf("%f",startTime);
        passedTime = startTime - lastTime;
        //printf("%f",lastTime);
        //printf("\n%f",passedTime);
         printf("\nmain after2");
        for(int i=0;i<3;i++){
            printf("\n");
            for(int j=0;j<3;j++){
                printf("%d ",board[i][j]);
            }
        }
        printf("\n");
        
        if (lastTime>0 && passedTime>=100.0){
            computer();
            printf("\nsidhin");
            for(int i=0;i<3;i++){
                printf("\n");
                for(int j=0;j<3;j++){
                    printf("%d ",board[i][j]);
                }
            }

            
        }
        
        
    
    }
    
    
    
}
