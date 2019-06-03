#include <gtest/gtest.h>
#include "gas_dynamics.h"
#include "initial_parameters.h"
//#include "mainwindow.h"
#include <stdint-gcc.h>


#include <fcntl.h>
#include <vector>

class gas_dynamics_tester : public ::testing::Test {
public:
    gas_dynamics *fun;

protected:
    virtual void SetUp() {
        initial_parameters params;
        params.density_left = 1.0;
        params.pressure_left = 1.0;
        params.velocity_left = 0.0;

        params.density_right = 0.125;
        params.pressure_right = 0.1;
        params.velocity_right = 0;

        fun = new gas_dynamics(3,-5,7,1.4,2.5, params);
    }

};

TEST_F(gas_dynamics_tester, make_nodes) {
    auto x = fun->make_nodes();
    std::cout<<std::endl;
    EXPECT_EQ(x[0],-5);
    EXPECT_EQ(x[1],-1);
    EXPECT_EQ(x[2],3);
    EXPECT_EQ(x[3],7);
}

TEST_F(gas_dynamics_tester,initial_condition){
    auto dens = fun->InitialCondition(1);
    auto pres = fun->InitialCondition(3);
    auto vel = fun->InitialCondition(2);

    EXPECT_EQ(dens[0],1);
    EXPECT_EQ(dens[1],1);
    EXPECT_EQ(dens[2],0.125);
    EXPECT_EQ(dens[3],0.125);

    for (auto i =0;i<4;++i){
        EXPECT_EQ(vel[i],0);
    }

    EXPECT_EQ(pres[0],1);
    EXPECT_EQ(pres[1],1);
    EXPECT_EQ(pres[2],0.1);
    EXPECT_EQ(pres[3],0.1);
}
TEST_F(gas_dynamics_tester, Newton_method){
    double e = 0.000001;
    auto pressure = fun->Newton();
    EXPECT_TRUE(fun->ExpressionForP3(pressure)<e);
}

TEST_F(gas_dynamics_tester,find_index){
    EXPECT_EQ(fun->find_index(-5),0);
    EXPECT_EQ(fun->find_index(-1),1);
    EXPECT_EQ(fun->find_index(3),2);
    EXPECT_EQ(fun->find_index(7),3);
}

TEST (initial_parameters, reading_from_file){
    initial_parameters params = initial_parameters();
    EXPECT_EQ(params.density_left,1);
    EXPECT_EQ(params.pressure_left,1);
    EXPECT_EQ(params.velocity_left,0);

    EXPECT_EQ(params.density_right,0.125);
    EXPECT_EQ(params.pressure_right,0.1);
    EXPECT_EQ(params.velocity_left,0);
}
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
