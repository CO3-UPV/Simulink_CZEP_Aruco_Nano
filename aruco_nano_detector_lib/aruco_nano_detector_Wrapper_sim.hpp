#ifndef ARUCO_NANO_DETECTOR_WRAPPER_SIM_HPP
#define ARUCO_NANO_DETECTOR_WRAPPER_SIM_HPP
typedef void* cv_Mat;
typedef void* vector_cv_Point;
typedef void* vector_cv_Point3d;
#ifdef __cplusplus
extern "C" {
#endif
extern void slwrap_aruco_nano_detector_draw(cv_Mat inoutImg,cv_Mat camMatrix,cv_Mat distCoeff,double markersSize,vector_cv_Point inoutMarkersID,vector_cv_Point3d markersT,vector_cv_Point3d markersR);
#ifdef __cplusplus
}
#endif
#endif
