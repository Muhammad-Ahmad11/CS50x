// Implements a dictionary's functionality
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include "dictionary.h"
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 99999;
//counter for total number of words
int totalwords = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    if(word != NULL)
    {
        //hash word to obtain hash value
        //Access linked list at that hash value
        //looking through linked list for that particular word
        node *position = table[hash(word)];
        while(position != NULL)
        {
              if(!(strcasecmp(position->word, word))) //this strcasecmp compares the word in dictionary with word in node and is case insensitive
              {
                  return true;  //if found returns true otherwise check for next location/position
              }
              else
              {
                  position = position->next;
              }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //This is dan Berstain algorithm
    int value = 0;
    int wordlength = strlen(word);
    for(int i = 0 ; i < wordlength ; i++)
    {
       value =  value * 37 + toupper(word[i]);
    }
    return value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input = fopen(dictionary, "r");
    char text[LENGTH + 1];
    //1 in added to length its is because of Null chracter '\0'
    if(input != NULL)
    {
      //reading words until pointer reaches the end of file
      while(fscanf(input,"%s",text) != EOF)
      {
           node *n = malloc(sizeof(node));
           if(n != NULL)
           {
             strcpy(n->word,text);
             int hash_value = hash(n->word); //hash the array to get the index of the array(hash value)
             n->next = table[hash_value];
             table[hash_value] = n; //table is pointing to what node n is pointing to and updating the list
             totalwords += 1; //This will count total number of words
           }
           else
           {
               return false; //this will execute if memory runs out than malloc return NULL
           }
      }
    }
    else
    {
      return false;
    }
    fclose(input);  //Closing the file
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return totalwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int i = 0;
    while(i < N)
    {
         if(table[i] != NULL)  //checking if our current location in table is either pointing to some key word or just NULL
         {
            node *position = table[i]->next;  //stores the next location to a node pointer
            free(table[i]); //removing that location whcih is not null
            table[i] = position;
         }
         i++;
    }
    return true;
}
