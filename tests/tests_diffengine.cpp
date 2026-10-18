#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "DiffEngine.h"
// Output format
// "  x" (double spaces) means line <x> was kept the same.
// "- x" means line <x> was removed
// "+ x" means line <x> was added.

TEST(DiffEngineTest, EmptyInputsGiveEmptyDiff) {
	EXPECT_TRUE(getDiff({}, {}).empty());
}

TEST(DIffEngineTest, SameInputsShowNoChanges) {
	Lines input = { "a", "b", "c" };
	Lines expected = { "  a", "  b", "  c" };
	EXPECT_EQ(getDiff(input, input), expected);
}