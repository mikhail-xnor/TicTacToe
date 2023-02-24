#include "test_setup.h"

bool SKIP_TESTS{false};

TEST(testMap, testFill) {
    GTEST_EXPECT_NO_DEATH({
        Map map;
        map.setPointValue(8, 0, Point::Cross);
    }) << "[ TEST_MSG ]: death Map test";
    if (HasFailure())
        SKIP_TESTS = true;
    if (!SKIP_TESTS) {
        Map map;
        map.setPointValue(0, 0, Point::Zero);
        map.setPointValue(8, 0, Point::Cross);
        map.setPointValue(0, 8, Point::Zero);
        map.setPointValue(-8, 0, Point::Cross);
        map.setPointValue(0, -8, Point::Zero);

        for (auto i = 16; i > -17; --i) {
            for (auto j = -16; j < 17; ++j) {
                auto point{map.getPointValue(j, i)};
                if (i == 0 && j == 0)
                    ASSERT_EQ(point, Point::Zero);
                else if (i == 0 && j == 8)
                    ASSERT_EQ(point, Point::Cross);
                else if (i == 8 && j == 0)
                    ASSERT_EQ(point, Point::Zero);
                else if (i == 0 && j == -8)
                    ASSERT_EQ(point, Point::Cross);
                else if (i == -8 && j == 0)
                    ASSERT_EQ(point, Point::Zero);
                else
                    ASSERT_EQ(point, Point::Empty);
            }
        }
    }
}

TEST(testMap, testModify) {
    if (!SKIP_TESTS) {
        Map map;
        map.setPointValue(0, 0, Point::Zero);
        map.setPointValue(8, 0, Point::Cross);
        map.setPointValue(0, 8, Point::Zero);
        map.setPointValue(-8, 0, Point::Cross);
        map.setPointValue(0, -8, Point::Zero);

        for (auto i = 16; i > -17; --i) {
            for (auto j = -16; j < 17; ++j) {
                auto point{map.getPointValue(j, i)};
                if (i == 0 && j == 0)
                    ASSERT_EQ(point, Point::Zero);
                else if (i == 0 && j == 8)
                    ASSERT_EQ(point, Point::Cross);
                else if (i == 8 && j == 0)
                    ASSERT_EQ(point, Point::Zero);
                else if (i == 0 && j == -8)
                    ASSERT_EQ(point, Point::Cross);
                else if (i == -8 && j == 0)
                    ASSERT_EQ(point, Point::Zero);
                else
                    ASSERT_EQ(point, Point::Empty);
            }
        }

        map.setPointValue(8, 0, Point::Zero);
        map.setPointValue(0, 8, Point::Cross);
        map.setPointValue(-8, 0, Point::Empty);
        map.setPointValue(0, -8, Point::Empty);

        for (auto i = 16; i > -17; --i) {
            for (auto j = -16; j < 17; ++j) {
                auto point{map.getPointValue(j, i)};
                if (i == 0 && j == 0)
                    ASSERT_EQ(point, Point::Zero);
                else if (i == 0 && j == 8)
                    ASSERT_EQ(point, Point::Zero);
                else if (i == 8 && j == 0)
                    ASSERT_EQ(point, Point::Cross);
                else if (i == 0 && j == -8)
                    ASSERT_EQ(point, Point::Empty);
                else if (i == -8 && j == 0)
                    ASSERT_EQ(point, Point::Empty);
                else
                    ASSERT_EQ(point, Point::Empty);
            }
        }
    }
}