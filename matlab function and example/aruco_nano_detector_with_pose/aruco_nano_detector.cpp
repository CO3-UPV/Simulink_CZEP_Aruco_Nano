//////////////////////////////////////////////////////////////////////////
// Creates C++ MEX-file for use aruco_nano.h like a Matlab function.
//
// September 2023 - Rafael Carbonell Lázaro.
//////////////////////////////////////////////////////////////////////////

#include "opencvmex.hpp"
using namespace cv;

#include "aruco_nano.h"

//////////////////////////////////////////////////////////////////////////////
// Check inputs
//////////////////////////////////////////////////////////////////////////////
void checkInputs(int nrhs, const mxArray *prhs[])
{
//     if (nrhs != 1)
//     {
//         mexErrMsgTxt("Incorrect number of inputs. Function expects 1 input.");
//     }

    if (mxGetNumberOfDimensions(prhs[0])!=3)
    {
        mexErrMsgTxt("Incorrect number of dimensions. First input must be a 3D matrix (matlab image).");
    }

	// Check image data type
    if (!mxIsUint8(prhs[0]))
    {
        mexErrMsgTxt("Template and image must be UINT8.");
    }
}

//////////////////////////////////////////////////////////////////////////////
// The main MEX function entry point
//////////////////////////////////////////////////////////////////////////////
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{  	
    checkInputs(nrhs, prhs);
    //checkOutputs(nlhs, plhs);

    cv::Ptr<cv::Mat> img = ocvMxArrayToImage_uint8(prhs[0], true);
    auto markers = aruconano::MarkerDetector::detect(*img);

    cv::Ptr<cv::Mat> camMatrix = ocvMxArrayToImage_double(prhs[1], true);
    cv::Ptr<cv::Mat> distCoeff = ocvMxArrayToImage_double(prhs[2], true);
    //mxGetClassID(pm) == mxDOUBLE_CLASS
    double *markersSize = mxGetPr(prhs[3]);

    // Crear un mxArray de tipo double para el resultado
    int numRows = 3;
    plhs[1] = mxCreateDoubleMatrix(numRows, markers.size(), mxREAL); // Rotaciones
    plhs[2] = mxCreateDoubleMatrix(numRows, markers.size(), mxREAL); // Traslaciones

    // Obtener un puntero al arreglo de tipo double del mxArray de salida
    double *Tout = mxGetPr(plhs[1]);
    double *Rout = mxGetPr(plhs[2]);

    int col = 0;
    int row = 0;
    int index = 0;
    for(const auto &m:markers){
        m.draw(*img);
        auto r_t = m.estimatePose(*camMatrix, *distCoeff, *markersSize);
        cv::Point3d T(r_t.second);
        cv::Point3d R(r_t.first);

        row = 0;
        index = col * numRows + row;
        Tout[index] = T.x;
        Rout[index] = R.x;

        row = 1;
        index = col * numRows + row;
        Tout[index] = T.y;    
        Rout[index] = R.y;

        row = 2;
        index = col * numRows + row;
        Tout[index] = T.z;  
        Rout[index] = R.z;

        col++;
    }

    plhs[0] = ocvMxArrayFromImage_uint8(*img);
}

