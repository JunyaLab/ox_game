# include <stdio.h>

#define IMAX 3

int main(){

    int a, o, x, i=0, j=0, val=1, judge=0, flag=0, parity=0, change=0, count=1, MAP[IMAX][IMAX];

    printf("\n");

// ox表を表示
        for(i=0; i<IMAX; i++){
            printf("     ");
            for(j=0; j<IMAX; j++){
                MAP[i][j]=val;
                printf("%d ", MAP[i][j]);    
                val++;                
            }
            printf("\n");
        }
    
    while(count < 10){
        change=0;
        if(parity%2==0){ // oの処理
            printf("\n oの番です。番号を選択してください。 -> ");
        }else{ // xの処理
            printf("\n xの番です。番号を選択してください。 -> ");
            }
            scanf("%d", &a);
            if(0<a&&a<10){
                for(i=0; i<IMAX; i++){
                    for(j=0; j<IMAX; j++){
                            if(MAP[i][j]==a){
                            if(parity%2==0){
                            MAP[i][j]=10;
                                change=1;
                            }else{
                                MAP[i][j]=-10;
                                change=1;
                            }
                        }
                    }
                }
            }else{
                printf(" 1~9の数字のみ有効です。\n");
                continue;
            }
        if(change==0){
            printf(" 既に選択されたマスなので、入力は無効です。\n");
            continue;
        }else if(change==1){
            parity++;
        }
        
// 選択結果を表示
        printf("\n");
        for(i=0; i<IMAX; i++){
            printf("     ");
            for(j=0; j<IMAX; j++){
                if(MAP[i][j]==10){
                    printf("\x1b[33mo \033[m");
                }else if(MAP[i][j]==-10){
                    printf("\x1b[35mx \033[m");
                }else{
                    printf("%d ", MAP[i][j]);    
                }
            }
            printf("\n");
        }
        printf("\n");

// 勝利判定

    // 横一列
        for(i=0; i<IMAX; i++){
            judge=0;
            for(j=0; j<IMAX; j++){
                judge += MAP[i][j];
                if(judge==30){
                    flag=1;
                    break;
                }else if(judge==-30){
                    flag=2;
                    break;
                }
            }
        }        
    // 縦一列
        for(i=0; i<IMAX; i++){
            judge=0;
            for(j=0; j<IMAX; j++){
                judge += MAP[j][i];
                if(judge==30){
                    flag=1;
                    break;
                }else if(judge==-30){
                    flag=2;
                    break;
                }
            }
        }
    // 斜め一列
        if(MAP[0][0]+MAP[1][1]+MAP[2][2]==30||MAP[0][2]+MAP[1][1]+MAP[2][0]==30){
            flag=1;
        }else if(MAP[0][0]+MAP[1][1]+MAP[2][2]==-30||MAP[0][2]+MAP[1][1]+MAP[2][0]==-30){
            flag=2;
        }
    // 結果の出力
        if(flag==1){
            printf("\x1b[31m oの勝ちです。\033[m\n\n");
            break;
        }else if(flag==2){
            printf("\x1b[31m xの勝ちです。\033[m\n\n");
            break;
        }else{
            if(count==9){
                printf("\x1b[31m この勝負は引き分けです。\033[m\n\n");
            }
        }
    
        count++;
    }

    return 0;
}