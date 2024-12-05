#pragma once
#include <string>
#include <time.h>

/**
 * @namespace TypeJson
 * @brief     包含json的一切属性
 */
namespace TypeJson{
    /**
     * @enum Leval
     * @brief 优先级
     */
    enum class Leval : uint8_t{
        Low = 0,
        Normal,
        High
    };
    /**
     * @enum Send
     * @brief 发送的类型
     */
    enum class Send : uint8_t{
        Regiest,
        CreateGroup,

        FdAdd,
        FdDel,
        FdAccept,
        FdReject,
        FdText,

        GpCreate,
        GpInvite,//invite not need response
        GpQuit,
        GpText,
        GpName,
        GpPix,

        ChangeName,
        ChangePix,
        ChangeStatus,
        ChangePass
    };
    /**
     * @enum Recv
     * @brief 接收的类型
     */
    enum class Recv : uint8_t{
        FdFind,
        FdAdd,
        FdDel,
        FdAccept,
        FdReject,
        FdStatus,
        FdName,
        FdPix,

        GpFind,
        GpAdd,
        GpDel,
        GpAccept,
        GpReject,
        GpName,
        GpPix,
    };
};
