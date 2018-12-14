//Program: Sieve of Eratosthenes
//Author: Joseph Castrejon

//License:MIT

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void FindPrimes(unsigned long int PrimeRange,int CMDFlag);

int main(int argc, char *argv[])
{

    //If used with command line arguments
	if(argc == 2)
	{
		unsigned long int Arg1 = atol(argv[1]);	
		printf("Sieve of Eratosthenes by JC\n");
		FindPrimes(Arg1,1);
		exit(0);	
	}
	
	unsigned long int UserInput;
	printf("Size of \"int\" in bytes: %lu bytes\n", sizeof(UserInput));
			
	//Get the user specified range
	printf("Enter the integer index\nto find prime numbers to: ");
	scanf("%lu",&UserInput);
	printf("Range: 1 - %lu\n", UserInput);
	
	FindPrimes(UserInput,0);
	

	return 0;
}

void FindPrimes(unsigned long int PrimeRange,int CMDFlag)
{
	char SeeList;
	//Check if there is available memory to find the primes.
	printf("Allocating %lu bytes of memory...\n", PrimeRange*sizeof(int));
	int *NumberList = (int*) malloc((PrimeRange)*sizeof(int));		 

	if(NumberList == NULL)
	{
		printf("Not enough memory to perform operation!");
		exit(-1);	
	}	
		
	printf("Initializing List...\n");
	for(unsigned long int x = 0; x < PrimeRange; x++)
	{
		NumberList[x] = 1;
	}

	printf("Array Initialized.\n");
	



	//Start Removing Primes	
	printf("Finding primes...");
	for(unsigned long int i = 2; i < (int) sqrt(PrimeRange); i++)
	{
		
		if(NumberList[i])
		{
		
			for(int x = i; i*x < PrimeRange; x++)
			{
				NumberList[x*i]=0;			
			}
		}
	}
		
	if(CMDFlag == 0){
		printf("Primes Found. See List? [Y/N]? ");
		scanf(" %c", &SeeList);
	
		if(SeeList == 'Y' || SeeList == 'y')
		{
			for(unsigned long int x = 0; x < PrimeRange; x++)
			{
				if(NumberList[x] != 0 && x > 1)
					printf("Prime Number : %lu\n",x);
			}	
		}
	}
	else if(CMDFlag == 1)
	{
		printf("\n");
		for(unsigned long int x = 0; x < PrimeRange; x++)
		{
				if(NumberList[x] != 0 && x > 1){
					printf("Prime Number : %lu\n",x);
				}
		}	
	}
	
	//Deallocate the memory 
	free(NumberList);		



}
/*
void ResultToFile(unsigned long int List[], unsigned long int Bound)
{
	FILE *Result;
	Result = fopen("Result.txt","w");
	for(unsigned long int x = 0; x < Bound; x++)
	{
		if(NumberList[x] != 0)
			fprintf("Prime Number : %lu\n",NumberList[x]);
	}	
	
	fclose(Result);

}
*/
