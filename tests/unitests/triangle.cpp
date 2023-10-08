#include "config.hpp"

using namespace geometry;

// TEST(triangle_test, init_class)
// {
//         point_t A{0, 0, 0};
//         point_t B{1, 1, 0};
//         point_t C{0, 0, 1};

//         triangle_t triangle {A, B, C};

//         EXPECT_NEAR(triangle.vertex_a.x, 0);
//         EXPECT_NEAR(triangle.vertex_a.y, 0);
//         EXPECT_NEAR(triangle.vertex_a.z, 0);
// }

// struct triangle_test : public testing::Test {
//         point_t A{0, 0, 0};
//         point_t B{1, 1, 0};
//         point_t C{0, 0, 1};

//         triangle_t *triangle;

//         void SetUp() { triangle = new triangle_t(); }
//         void TearDown() { delete triangle; }
// };

// class triangle_mock : public triangle_t {

// }

// class MylibMock : public MylibInterface {
//         public:
//         ~MylibMock() override = default;
//         MOCK_METHOD1(setVoltage, void(int));
// };

// TEST(MylibTestSuite, mock_mylib_setVoltage) {
//         MylibMock mylib_mock;
//         Myapp myapp_mock(&mylib_mock);

//         EXPECT_CALL(mylib_mock, setVoltage(220)).Times(1);

//         myapp_mock.run("ON");
// }