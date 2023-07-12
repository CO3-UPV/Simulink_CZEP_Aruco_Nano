#pragma once

#include "aruco_nano.h"
#include <vector>

void aruco_nano_detector_draw(cv::Mat& inoutImg, cv::Mat& camMatrix, cv::Mat& distCoeff, double markersSize, std::vector<cv::Point2i>& inoutMarkersID, std::vector<cv::Point3d>& markersT, std::vector<cv::Point3d>& markersR);