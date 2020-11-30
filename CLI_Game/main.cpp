#include "Structs.h"
#include "GameApp.h"
#include "LogsOutput.h"

int main()
{
    if (Init())
    {
        RunGame();
    }

    TurnOff();

    return 0;
}
