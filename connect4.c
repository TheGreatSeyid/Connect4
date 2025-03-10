#include <stdio.h>
#include <assert.h>
#include <string.h>

void mapViz(char map[][9]){
	for (int i = 0;i < 8;i++){
		for (int j = 0;j < 9;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
}

void move(char move, char map[][9]){
	int column;

	if (move == 'r')
		puts("Player 1 play");
	else
		puts("PLayer 2 play");

	puts("Enter column you want to enter your disk");
	scanf("%d",&column);

	for (int i = 1;i < 6;i++){
		if (map[i+1][column+1] != ' '){
			if (move == 'r')
				map[i][column+1] = '*';
			else
				map[i][column+1] = 'o';
		}
	}

}


int main(){
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

	mapViz(map);
	return 0;

}
