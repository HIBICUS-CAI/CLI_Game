#include "Tools.h"

int g_DeltaTime = DELTATIME;

void SetDeltaTime(int time)
{
    g_DeltaTime = time;
}

int GetDeltaTime()
{
    return g_DeltaTime;
}

int GetIntValueBit(int value)
{
    int flag = 0;
    int bits = 0;
    int baseNum = 1;
    while (flag == 0)
    {
        flag = value / baseNum;
        if (flag != 0)
        {
            ++bits;
            baseNum *= 10;
        }
    }

    return bits;
}

QSINGLENODE* CreateQueue()
{
    QSINGLENODE* queue = (QSINGLENODE*)malloc(sizeof(QSINGLENODE));
    queue->Next = NULL;

    QUEUE_INT queueFlagNode{ queue,queue };

    return queue;
}

QSINGLENODE* EnQueue(QSINGLENODE* end, int data)
{
    QSINGLENODE* enElem = (QSINGLENODE*)malloc(sizeof(QSINGLENODE));
    enElem->Data = data;
    enElem->Next = NULL;
    end->Next = enElem;
    end = enElem;

    return end;
}

int DeQueue(QSINGLENODE* top, QSINGLENODE* end)
{
    if (top->Next == NULL)
    {
        return -1;
    }
    QSINGLENODE* node = top->Next;
    int temp = node->Data;
    top->Next = node->Next;
    if (end == node)
    {
        end = top;
    }
    free(node);

    return temp;
}

void SetRandomBySeed(int seedNum)
{
    srand(seedNum);
}

void SetRandom()
{
    srand((int)time(NULL));
}

int CreateRandomNumIn(int minNum, int maxNum)
{
    return rand() % (maxNum - minNum + 1) + minNum;
}
