#include "StartEndPoint.h"
#include "AppDeclared.h"
#include "SceneManager.h"
#include "SceneNode.h"

void InitStartEndPoint()
{
    GetStartEndPointArray()->ObjSelf.Position = POSITION_2D(0, 0);
    GetStartEndPointArray()->ObjSelf.Width = 1;
    GetStartEndPointArray()->ObjSelf.Height = 1;
    GetStartEndPointArray()->ObjSelf.ColliRadius = 1;
    GetStartEndPointArray()->PointFlag = START_END_POINT::START_POINT;

    (GetStartEndPointArray() + 1)->ObjSelf.Position = POSITION_2D(0, 0);
    (GetStartEndPointArray() + 1)->ObjSelf.Width = 1;
    (GetStartEndPointArray() + 1)->ObjSelf.Height = 1;
    (GetStartEndPointArray() + 1)->ObjSelf.ColliRadius = 1;
    (GetStartEndPointArray() + 1)->PointFlag = START_END_POINT::END_POINT;
}

void UpdateStartEndPoint()
{
    if ((GetStartEndPointArray() + 1)->
        ObjSelf.IsCollied(GetPlayer()->ObjSelf))
    {
        DebugLog("player arrived at endpoint");
        SetStageID(0);
        SetIsPlayingMaze(0);
        SwitchSceneToName("selection");
        GetUIObjByName("after-clear")->TurnOn();
        SetSelectedBtn(GetUIObjByName("after-clear")->Buttons);
    }
}

void SetStartPointPos(POSITION_2D pos)
{
    GetStartEndPointArray()->ObjSelf.Position = pos;
}

void SetEndPointPos(POSITION_2D pos)
{
    (GetStartEndPointArray() + 1)->ObjSelf.Position = pos;
}
