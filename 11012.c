#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char S[10000];
char ans[40][40];
int visit[40][40]={0};
int encrypt(int width, int length){
    int i,j,k;
    int row_cur=0;
    int col_cur=0;
    int mode=0;
    ans[row_cur][col_cur]=S[0];
    visit[row_cur][col_cur]=1;
    for(i=1;i<length;i++){
        /*for(j=0;j<width;j++){
                for(k=0;k<width;k++){
                    printf("%c ",ans[j][k]);
                }
                printf("\n");
        }*/
        if(visit[row_cur+1][col_cur]==0&&row_cur+1<width&&mode==0){
            ans[row_cur+1][col_cur]=S[i];
            visit[row_cur+1][col_cur]=1;
            row_cur++;
            if(row_cur+1>=width){
                mode=1;
            }
            continue;
        }
        if(visit[row_cur][col_cur+1]==0&&col_cur+1<width&&mode==1){
            ans[row_cur][col_cur+1]=S[i];
            visit[row_cur][col_cur+1]=1;
            col_cur++;
            if(col_cur+1>=width){
                mode=2;
            }
            continue;
        }
        if(visit[row_cur-1][col_cur]==0&&row_cur-1>=0){
            ans[row_cur-1][col_cur]=S[i];
            visit[row_cur-1][col_cur]=1;
            row_cur--;
            if(row_cur-1<0){
                mode=3;
            }
            continue;
        }
        if(visit[row_cur][col_cur-1]==0&&col_cur-1>=0){
            ans[row_cur][col_cur-1]=S[i];
            visit[row_cur][col_cur-1]=1;
            col_cur--;
            continue;
        }
    }
    return 0;
}


int main(){
char tmp;
int c=0;
int i,width,j;

    while(1){
        tmp=getchar();
        if(tmp=='\n'){
            for(i=0;i<40;i++){
                if((i*i)>c){
                    width=i;
                    break;
                }
            }
            printf("%s\n",S);
            printf("%d %d\n",width,c);
            encrypt(width,c);
            for(i=0;i<width;i++){
                for(j=0;j<width;j++){
                    printf("%c ",ans[i][j]);
                }
                printf("\n");
            }

            continue;
        }else if(tmp==EOF){
            break;
        }else{
            S[c]=tmp;
            c++;
        }

    }


return 0;
}
