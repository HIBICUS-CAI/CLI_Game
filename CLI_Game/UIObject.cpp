#include "UIObject.h"
#include "Tools.h"
#include "LogsOutput.h"
#include "ConsolePrint.h"
#include "DeclaredValues.h"

void InitUIObj()
{
    //g_UIObjIndex = 0;
    SetUIOIndex(0);
    for (int i = 0; i < UIOBJSIZE; i++)
    {
        //g_UIObjs[i].ID = -1;
        (GetUIObj() + i)->ID = -1;
    }
}

UIOBJECT* GetUIObjByID(int id)
{
    //if (g_UIObjs[id - 10000].ID != -1)
    if ((GetUIObj() + (id - 10000))->ID != -1)
    {
        return GetUIObj() + (id - 10000);
    }
    else
    {
        ErrorLogI1("you don't have a UI object which id is", id);
        return NULL;
    }
}

UIOBJECT* GetUIObjByName(const char* name)
{
    int i = 0;
    while ((GetUIObj() + i)->ID != -1)
    {
        if (!strcmp((GetUIObj() + i)->UIName, (char*)name))
        {
            return GetUIObj() + i;
        }
        ++i;
    }
    char log[512] = "you don't have a UI object which name is ";
    strcat_s(log, sizeof(log), (const char*)name);
    ErrorLog((const char*)log);
    return NULL;
}

UIOBJECT* CreateUIO(const char* name, POSITION_2D startPoint, int width, int height,
    UIO_DESIGN design, UIOBJECT* parent, UIOBJECT* child,
    int visiblity)
{
    if (*GetUIOIndex() >= UIOBJSIZE)
    {
        ErrorLog("the number of UI object has overflowed");
        exit(-1);
    }
    int id = *GetUIOIndex() + 10000;

    UIOBJECT temp(TYPEID::UIObj, id, (char*)name, startPoint, width, height,
        design, parent, child, visiblity);
    //g_UIObjs[g_UIObjIndex] = temp;
    *(GetUIObj() + *GetUIOIndex()) = temp;
    SetUIOIndex(*GetUIOIndex() + 1);
    //AddUIOIndex();

    return GetUIObj() + *GetUIOIndex() - 1;
}

void DrawUIO(UIOBJECT* uiObject)
{
    if (uiObject->Visiblity != 0)
    {
        SetTopUIO(uiObject);

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
        if (uiObject->ChildUIO != NULL)
        {
            DrawUIO(uiObject->ChildUIO);
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
