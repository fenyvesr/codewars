#include <gtest/gtest.h>

#include "returnLocation.h"

TEST(PersonTest, ReturnLocation) {
    Person person(1, 2, 3);

    int x{0};
    int y{0};
    int z{0};

    person.location(x, y, z);

    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(z, 3);
}