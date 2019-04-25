#pragma once

#include "rthsTypes.h"

namespace rths {

class GfxContext
{
public:
    static bool initializeInstance();
    static void finalizeInstance();
    static GfxContext* getInstance();

    bool valid() const;
    ID3D12ResourcePtr translateTexture(void *ptr);
    ID3D12ResourcePtr translateBuffer(void *ptr);

private:
    GfxContext();
    ~GfxContext();

    IDXGISwapChain3Ptr m_swapchain;
    ID3D12Device5Ptr m_device;
    ID3D12CommandQueuePtr m_cmd_queue;
    ID3D12GraphicsCommandList4Ptr m_cmd_list;
    ID3D12FencePtr m_fence;
};

const std::string& GetErrorLog();
void SetErrorLog(const char *format, ...);

} // namespace rths
