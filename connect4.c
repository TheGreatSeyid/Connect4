#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
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

void mapViz(char map[][9]){
	for (int i = 0;i < 8;i++){
		for (int j = 0;j < 9;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
}
void mapColor(char map[][9],char answer){
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
    main();
}
int main(){
	
    mapViz(map);
    printf("Which color you choose r/y: ");
    char answer;
    scanf(" %c",&answer);
    if(toupper(answer)=='R'){
        answer='*';
    }
    if(toupper(answer)=='Y'){
        answer='o';
    }
    mapColor(map,answer);
    

    return 0;

}
