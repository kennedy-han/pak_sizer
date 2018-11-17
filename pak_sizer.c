/***************************************************************
 * Name:      pack_sizer.c
 * Purpose:   Code for Console 
 * Author:    DevNP (dev.necropan@gmail.com)
 * Created:   2018-11-17
 * Copyright: DevNP (devnp.net)
 * License: MIT
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_usage(const char* argv0) {
	printf("Usage: %s output.pak\n", argv0);	
	return 0;
}

int main(int argc, char** argv) {
	FILE *fpin;
	int blok;
	unsigned long int len,sum;	//1 607		
	unsigned long int maxSize = 545259520;//всего записать 545 259 520 байт	
	///1024
	char  empty[1024] = {0};
	
	if (argc < 2) {
		print_usage(argv[1]);
		exit(0);
	}
	
	fpin = fopen(argv[1], "r+b");
	
	if (fpin == NULL) {
		printf("Can not read: %s\n",argv[1]);
		exit(0);
	}
	fseek(fpin, 0, SEEK_END);	
	len = ftell(fpin);	
	printf("Original file size %d bytes\n", (int)len);
	
	if(len<maxSize){
		sum = maxSize-len;		
		blok = sum/1024;		
		for (int i=0; i<blok; i++){
			fwrite(empty, 1024,  1, fpin);		
		}
		printf("Add size of %d bytes\n",  (int)sum);	
		
	}else printf("is Not Added size of %d bytes\n",  (int)len);	
		
	printf("Total size of %d bytes\n",  (int)maxSize);	
    fclose(fpin);
	return 0;
}