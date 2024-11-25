# Saci Testing

Simply copy-paste/download the `saci-tessting.h` file to your project!

# Example

```c
#define SACI_TEST_IMPLEMENTATION 

#include "path-to/saci-testing.h" // define before including

static void MyTestFunction() {
    saci_Test_PrintPassed(true); // will print the passed tests. Default: false.
    { // Test some functionality
        saci_Test_ClockBegin(); // if you want to begin the clock!
        
        SACI_TEST_ASSERT(1 > 0, "One should be more than zero"); // SUCCESS
        SACI_TEST_ASSERT(0 > 1, "One should be less than zero"); // FAIL
    
        saci_Test_ClockEnd();
        SACI_TEST_ASSERT(saci_Test_GetElapsedTimeMS() < 5, "Should run in less then 5 ms");
    }
    {
        for(int i = 0; i < 10; ++i) {
            SACI_TEST_ASSERT(i < 5, "Number iteration should be less than 5"); 
            // Should fail 5 times, but because the file, line number and 
            // description is the same, it will only print once
        }
    }
    saci_Test_End(); // Ends the test and prints the results
}
```

You can change the macros:

```c

#define SACI_EPSILON 1e-8 
// Default: 1e-6

#define SACI_TEST_VEC3_IS_EQUAL(v1x,v1y,v1z,v2x,v2y,v2z)... 
// Default is: SACI_TEST_VEC3_IS_EQUAL(v1,v2)

// you can also change SACI_TEST_VEC2_IS_EQUAL, SACI_TEST_COLOR_IS_EQUAL,
// SACI_RAND_RANGE_INT, SACI_RAND_RANGE_FLOAT

// The SACI_TEST_ASSERT can also be changed
#define SACI_TEST_ASSERT(condition)... 
// Default is: SACI_TEST_ASSERT(condition, description)

#define SACI_TEST_MAXIMUM 10 // Will only have 10 tests. Will crash if there are more!
// Default: 0x1000.

```
