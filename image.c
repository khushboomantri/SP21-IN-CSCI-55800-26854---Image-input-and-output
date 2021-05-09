// Khushboo Mantri 
// multimedia class 
// assignment 1

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// global variables
# define Size 375000 //size in bytes
unsigned char data[Size], output1[Size], output2[Size] , output3[Size];
FILE *File1, *File2, *File3 , *File4;
	void main( )
	{	//opeaning raw file provided
		File1 = fopen("unesco750-1.raw","rb");
		if(File1 == NULL)
    {
       // error if file does not open
        printf("\n Unable to open file");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }
	// File open success message 
    printf("\n File opened successfully , Now performing opeartions ");
	
	/* Allocate memory for the array like this:
	int** array;
	array = malloc(n * sizeof(*array)); 
	//	Assuming `n` is the number of rows 
	if(!array) 
	//If `malloc` failed 
	{
	    fputs(stderr, ""Error allocating memory; Bailing out!"");
	    exit(-1);
	} */

		//reading the file 
		fread(data, 1, Size, File1);
		//close file
		fclose(File1);

		int i, j, m;
		// Store contents of file
		
	//print out pixel data 
    //extern void print_array(struct File1 *File1);
	int TemporaryData[Size] = {0};
	//this reverses the pixel 
	//extern void reverse_array(struct File1 *File1);
		int invert = 0;
		int add20 = 0;
		int add128 = 0;
	//free the memory used by the images pixel data
	//void free_array(unsigned char *pixel_array, struct File1 *File1);
		// Storing raw file in array
	   for(i = 0; i < Size; i++)
	   {
		   if (i > 100 && i < Size)
	   {
			TemporaryData[i] = data[i-9];
	   }		
		   
	   }
			for(i = 0; i < Size; i++)
			{
		   
			
			// performing fiven operation
			for(j = i, m = 0; m < 25 ; j++, m++)
			{
				// inverting image
				invert = 255 - TemporaryData[j];
				// adding 20 to pixel 
				add20 = TemporaryData[j]+20;
				// adding 128 to pixel value
				add128 = TemporaryData[j]+128;
			}
				//out put of invert
				output1[i] = invert;
				//output of addtion og 20pixel
				output2[i] = add20;
				//outpiut of addition of 128 pixel
				output3[i] = add128;
			}

		// Printing inverting image
		File2 = fopen("invert.raw","wb");
		//writing the output to the file
		fwrite(output1, 1, Size, File2);
		//closing the file after writing
		fclose(File2);
		// printing +20 to pixel 	
		File3 = fopen("add20.raw","wb");
		//writing the output to the file
		fwrite(output2, 1, Size, File3);
		//closing the file after writing
		fclose(File3);
		// Printing +128 to pixel 
		File4 = fopen("add128.raw","wb");
		//writing the output to the file
		fwrite(output3, 1, Size, File4);
		//closing the file after writing
		fclose(File4);
		
	}