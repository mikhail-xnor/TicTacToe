#include "test_setup.h"

TEST(testEngine, testBase) {
    GTEST_EXPECT_NO_DEATH({
        Engine engine;
        engine.move(8, 0);
    }) << "[ TEST_MSG ]: death testMapModification";
    if (HasFailure())
        SKIP_TESTS = true;
    if (!SKIP_TESTS) {
        Engine engine;

        for (auto i = 0; i != 5; ++i) {
            engine.move(0, -i);
            engine.move(4 - i, 0);
        }

        EXPECT_EQ(engine.getCurrentState(), Point::Zero);
        EXPECT_EQ(engine.getGameStatus(), GameStatus::Finish);

        if (HasFailure())
            SKIP_TESTS = true;
    }
}

TEST(testEngine, testErrorCodes) {
    if (!SKIP_TESTS) {
        Engine engine;

        for (auto i = 0; i != 4; ++i) {
            engine.move(0, -i);
            engine.move(3 - i, 0);
        }
        EXPECT_EQ(engine.move(0, 0), 2);
        EXPECT_EQ(engine.move(1, 0), 1);
        engine.move(-1, 0);
        EXPECT_EQ(engine.move(0, -4), 0);
        EXPECT_EQ(engine.move(0, 0), 3);
    }
}