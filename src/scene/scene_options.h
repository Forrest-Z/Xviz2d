/**
 * @Author: Xia Yunkai
 * @Date:   2024-05-29 10:12:43
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-05-30 18:18:25
 */
#include <stdint.h>

#ifndef __SCENE_OPTIONS_H__
#define __SCENE_OPTIONS_H__
#include "scene_color.h"
#include <memory>
namespace scene
{
    struct SceneOptions
    {
		SceneOptions()
		{
			for (size_t i = 0; i < 14; i++)
			{
				drawObject[i] = true;
			}
		}
        typedef std::shared_ptr<SceneOptions> Ptr;
        unsigned int backgroundColor = IM_WHITE;
        unsigned int gridColor = IM_COL32(0, 0, 0, 100);
        unsigned int measureColor = IM_BLACK;

        float gridInterval = 5.0f;
        float gridDashSize = 0.5f;
        float gridXmin = -50.0f;
        float gridYmin = -20.0;
        float gridXmax = 150.0f;
        float gridYmax = 20.0;

        int gridWidth = 10;
        int gridHeight = 10;

        float girdThickness = 0.02f;
        float originAxisLength = 5.0f;
        float originAxisThickness = 0.05f;
        bool drawGrid = true;
        bool drawOriginAxis = false;

        float zoomStep = 0.005f;
        float maxZoom = 0.5f;
        float minZoom = 0.005f;

        bool drawMeasure = false;
        bool drawTransformNodeList = false;
        bool drawObject[14];
        int topDrawtype = 4;
    };
}

#endif /* __SCENE_OPTIONS_H__ */
