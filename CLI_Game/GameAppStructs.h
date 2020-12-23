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

struct OBJECT
{
    POSITION_2D Position;
    int Width;
    int Height;
    float ColliRadius;

    int IsCollied(OBJECT obj)
    {
        float distX = ((float)(Width) / 2.f + (float)Position.posX) -
            ((float)(obj.Width) / 2.f + (float)obj.Position.posX);
        float distY = (float)(Height) / 2.f + (float)Position.posY -
            ((float)(obj.Height) / 2.f + (float)obj.Position.posY);

        return (distX * distX + distY * distY <=
            (ColliRadius + obj.ColliRadius) * (ColliRadius + obj.ColliRadius)) ?
            1 : 0;
    }
};
