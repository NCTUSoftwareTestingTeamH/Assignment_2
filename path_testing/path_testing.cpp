#include<iostream>
#include"gtest/gtest.h"
#include<sstream>
#include"../feature_code/Link_List.h"

namespace
{

	class PathTest : public ::testing::Test
	{
		protected:
			virtual void SetUp()
			{
			}
			virtual void TearDown()
			{
			}

	};
	TEST_F(PathTest,C0C1C2MCDC)
	{
		//we assume default constructer is correct
		Link_List emptyList;//this is correct
		stringstream ss;
		ss << emptyList;
		string strTemp;
		ss >> strTemp;
		ASSERT_STREQ(strTemp.c_str(),"");
		ASSERT_EQ(0,emptyList.getSize());
		Link_List testList(emptyList);
		ASSERT_EQ(true,emptyList==testList);
		emptyList = emptyList;
		ASSERT_EQ(true,emptyList==testList);
		testList = emptyList;
		ASSERT_EQ(true,emptyList==testList);
		ASSERT_EQ(true,testList.insert_node(11));
		ASSERT_EQ(true,testList.insert_node(22));
		ASSERT_EQ(11,testList[0]);
		ASSERT_EQ(22,testList[1]);//return value
		testList[1] = -22;//return reference
		ASSERT_EQ(-22,testList[1]);
		ASSERT_EQ(false,testList.insert_node(-1,44));
		ASSERT_EQ(false,testList.insert_node(100,44));//MCDC
		ASSERT_EQ(true,testList.insert_node(0,0));
		ASSERT_EQ(true,testList.insert_node(3,33));
		ASSERT_EQ(true,testList.insert_node(1,11));
		ss.str("");
		ss.clear();
		ss << testList;
		getline(ss,strTemp);
		ASSERT_STREQ(strTemp.c_str(),"0 11 11 -22 33");
		emptyList = testList;
		ASSERT_EQ(false,emptyList.delete_node(-1));//MCDC
		ASSERT_EQ(true,emptyList.delete_node(2));
		ASSERT_EQ(true,emptyList.delete_node(3));
		ASSERT_EQ(true,emptyList.delete_node(0));
		ASSERT_EQ(true,emptyList.delete_node(0));
		ASSERT_EQ(true,emptyList.delete_node(0));
		ASSERT_EQ(false,emptyList.delete_node(0));
		ASSERT_EQ(false,emptyList.delete_node());
		ss.str("");
		ss.clear();
		ss << testList;
		while(!ss.eof())ss >> emptyList;
		ss.str("");
		ss.clear();
		ss << emptyList;
		getline(ss,strTemp);
		ASSERT_STREQ(strTemp.c_str(),"0 11 11 -22 33");
		ASSERT_EQ(true,emptyList==testList);
		ASSERT_EQ(true,emptyList.delete_node());
		ASSERT_EQ(false,emptyList==testList);
		emptyList.insert_node(55);
		ASSERT_EQ(false,emptyList==testList);
		emptyList = Link_List(testList);
		emptyList.insert_node(32);
		testList = emptyList;
		cout<<emptyList<<endl;
		emptyList.delete_node();
		emptyList.delete_node();
		emptyList.delete_node();
		emptyList.delete_node();
		emptyList.delete_node();
		emptyList.delete_node();
	}

}











int main(int argc,char** argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
