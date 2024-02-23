/*Programmer: Joshua Jaggernauth
Date: 02/23/2024
Project: Lab Assignment 6 
*/
//This code reads test cases from a file "input.txt", each containing an array size followed by array elements. 
//For each case, it calculates the average of array elements and searches for it using binary search.
//It prints the index if found, otherwise, it prints that the value doesn't exist. 
//Finally, it repeats this process until all cases are processed.

#include <stdio.h>

#include <stdlib.h>

//Implementing binary search algorithm
int search(int numbers[], int low, int high, int value) {
  //Base case: If the range is invalid
  if (high < low) {
    return -1;
  }

  //Find the middle index
  int mid = low + (high - low) / 2;

  //If the element is present at the middle itself
  if (numbers[mid] == value) {
    return mid;
  }

  //If the element is smaller than mid, then it can only be present in the left subarray
  if (numbers[mid] > value) {
    return search(numbers, low, mid - 1, value);
  }

  //Else the element can only be present in the right subarray
  return search(numbers, mid + 1, high, value);
}

//Function to print the elements of an array
void printArray(int numbers[], int sz) {
  int i;
  printf("Number array : ");
  for (i = 0; i < sz; ++i) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}

int main(void) {
  int i, numInputs;
  float average;
  int value;
  int index;
  int * numArray = NULL;
  int countOfNums;
  FILE * inFile = fopen("input.txt", "r");

  //Check if the input file opened successfully
  if (inFile == NULL) {
    printf("Could not open file\n");
    return 1;
  }

  //Read the number of test cases from the input file
  fscanf(inFile, " %d\n", & numInputs);

  //Process each test case
  while (numInputs--> 0) {
    //Read the number of elements in the current test case
    fscanf(inFile, " %d\n", & countOfNums);
    //Allocate memory for the array dynamically
    numArray = (int * ) malloc(countOfNums * sizeof(int));
    average = 0;
    //Read the elements of the array from the input file
    for (i = 0; i < countOfNums; i++) {
      fscanf(inFile, " %d", & numArray[i]);
      average += numArray[i];
    }

    //Print the array elements
    printArray(numArray, countOfNums);
    //Calculate the average of array elements
    value = average / countOfNums;
    //Search for the average value in the array using binary search
    index = search(numArray, 0, countOfNums - 1, value);
    //Print the result of the search
    if (index >= 0) {
      printf("Item %d exists in the number array at index %d!\n", value, index);
    } else {
      printf("Item %d does not exist in the number array!\n", value);
    }

    //Free the memory allocated for the array
    free(numArray);
  }

  //Close the input file
  fclose(inFile);
  return 0;
}