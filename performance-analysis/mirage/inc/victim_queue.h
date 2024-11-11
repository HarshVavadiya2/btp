#include <vector>
#include <stdint.h>

using namespace std;



#define QUEUE_SIZE 128



class VICTIM_Q_BLOCK
{

public:
    uint64_t full_add;
    int valid = 0;
    int LRU_bit;

    VICTIM_Q_BLOCK(uint64_t add,int valid_bit);
    ~VICTIM_Q_BLOCK();
};

VICTIM_Q_BLOCK::VICTIM_Q_BLOCK(uint64_t add = 0,int valid_bit = 0)
{
    full_add = add;
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
    int LRU_bit;
    // VICTIM_Q_BLOCK* v_queue;


    VICTIM_QUEUE();
    ~VICTIM_QUEUE();
    VICTIM_QUEUE::VICTIM_QUEUE()
    {
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            v_queue.push_back(VICTIM_Q_BLOCK(0,0));
        }
        LRU_bit =  0; 
    }

    VICTIM_QUEUE::~VICTIM_QUEUE()
    {
    }

    /*------------------------------Implimentation-------------------------------------*/

    // harsh
    void add(int add);
    
    //sushil
    VICTIM_Q_BLOCK  find();







};

