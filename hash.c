#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct hash_table
{
    int length;
    int *data;
    int used_length;
} hash_table_t;

hash_table_t* init_hash_table(const int table_length);
void destroy_hash_table(hash_table_t *t);
void print_hash_table(const hash_table_t *t);
void insert_data(hash_table_t *t, const int value);
int find_data(const hash_table_t *t, const int value);
int get_address(const hash_table_t *t, const int key);

hash_table_t* init_hash_table(const int table_length)
{
    hash_table_t *table = calloc(1, sizeof(hash_table_t));
    table->length = table_length;
    table->data = calloc(table_length, sizeof(int));
    printf("[INFO] create hash table successfully\n");
    return table;
}

void destroy_hash_table(hash_table_t *t)
{
    if(t->data) free(t->data);
    t->data = NULL;
    if(t) free(t);
    t = NULL;
    printf("[INFO] destroy hash table successfully\n");
    return;
}

void print_hash_table(const hash_table_t *t)
{
    assert(t);
    printf("[INFO] ---- print hash table ----\n");
    printf("[INFO] t->length:%d\n", t->length);
    printf("[INFO] t->used_length:%d\n", t->used_length);
    printf("addr value\n");
    int *data = t->data;
    for(int eidx = 0; eidx < t->length; ++eidx)
    {
        if(data[eidx] != 0)
            ;//printf("%d %d\n", eidx, data[eidx]);
        printf("%4d %4d\n", eidx, data[eidx]);
    }
    printf("\n");
    return;
}

void insert_data(hash_table_t *t, const int value)
{
    assert(t);
    int address = get_address(t, value);
    t->data[address] = value;
    ++t->used_length;
    return;
}

int find_data(const hash_table_t *t, const int value)
{
    int start_address = value % t->length;
    int address = start_address;
    int *data = t->data;
    while(data[address] != value)
    {
        address = (1+address) % t->length;
        if(address == start_address || data[address]==0)
        {
            printf("[WARN] %d not found in hash table\n", value);
            return -1;
        }
    }
    printf("[INFO] %d found in hash table address: %d\n", value, address);
    return address;
}

int get_address(const hash_table_t *t, const int key)
{
    assert(t);
    int start_address = key % t->length;
    int address = start_address;
    while(t->data[address])
    {
        address = (1+address) % t->length; // 开放定址法
        if(address == start_address)
        {
            printf("[ERROR] hash table has no space\n");
            exit(0);
        }
    }
    return address;
}

int main()
{
    const int table_length = 15;
    hash_table_t *t = init_hash_table(table_length);
    print_hash_table(t);

    insert_data(t, 93);
    insert_data(t, 95);
    insert_data(t, 12);
    print_hash_table(t);
    find_data(t, 30);
    find_data(t, 12);

    destroy_hash_table(t);
    return 0;
}
