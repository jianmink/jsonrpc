#include "gmock/gmock.h"
#include <string.h>
#include "gtest/gtest.h"

using testing::GMOCK_FLAG(verbose);
using testing::InitGoogleMock;
using testing::internal::g_init_gtest_count;

#include <stdio.h>
#include <iostream>

#include "EnumParser.h"

class TestEnumParser: public testing::Test
{
protected:
};


TEST_F(TestEnumParser,dn_has_3_digits_and_zone_has_3_segments)
{
    std::string fqdn="1.2.3.e164.ericsson.com";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("321", dn.c_str());
    ASSERT_STREQ("e164.ericsson.com", zone.c_str());
}


TEST_F(TestEnumParser,dn_has_1_digits_and_zone_has_3_segments)
{
    std::string fqdn="1.e164.ericsson.com";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("1", dn.c_str());
    ASSERT_STREQ("e164.ericsson.com", zone.c_str());
}

TEST_F(TestEnumParser,dn_has_0_digits_and_zone_has_3_segments)
{
    std::string fqdn="e164.ericsson.com";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("", dn.c_str());
    ASSERT_STREQ("e164.ericsson.com", zone.c_str());
}


TEST_F(TestEnumParser,dn_has_3_digits_and_zone_has_1_segments)
{
    std::string fqdn="1.2.3.com";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("321", dn.c_str());
    ASSERT_STREQ("com", zone.c_str());
}

TEST_F(TestEnumParser,dn_has_1_digits_and_zone_has_1_segments)
{
    std::string fqdn="1.com";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("1", dn.c_str());
    ASSERT_STREQ("com", zone.c_str());
}


TEST_F(TestEnumParser,dn_has_0_digits_and_zone_has_1_segments)
{
    std::string fqdn="com";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("", dn.c_str());
    ASSERT_STREQ("com", zone.c_str());
}


TEST_F(TestEnumParser,dn_has_0_digits_and_zone_has_0_segments)
{
    std::string fqdn="";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("", dn.c_str());
    ASSERT_STREQ("", zone.c_str());
}

TEST_F(TestEnumParser,dn_has_1_digits_and_zone_has_0_segments)
{
    std::string fqdn="1";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("1", dn.c_str());
    ASSERT_STREQ("", zone.c_str());
}

TEST_F(TestEnumParser,dn_has_3_digits_and_zone_has_0_segments)
{
    std::string fqdn="1.2.3";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("321", dn.c_str());
    ASSERT_STREQ("", zone.c_str());
}


TEST_F(TestEnumParser,dn_has_0_digits_and_zone_has_1_segment_with_single_char)
{
    std::string fqdn="x";
    std::string zone, dn;

    parseFqdn(fqdn, zone, dn);

    ASSERT_STREQ("", dn.c_str());
    ASSERT_STREQ("x", zone.c_str());
}

TEST_F(TestEnumParser,dn_start_with_dash)
{
    std::string fqdn="1.-s.com";
    std::string zone, dn;

    ASSERT_FALSE(parseFqdn(fqdn, zone, dn));

}

TEST_F(TestEnumParser,dn_end_with_dash)
{
    std::string fqdn="1.2.3.s.com-";
    std::string zone, dn;

    ASSERT_FALSE(parseFqdn(fqdn, zone, dn));

}
