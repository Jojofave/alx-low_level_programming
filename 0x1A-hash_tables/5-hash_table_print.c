#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    int flag = 0;
    hash_node_t *tmp;

    /* Check if the hash table is NULL */
    if (ht == NULL)
        return;

    /* Print the hash table */
    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        tmp = ht->array[i];
        while (tmp)
        {
            if (flag == 1)
                printf(", ");
            printf("'%s': '%s'", tmp->key, tmp->value);
            flag = 1;
            tmp = tmp->next;
        }
    }
    printf("}\n");
}
