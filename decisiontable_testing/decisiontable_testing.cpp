#include<iostream>
#include"gtest/gtest.h"
#include<sstream>
#include"../feature_code/Link_List.h"

namespace
{

	class DTtest : public ::testing::Test
	{
		protected:
			virtual void SetUp()
			{
				//linkList.insert_node(22);	
			}
			virtual void TearDown()
			{
				//cout<<linkList<<endl;
			}

	};
	

	TEST_F(DTtest,RandomAccess)
	{
		Link_List linkList;
		//need definition of this behavior
		//EXPECT_EQ(linkList[0],0);
		linkList.insert_node(11);
		linkList.insert_node(22);
		linkList.insert_node(33);
		linkList.insert_node(44);//11 22 33 44
		EXPECT_EQ(linkList[0],11);//R11
		EXPECT_EQ(linkList[1],22);//R11
		EXPECT_EQ(linkList[2],33);//R11
		EXPECT_EQ(linkList[3],44);//R11
	}
	TEST_F(DTtest,insert_node)
	{
		Link_List linkList;
		//empty
		EXPECT_EQ(linkList.insert_node(-1,23),false);//R2
		//empty
		EXPECT_EQ(linkList.insert_node(212),true);//R1
		//212
		EXPECT_EQ(linkList.insert_node(11),true);//R7
		//212 11
		stringstream temp;
		temp << linkList;
		EXPECT_STREQ(temp.str().c_str(),"212 11 ");
		EXPECT_EQ(linkList.insert_node(0,13),true);//R7
		//13 212 11
		EXPECT_EQ(linkList.insert_node(3,44),true);//R7
		//12 212 11 44i
		EXPECT_EQ(linkList.insert_node(8,432),false);//R8
		stringstream temp2;
		temp2 << linkList;
		EXPECT_STREQ(temp2.str().c_str(),"13 212 11 44 ");
	}
	TEST_F(DTtest,delete_node)
	{
		Link_List linkList;
		//empty
		linkList.insert_node(11);
		linkList.insert_node(22);
		linkList.insert_node(33);
		//11 22 33
		EXPECT_EQ(linkList.delete_node(2),true);//R9
		EXPECT_EQ(linkList.delete_node(5),false);//R10
		//11 33
		stringstream temp;
		temp << linkList;
		EXPECT_STREQ(temp.str().c_str(),"11 33 ");
		EXPECT_EQ(linkList.delete_node(),true);//R9
		//11
		EXPECT_EQ(linkList.delete_node(),true);//R9
		//empty
		stringstream temp2;
		temp2 << linkList;
		EXPECT_STREQ(temp2.str().c_str(),"");
		EXPECT_EQ(linkList.delete_node(3),false);//R3
		EXPECT_EQ(linkList.delete_node(),false);//R3
		EXPECT_EQ(linkList.delete_node(-1),false);//R4
	}
	TEST_F(DTtest,copy)
	{//most can be test in compile time
		Link_List linkList;
		EXPECT_EQ(linkList.getSize(),0);
		linkList.insert_node(2);
		linkList.insert_node(2);
		linkList.insert_node(2);
		Link_List linktemp(linkList);
		EXPECT_EQ(linktemp.getSize(),3);
		EXPECT_EQ(linkList==linktemp,true);
		linkList.delete_node();
		EXPECT_EQ(linkList==linktemp,false);
		linktemp = linkList;	
		EXPECT_EQ(linkList==linktemp,true);
	}

}











int main(int argc,char** argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
