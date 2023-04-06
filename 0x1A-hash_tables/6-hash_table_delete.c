#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *tmp, *next;

    /* Check if the hash table is NULL */
    if (ht == NULL)
        return;

    /* Free the nodes in each element of the hash table array */
    for (i = 0; i < ht->size; i++)
    {
        tmp = ht->array[i];
        while (tmp)
        {
            next = tmp->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
            tmp = next;
        }
    }

    /* Free the hash table array and the hash table itself */
    free(ht->array);
    free(ht);
}
