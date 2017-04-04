#include "gtest/gtest.h"
#include "../feature_code/Link_List.h"

class Strong_LinkListTest : public ::testing::Test {
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
TEST_F(Strong_LinkListTest, OperatorSquareBrackets){
    // Weak Noraml
    EXPECT_EQ(linkList[0], 10);
    // Weak Robust
    // EXPECT_EQ(linkList[-1], 0); no ideas how to test
    // Strong Noraml
    // Strong Robust
}

TEST_F(Strong_LinkListTest, InsertNode){
    // Weak Noraml
    EXPECT_EQ(linkList.insert_node(15), true);
    // Weak Robust
    // EXPECT_EQ(linkList.insert_node(), true);
    // Strong Noraml
        // no multi falut
    // Strong Robust
        // no multi falut
}

TEST_F(Strong_LinkListTest, InsertIndexNode){
    // Weak Noraml
    EXPECT_EQ(linkList.insert_node(5, 15), true);
    // Weak Robust
    EXPECT_EQ(linkList.insert_node(-1, 16), false);
    // Strong Noraml
    EXPECT_EQ(linkList.insert_node(1, 17), true);
    // Strong Robust
    EXPECT_EQ(linkList.insert_node(-1, -1), false);
}

TEST_F(Strong_LinkListTest, DeleteIndexNode){
    // Weak Noraml
    EXPECT_EQ(linkList.delete_node(5), true);
    // Weak Robust
    EXPECT_EQ(linkList.delete_node(-1), false);
    // Strong Noraml
        // no multi falut
    // Strong Robust
        // no multi falut
}