//
// Created by Diego Santos Seabra on 27/06/21.
//

#include "camera.h"

Camera::Camera()
        : mCameraUpdated (false)
        , mWindowSize ({})
        , mViewport ({})
        , cZoomMin (0.1f), cZoomMax (10.0f)
        , mBasePan ({0.0f, 0.0f})
        , mPan ({0.0f, 0.0f})
        , mZoom (1.0f)
        , mAspect (1.0f)
{
    setWindowSize(640, 480);
}

bool Camera::updated()
{
    if (mCameraUpdated)
    {
        mCameraUpdated = false;
        return true;
    }
    else
        return false;
}

// Set window size
void Camera::setWindowSize(int width, int height)
{
    mWindowSize = {width, height};
    mViewport = {(float)width, (float)height};
    setAspect((float) width / (float)height);
}

// Clamp val between lo and hi
float Camera::clamp(float val, float lo, float hi)
{
    return std::max(lo, std::min(val, hi));
}
