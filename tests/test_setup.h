#pragma once
#include <gtest/gtest.h>
#include <Game.h>

#define GTEST_EXPECT_NO_DEATH(statement) \
    EXPECT_EXIT({{ statement } ::exit(EXIT_SUCCESS); }, ::testing::ExitedWithCode(0), "")

#define GTEST_ASSERT_NO_DEATH(statement) \
    ASSERT_EXIT({{ statement } ::exit(EXIT_SUCCESS); }, ::testing::ExitedWithCode(0), "")

using namespace TicTacToe;

extern bool SKIP_TESTS;