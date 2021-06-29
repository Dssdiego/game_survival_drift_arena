//
// Created by Diego Santos Seabra on 27/06/21.
//

#pragma once


#include <SDL2/SDL_opengl.h>
#include "structs.h"
#include <algorithm>

class Camera
{
public:
    Camera();

    bool updated();

    // Window
    Rect& windowSize() { return mWindowSize; }
    void setWindowSize (int width, int height);
    GLfloat* viewport() { return (GLfloat*)&mViewport; }

    GLfloat* pan() { return (GLfloat*)&mPan; }
    GLfloat zoom() { return mZoom; }
    GLfloat aspect() { return mAspect; }

    void setPan (Vec2 pan) { mPan = pan; mCameraUpdated = true; }
    void setPanDelta (Vec2 panDelta) { mPan.x += panDelta.x; mPan.y += panDelta.y; mCameraUpdated = true; }
    void setZoom (GLfloat zoom) { mZoom = clamp(zoom, cZoomMin, cZoomMax); mCameraUpdated = true; }
    void setZoomDelta (GLfloat zoomDelta) { mZoom = clamp(mZoom + zoomDelta, cZoomMin, cZoomMax); mCameraUpdated = true; }
    void setAspect (GLfloat aspect) { mAspect = aspect; mCameraUpdated = true; }

    Vec2& basePan() { return mBasePan; }
    void setBasePan () { mBasePan = mPan; }

private:
    float clamp (float val, float lo, float hi);

    bool mCameraUpdated;
    Rect mWindowSize;
    Vec2 mViewport;

    Vec2 mBasePan, mPan;
    GLfloat mZoom, mAspect;

    const GLfloat cZoomMin, cZoomMax;
};
