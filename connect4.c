#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

int winstrike=0;


bool Available(char map[][9], int choice){
    if(choice>7 || choice<1){
        return false;
    }
    if(map[1][choice]!=' '){
        return false;
    }
    return true;
}

int Advice(char map[][9],char answer){
    int colu=1;
    int point = 0;
    int maxpoint=0;

    // horizontal check
    for (int row = 6; row > 0; row--) {
        point = 0;
        for (int column = 1; column <= 7; column++) {
            if (map[row][column] == answer) {
                point += 1;
            } else {
                point = 0;
            }
            if (point > 0) {
                if(map[row][column-1]==' ' || map[row][column+1]==' '){
                    if(maxpoint<point){
                        maxpoint=point;
                        if(map[row][column-1]==' '){
                            colu=column-1;
                        }
                        else if(map[row][column+1]==' '){
                            colu=column+1;
                        }
                    }

                }

                    
            }
        }
    }

    // vertical check
    for (int column = 1; column <= 7; column++) {
        point = 0;
        for (int row = 6; row > 0; row--) {
            if (map[row][column] == answer) {
                point += 1;
            } else {
                point = 0;
            }
            if (point > 0) {
                if(map[row-1][column]==' '){
                    if(maxpoint<point){
                        maxpoint=point;
                        if(map[row-1][column]==' '){
                            colu=column;
                        }
                    }  
                }
            }
        }
    }

    // diagonal check (bottom-left to top-right)
    for (int row = 6; row > 0; row--) {
        for (int column = 1; column <= 7; column++) {
            point = 0;
            for (int i = 0; i < 4; i++) {
                if (row - i > 0 && column + i <= 7 && map[row - i][column + i] == answer) {
                    point += 1;
                } else {
                    break;
                }
                if (point > 0) {
                    if(map[row-i-1][column+i+1]==' '){
                        if(maxpoint<point){
                            maxpoint=point;
                            if(map[row-i-1][column+i+1]==' '){
                                colu=column;
                            }
                        }
                    }
                    
                }
            }
        }
    }

    // diagonal check (from left down to right) 
    for (int row = 6; row > 0; row--) {
        for (int column = 7; column > 0; column--) {
            point = 0;
            for (int i = 0; i < 4; i++) {
                if (row - i > 0 && column - i > 0 && map[row - i][column - i] == answer) {
                    point += 1;
                } else {
                    break;
                }
                if (point > 0) {
                    if(map[row-i-1][column-i-1]==' '){
                        if(maxpoint<point){
                            maxpoint=point;
                            if(map[row-i-1][column-i-1]==' '){
                                colu=column;
                            }
                        }
                    }
                    
                }
            }
        }
    }
	return colu;
}


int WinCheck(char map[][9], char answer) {
    int point = 0;

    // horizontal check
    for (int row = 6; row > 0; row--) {
        point = 0;
        for (int column = 1; column <= 7; column++) {
            if (map[row][column] == answer) {
                point += 1;
            } else {
                point = 0;
            }
            if (point >= 4) {
                return 100;
            }
        }
    }

    // vertical check
    for (int column = 1; column <= 7; column++) {
        point = 0;
        for (int row = 6; row > 0; row--) {
            if (map[row][column] == answer) {
                point += 1;
            } else {
                point = 0;
            }
            if (point >= 4) {
                return 100;
            }
        }
    }

    // diagonal check (bottom-left to top-right)
    for (int row = 6; row > 0; row--) {
        for (int column = 1; column <= 7; column++) {
            point = 0;
            for (int i = 0; i < 4; i++) {
                if (row - i > 0 && column + i <= 7 && map[row - i][column + i] == answer) {
                    point += 1;
                } else {
                    break;
                }
                if (point >= 4) {
                    return 100;
                }
            }
        }
    }

    // diagonal check (from left down to right) 
    for (int row = 6; row > 0; row--) {
        for (int column = 7; column > 0; column--) {
            point = 0;
            for (int i = 0; i < 4; i++) {
                if (row - i > 0 && column - i > 0 && map[row - i][column - i] == answer) {
                    point += 1;
                } else {
                    break;
                }
                if (point >= 4) {
                    return 100;
                }
            }
        }
    }

    return 0;
}


void mapViz(char map[][9]){
	for (int i = 0;i < 8;i++){
		for (int j = 0;j < 9;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
}

void Player1(char map[][9],char answer){
    int choice;
    int row=6;
    printf("%d is good idea\n",Advice(map,answer));
    do{
        printf("Please choose column: ");
        scanf("%d",&choice);
    }while(Available(map,choice)==false);
    

    while (map[row][choice]!=' ')
    {
        row-=1;
        
    }
    map[row][choice]=answer;
    winstrike=WinCheck(map,answer);
    mapViz(map);
    
}

void Player2(char map[][9],char answer){
    int choice;
    int row=6;
    if(answer=='*'){
        answer='o';
    }
    else{
        answer='*';
    }
    printf("%d is good idea\n",Advice(map,answer));
    do{
        printf("Please choose column: ");
        scanf("%d",&choice);
    }while(Available(map,choice)==false);

   
    while (map[row][choice]!=' ')
    {
        row-=1;
    }
    map[row][choice]=answer;
    winstrike=WinCheck(map,answer);
    mapViz(map);
    
}

void Computer(char map[][9],char answer){
    srand(time(NULL));
    if(answer=='*'){
        answer='o';
    }
    else{
        answer='*';
    }
    int choice=Advice(map,answer);
    int row=6;
    /*do{
        choice=Advice(map,answer);
    }while(Available(map,choice)==false);*/

    
    while (map[row][choice]!=' ')
    {
        row-=1;
    }
    map[row][choice]=answer;
    winstrike=WinCheck(map,answer);
    mapViz(map);
}

int main(){
	
    mapViz(map);
    char answer;
    printf("Hello, plz choose 1-player or 2-players game? 1/2: ");
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
        while(winstrike!=100){
            Player1(map,answer);
            if(winstrike==100){
                printf("Player 1 won ");
                return 0;
            }
            Computer(map,answer);
        }
        printf("Computer won");
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
        while(winstrike!=100){
            Player1(map,answer);
            if(winstrike==100){
                printf("Player 1 won");
                return 0;
            }
            
            Player2(map,answer);
        }
        printf("Player 2 won");
    }  
    return 0;

}
