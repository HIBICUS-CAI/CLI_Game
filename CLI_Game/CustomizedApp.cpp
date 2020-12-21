#include "CustomizedApp.h"
#include "AppTitleScene.h"

void AppInit()
{
    InitSceneNodes();

    InitTitleScene();
}

void AppUpdate()
{
    UpdateTitleScene();
    DrawScene(GetSceneNodeByName("title"));
}

void AppTurnOff()
{

}
