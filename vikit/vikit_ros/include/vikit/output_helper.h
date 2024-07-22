/*
 * output_helper.h
 *
 *  Created on: Jan 20, 2013
 *      Author: cforster
 */

#pragma once

#include <string>
#include <ros/ros.h>
#include <Eigen/Core>
#include <tf/transform_broadcaster.h>
#include <kindr/minimal/quat-transformation.h>

#include <opencv2/imgproc/imgproc.hpp>

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <sensor_msgs/image_encodings.h>
#include <tf/tf.h>
#include <ros/package.h>
#include <cv_bridge/cv_bridge.h>

#include <vikit/timer.h>
#include <vikit/output_helper.h>
#include <vikit/params_helper.h>

#include <svo_msgs/DenseInput.h>
#include <svo_msgs/DenseInputWithFeatures.h>
#include <svo_msgs/Info.h>


#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <Eigen/Dense>
namespace vk {

using Transformation = kindr::minimal::QuatTransformation;

namespace output_helper {

using namespace std;
using namespace Eigen;

Eigen::Vector3d _dv;

void publishTfTransform(
    const Transformation& T,
    const ros::Time& stamp,
    const string& frame_id,
    const string& child_frame_id,
    tf::TransformBroadcaster& br);



void publishPointMarker(
    ros::Publisher pub,
    const Vector3d& pos,
    const string& ns,
    const ros::Time& timestamp,
    int id,
    int action,
    double marker_scale,
    const Vector3d& color,
    ros::Duration lifetime = ros::Duration(0.0)
    // //改动
    // const Vector3d& prev_pos,
    // const ros::Time& prev_timestamp,
    // const Vector3d& d_pose,
    // const ros::Time& d_time
    );

void publishLineMarker(
    ros::Publisher pub,
    const Vector3d& start,
    const Vector3d& end,
    const string& ns,
    const ros::Time& timestamp,
    int id,
    int action,
    double marker_scale,
    const Vector3d& color,
    ros::Duration lifetime = ros::Duration(0.0));

void publishArrowMarker(
    ros::Publisher pub,
    const Vector3d& pos,
    const Vector3d& dir,
    double scale,
    const string& ns,
    const ros::Time& timestamp,
    int id,
    int action,
    double marker_scale,
    const Vector3d& color);

void publishHexacopterMarker(
    ros::Publisher pub,
    const string& frame_id,
    const string& ns,
    const ros::Time& timestamp,
    int id,
    int action,
    double marker_scale,
    const Vector3d& color);

void publishQuadrocopterMarkers(ros::Publisher pub,
                        const string& frame_id,
                        const string& ns,
                        const ros::Time& timestamp,
                        int id,
                        int action,
                        double marker_scale,
                        const Vector3d& color);

void publishCameraMarker(
    ros::Publisher pub,
    const string& frame_id,
    const string& ns,
    const ros::Time& timestamp,
    int id,
    int action,
    double marker_scale,
    const Vector3d& color);

void publishFrameMarker(
    ros::Publisher pub,
    const Matrix3d& rot,
    const Vector3d& pos,
    const string& ns,
    const ros::Time& timestamp,
    int id,
    int action,
    double marker_scale,
    ros::Duration lifetime = ros::Duration(0.0));

void publishGtsamPoseCovariance(
    const ros::Publisher& pub,
    const Eigen::Vector3d& mean,
    const Eigen::Matrix3d& R_W_B, // Body in World-Frame
    const Eigen::Matrix<double, 6, 6>& covariance,
    const string& ns,
    int id,
    int action,
    double sigma_scale,
    const Vector4d& color);


} // namespace output_helper
} // namespace vk

