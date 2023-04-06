#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to modify
 * @key: the key to add
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *tmp;

    /* Check if the key is empty */
    if (key == NULL || strlen(key) == 0)
        return (0);

    /* Get the index of the key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Check if the index already has a node */
    tmp = ht->array[index];
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            /* If the key already exists, update the value */
            free(tmp->value);
            tmp->value = strdup(value);
            return (1);
        }
        tmp = tmp->next;
    }

    /* If the key does not exist, create a new node and add it to the beginning of the list */
    new_node = malloc(sizeof(hash_node_t));
    if (!new_node)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
