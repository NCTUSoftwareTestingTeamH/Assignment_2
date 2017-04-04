#include "gtest/gtest.h"
#include "../feature_code/Link_List.h"

class WeakFormLinkListTest : public ::testing::Test {
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

TEST_F(WeakFormLinkListTest, OperatorSquareBrackets){
    // Weak Noraml
    EXPECT_EQ(linkList[0], 10);
    // Weak Robust
    // EXPECT_EQ(linkList[-1], 0); no ideas how to test
}

TEST_F(WeakFormLinkListTest, InsertNode){
    // Weak Noraml
    EXPECT_EQ(linkList.insert_node(15), true);
    // Weak Robust
    // EXPECT_EQ(linkList.insert_node(), true);
}

TEST_F(WeakFormLinkListTest, InsertIndexNode){
    // Weak Noraml
    EXPECT_EQ(linkList.insert_node(5, 15), true);
    // Weak Robust
    EXPECT_EQ(linkList.insert_node(-1, 16), false);
}

TEST_F(WeakFormLinkListTest, DeleteIndexNode){
    // Weak Noraml
    EXPECT_EQ(linkList.delete_node(5), true);
    // Weak Robust
    EXPECT_EQ(linkList.delete_node(-1), false);
}