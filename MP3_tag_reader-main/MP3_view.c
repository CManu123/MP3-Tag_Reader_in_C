/*
NAME = C MANU
DATE = 30/07/2026
DESCRIPTION = "MP3 TAG EDITOR AND VIEWER"
              1. A small C program to view and edit ID3v2 tags inside an MP3 file.

              2. Reads out tag values like Title, Artist, Album, Year and Comments.

              3. Lets you update a chosen tag (-t, -a, -A, -y, -c) with a new value.

              4. Checks the command line arguments so the program is used correctly.

              5. Writes changes to a temp MP3 file first, then swaps it in place of the original.

              6. Run with --help to see all supported options and how to use them.
*/


#include<stdio.h>
#include "MP3_header.h"
#include<string.h>
#include<stdlib.h>


// Function to display MP3 tag information
void mp3_view(int argc,char* argv[])
{
	FILE* fb = fopen(argv[2],"r");
	if(fb == NULL)
	{
		printf("File is not found :");
		exit(0);
	}

	// Verify MP3 header (must start with "ID3")
	char buffer[3];
	fread(buffer,sizeof(buffer),1,fb);
	buffer[3]='\0';

	if(!(strcmp(buffer,"ID3")))
	{
                printf("MP3 tag reader for ID3v2\n");
	}
	else
	{
		printf("Its Not MP3 File :\n");
		exit(0);
	}
	// Skip unnecessary header bytes
	fseek(fb,7,SEEK_CUR);

	// Read and display first 6 tags
	int i = 6;
	while(i)
	{
		char tag[4];
		fread(tag,sizeof(tag),1,fb);
		tag[4]='\0';

		int size;
		fread(&size,sizeof(size),1,fb);
		int new_size = convert(size);
	
	
		fseek(fb,3,SEEK_CUR);
		char content[new_size-1];
		fread(content,sizeof(content),1,fb);
		content[new_size-1]='\0';

		print_contents(tag,content);
		i--;
		if(i==0)
		{
		      
                printf("\n");

		}
	}
	fclose(fb);



}

// Function to convert integer from little-endian to big-endian
int convert(int size)
{
	unsigned char* ptr = (unsigned char*)&size;
	int s = sizeof(int);
	for(int i=0;i<s/2;i++)
	{
		char temp = ptr[i];
		ptr[i] = ptr[s-i-1];
		ptr[s-i-1]=temp;

	}
	return size;

}

// Function to print formatted tag and its value
void print_contents(char* tag,char* content)
{

	if(!(strcmp(tag,"TIT2")))
	{
		//printf("%s: %s\n",tag,content);
		printf("%-15s%-8s%-51s\n","TITLE",":",content);
	}
	if(!(strcmp(tag,"TPE1")))
	{
		//printf("%s: %s\n",tag,content);
		printf("%-15s%-8s%-51s\n","ARTIST",":",content);
	}
	if(!(strcmp(tag,"TALB")))
	{
		//printf("%s: %s\n",tag,content);
		printf("%-15s%-8s%-51s\n","ALBUM",":",content);
	}
	if(!(strcmp(tag,"TYER")))
	{
		//printf("%s: %s\n",tag,content);
		printf("%-15s%-8s%-51s\n","YEAR",":",content);
	}
	if(!(strcmp(tag,"TCON")))
	{
		//printf("%s: %s\n",tag,content);
		printf("%-15s%-8s%-51s\n","CONTENT",":",content);
	}
	if(!(strcmp(tag,"COMM")))
	{
		//printf("%s: %s\n",tag,content);
		printf("%-15s%-8s%-51s\n","COMMENTS",":",content);
	}
	

}
