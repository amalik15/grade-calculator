#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct grade
{
	int numberElm;
	char *category;
	double sum;
	double weight;
	struct grade *next;

}grade;


void Category(char input[], grade **root, char c[])
{
	
	grade *cur = *root;
	grade *pur = NULL;
	
	/*this will look through the nodes. It will print out and error message 
	if the category is already exists and will return to main without creating a new node.*/
	while (cur != NULL)
	{
		if (strcmp(input, cur->category) == 0) 
		{
			printf("category already exists\n");
			return;
		}
		
		else 
		{
			pur = cur;
			cur = cur->next;
		}
	}
	/* if the while loop complets than that means the category is not found 
	thus it will creat a new */
	
	
	/*this block of code will loke for the first space in the input string 
	in order to find the seperation between the category name and it's weight*/
	int i;
	int length = strlen(input);
	for (i = 0; i < length; i++)
	{
		if (input[i] == ' ') 
		{
			break;
		}
	}
	
	/*create a new vearable weight. Convert the part from the input string that is the 
	weight into a double. sSet that double equal to the weight/*/ 
	double weight = atof(input + (i + 1));
	
	//allocate memory for a new node
	grade *node = (grade*)malloc(sizeof(grade));
	
	//allocate memory and set the allocated memory to the name of the category
	char *catagory = (char*)malloc(sizeof(char) * (i + 1));
	strncpy(catagory, input + 1, i);
	
	//set values to new node
	node->category = catagory;
	strcpy(c, catagory);   //update string c
	node->weight = weight;
	node->numberElm = 0;
	node->sum = 0;
	node->next = NULL;
	
	//add node to the end of the likned list
	if (pur == NULL) 
	{
		*root = node;
	}
	
	else 
	{
		pur->next = node;
	}
}


void Fraction(char input[], grade **root, char c[])
{
	int i;
	grade *cur = *root;
	
	//this while loop is used to stop cur at the desired category
	while (cur != NULL)
	{
		if (strcmp(cur->category, c) == 0) 
		{
			break;
		}
		
		else 
		{
			cur = cur->next;
		}
	}

	/*if cur is null, the category was not found and it will print an error message and return to main. 
	this shouldn't be possible but I just put it as a precation*/
	if (cur == NULL) 
	{
		printf("category not found\n");
		return;
	}

	int length = strlen(input);

	for (i = 0; i < length; i++)
	{
		if (input[i] == '/') 
		{
			break;
		}
	}

	i++;
	double first = atof(input);
	double secound = atof(input + i);
	
	//if the second number is zero, the fraction will not be added
	if (secound == 0)
	{
		printf("improper fraction\n");
		return;
	}

	double fraction = first / secound;
	
	//update node for that category
	cur->sum = (cur->sum) + fraction;
	cur->numberElm = (cur->numberElm) + 1;
}


void Decimal(char input[], grade **root, char c[])
{
	int i;
	grade *cur = *root;
	
	//this while loop is used to stop cur at the desired category
	while (cur != NULL)
	{
		if (strcmp(cur->category, c) == 0) 
		{
			break;
		}
		
		else 
		{
			cur = cur->next;
		}
	}
	
	/*if cur is null, the category was not found and it will print an error message and return to main. 
	this shouldn't be possible but I just put it as a precation*/
	if (cur == NULL) 
	{
		printf("category not found\n");
		return;
	}

	double decimal = atof(input);
	
	//update node for that category
	cur->sum = (cur->sum) + decimal;
	cur->numberElm = (cur->numberElm) + 1;
}


void Percent(char input[], grade **root, char c[])
{
	int i;
	grade *cur = *root;
	
	//this while loop is used to stop cur at the desired category
	while (cur != NULL)
	{
		if (strcmp(cur->category, c) == 0) 
		{
			break;
		}
		
		else 
		{
			cur = cur->next;
		}
	}

	/*if cur is null, the category was not found. this shouldn't be possible but it is just a precation*/
	if (cur == NULL) {
		printf("category not found\n");
		return;
	}

	double percent = (atoi(input)) / 100.0;
	
	//update node for that category
	cur->sum = (cur->sum) + percent;
	cur->numberElm = (cur->numberElm) + 1;
}

//function that would return 1 if the string inputed is a category
int isCategory(char input[])
{
	char category = '$';
	char *ret;

	ret = strchr(input, category);

	if (ret == NULL) 
	{
		return 0;
	}

	return 1;
}


//function that would return 1 if the string inputed is a function
int isFraction(char input[])
{
	char divison = '/';
	char *ret;
	
	//looks for a "/" in the string inputed or returns null if it doesn't find it
	ret = strchr(input, divison);

	if (ret == NULL) 
	{
		//return false
		return 0;
	}
	
	//return true
	return 1;
}

//function that would return 1 if the string inputed is a decimal
int isDecimal(char input[])
{
	char decimal = '.';
	char *ret;
	
	//looks for a "." in the string inputed or returns null if it doesn't find it
	ret = strchr(input, decimal);

	if (ret == NULL) 
	{
		//return false
		return 0;
	}
	
	//return true
	return 1;
}

//function that would return 1 if the string inputed is a percent
int isPercent(char input[])
{
	char percent = '%';
	char *ret;

	//looks for a "%" in the string inputed or returns null if it doesn't find it
	ret = strchr(input, percent);

	if (ret == NULL) 
	{
		//return false
		return 0;
	}
	
	//return true
	return 1;
}

//calculate and prints out grade
void printGrade(grade *root)
{

	grade *cur = root;
	double score = 0.0;
	double weight = 0.0;
	double grade; 
	
	//sums out all the weights and the weighted grades for each individual category 
	while (cur != NULL)
	{
		score = score + (((cur->sum) / (cur->numberElm))*cur->weight);
		weight = weight + cur->weight;
		cur = cur->next;
	}
	
	//cheacks if the wight is not zero
	if(weight != 0.0)
	{
		grade = score / weight;
	}
	
	//makes the grade 0 if the weight total is 0
	else
	{
		grade = 0.0;
	}
	
	
	//prints grde with 3 significant digits
	printf("Grade: %.3lf%%\n", (grade*100));
	
}


int main()
{
	printf("This is a weighted grade calculator\n");

	grade *Node = NULL;
	char c[256]; 

	char input[256];
	int linesize = sizeof(input) / sizeof(input[0]);

	//get user input
	printf(">> enter a grade or a new category (Enter to quit): ");
	fgets(input, linesize, stdin);
	input[strcspn(input, "\r\n")] = '\0';
	
	//checks if the user only pressed  the return key
	while (strlen(input) > 0)
	{
		//checks is the string inputted is a category
		if (isCategory(input) == 1)
		{
			//call a function to add category 
			Category(input, &Node, c);
		}
		
		//checks is the string inputted is a Fraction
		else if (isFraction(input) == 1)
		{
			//call a function to convert string to double
			Fraction(input, &Node, c);
		}
		
		//checks is the string inputted is a Decimal
		else if (isDecimal(input) == 1)
		{
			//call a function to convert string to double
			Decimal(input, &Node, c);
		}
		
		//checks is the string inputted is a Percent
		else if (isPercent(input) == 1)
		{
			//call a function to convert string to double
			Percent(input, &Node, c);
		}
		
		//get next user input
		printf(">> enter a grade or a new category (Enter to quit): ");
		fgets(input, linesize, stdin);
		input[strcspn(input, "\r\n")] = '\0';
	}
	
	//call a function  to calculate and print grade
	printGrade(Node);

	return 0;
}
