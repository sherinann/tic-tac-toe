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

int board[3][3];

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



void set(int mark,int position){
    int i,j;
    /*for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d",board[i][j]);
        }
    }*/
    printf("position %d",position);
    e[position].value=mark;
    switch(position){
        case 0: e[position].DestEntity.x=0*250;
                e[position].DestEntity.y=0*250;
                board[0][0]=mark;
                break;
        case 1: e[position].DestEntity.x=0*250;
            e[position].DestEntity.y=1*250;
            board[0][1]=mark;
            break;
        case 2: e[position].DestEntity.x=0*250;
            e[position].DestEntity.y=2*250;
            board[0][2]=mark;
            break;
        case 3: e[position].DestEntity.x=1*250;
            e[position].DestEntity.y=0*250;
            board[1][0]=mark;
            break;
        case 4: e[position].DestEntity.x=1*250;
            e[position].DestEntity.y=1*250;
            board[1][1]=mark;
            break;
        case 5: e[position].DestEntity.x=1*250;
            e[position].DestEntity.y=2*250;
            board[1][2]=mark;
            break;
        case 6: e[position].DestEntity.x=2*250;
            e[position].DestEntity.y=0*250;
            board[2][0]=mark;
            break;
        case 7: e[position].DestEntity.x=2*250;
            e[position].DestEntity.y=1*250;
            board[2][1]=mark;
            break;
        case 8: e[position].DestEntity.x=2*250;
            e[position].DestEntity.y=2*250;
            board[2][2]=mark;
            break;

    }
  
    
}


void getpos(int x, int y){
    if(x==0){
        if(y==0){
            set(COMPUTER,0);
        }
        else if(y==1){
            set(COMPUTER,1);
        }
        else{
            set(COMPUTER,2);
        }
    }
    else if(x==1){
        if(y==0){
            set(COMPUTER,4);
        }
        else if(y==1){
            set(COMPUTER,4);
        }
        else{
            set(COMPUTER,5);
        }
    }
    else{
        if(y==0){
            set(COMPUTER,6);
        }
        else if(y==1){
            set(COMPUTER,7);
        }
        else{
            set(COMPUTER,8);
        }
    }
    
}

void computer(){
      int i,j,count;
    printf("\nfunction computer");
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf("%d ",board[i][j]);
        }
    }
    printf("\n");
    if(board[1][1]==UNSET){
        printf("inside");
        
        set(COMPUTER,4);
    }
    
  
    //printf("here");
    //checking for winning chances
    
    for(i=0;i<3;i++){
        count=0;
        for(j=0;j<3;j++){
            if(board[i][j]==COMPUTER){
                count++;
            }
            
        }
        if(count==2){
            for(j=0;j<3;j++){
                if(board[i][j]==UNSET){
                    getpos(i,j);
                    return;
                }
            }
        }
    }
    
    
    for(j=0;j<3;j++){
        count=0;
        for(i=0;i<3;i++){
            if(board[i][j]==COMPUTER){
                count++;
            }
            
        }
        if(count==2){
            for(i=0;i<3;i++){
                if(board[i][j]==UNSET){
                    getpos(i,j);
                    return;
                }
            }
        }
    }

    count=0;
    for(i=0;i<3;i++){
        if(board[i][i]==COMPUTER){
            count++;
        }
    }
    
    if(count==2){
        for(i=0;i<3;i++){
            if(board[i][i]==UNSET){
                getpos(i, i);
                return;
            }
        }
    }
    
    
    count=0;
    for(i=0;i<3;i++){
        if(board[i][2-i]==COMPUTER){
            count++;
        }
    }
    
    if(count==2){
        for(i=0;i<3;i++){
            if(board[i][2-i]==UNSET){
                getpos(i, 2-i);
                return;
            }
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
                     set(USER,0);
                    
                 }
                 else if(b>250 && b<=500){
                       printf("\ncalled 1");
                      set(USER,1);
                   
                 }
                 else{
                      printf("\ncalled 2");
                      set(USER,2);
                    
                     
                 }
                 
             }
             else if(a>250 && a<=500){
                 if(b>0 && b<=250){
                      printf("\ncalled 3");
                     set(USER,3);
                    
                 }
                 else if(b>250 && b<=500){
                     printf("\ncalled 4");
                     set(USER,4);
                     
                 }
                 else{
                        printf("\ncalled 5");
                     set(USER,5);
                  
                     
                 }
             }
             else{
                 if(b>0 && b<=250){
                      printf("\ncalled 6");
                     set(USER,6);
                    
                 }
                 else if(b>250 && b<=500){
                            printf("\ncalled 7");
                     set(USER,7);
              
                 }
                 else{
                     printf("\ncalled 8");
                     set(USER,8);
                     
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
        }
        
        
    
    }
    
    
    
}
