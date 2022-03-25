
#include "ros/ros.h"
#include "xsens_mtw_driver/xsens2kinova.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<xsens_mtw_driver::xsens2kinova>("chatter", 1000);
    ros::Rate loop_rate(10);
    int count = 0;
    while (ros::ok())
    {
        xsens_mtw_driver::xsens2kinova msg;
        msg.position[0] = count;
        msg.position[1] = count + 1;
        msg.position[2] = count + 2;
        msg.velocity[0] = -count;
        msg.velocity[1] = -count - 1;
        msg.velocity[2] = -count - 2;
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}