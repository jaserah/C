#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>



void anagram(char firstWord[], char secondWord[]){
	int i;
	int j;
	int temporary;
	int length1;
	int length2;
	length1 = strlen(firstWord);
	length2 = strlen(secondWord);

	if (length1 != length2) {
		printf("%s is NOT an anagram of %s", firstWord, secondWord);
		exit(0);
	}
	for (i = 0; i < length1 + 1; i++) {
		for (j = i+1; j < length1; j++) {
			if (firstWord[i] > firstWord[j]) {
				temporary = firstWord[i];
				firstWord[i] = firstWord[j];
				firstWord[j] = temporary;
			}
			if (secondWord[i] > secondWord[j]) {
				temporary = secondWord[i];
				secondWord[i] = secondWord[j];
				secondWord[j] = temporary;
			}
		}
	}

	for (i = 0; i < length1; i++) {
		if (firstWord[i] != secondWord[i]) {
			printf("%s is NOT an anagram of %s", firstWord, secondWord);
			exit(0);
		}
	}
	printf("%s is an anagram of %s", firstWord, secondWord);

}

int main() {
	char firstWord[21];
	char secondWord[21];

	printf("Please enter the first word: ");
	scanf("%s", firstWord);

	printf("Please enter the second word: ");
	scanf("%s", secondWord);

	anagram(firstWord, secondWord);
	
	return 0;
}