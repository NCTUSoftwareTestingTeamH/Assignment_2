#include <type_traits>
#include <limits>

#include <gtest/gtest.h>

#include "../feature_code/Link_List.h"

using namespace ::testing;

namespace {

void
appendNItemsToLinkedList(Link_List& list, const size_t itemNum) {
    for (auto i = itemNum; i --> 0;) {
        list.insert_node(i);
    }
}

} // namespace

// Testings for operator[]
TEST(Link_List_indexing_operator, with_valid_edge_index) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    EXPECT_NO_THROW(linkedList[0]);
    EXPECT_NO_THROW(linkedList[itemNum - 1]);
}

TEST(Link_List_indexing_operator, with_invalid_edge_index) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    ASSERT_EXIT(linkedList[-1], ExitedWithCode(1), ".*");
    ASSERT_EXIT(linkedList[itemNum], ExitedWithCode(1), ".*");
}

// Testings for operator[] const
TEST(Link_List_indexing_operator_const, with_valid_edge_index) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    const auto& constLinkedList = linkedList;

    EXPECT_NO_THROW(constLinkedList[0]);
    EXPECT_NO_THROW(constLinkedList[itemNum - 1]);
}

TEST(Link_List_indexing_operator_const, with_invalid_edge_index) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    const auto& constLinkedList = linkedList;

    ASSERT_EXIT(constLinkedList[-1], ExitedWithCode(1), ".*");
    ASSERT_EXIT(constLinkedList[itemNum], ExitedWithCode(1), ".*");
}

// Testings for insert_node(int value)
TEST(Link_List_insert_node_int_value, with_valid_edge_index) {
    Link_List linkedList;

    constexpr auto minValidValue = std::numeric_limits<int>::min();
    constexpr auto maxValidValue = std::numeric_limits<int>::max();

    EXPECT_EQ(linkedList.insert_node(minValidValue), true);
    EXPECT_EQ(linkedList.insert_node(maxValidValue), true);
}

// Testings for insert_node(int value)
TEST(Link_List_insert_node_int_index_int_value,
     with_lower_valid_edge_index_and_valild_value) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    constexpr auto lowerIndex = 0;
    constexpr auto value = 42;
    EXPECT_EQ(linkedList.insert_node(lowerIndex, value), true);
}

TEST(Link_List_insert_node_int_index_int_value,
     with_upper_valid_edge_index_and_valild_value) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    constexpr auto upperIndex = itemNum;
    constexpr auto value = 42;
    EXPECT_EQ(linkedList.insert_node(upperIndex, value), true);
}

TEST(Link_List_insert_node_int_index_int_value,
     with_lower_invalid_edge_index_and_valild_value) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    constexpr auto lowerInvalidIndex = -1;
    constexpr auto value = 42;
    EXPECT_EQ(linkedList.insert_node(lowerInvalidIndex, value), false);
}

TEST(Link_List_insert_node_int_index_int_value,
     with_upper_invalid_edge_index_and_valild_value) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    constexpr auto upperInvalidIndex = itemNum + 1;
    constexpr auto value = 42;
    EXPECT_EQ(linkedList.insert_node(upperInvalidIndex, value), false);
}

// Testings for delete_node(int index)
TEST(Link_List_delete_node_int_index, with_valid_lower_edge_index) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    EXPECT_EQ(linkedList.delete_node(0), true);
}

TEST(Link_List_delete_node_int_index, with_valid_upper_edge_index) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    EXPECT_EQ(linkedList.delete_node(itemNum - 1), true);
}

TEST(Link_List_delete_node_int_index, with_invalid_edge_index) {
    Link_List linkedList;

    constexpr auto itemNum = size_t{32};
    appendNItemsToLinkedList(linkedList, itemNum);

    ASSERT_EQ(linkedList.delete_node(-1), false);
    ASSERT_EQ(linkedList.delete_node(itemNum), false);
}
