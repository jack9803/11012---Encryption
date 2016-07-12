#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char S[1010];
char A[40][40];
char ans[1600];
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
                A[i][j]=' ';
            }
            }
        for(i=0;i<40;i++){
            for(j=0;j<40;j++){
                valid[i][j]=1;
            }
        }
        for(i=0;i<1600;i++){
            ans[i]=' ';
        }
        for(i=0;i<1010;i++){
            S[i]=' ';
        }


while(1){


    tmp=getchar();
    if(tmp=='\n'&&start==0){
        printf("\n");
    }
    else if (tmp==EOF) {
        break;
    }
    else if((tmp=='\n')&&start==1){

        for(i=0;i<40;i++){
            if((i*i)>=count){
                width=i;
                break;
            }
        }
        for(i=0;i<width;i++){
            for(j=0;j<width;j++){
                valid[i][j]=0;
            }
        }

        A[0][0]=S[0];
        row_cur=0;
        col_cur=0;
        valid[0][0]=1;
        dir=0;
        num=1;
    while(num<count){
        if(dir%4==0){
            while(valid[row_cur+1][col_cur]==0){
                row_cur++;
                A[row_cur][col_cur]=S[num];
                num++;
                valid[row_cur][col_cur]=1;
            }
            dir++;
        }
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
        count_ans=0;
        for(i=0;i<width;i++){
            for(j=0;j<width;j++){
                ans[count_ans]=A[i][j];
                count_ans++;
            }
        }
        for(j=count_ans-1;j>=0;j--){
            if(ans[j]!=' '){
                ans[j+1]='\0';
                printf("%s",ans);
                j=-1;
            }
        }

            printf("\n");

        /*intitialize*/
        start=0;
        count=0;
        for(i=0;i<1600;i++){
            ans[i]=' ';
        }
        for(i=0;i<1010;i++){
            S[i]=' ';
        }
        width=0;
        for(i=0;i<40;i++){
            for(j=0;j<40;j++){
                valid[i][j]=1;
            }
        }
        for(i=0;i<40;i++){
            for(j=0;j<40;j++){
                A[i][j]=' ';
            }
            }
        /*intitialize*/
    }else{
        start=1;
        S[count]=tmp;
        count++;
    }
}
return 0;
}
