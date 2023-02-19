#include "test_setup.h"

TEST(testMapModification, testCorrect) {
    GTEST_ASSERT_NO_DEATH({
        Map map;
        map.setPointValue(8, 0, Point::Cross);
    }) << "[ TEST_MSG ]: death testMapModification";
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