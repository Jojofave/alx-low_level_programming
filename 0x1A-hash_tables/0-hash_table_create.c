#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table of the specified size
 * @size: the size of the hash table
 *
 * Return: a pointer to the newly created hash table, or NULL if an error occurred
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *hash_table;

    /* Allocate memory for the hash table */
    hash_table = malloc(sizeof(hash_table_t));
    if (hash_table == NULL)
        return (NULL);

    /* Allocate memory for the array */
    hash_table->array = calloc(size, sizeof(hash_node_t *));
    if (hash_table->array == NULL)
    {
        free(hash_table);
        return (NULL);
    }

    /* Set the size of the hash table */
    hash_table->size = size;

    return (hash_table);
}
