#include "Person.h"
//LCOV_EXCL_START
#include "gtest/gtest.h"
//LCOV_EXCL_STOP


TEST(PersonTests, defaultConstructor)
{
	Person person;
	EXPECT_TRUE(person.getName() == "?");
	EXPECT_TRUE(person.getHeight() == 0);
	EXPECT_TRUE(person.getJob() == "?");
	EXPECT_TRUE(person.getAge() == 0);
}

TEST(PersonTests, OverloadedEqualityOperator)
{
	Person person1(30, "John", 6.4, "Software Engineer");
	Person person2(30, "John", 6.4, "Software Engineer");
	EXPECT_TRUE(person1 == person2);
}

TEST(PersonTests, OverloadedEqualityOperatorShouldReturnFalse)
{
	Person person1(30, "John", 6.4, "Software Engineer");
	Person person2;
	EXPECT_FALSE(person1 == person2);
}

TEST(PersonTests, GetNameTest)
{
	Person person(30, "John", 6.4, "Software Engineer");
	EXPECT_TRUE(person.getName() == "John");
}

TEST(PersonTests, GetAgeTest)
{
	Person person(30, "John", 6.4, "Software Engineer");
	EXPECT_TRUE(person.getAge() == 30);
}
TEST(PersonTests, GetHeightTest)
{
	Person person(30, "John", 6.4, "Software Engineer");
	EXPECT_TRUE(person.getHeight() == 6.4);
}

TEST(PersonTests, GetJobTest)
{
	Person person(30, "John", 6.4, "Software Engineer");
	EXPECT_TRUE(person.getJob() == "Software Engineer");
}