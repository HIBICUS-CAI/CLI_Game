#pragma once

#include "Structs.h"

struct SCENECAMERA
{
    char CamBuffer[CONSOLE_HEIGHT * CONSOLE_WIDTH];

    POSITION_2D CameraPosition;
    int CameraWidth;
    int CameraHeight;

    SCENECAMERA() {}

    SCENECAMERA(POSITION_2D _pos, int _camWdt, int _camHgt)
    {
        CameraPosition = _pos;
        CameraWidth = _camWdt;
        CameraHeight = _camHgt;
    }

    char* GetCamBuffer()
    {
        return CamBuffer;
    }
};

struct SCENENODE
{
    int SceneID;
    char SceneName[50];
    UIOBJECT* BaseUIObj;
    SCENECAMERA Camera;

    SCENENODE() {}

    SCENENODE(const char* _name, UIOBJECT* _baseUIO,
        SCENECAMERA _cam)
    {
        strcpy_s(SceneName, sizeof(SceneName), _name);
        BaseUIObj = _baseUIO;
        Camera = _cam;
    }

    SCENECAMERA* GetCamAddr()
    {
        return &Camera;
    }

    void SetBaseUIO(UIOBJECT* uiObj)
    {
        BaseUIObj = uiObj;
    }

    UIOBJECT* GetBaseUIOAddr()
    {
        return BaseUIObj;
    }
};
