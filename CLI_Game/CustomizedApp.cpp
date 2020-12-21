#include "CustomizedApp.h"

//----------------------------------
int test = 0;
int testflag = 1;

void AppInit()
{
    InitSceneNodes();

    CreateSceneNode(SCENENODE("title", NULL,
        SCENECAMERA(POSITION_2D(2, 2), 10, 5)));

    CreateUIO("title", POSITION_2D(20, 20), 20, 6, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("title")->AddBtn(UI_BUTTON(-1, POSITION_2D(6, 2),
        (char*)"é_Ê¼", BTN_DESIGN::LINE));
    GetUIObjByName("title")->AddBtn(UI_BUTTON(-1, POSITION_2D(6, 4),
        (char*)"½KÁË", BTN_DESIGN::LINE));
    SetSelectedBtn(GetUIObjByName("title")->Buttons);
    GetSceneNodeByName("title")->SetBaseUIO(GetUIObjByName("title"));
}

void AppUpdate()
{
    char* temp = GetSceneNodeByName("title")->GetCamAddr()->GetCamBuffer();
    for (int i = 0; i < GetSceneNodeByName("title")->GetCamAddr()->CameraHeight; i++)
    {
        for (int j = 0; j < GetSceneNodeByName("title")->GetCamAddr()->CameraWidth; j++)
        {
            if (testflag)
            {
                *(temp + i * GetSceneNodeByName("title")->GetCamAddr()->CameraWidth + j) = '-';
                ++test;
                if (test == 1000)
                {
                    testflag = 0;
                }
            }
            else
            {
                *(temp + i * GetSceneNodeByName("title")->GetCamAddr()->CameraWidth + j) = '|';
                --test;
                if (test == 0)
                {
                    testflag = 1;
                }
            }
        }
    }

    DrawScene(GetSceneNodeByName("title"));
}

void AppTurnOff()
{

}
