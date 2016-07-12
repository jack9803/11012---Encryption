#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char S[1000];
char A[40][40]={'\0'};
char ans[1600]={'\0'};
int valid[40][40];
int main(){
char tmp;
int start=0;
int count=0;
int i,j,width;
int row_cur,col_cur,num,dir;
int count_ans;
for(i=0;i<40;i++){
            for(j=0;j<40;j++){
                valid[i][j]=1;
            }
}
while(1){
    tmp=getchar();
    if(tmp=='\n'&&start==0){
        printf("\n");
    }else if((tmp=='\n'||tmp==EOF)&&start==1){
        //printf("%s\n",S);
        for(i=0;i<40;i++){
            if((i*i)>count){
                width=i;
                break;
            }
        }
        for(i=0;i<width;i++){
            for(j=0;j<width;j++){
                valid[i][j]=0;
            }
        }
        //yayayayyayayaya
        /*for(i=0;i<40;i++){
            for(j=0;j<40;j++){
                printf("%d",valid[i][j]);
            }
            printf("\n");
        }*/
        //printf("%s\n",S);
        A[0][0]=S[0];
        row_cur=0;
        col_cur=0;
        valid[0][0]=1;
        dir=0;
        num=1;
//printf("num: %d count:%d\n",num,count);
    while(num<=count){


        if(dir%4==0){
            while(valid[row_cur+1][col_cur]==0){
                row_cur++;
                A[row_cur][col_cur]=S[num];
                num++;
                valid[row_cur][col_cur]=1;
            }
            dir++;
        }
        //printf("num: %d dir: %d count:%d\n",num,dir,count);
        if(dir%4==1){
            while(valid[row_cur][col_cur+1]==0){
                col_cur++;
                A[row_cur][col_cur]=S[num];
                num++;
                valid[row_cur][col_cur]=1;
            }
            dir++;
        }
        if(dir%4==2){
            while(valid[row_cur-1][col_cur]==0
                  &&row_cur-1>=0){
                row_cur--;
                A[row_cur][col_cur]=S[num];
                num++;
                valid[row_cur][col_cur]=1;
            }
            dir++;
        }
        if(dir%4==3){
            while(valid[row_cur][col_cur-1]==0
                  &&col_cur-1>=0){
                col_cur--;
                A[row_cur][col_cur]=S[num];
                num++;
                valid[row_cur][col_cur]=1;
            }
            dir++;
        }
    }
        /*for(i=0;i<width;i++){
            for(j=0;j<width;j++){
                printf("%c",A[i][j]);
            }
                printf("\n");
        }*/
        count_ans=0;
        for(i=0;i<width;i++){
            for(j=0;j<width;j++){
                ans[count_ans]=A[i][j];
                count_ans++;
            }
        }
        for(j=0;j<count_ans;j++){
            printf("%c",ans[j]);
        }
        printf("\n");
        /*intitialize*/
        start=0;
        count=0;
        memset(S,'\0',1000);
        memset(A,'\0',1600);
        memset(ans,'\0',1600);
        width=0;
        for(i=0;i<40;i++){
            for(j=0;j<40;j++){
                valid[i][j]=1;
            }
        }
        /*intitialize*/
        if(tmp==EOF){
            break;
        }
    }else{
        start=1;
        S[count]=tmp;
        count++;
    }
}

return 0;
}
