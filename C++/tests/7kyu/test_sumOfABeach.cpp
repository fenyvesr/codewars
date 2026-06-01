#include <gtest/gtest.h>

#include "sumOfABeach.h"

TEST(SumOfABeachTest, BasicCases) {
    EXPECT_EQ(
        sumOfABeach("WAtErSlIde"),
        1
    );

    EXPECT_EQ(
        sumOfABeach("GolDeNSanDyWateRyBeaChSuNN"),
        3
    );

    EXPECT_EQ(
        sumOfABeach("gOfIshsunesunFiSh"),
        4
    );

    EXPECT_EQ(
        sumOfABeach("cItYTowNcARShoW"),
        0
    );
}
