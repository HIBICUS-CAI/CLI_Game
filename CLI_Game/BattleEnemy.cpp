#include "BattleEnemy.h"
#include "Tools.h"
#include "SceneManager.h"

void InitBattleEnemy()
{
    for (int i = 0; i < BATTLEENEMYSIZE; i++)
    {
        (GetBattleEnemyArray() + i)->ID = -1;
        (GetBattleEnemyArray() + i)->ObjSelf.Position =
            POSITION_2D(0, 0);
        (GetBattleEnemyArray() + i)->ObjSelf.Width = 2;
        (GetBattleEnemyArray() + i)->ObjSelf.Height = 1;
        (GetBattleEnemyArray() + i)->ObjSelf.ColliRadius = 1.f;
        char temp[3] = "¡ö";
        *((GetBattleEnemyArray() + i)->Sprite) = temp[0];
        *((GetBattleEnemyArray() + i)->Sprite + 1) = temp[1];
        (GetBattleEnemyArray() + i)->TurnOff();
    }
}

void ClearBattleEnemyArray()
{
    for (int i = 0; i < BATTLEENEMYSIZE; i++)
    {
        (GetBattleEnemyArray() + i)->ID = -1;
        (GetBattleEnemyArray() + i)->TurnOff();
    }
}

int IsValueExistInArray(int value, int* array)
{
    for (int i = 0; i < BATTLEENEMYSIZE; i++)
    {
        if (*(array + i) == value ||
            *(array + i) == (value - 1) ||
            *(array + i) == (value + 1))
        {
            return 1;
        }
        if (*(array + i) == -1)
        {
            return 0;
        }
    }
}

void SetEnemyToBattleRandomly()
{
    SetRandom();
    int stageID = GetStageID();
    int enemySize = 0;
    int posXRecord[BATTLEENEMYSIZE];

    if (stageID == 1)
    {
        enemySize = BATTLEENEMYSIZE - 45;
    }

    for (int i = 0; i < enemySize + 1; i++)
    {
        posXRecord[i] = -1;
    }

    for (int i = 0; i < enemySize; i++)
    {
        int posX = CreateRandomNumIn(5, 113);

        while (IsValueExistInArray(posX, posXRecord))
        {
            posX = CreateRandomNumIn(5, 113);
        }

        POSITION_2D position =
        { posX,CreateRandomNumIn(5,18) };
        (GetBattleEnemyArray() + i)->ID = i;
        (GetBattleEnemyArray() + i)->ObjSelf.Position =
            position;
        posXRecord[i] = posX;
    }

    TurnOnAllBattleEnemy();
}

void UpdateBattleEnemy()
{
    char* camBuffer = GetManagedCurrScene()->GetCamAddr()->GetCamBuffer();
    int camWidth = GetManagedCurrScene()->GetCamAddr()->CameraWidth;
    POSITION_2D battlePos;

    for (int i = 0; i < BATTLEENEMYSIZE; i++)
    {
        if ((GetBattleEnemyArray() + i)->ID == -1)
        {
            break;
        }

        if ((GetBattleEnemyArray() + i)->Visible == 1)
        {
            battlePos = (GetBattleEnemyArray() + i)->ObjSelf.Position;
            if (*(camBuffer + (battlePos.posY + 1) * camWidth +
                battlePos.posX) != '-' ||
                *(camBuffer + (battlePos.posY + 1) * camWidth +
                    battlePos.posX + 1) != '-')
            {
                ++(GetBattleEnemyArray() + i)->ObjSelf.Position.posY;
            }
        }
    }
}

void DrawBattleEnemyToCamBuffer()
{
    char* buffer = GetManagedCurrScene()->GetCamAddr()->GetCamBuffer();
    int width = GetManagedCurrScene()->GetCamAddr()->CameraWidth;

    int index = 0;
    while ((GetBattleEnemyArray() + index)->ID != -1)
    {
        POSITION_2D pos = (GetBattleEnemyArray() + index)->ObjSelf.Position;
        if (pos.posY <= 33)
        {
            *(buffer + pos.posY * width + pos.posX) =
                *((GetBattleEnemyArray() + index)->Sprite);
            *(buffer + pos.posY * width + pos.posX + 1) =
                *((GetBattleEnemyArray() + index)->Sprite + 1);
        }
        ++index;
    }
}

void TurnOffAllBattleEnemy()
{
    int index = 0;
    while ((GetBattleEnemyArray() + index)->ID != -1)
    {
        (GetBattleEnemyArray() + index)->TurnOff();
        ++index;
    }
}

void TurnOnAllBattleEnemy()
{
    int index = 0;
    while ((GetBattleEnemyArray() + index)->ID != -1)
    {
        (GetBattleEnemyArray() + index)->TurnOn();
        ++index;
    }
}
