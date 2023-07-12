#include "aruco_nano_detector_Wrapper_cg.hpp"
#include "./aruco_nano_detector.hpp"
void slwrap_aruco_nano_detector_draw(cv_Mat &inoutImg,cv_Mat &camMatrix,cv_Mat &distCoeff,double markersSize,vector_cv_Point &inoutMarkersID,vector_cv_Point3d &markersT,vector_cv_Point3d &markersR){
    aruco_nano_detector_draw(inoutImg,camMatrix,distCoeff,markersSize,inoutMarkersID,markersT,markersR);
}
