#pragma once

#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40

#define ESC_VALUE 27
#define SPACE_VALUE 32
#define W_VALUE 119
#define A_VALUE 97
#define S_VALUE 115
#define D_VALUE 100
#define F_VALUE 102
#define J_VALUE 106
#define K_VALUE 107

#define RUNCONTINUOUS

#ifdef RUNCONTINUOUS
#define LOCKFPS
#endif // RUNCONTINUOUS

enum class TYPEID
{
    UIObj,
    CollisionObj,
    ButtonObj,
    TextObj
};
