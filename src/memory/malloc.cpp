#include<malloc.hpp>
struct Block
{
    size_t size;
    bool is_free;
    Block* previous;
    Block* next;
};
Block* header = nullptr;
void* memory_pool;
void split_block(Block*,size_t);
void memcopy(void* from, void* to, size_t size)
{
    for(size_t i = 0;i<size;i++)
    {
        ((char*)to)[i] = ((char*)from)[i];
    }
}
Block* find_free_block(size_t size)
{
    Block* cur_block = header;
    while(cur_block != nullptr)
    {
        if(cur_block->is_free && cur_block->size > size)
        {
            split_block(cur_block,size);
            return cur_block;
        }
        cur_block = cur_block->next;
    }
    return nullptr;
}

Block* get_end(Block* block)
{
    while(block->next != nullptr)
    {
        block=block->next;
    }
    return block;
}

void split_block(Block* block_pointer, size_t size)
{
    size_t remaining_size = block_pointer->size - size - sizeof(Block);
    // Check if there's enough space left to create a new block after the split
    if (remaining_size > sizeof(Block)) {
        // Create a new block in the remaining memory after the split
        Block* newBlock = (Block*)((char*)block_pointer + sizeof(Block) + size);
        
        // Set the size of the new block to the remaining size
        newBlock->size = remaining_size;
        newBlock->is_free = true; // New block is free
        newBlock->previous = block_pointer; // Link to previous block
        newBlock->next = block_pointer->next; // Point to the next block

        // Update the current block's size to the requested size
        block_pointer->size = size;
        block_pointer->next = newBlock; // Link to the new block

        // If there’s a next block, update its previous pointer to the new block
        if (newBlock->next) {
            newBlock->next->previous = newBlock;
        }
    }
}

void merge_block(Block* fst_block, Block* snd_block)
{
    if(fst_block->is_free && snd_block->is_free)
    {
        fst_block->size += snd_block->size + sizeof(Block);
        fst_block->next = snd_block->next;
        if(snd_block->next){
            snd_block->next->previous = fst_block;
        }
    }
}
void init_memory_pool()
{
    void* ptr = sbrk(1024*1024);
    header = (Block*)ptr;
    header->size = 1024*1024 - sizeof(Block);
    header->is_free = true;
    header->previous = nullptr;
    header->next = nullptr;
}
void mfree(void* ptr)
{
    Block* block = (Block*)((char*)ptr - sizeof(Block));
    block->is_free = true;
    if(block->previous)
    {
        merge_block(block->previous,block);
    }
}
void* mrealloc(void* ptr, size_t size)
{
    Block* prevBlock = (Block*)((char*)ptr - sizeof(Block));
    void* newPtr = mmalloc(size);
    if(prevBlock->size < size)
    {
        memcopy(ptr,newPtr,prevBlock->size);
    }else
    {
        memcopy(ptr,newPtr,prevBlock->size);
    }
    mfree(ptr);
    return newPtr; 
}
void* mmalloc(size_t size)
{
    if(header == nullptr)
    {
        init_memory_pool();
    }
    Block* ptr = find_free_block(size);
    if(ptr == nullptr)
    {
        ptr = (Block*)sbrk(size + sizeof(Block));
        ptr->size = size;
        ptr->is_free = true;
        ptr->previous = get_end(header);
        ptr->previous->next = ptr;
        return (void*)((char*)ptr+sizeof(Block));
    }else{
        ptr->is_free = false;
        return (void*)((char*)ptr) + sizeof(Block);
    }
}