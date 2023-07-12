#include "aruco_nano_detector_Wrapper_sim.hpp"
#include "./aruco_nano_detector.hpp"
#ifdef __cplusplus
extern "C" {
#endif
void slwrap_aruco_nano_detector_draw(cv_Mat inoutImg,cv_Mat camMatrix,cv_Mat distCoeff,double markersSize,vector_cv_Point inoutMarkersID,vector_cv_Point3d markersT,vector_cv_Point3d markersR){
    cv::Mat* inoutImgtmp = reinterpret_cast<cv::Mat*>(inoutImg);
    cv::Mat* camMatrixtmp = reinterpret_cast<cv::Mat*>(camMatrix);
    cv::Mat* distCoefftmp = reinterpret_cast<cv::Mat*>(distCoeff);
    std::vector<cv::Point2i>* inoutMarkersIDtmp = reinterpret_cast<std::vector<cv::Point2i>*>(inoutMarkersID);
    std::vector<cv::Point3d>* markersTtmp = reinterpret_cast<std::vector<cv::Point3d>*>(markersT);
    std::vector<cv::Point3d>* markersRtmp = reinterpret_cast<std::vector<cv::Point3d>*>(markersR);
    aruco_nano_detector_draw( * inoutImgtmp, * camMatrixtmp, * distCoefftmp,markersSize, * inoutMarkersIDtmp, * markersTtmp, * markersRtmp);
}
#ifdef __cplusplus
}
#endif
