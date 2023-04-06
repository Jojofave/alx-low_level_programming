#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table, or NULL if failed
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    /* Allocate memory for the hash table */
    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    /* Allocate memory for the hash table array */
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    /* Initialize the hash table elements to NULL */
    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    /* Initialize the rest of the hash table fields */
    ht->size = size;
    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - adds or updates an element in the sorted hash table
 * @ht: the hash table to add/update the element to
 * @key: the key of the element
 * @value: the value of the element
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *node, *tmp;
    unsigned long int index;

    /* Check if the hash table and the key are not NULL */
    if (ht == NULL || key == NULL || strcmp(key, "") == 0)
        return (0);

    /* Compute the index of the element in the hash table array */
    index = key_index((unsigned char *)key, ht->size);

    /* Check if the key already exists in the hash table */
    tmp = ht->array[index];
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            /* Update the value of the existing key */
            free(tmp->value);
            tmp->value = strdup(value);
            return (1);
        }
        tmp = tmp->next;
    }

    /* Allocate memory for the new node */
    node = malloc(sizeof(shash_node_t));
    if (node == NULL)
        return (0);

    /* Initialize the new node fields */
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = ht->array[index];

    /* Insert the new node in the sorted list */
    if (ht->shead == NULL)
    {
        /* The sorted list is empty */
        ht->shead = node;
        ht->stail = node;
    }
    else if (strcmp(node->key, ht->shead->key) < 0)
    {
        /* The new node should be the new head of the sorted list */
        node->snext = ht->shead;
        ht->shead->sprev = node;
        ht->shead = node;
    }
    else
    {
        /* Find the correct position of the new node in the sorted list */
        tmp = ht->shead;
        while (tmp->snext && strcmp(tmp->snext->key, node->key) < 0)
            tmp = tmp->snext;

        /* Insert the new node
