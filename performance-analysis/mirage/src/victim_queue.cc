
#include <victim_queue.h>


    // harsh
    // Add new evicted block to queue for future
    // Rule number 1 before adding any address to the queue update the queue
void VICTIM_QUEUE::push_victim_queue(int64_t address)
    {
        int toBeRemove = 0;
        int32_t max_lru = 0;
        bool is = false;
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            if ((queue[i].valid == 0) && (!is))
            {
                queue[i].full_addr = address;
                queue[i].LRU_bit = 0;
                queue[i].check = 0;
                queue[i].valid = 1;
                is = true;
                // return;
            }
            else if (queue[i].valid == 1) 
            {
                queue[i].LRU_bit++;
                /* code */
            }
            
            if (queue[i].valid == 1 && queue[i].LRU_bit == QUEUE_SIZE)
            {
                queue[i].valid = 0;
                toBeRemove = i;
            }
                  
        }

        if (is)
        {
            return;
        }
        

        queue[toBeRemove].full_addr = address;
        queue[toBeRemove].LRU_bit = 0;
        queue[toBeRemove].valid = 1;
        queue[toBeRemove].check = 0;
                
        return ;

    };

    //use this before update function of victim queue
    bool VICTIM_QUEUE::check_hit_victim_queue(int64_t address) {

        bool is = false;
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
    
    // Update LRU bit on every access of cache blocks 
    void VICTIM_QUEUE:: update_victim_queue() {
        
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            if (queue[i].valid == 1)
            {
                queue[i].LRU_bit++;
                if (queue[i].LRU_bit >= QUEUE_SIZE)
                {
                    queue[i].valid = 0;
                }
            }
        }
    };

    void VICTIM_QUEUE:: delete_victim_queue(int64_t address)
    {
        for (int i = 0; i < QUEUE_SIZE; i++)
        {

            if ((1 == queue[i].valid) && queue[i].full_addr == address)
            {
                queue[i].valid = 0;
                break;
            }
        }

        return;
    };

    void VICTIM_QUEUE:: set_victim_queue(int64_t address) {
        
        for (int i = 0; i < QUEUE_SIZE; i++)
        {

            if ((1 == queue[i].valid) && queue[i].full_addr == address)
            {
                queue[i].check = 1;
                break;
            }
        }

        return;
    }

    
    int VICTIM_QUEUE:: check_set_victim_queue(int64_t address) {
        
        for (int i = 0; i < QUEUE_SIZE; i++)
        {

            if ((1 == queue[i].valid) && queue[i].full_addr == address)
            {
                return queue[i].check;
            }
        }

        return 0;
    }
    