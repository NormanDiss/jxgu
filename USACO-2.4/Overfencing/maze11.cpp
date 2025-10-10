

/*
ID: ayushn.2
LANG: C
TASK: maze1
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXW 38
#define MAXH 100
int W,H;
char maze[MAXH*2+1][MAXW*2+1];
int delta1[]={-1,1,0,0};
int delta2[]={0,0,-1,1};
char delta3[]={'-','-','|','|'};

int bfs(int ex1x,int ex1y,int ex2x,int ex2y){
    bool visited[MAXH*2+1][MAXW*2+1];
    int i,j,k,count=0;
    struct {
           int x,y;
           int step;
           } que[20000];
    int nowpoint=0;
    int addpoint=1;
    for (i=1;i<=H;i++) for (j=1;j<=W;j++) visited[i][j]=0;
    que[0].x=ex1x;
    que[0].y=ex1y;
    que[0].step=1;
    if (!(ex1x==ex2x && ex1y==ex2y)){
                     que[1].x=ex2x;
                     que[1].y=ex2y;
                     que[1].step=1;
                     visited[ex2x][ex2y]=1;
                     addpoint++;
                     }
    visited[ex1x][ex1y]=1;
    while (count<=W*H){
          count++;
          for (k=0;k<=3;k++)
              if (maze[que[nowpoint].x*2-1+delta1[k]][que[nowpoint].y*2-1+delta2[k]]!=delta3[k]
                  && visited[que[nowpoint].x+delta1[k]][que[nowpoint].y+delta2[k]]==0){
                  que[addpoint].x=que[nowpoint].x+delta1[k];
                  que[addpoint].y=que[nowpoint].y+delta2[k];
                  que[addpoint].step=que[nowpoint].step+1;
                  visited[que[addpoint].x][que[addpoint].y]=1;
                  addpoint++;
                  }
          nowpoint++;
          }
    return que[nowpoint-2].step;
}
   
   
int main(){
    int i,j,count=0,exroomx[3],exroomy[3];
    FILE *in=fopen("maze1.in","r");
    FILE *out=fopen("maze1.out","w");
    //read file
    fscanf(in, "%d%d", &W, &H);
    for (i=0;i<H*2+1;i++) {
        fgetc(in);
        for (j=0;j<W*2+1;j++)
           maze[i][j]=fgetc(in);
        maze[i][j]='\0';
    }
    //find "exit"
    for (j=1;j<=W;j++){
        if (maze[0][j*2-1]==' '){
                                 exroomx[count]=1;
                                 exroomy[count]=j;
                                 maze[0][j*2-1]='-';
                                 count++;
                                 }
        if (maze[H*2][j*2-1]==' '){
                                 exroomx[count]=H;
                                 exroomy[count]=j;
                                 maze[H*2][j*2-1]='-';
                                 count++;
                                }
        }
    for (i=1;i<=H;i++){
        if (maze[i*2-1][0]==' '){
                                 exroomx[count]=i;
                                 exroomy[count]=1;
                                 maze[i*2-1][0]='|';
                                 count++;
                              }
        if (maze[i*2-1][W*2]==' '){
                                 exroomx[count]=i;
                                 exroomy[count]=W;
                                 maze[i*2-1][W*2]='|';
                                 count++;
                                }
        }
    //find the longest shortest path
    fprintf(out,"%d\n",bfs(exroomx[0],exroomy[0],exroomx[1],exroomy[1]));
    return 0;
}