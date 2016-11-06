#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix("a+b"));
}
TEST(TPostfix, allegiance_test_one)
{ 
	string tmp;
	tmp = "a+b";

	TPostfix k(tmp);

	string res;
	res = "ab+";

	EXPECT_EQ(res, k.ToPostfix());
}
TEST(TPostfix, allegiance_test_two)
{
	string tmp;
	tmp = "a+b*c-d";

	TPostfix k(tmp);

	string res;
	res = "abc*+d-";

	EXPECT_EQ(res, k.ToPostfix());
}
TEST(TPostfix, allegiance_test_three)
{
	string tmp;
	tmp = "a/d*k-c*z";

	TPostfix k(tmp);

	string res;
	res = "ad/k*cz*-";

	EXPECT_EQ(res, k.ToPostfix());
}
TEST(TPostfix, allegiance_test_four)
{
	string tmp;
	tmp = "(a+b)-d*(k-z)";

	TPostfix k(tmp);

	string res;
	res = "ab+dkz-*-";

	EXPECT_EQ(res, k.ToPostfix());
}
TEST(TPostfix, allegiance_test_five)
{
	string tmp;
	tmp = "(a+b-c*k)/(d-(z*e-p))";

	TPostfix k(tmp);

	string res;
	res = "ab+ck*-dze*p--/";

	EXPECT_EQ(res, k.ToPostfix());
}
