#include "hash_tables.h"

/**
 * key_index - gets the index of a key in a hash table
 * @key: the key to look up
 * @size: the size of the hash table's array
 *
 * Return: the index at which the key/value pair should be stored in the array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash_value;

    /* Get the hash value for the key */
    hash_value = hash_djb2(key);

    /* Get the index in the array by performing modulo with the table size */
    return (hash_value % size);
}
