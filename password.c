#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define N 12

void passwordGen(char *password)
{
	int random = 0;

	srand((unsigned int)(time(NULL)));

	char num[] = "0123456789";

	char symbols[] = "?*&^!$@#";

	char s_letters[] = "abcdefghijklmnopqrstuvwxyz";

	char c_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	random = rand() % 4;

	printf("Your password: ");

	for(int i = 0; i < N; i++)
	{
		if(1 == random)
		{
			password[i] = num[rand() % 10];
			random = rand() % 4;
			printf("%c", password[i]);
		}
		else if(2 == random)
		{
			password[i] = symbols[rand() % 8];
			random = rand() % 4;
			printf("%c", password[i]);
		}
		else if(3 == random)
		{
			password[i] = s_letters[rand() % 26];
			random = rand() % 4;
			printf("%c", password[i]);
		}
		else
		{
			password[i] = c_letters[rand() % 26];
			random = rand() % 4;
			printf("%c", password[i]);
		}
	}
}

int main(int argc, char *argv[])
{
	char password[N];

	FILE *fp;

	if(argc != 3)
	{
		puts("Improper number of Arguments!");
		exit(1);
	}

	passwordGen(password);

	fp = fopen(argv[2], "a");

	if(fp == NULL)
	{
		perror(argv[2]);
		printf("\n");
		exit(2);
	}

	fputs(argv[1], fp);
	fputs(" - ", fp);

	for(int i = 0; i < N; i++)
	{
		fputc(password[i], fp);
	}

	fputs("\n", fp);
	printf("\n");

	fclose(fp);

	return 0;
}
