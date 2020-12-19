#include "ButtonEvents.h"
#include "UIObject.h"
#include "DeclaredValues.h"

void OpenUIObj(int id)
{
    GetUIObjByID(id)->TurnOn();
}

void CloseUIObj(int id)
{
    GetUIObjByID(id)->TurnOff();
}

void RunButtonEvent(int value)
{
    switch (value)
    {
    case TEST_OPENSUB:
        OpenUIObj(GetUIObjByName("child")->ID);
        SetSelectedBtn(GetUIObjByName("child")->Buttons);
        GetSelectedBtn();
        break;

    case TEST_CLOSETHIS:
        CloseUIObj(GetUIObjByName("child")->ID);
        SetSelectedBtn(GetUIObjByName("parent")->Buttons);
        break;

    default:
        break;
    }
}
