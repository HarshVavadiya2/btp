#include <vector>
#include <stdint.h>


#define QUEUE_SIZE 32



class VICTIM_Q_BLOCK
{

public:
    uint64_t full_addr;
    int valid = 0;
    int32_t LRU_bit;

    VICTIM_Q_BLOCK(uint64_t address = 0, int valid_bit = 0)
    {
        full_addr = address;
        valid = valid_bit;
        LRU_bit = 0;
    }

    ~VICTIM_Q_BLOCK()
    {
    }
};





class VICTIM_QUEUE
{
private:
    
public:
    std::vector<VICTIM_Q_BLOCK> queue;
    // int32_t Max_LRU;
    // VICTIM_Q_BLOCK* v_queue;

    VICTIM_QUEUE()
    {
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            queue.push_back(VICTIM_Q_BLOCK(0,0));
        }
        
        // Max_LRU =  0; 
    }
    // ~VICTIM_QUEUE();

    ~VICTIM_QUEUE()
    {
    }

    /*------------------------------Implimentation-------------------------------------*/

    void push_victim_queue(int64_t address);    
    bool check_hit_victim_queue(int64_t address);
    void update_victim_queue();


};

