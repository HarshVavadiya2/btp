
#include <victim_queue.h>


    // harsh
    // Add new evicted block to queue for future
    // Rule number 1 before adding any address to the queue update the queue
void VICTIM_QUEUE::push_victim_queue(int64_t address)
    {
        int toBeRemove = 0;
        int32_t max_lru = 0;
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            if (queue[i].valid == 0)
            {
                queue[i].full_addr = address;
                queue[i].LRU_bit = 0;
                queue[i].valid = 1;
                return;
            }
            if (queue[i].LRU_bit > max_lru)
            {
                max_lru = queue[i].LRU_bit;
                toBeRemove = i;
            }
                  
        }

        queue[toBeRemove].full_addr = address;
        queue[toBeRemove].LRU_bit = 0;
        queue[toBeRemove].valid = 1;
                
        return ;

    };


    bool VICTIM_QUEUE::check_hit_victim_queue(int64_t address) {

        for (int i = 0; i < QUEUE_SIZE; i++)
        {

            if (queue[i].valid == 1 && queue[i].full_addr == address)
            {
                
                return true;
            }
        }
        
        return false;
    }
    //sushil
    // Give valid queue block on hit
    // Give invalid queue block on miss
    VICTIM_Q_BLOCK VICTIM_QUEUE:: get_victim_q_block(int64_t address)
    {
            VICTIM_Q_BLOCK q_block;

        for (int i = 0; i < QUEUE_SIZE; i++)
        {

            if (queue[i].valid == 1 && queue[i].full_addr == address)
            {
                q_block.full_addr = queue[i].full_addr;
                q_block.LRU_bit = queue[i].LRU_bit;
                q_block.valid = queue[i].valid;
                queue[i].valid = 0;
                return q_block;
            }
        }
            q_block.valid = 0;
        return q_block;
    };


    // Update LRU bit on every access of cache blocks 
    void VICTIM_QUEUE:: update_victim_queue() {
        
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            if (queue[i].valid)
            {
                queue[i].LRU_bit++;
                if (queue[i].LRU_bit >= QUEUE_SIZE)
                {
                    queue[i].valid = 0;
                }
            }
        }
    };

    // void delete_from_v_queue(int64_t address)
    // {
    //     for (int i = 0; i < QUEUE_SIZE; i++)
    //     {

    //         if (v_queue[i].valid && v_queue[i].full_addr == address)
    //         {
    //             v_queue[i].valid = 0;
    //             break;
    //         }
    //     }
    // };