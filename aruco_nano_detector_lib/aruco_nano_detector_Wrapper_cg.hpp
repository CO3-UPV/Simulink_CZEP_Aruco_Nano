#ifndef ARUCO_NANO_DETECTOR_WRAPPER_CG_HPP
#define ARUCO_NANO_DETECTOR_WRAPPER_CG_HPP
#include "opencv2/core.hpp" 
typedef cv::Mat cv_Mat;
typedef std::vector<cv::Point2i> vector_cv_Point;
typedef std::vector<cv::Point3d> vector_cv_Point3d;
extern void slwrap_aruco_nano_detector_draw(cv_Mat &inoutImg,cv_Mat &camMatrix,cv_Mat &distCoeff,double markersSize,vector_cv_Point &inoutMarkersID,vector_cv_Point3d &markersT,vector_cv_Point3d &markersR);
#endif
