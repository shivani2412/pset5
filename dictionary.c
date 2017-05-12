/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<stdio.h>
#include<ctype.h>
#include<strings.h>
#include "dictionary.h"

int hash (const char *word);
typedef struct node
{
    char *word[27];
    struct node*next;
}node;
int count=0;
node *hashtable[27];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE*spell=fopen(dictionary,"r");
    if(spell==NULL)
    return false;
    while(fscanf(spell,"%s\n",word)!=EOF)
    {
         
        
        node *new = malloc(sizeof(node));

        
        new->word = malloc(strlen(word) + 1);

    
        strcpy(new->word, word);

        
        int hash_1 = hash(word);

        
        if (hashtable[hash_1] == NULL)
        {
            hashtable[hash_1] = new;
            new->next = NULL;
        }

        
        else
        {
            new->next = hashtable[hash_1];
            hashtable[hash_1] = new;
        }

        // count words
        count++;
    }

    // close dictionnary
    fclose(spell);

    // that's all folks!
    return true;
}


int hash(const char*word)
{
    int j=0;
    for(int i=0;i<word[i]!='/0';i++)
    {
        j=j+tolower(word[i]);
        
    }
    return j%27
}
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
