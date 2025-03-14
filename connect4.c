#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
char map[8][9]={
    {{' '},{'1'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{' '}},
    {{'6'},{' '},{' '},{' '},{' '},{' '},{' '},{' '},{'6'}},
    {{'5'},{' '},{' '},{' '},{' '},{' '},{' '},{' '},{'5'}},
    {{'4'},{' '},{' '},{' '},{' '},{' '},{' '},{' '},{'4'}},
    {{'3'},{' '},{' '},{' '},{' '},{' '},{' '},{' '},{'3'}},
    {{'2'},{' '},{' '},{' '},{' '},{' '},{' '},{' '},{'2'}},
    {{'1'},{' '},{' '},{' '},{' '},{' '},{' '},{' '},{'1'}},
    {{' '},{'1'},{'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{' '}}
};


int WinCheck(char map[][9],char answer){
    int point=0;
    //horizontal check
    for(int row=6;row>0;row--){
        for(int column=7;column>0;column--){
            if(map[row][column]==answer){
                point++;
            }
            else{
                point=0;
            }
        }
    }
    if(point>=4){
        return 100;
    }
    //vertical check
    for(int column=7;column>0;column--){
        for(int row=6;row>0;row--){
            if(map[row][column]==answer){
                point++;
            }
            else{
                point=0;
            }
        }
    }
    if(point>=4){
        return 100;
    }
    //diagonal check
    
}
void mapViz(char map[][9]){
	for (int i = 0;i < 8;i++){
		for (int j = 0;j < 9;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
}
void Player1(char map[][9],char answer){
    printf("Which column you want: ");
    int choice;
    scanf("%d",&choice);
    int row=6;
    while (map[row][choice]!=' ')
    {
        row-=1;
    }
    map[row][choice]=answer;
    
    mapViz(map);
}
void Player2(char map[][9],char answer){
    printf("Which column you want: ");
    int choice;
    scanf("%d",&choice);
    int row=6;
    if(answer=='*'){
        answer='o';
    }
    else{
        answer='*';
    }
    while (map[row][choice]!=' ')
    {
        row-=1;
    }
    map[row][choice]=answer;
    
    mapViz(map);
}

void Computer(char map[][9],char answer){
    srand(time(NULL));
    int column=rand() % 7 + 1;
    int row=6;
    if(answer=='*'){
        answer='o';
    }
    else{
        answer='*';
    }
    while (map[row][column]!=' ')
    {
        row-=1;
    }
    map[row][column]=answer;
    
    mapViz(map);
}

int main(){
	
    mapViz(map);
    char answer;
    printf("Hello, plz choose 1-player or 2-players game? 1/2");
    scanf("%c",&answer);
    if(answer=='1'){
        do
        {
            printf("Which color you choose r/y: ");
            scanf(" %c",&answer);
        } while (toupper(answer)!='R'&& toupper(answer)!='Y');
        if(toupper(answer)=='R'){
            answer='*';
        }
        else{
            answer='o'; 
        }
        while(WinCheck(map,answer)!=100){
            Player1(map,answer);
            Computer(map,answer);
        }
        printf("You won");
    }
    else if(answer=='2'){
        do
        {
            printf("Which color you choose r/y: ");
            scanf(" %c",&answer);
        } while (toupper(answer)!='R'&& toupper(answer)!='Y');
        if(toupper(answer)=='R'){
            answer='*';
        }
        else{
            answer='o'; 
        }
        while(WinCheck(map,answer)!=100){
            Player1(map,answer);
            Player2(map,answer);
        }
        printf("You won");
    }  
    return 0;

}


