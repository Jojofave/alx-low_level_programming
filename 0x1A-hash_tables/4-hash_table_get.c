#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table to look into
 * @key: the key to look for
 *
 * Return: the value associated with the element, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *tmp;

    /* Check if the key is empty */
    if (key == NULL || strlen(key) == 0)
        return (NULL);

    /* Get the index of the key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Traverse the linked list at the index to find the key */
    tmp = ht->array[index];
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }

    /* If the key was not found, return NULL */
    return (NULL);
}
