/**
 * @Author: Xia Yunkai
 * @Date:   2024-05-29 19:02:44
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-05-30 15:13:51
 */
#include <stdint.h>

#ifndef __MAIN_LAYER_H__
#define __MAIN_LAYER_H__

#include "base_layer.h"
#include <vector>
struct GLFWwindow;

namespace ui
{
    class SceneLayer;
    class PlotLayer;
    class SceneEditLayer;
    class MainLayer : public BaseLayer
    {
    public:
        MainLayer(const std::string &name);
        virtual bool Init() override;
        virtual void Draw() override;
        virtual void Shutdown() override;
        virtual void FilesDropCallback(int count, const char **paths) override;
        bool InitHandle(GLFWwindow *window);
        void BeginDraw();
        void EndDraw();
        void AddLayer(const BaseLayer::Ptr &layer);
        static void DropCallback(GLFWwindow *window, int count, const char **paths);

    protected:
        void DrawMenuBar();
        void InitStyle();
        void InitFontAndIcon();

    protected:
        std::vector<BaseLayer::Ptr> m_layers;
        std::shared_ptr<SceneLayer> m_sceneLayer;
        std::shared_ptr<PlotLayer> m_plotLayer;
        std::shared_ptr<SceneEditLayer> m_sceneEditLayer;
        UIContext::Ptr m_uiContext;
    };
}
#endif /* __MAIN_LAYER_H__ */
