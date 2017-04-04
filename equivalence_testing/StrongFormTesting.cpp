#include "gtest/gtest.h"
#include "../feature_code/Link_List.h"

class LinkListTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            linkList.insert_node(10);
            linkList.insert_node(11);
            linkList.insert_node(12);
            linkList.insert_node(13);
            linkList.insert_node(14);
        }

    // virtual void TearDown() {}

    Link_List linkList;
};

// Strong Form
TEST_F(LinkListTest, StrongFormTesting){
    EXPECT_EQ(linkList[0], 10);
}