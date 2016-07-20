#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char S[1010];
char A[40][40];
int visit[40][40];
char ans[1010];

int main(){

char tmp;
int start=0;
int num_s=0;
int width,dir,cur,row_cur,col_cur;
int c_ans;
int i,j;

for(i=0;i<40;i++){
    for(j=0;j<40;j++){
        visit[i][j]=1;
        A[i][j]=' ';
    }
}
for(i=0;i<1010;i++){
    S[i]=' ';
    ans[i]=' ';
}

while(1){
    tmp=getchar();

    if(start==0&&tmp=='\n'){
        printf("\n");
    }else if(tmp==EOF){
        break;
    }else if(tmp!='\n'){
        start=1;
        S[num_s]=tmp;
        num_s++;
    }else if(start==1&&tmp=='\n'){

        S[num_s]='\0';
        //printf("%s\n",S);
        for(i=0;i<40;i++){
            if(i*i>=num_s){
                width=i;
                break;
            }
        }
        for(i=0;i<width;i++){
            for(j=0;j<width;j++){
                visit[i][j]=0;
            }
        }
        S[num_s]=' ';
        A[0][0]=S[0];
        visit[0][0]=1;
        row_cur=0;
        col_cur=0;
        dir=0;
        cur=1;
        while(cur<num_s){

            if((dir%4)==0){
                while(visit[row_cur+1][col_cur]==0){
                    row_cur++;
                    A[row_cur][col_cur]=S[cur];
                    visit[row_cur][col_cur]=1;
                    cur++;
                }
                dir++;
            }

            if((dir%4)==1){
                while(visit[row_cur][col_cur+1]==0){
                    col_cur++;
                    A[row_cur][col_cur]=S[cur];
                    visit[row_cur][col_cur]=1;
                    cur++;
                }
                dir++;
            }

            if((dir%4)==2){
                while(visit[row_cur-1][col_cur]==0&&
                      row_cur-1>=0){
                    row_cur--;
                    A[row_cur][col_cur]=S[cur];
                    visit[row_cur][col_cur]=1;
                    cur++;
                }
                dir++;
            }

            if((dir%4)==3){
                while(visit[row_cur][col_cur-1]==0&&
                      col_cur-1>=0){
                    col_cur--;
                    A[row_cur][col_cur]=S[cur];
                    visit[row_cur][col_cur]=1;
                    cur++;
                }
                dir++;
            }
        }
        c_ans=0;
        for(i=0;i<width;i++){
            for(j=0;j<width;j++){
                ans[c_ans]=A[i][j];
                c_ans++;
            }
        }
        for(i=c_ans-1;i>=0;i--){
            if(ans[i]!=' '){
                ans[i+1]='\0';
                break;
            }
        }
        printf("%s\n",ans);
        /*initialize*/
        start=0;
        num_s=0;
        for(i=0;i<40;i++){
            for(j=0;j<40;j++){
                visit[i][j]=1;
                A[i][j]=' ';
            }
        }
        for(i=0;i<1010;i++){
            S[i]=' ';
            ans[i]=' ';
        }
    }
}
return 0;
}
