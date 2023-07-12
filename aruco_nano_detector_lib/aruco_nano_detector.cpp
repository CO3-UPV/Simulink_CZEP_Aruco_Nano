#include "aruco_nano_detector.hpp"

void aruco_nano_detector_draw(cv::Mat& inoutImg, cv::Mat& camMatrix, cv::Mat& distCoeff, double markersSize, std::vector<cv::Point2i>& inoutMarkersID, std::vector<cv::Point3d>& markersT, std::vector<cv::Point3d>& markersR)
{
    
    while(markersT.size() < inoutMarkersID.size()) markersT.push_back(cv::Point3d(0,0,0));
    while(markersR.size() < inoutMarkersID.size()) markersR.push_back(cv::Point3d(0,0,0));

    auto markers=aruconano::MarkerDetector::detect(inoutImg);
    for(unsigned int i = 0; i < inoutMarkersID.size(); i++){
        bool found = false;
        for(const auto &m:markers){
            if(inoutMarkersID[i].x == m.id){
                inoutMarkersID[i].y = 1;
                m.draw(inoutImg);
                auto r_t = m.estimatePose(camMatrix, distCoeff, markersSize);
                cv::Point3d T(r_t.second);
                cv::Point3d R(r_t.first);
                markersT.at(i) = T;
                markersR.at(i) = R;
                found = true;
                break;
            }
        }
    }
}