//Author:Raul Delgado
//Date:5/4/25
//Purpose:Project 10

#include <stdio.h>
#include <stdbool.h>


#define LEN 5
#define GUESS 6
#define FILENAME "mystery.txt"

void compare(char word[],char guess[],bool *dec);
void display(char guess[][LEN+1],int num,char word[]);
bool valid(char guess[]);
int getword(char word[]);
void check(char guess[]);
char getguess(char guess[]);
char upper(char c);
char lower(char c);

int main(){
	char answer[LEN],guess[LEN];
	getword(answer);
	bool over=false;
	int guesses=0;
	while(guesses<GUESS && !over){
	getguess(guess);
}
	return 0;
}

int getword(char word[]){
	FILE *file=fopen("mystery.txt","r");
	if(file==NULL){
		printf("Could not open");
		return 0;
	} 
	fscanf(file,"%5s",word);
	fclose(file);
}

char getguess(char guess[]){
	bool valid=false;
	while(!valid){
		printf("Enter your first guess:");
		scanf("%5s",guess);
		}
		int i;
		while ((i=getchar())!='\n' && i!= EOF);
		
		if(!valid){
			printf("Invalid Guess");
		}		
	}

bool valid(char guess[]){
	int guesslen=0;
	while(guess[guesslen]!=0){
		guesslen++;
	}
	if(guesslen!=LEN){
		return false;
	}
	for (int i=0; i<LEN;i++){
		if(guess[i]!='A'&& guess[i]!='Z'&& guess[i]!='a' && guess[i] != 'z'){
			return false;
		}
	}
	return true;
}

void display(char guess[][LEN+1],int num,char word[]){
	for(int i =0;i<num;i++){
		char hint[LEN+1];	
		for(int k=0;k<LEN;k++){
			hint[k]=' ';
	}
	hint[LEN]='\0';
	for(int j=0;j<LEN;j++){
		if(lower(guess[i][j]==lower(word[j]))){
			printf("%c",upper(guess[i][j]));
		} else{
			printf("%c",lower(guess[i][j]));
		}
	} 
	printf("\n");
	for(int y=0;y<LEN;y++){
		if(lower(guess[i][y])==lower(word[y])){
			continue;
		}
		bool spot=false;
	for(int k=0;k<LEN;k++){
		if(lower(guess[i][y]==lower(word[k]))&&lower(guess[i][k]!=lower(guess[i][k]))){
			spot=true;
			break;
			}
		}
		if(spot){
			hint[y]='^';
		}
			printf("%s\n",hint);
		}
	}
}

void compare(char word[],char guess[],bool *dec){
	*dec=true;
	for(int i=0; i<LEN;i++){
	if(lower(guess[i])!= lower(word[i])){
		*dec=false;
		return;
	}
	}
}
char lower(char c){
	if (c >='a'&&c <= 'z'){
		return c-('a'-'A');
	}
	return c;
}

char upper(char c){
	if (c >='a'&&c <= 'z'){
		return c+('a'-'A');
	}
	return c;
}
