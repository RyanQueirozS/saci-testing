#define GLITCH_STD
#define GLITCH_COMPLEX
#define GLITCH_CLOCK
#include "../glitc-clock.h"
#include "../glitc-complex.h"
#include "../glitc.h"

int main(void) {
    GlitchTester* t = glitch_Tester_New();

    glitch_Clock_Begin();
    glitch_Clock_End();

    GLITCH_CMPX_VEC2(a);
    a[0]       = 0;
    a[1]       = 0;
    float b[2] = {0, 0};

    GLITCH_ASSERT(t, glitch_Cmpx_Vec2_Is_Equal(a, b), "a");
    GLITCH_ASSERT(t, glitch_Clock_Get_Elapsed_MS() < 1, "b");
    glitch_End(t);
}
