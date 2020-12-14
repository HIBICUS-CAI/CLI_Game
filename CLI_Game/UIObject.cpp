#include "UIObject.h"
#include "Tools.h"
#include "LogsOutput.h"
#include "ConsolePrint.h"

#define UIOBJSIZE 10000
UIOBJECT g_UIObjs[UIOBJSIZE];
int g_UIObjIndex = 0;

void InitUIObj()
{
    g_UIObjIndex = 0;
    for (int i = 0; i < UIOBJSIZE; i++)
    {
        g_UIObjs[i].ID = -1;
    }
}

UIOBJECT* GetUIObjByID(int id)
{
    if (g_UIObjs[id - 10000].ID != -1)
    {
        return g_UIObjs + (id - 10000);
    }
    else
    {
        ErrorLogI1("you don't have a UI object which id is", id);
        return NULL;
    }
}

UIOBJECT* CreateUIO(POSITION_2D startPoint, int width, int height,
    UIO_DESIGN design, UIOBJECT* parent, UIOBJECT* child,
    int visiblity)
{
    if (g_UIObjIndex >= UIOBJSIZE)
    {
        ErrorLog("the number of UI object has overflowed");
        exit(-1);
    }
    int id = g_UIObjIndex + 10000;

    UIOBJECT temp(TYPEID::UIObj, id, startPoint, width, height,
        design, parent, child, visiblity);
    g_UIObjs[g_UIObjIndex] = temp;

    return g_UIObjs + g_UIObjIndex++;
}

void DrawUIO(UIOBJECT* uiObject)
{
    if (uiObject->Visiblity != 0)
    {
        if (uiObject->BorderDesign == UIO_DESIGN::STRAIGHT)
        {
            for (int i = uiObject->StartPoint.posX;
                i < uiObject->StartPoint.posX + uiObject->Width; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(i, uiObject->StartPoint.posY), '-');
            }
            for (int i = uiObject->StartPoint.posX;
                i < uiObject->StartPoint.posX + uiObject->Width; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(i,
                        uiObject->StartPoint.posY + uiObject->Height - 1),
                    '-');
            }
            for (int i = uiObject->StartPoint.posY;
                i < uiObject->StartPoint.posY + uiObject->Height; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(uiObject->StartPoint.posX, i), '|');
            }
            for (int i = uiObject->StartPoint.posY;
                i < uiObject->StartPoint.posY + uiObject->Height; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(uiObject->StartPoint.posX + uiObject->Width - 1,
                        i), '|');
            }

            DrawTextInUIO(uiObject);
        }
        else if (uiObject->BorderDesign == UIO_DESIGN::STAR)
        {
            for (int i = uiObject->StartPoint.posX;
                i < uiObject->StartPoint.posX + uiObject->Width; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(i, uiObject->StartPoint.posY), '*');
            }
            for (int i = uiObject->StartPoint.posX;
                i < uiObject->StartPoint.posX + uiObject->Width; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(i,
                        uiObject->StartPoint.posY + uiObject->Height - 1),
                    '*');
            }
            for (int i = uiObject->StartPoint.posY;
                i < uiObject->StartPoint.posY + uiObject->Height; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(uiObject->StartPoint.posX, i), '*');
            }
            for (int i = uiObject->StartPoint.posY;
                i < uiObject->StartPoint.posY + uiObject->Height; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(uiObject->StartPoint.posX + uiObject->Width - 1,
                        i), '*');
            }

            DrawTextInUIO(uiObject);
        }
        else if (uiObject->BorderDesign == UIO_DESIGN::NOTHING)
        {
            for (int i = uiObject->StartPoint.posX;
                i < uiObject->StartPoint.posX + uiObject->Width; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(i, uiObject->StartPoint.posY), ' ');
            }
            for (int i = uiObject->StartPoint.posX;
                i < uiObject->StartPoint.posX + uiObject->Width; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(i,
                        uiObject->StartPoint.posY + uiObject->Height - 1),
                    ' ');
            }
            for (int i = uiObject->StartPoint.posY;
                i < uiObject->StartPoint.posY + uiObject->Height; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(uiObject->StartPoint.posX, i), ' ');
            }
            for (int i = uiObject->StartPoint.posY;
                i < uiObject->StartPoint.posY + uiObject->Height; i++)
            {
                WriteCharIntoOutputBuffer(
                    POSITION_2D(uiObject->StartPoint.posX + uiObject->Width - 1,
                        i), ' ');
            }

            DrawTextInUIO(uiObject);
        }
    }
}

void DrawTextInUIO(UIOBJECT* uiObject)
{
    int index = 0;
    while (uiObject->Texts[index].ID != -1)
    {
        WriteStrIntoOutputBufferByPos(uiObject->Texts[index].Position,
            uiObject->Texts[index].Text);
        ++index;
    }
}
