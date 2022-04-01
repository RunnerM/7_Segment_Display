#include "gtest/gtest.h"

extern "C" {

}

class SevenSegmentDriverTest : public ::testing::Test {
protected:
	void SetUp() 
	{}
	void TearDown() 
	{}
};

TEST_F(SevenSegmentDriverTest, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}