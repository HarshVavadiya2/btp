#include <vector>
#include <stdint.h>

using namespace std;



#define QUEUE_SIZE 128



class VICTIM_Q_BLOCK
{

public:
    uint64_t full_addr;
    int valid = 0;
    int32_t LRU_bit;

    VICTIM_Q_BLOCK(uint64_t address,int valid_bit);
    ~VICTIM_Q_BLOCK();
};

VICTIM_Q_BLOCK::VICTIM_Q_BLOCK(uint64_t address = 0,int valid_bit = 0)
{
    full_addr = address;
    valid = valid_bit;
    LRU_bit = 0;
}

VICTIM_Q_BLOCK::~VICTIM_Q_BLOCK()
{
}




class VICTIM_QUEUE
{
private:
    
public:
    std::vector<VICTIM_Q_BLOCK> v_queue;
    int32_t Max_LRU;
    // VICTIM_Q_BLOCK* v_queue;


    VICTIM_QUEUE();
    ~VICTIM_QUEUE();
    VICTIM_QUEUE::VICTIM_QUEUE()
    {
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            v_queue.push_back(VICTIM_Q_BLOCK(0,0));
        }
        
        Max_LRU =  0; 
    }

    VICTIM_QUEUE::~VICTIM_QUEUE()
    {
    }

    /*------------------------------Implimentation-------------------------------------*/

    // harsh
    void add_in_v_queue(int64_t address)
    {
        int toBeRemove = 0;
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            if (v_queue[i].valid == 0)
            {
                v_queue[i].full_addr = address;
                v_queue[i].valid = 1;
                v_queue[i].LRU_bit = 0;
                for (int j = i + 1; j < QUEUE_SIZE; j++)
                {
                    v_queue[j].LRU_bit++;
                }
                break;
            }
            else
            {
                if (v_queue[i].LRU_bit > v_queue[toBeRemove].LRU_bit)
                {
                    toBeRemove = i;
                }
                v_queue[i].LRU_bit++;
            }
            if (i == QUEUE_SIZE - 1)
            {
                v_queue[toBeRemove].full_addr = address;
                v_queue[toBeRemove].valid = 1;
                v_queue[toBeRemove].LRU_bit = 0;
            }
        }
    };

    //sushil
    VICTIM_Q_BLOCK check_queue_for_address(int64_t address)
    {
        for (int i = 0; i < QUEUE_SIZE; i++)
        {

            if (v_queue[i].valid && v_queue[i].full_addr == address)
            {
                v_queue[i].valid = 0;
                return v_queue[i];
            }
        }
        return VICTIM_Q_BLOCK(0, 0);
    };

    void delete_from_v_queue(int64_t address)
    {
        for (int i = 0; i < QUEUE_SIZE; i++)
        {

            if (v_queue[i].valid && v_queue[i].full_addr == address)
            {
                v_queue[i].valid = 0;
                break;
            }
        }
    };
};

