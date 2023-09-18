%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This example tests C++ MEX-file aruco_nano_detector.cpp. This example 
% shows how to use aruco nano detection algorithm to find the moving robot
% in a video stream.
%
% September 2023 - Rafael Carbonell Lázaro.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    

load_params;

 matlab.video.read.UseHardwareAcceleration('on');

% Create video reader object
hsrc = vision.VideoFileReader('WIN_20230810_12_25_32_Pro.mp4', ...
                                  'ImageColorSpace', 'RGB', ...
                                  'VideoOutputDataType', 'uint8');
                              
% Create video player object
hsnk = vision.VideoPlayer;
frameCnt = 1;

while ~isDone(hsrc)
  % Read frame
  frame  = step(hsrc);
  
  % Compute foreground mask
  [frame, T, R] = aruco_nano_detector(frame, camMatrix, distCoeff, markerSize);

  T
  R
  
  % view results in the video player
  step(hsnk, frame);
  frameCnt = frameCnt + 1;
end

release(hsnk);
release(hsrc);