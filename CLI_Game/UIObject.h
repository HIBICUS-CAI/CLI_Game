#pragma once

#include <stdlib.h>
#include "DefinedValues.h"
#include "Structs.h"

void InitUIObj();

UIOBJECT* GetUIObjByID(int id);

UIOBJECT* CreateUIO(POSITION_2D startPoint, int width, int height,
    UIO_DESIGN design, UIOBJECT* parent = NULL, UIOBJECT* child = NULL,
    int visiblity = 1);

void DrawUIO(UIOBJECT* uiObject);

void DrawTextInUIO(UIOBJECT* uiObject);
