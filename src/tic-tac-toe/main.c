#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>

//states of variables
enum {
    UNSET,
    COMPUTER,
    USER,
    WIN_COMPUTER,
    WIN_USER,
    TIE
};

int HEIGHT= 750;
int  WIDTH =750;
int board[3][3];
int xvalue[]={0,1,2,0,1,2,0,1,2,};
int yvalue[]={0,0,0,1,1,1,2,2,2,};
double lastTime;
double startTime;
double passedTime;

//structure where the updated box values are stored
struct tile{
    int value;
    SDL_Rect DestEntity;
}e[9];

//to check if all boxes have been occupied/tie
void checkEnd(){
    int i;
    for(i=0;i<9;i++){
        if(e[i].value==UNSET)
            return;
        
    }
    for(i=0;i<9;i++){
        e[i].value=TIE;
    }
    return;
}

//to store the state for winning display
void Win(int mark){
    int i;
    for(i=0;i<9;i++){
        if(mark==COMPUTER)
            e[i].value=WIN_COMPUTER;
        else
            e[i].value=WIN_USER;
    }
}

//to check if anyone won
void checkWin(int mark){
    int i,count;
    for(i=0;i<=8;i+=3){
        count=0;
        if(e[i].value==mark)
            count++;
        if(e[i+1].value==mark)
            count++;                //checking winning by horizontal line
        if(e[i+2].value==mark)
            count++;
        if(count==3){
            Win(mark);
            return;
        }
    }
    
    for(i=0;i<3;i++){
        count=0;
        if(e[i].value==mark)
            count++;               //checking winning by vertical lines
        if(e[i+3].value==mark)
            count++;
        if(e[i+6].value==mark)
            count++;
        if(count==3){
            Win(mark);
            return;
        }
        
        }

     count=0;
    if(e[0].value==mark)
        count++;
    if(e[4].value==mark)        //checking winning by a diagonal
        count++;
    if(e[8].value==mark)
        count++;
    if(count==3){
        Win(mark);
        return;
    }
    
    count=0;
    if(e[2].value==mark)
        count++;
    if(e[4].value==mark)
        count++;            //checking winning by anti diagonal
    if(e[6].value==mark)
        count++;
    if(count==3){
        Win(mark);
        return;
    }
    
    checkEnd();
    return;
}

//to set boxes as being occupied by computer or user
void set(int mark, int grid){
    e[grid].value=mark;
    e[grid].DestEntity.x=xvalue[grid]*250;
     e[grid].DestEntity.y=yvalue[grid]*250;
    checkWin(mark);
}

//to check if 2 out of three boxes in any horizontal line is occupied
int checkHorizontal(int mark){
    int count,i;
    for(i=0;i<=8;i+=3){
        count=0;
        if(e[i].value==mark)
            count++;
        if(e[i+1].value==mark)
            count++;
        if(e[i+2].value==mark)
            count++;
        if(count==2){
            if(e[i].value==UNSET){
                return i;
            }
            else if(e[i+1].value==UNSET){
                return i+1;
            }
            else{
                if(e[i+2].value==UNSET){
                    return i+2;
                }
                return -1;
            }
        }
        
        

    }
    return -1;
}

//to check if 2 out of three boxes in any vertical line is occupied
int checkVertical(int mark){
    int count,i;
    for(i=0;i<3;i++){
        count=0;
        if(e[i].value==mark)
            count++;
        if(e[i+3].value==mark)
            count++;
        if(e[i+6].value==mark)
            count++;
        if(count==2){
            if(e[i].value==UNSET){
                return i;
            }
            else if(e[i+3].value==UNSET){
                return i+3;
            }
            else{
                if(e[i+6].value==UNSET){
                   return i+6;
                }
                return -1;
            }
        }
        

        
    }
    return -1;
}

//to check if 2 out of three boxes in  diagonal line is occupied
int checkDiagonal(int mark){
    
    int count=0;
    if(e[0].value==mark)
        count++;
    if(e[4].value==mark)
        count++;
    if(e[8].value==mark)
        count++;
    if(count==2){
        if(e[0].value==UNSET){
            return 0;
        }
        else if(e[4].value==UNSET){
            return 4;
        }
        else{
            if(e[8].value==UNSET){
                 return 8;
            }
            return -1;
        }
    }
    
    
    return -1;
}

//to check if 2 out of three boxes in  anti diagonal line is occupied
int checkAntiDiagonal(int mark){
    
    int count=0;
    if(e[2].value==mark)
        count++;
    if(e[4].value==mark)
        count++;
    if(e[6].value==mark)
        count++;
    if(count==2){
        if(e[2].value==UNSET){
            return 2;
        }
        else if(e[4].value==UNSET){
            return 4;
        }
        else{
            if(e[6].value==UNSET){
               return 6;
            }
            return -1;
        }
    }
    
    return -1;
}


//generate the box number to be occupied based on the mouse click position
void playerMove(int x,int y){
    if(y>0 && y<=250){
        
        if(x>0 && x<=250){
            if(e[0].value==UNSET){
                set(USER,0);
                lastTime = SDL_GetTicks();
            }
        }
        else if(x>250 && x<=500){
            if(e[1].value==UNSET){
              set(USER,1);
                lastTime = SDL_GetTicks();
            }
        }
        else{
            if(e[2].value==UNSET){
              set(USER,2);
                lastTime = SDL_GetTicks();
            }
        }
    }
    
    else if(y>250 && y<=500){
        
        if(x>0 && x<=250){
            if(e[3].value==UNSET){
              set(USER,3);
                lastTime = SDL_GetTicks();
            }
        }
        else if(x>250 && x<=500){
            if(e[4].value==UNSET){
              set(USER,4);
                lastTime = SDL_GetTicks();
            }
        }
        else{
            if(e[5].value==UNSET){
              set(USER,5);
                lastTime = SDL_GetTicks();
            }
        }
    }
    
    else{
        
        if(x>0 && x<=250){
            if(e[6].value==UNSET){
              set(USER,6);
                lastTime = SDL_GetTicks();
            }
        }
        else if(x>250 && x<=500){
            if(e[7].value==UNSET){
              set(USER,7);
                lastTime = SDL_GetTicks();
            }
        }
        else{
            if(e[8].value==UNSET){
              set(USER,8);
                lastTime = SDL_GetTicks();
            }
        }
    }
}



//move of the computer
void computer(){
    int i,status;
    
    status=checkHorizontal(COMPUTER);
    if(status!=-1){
        if(e[status].value==UNSET){     //checking winning chance by making horizontal line
        set(COMPUTER,status);
        return;
        }
        
    }
    
    status=checkVertical(COMPUTER);
    if(status!=-1){                  //checking winning chance by making vertical line
        if(e[status].value==UNSET){
        set(COMPUTER,status);
        return;
        }
    }
    status=checkDiagonal(COMPUTER);
    if(status!=-1){
        if(e[status].value==UNSET){      //checking winning chance by making digonal line
        set(COMPUTER,status);
        return;
        }
    }
    
    status=checkAntiDiagonal(COMPUTER);
    if(status!=-1){
        if(e[status].value==UNSET){      //checking winning chance by making anti diagonal line
        set(COMPUTER,status);
        return;
        }
    }
    
    status=checkHorizontal(USER);
    if(status!=-1){                 //check need to block horizontal line
        if(e[status].value==UNSET){
        set(COMPUTER,status);
        return;
        }
    }
    
    status=checkVertical(USER);
    if(status!=-1){                     //check need to block vertical line
        if(e[status].value==UNSET){
        set(COMPUTER,status);
        return;
        }
    }
    status=checkDiagonal(USER);
    if(status!=-1){                     //check need to block diagonal line
        if(e[status].value==UNSET){
        set(COMPUTER,status);
        return;
        }
    }
    status=checkAntiDiagonal(USER);     //check need to block anti diagonal line
    if(status!=-1){
        if(e[status].value==UNSET){
        set(COMPUTER,status);
        return;
        }
    }
    
    if(e[4].value==UNSET){
       set(COMPUTER,4);
        return;
    }
     if(e[0].value==UNSET){     //forming a triangle algorithm
       set(COMPUTER,0);
        return;
    }
    if(e[2].value==UNSET){
        set(COMPUTER,2);
        return;
    }
    
    for(i=0;i<9;i++){
        if(e[i].value==UNSET){  //place in other available places
            set(COMPUTER,i);
            return;
        }
    }
}


//main function
int main(int argc,const char * argv[]){
    
    //forming surfaces
    SDL_Surface* window=NULL;
    SDL_Surface* boardSurface=NULL;
    SDL_Surface* xSurface=NULL;
    SDL_Surface* circle=NULL;
    SDL_Surface* winComputer=NULL;
    SDL_Surface* winUser=NULL;
    SDL_Surface* tie=NULL;
    
    SDL_Rect Destwinlose;
    Destwinlose.x=50;
    Destwinlose.y=200;
    SDL_Rect Destboard;
    Destboard.x=0;
    Destboard.y=0;
    
    
    if( SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf("error %s",SDL_GetError());
    }
    
    //new window
    SDL_Window *newWindow= SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    window= SDL_GetWindowSurface(newWindow);
    if(NULL==window){
        printf("error %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Event windowEvent;
    while(1)
    {
        SDL_FillRect( window, NULL, SDL_MapRGB( window->format, 0x66, 0x66, 0x99) );
        if(SDL_PollEvent(& windowEvent)){
            if(SDL_QUIT==windowEvent.type){
                break;
            }
        }
        
        //load needed images
        boardSurface=SDL_LoadBMP("board.bmp");
        circle=SDL_LoadBMP("c15.bmp");
        xSurface=SDL_LoadBMP("x3.bmp");
        winComputer=SDL_LoadBMP("lose.bmp");
        winUser=SDL_LoadBMP("win.bmp");
        tie=SDL_LoadBMP("tie.bmp");
        
        //display surfaces based on win, lose, tie, on going match
        for(int i=0;i<9;i++){
            if(e[i].value==WIN_COMPUTER){
                SDL_BlitSurface(winComputer,NULL,window,&Destwinlose);
                break;
            }
            else if(e[i].value==WIN_USER){
                SDL_BlitSurface(winUser,NULL,window,&Destwinlose);
                break;
            }
            else if(e[i].value==TIE){
                SDL_BlitSurface(tie,NULL,window,&Destwinlose);
                break;

            }
             else if(e[i].value==USER){
                SDL_BlitSurface(boardSurface,NULL,window,&Destboard);
                SDL_BlitSurface(circle,NULL,window,&e[i].DestEntity);
            }
            else if(e[i].value==COMPUTER){
                SDL_BlitSurface(boardSurface,NULL,window,&Destboard);
                SDL_BlitSurface(xSurface,NULL,window,&e[i].DestEntity);
                
            }
            else
                SDL_BlitSurface(boardSurface,NULL,window,&Destboard);
        }
        
        SDL_UpdateWindowSurface(newWindow);
        int a,b;
        if(SDL_MOUSEBUTTONDOWN && SDL_GetMouseState(&a,&b)){
            playerMove(a,b);
          }
        
        //initiate computers move based on time of players move
        startTime = SDL_GetTicks();
        passedTime = startTime - lastTime;
        if (lastTime>0 && passedTime>=100.0){
            computer();
            lastTime=0;
            
        }
    }
    //freeing the memory
    SDL_FreeSurface(window);
    SDL_FreeSurface(boardSurface);
    SDL_FreeSurface(circle);
    SDL_FreeSurface(xSurface);
    SDL_FreeSurface(winUser);
    SDL_FreeSurface(winComputer);
    SDL_FreeSurface(tie);
    
    window=NULL;
    boardSurface=NULL;
    circle=NULL;
    xSurface=NULL;
    tie=NULL;
    winUser=NULL;
    winComputer=NULL;
    
    SDL_DestroyWindow(newWindow);
    SDL_Quit();
    
    return EXIT_SUCCESS;
    
    }
    
    
    

