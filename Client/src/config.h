#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <QSize>
#include <QDebug>
#include <QPixmap>

// #include "nlohmann/json.hpp"
// using json = nlohmann::json;
//==================================enum===================================//

/**
 * @namespace Type
 * @brief 对外暴露的枚举类型
 */
namespace Type{
    /**
     * @enum Role
     * @brief 群成员角色
     */
    enum class Role{
        Owner = 0,
        Admin = 1,
        Member = 2
    };
    /**
    * @enum Status
    */
    enum class Status{
        Online,
        Offline,
        Busy,
        Away
    };
    /**
     * @enum Identity
     * @brief 聊天对象
     */
    enum class Identity{
        Friend,
        Group
    };
}


//=======================================define=======================================
#include <QTimer>

//防止按钮多次点击
#define __DELAY__ QTimer::singleShot(200, this, [&](){});

//=======================================Size=========================================

namespace sz{
#ifndef sc
    #define sc static constexpr const
#endif
#ifndef QSize
    #define QSize ::QSize
#endif
    /* dialog-size */
    sc QSize dialog_wid                                                  = QSize(400, 300);

    sc QSize main_window_wid                                             = QSize(1200, 800);
    /* size-widget-tool */
    sc QSize tool_btn                                                    = QSize(50, 50);
    sc int tool_wid                                                      = 60;

    /* size-friend-list */
    sc QSize fd_list_name                                                = QSize(120, 30);
    sc QSize fd_list_photo                                               = QSize(57, 57);
    sc QSize fd_list_wid                                                 = QSize(200, 70);
    
    sc int list_bar_w                                                    = 300;
    /* size-role */
    sc QSize role                                                        = QSize(30, 20);

    /* size-member */
    sc int member_h                                                 = 50;
    sc QSize member_lab                                             = QSize(60, 30);
    sc QSize member_photo                                           = QSize(45, 45);

    /* size-title */
    sc int title_bar_h                                                   = 30;

    //============================================Talk============================================
    /* size-talk-top */
    sc QSize chat_top_lab                                                = QSize(150, 30);
    sc QSize chat_top_photo                                              = QSize(45, 45);
    sc QSize chat_top_wid                                                = QSize(250, 70);

    /* size-talk-mid */                                     
    sc QSize chat_mid_wid_base                                           = QSize(450, 600);

    /* size-talk-buttom */                                      
    sc QSize chat_btm_btn                                                = QSize(70, 30);
    sc int chat_btm_wid_max_h                                            = 120;

    /* size-talk-window */                                      
    sc QSize chat_wid_min                                                = QSize(400, 600);
    sc QSize chat_wid_base                                               = QSize(500, 600);
    //============================================Talk============================================

    //============================================Card============================================
    sc QSize card_id                                                     = QSize(100, 30);
    sc QSize card_name                                                   = QSize(100, 30);
    sc QSize card_photo                                                  = QSize(120, 120);
    sc QSize card_btn                                                    = QSize(70, 30);
    //============================================Card============================================

    //============================================Search============================================
    sc QSize find_gif                                                    = QSize(40, 40);
    sc QSize find_btn                                                    = QSize(60, 40);
    //============================================Search============================================

    /* size-widget-main */
    sc QSize main_wid_base                           = QSize(fd_list_wid.width() + tool_wid + chat_wid_min.width() + 30, 
                                                                                chat_wid_base.height() + title_bar_h + 15);
#ifdef QSize
    #undef QSize
#endif
#ifdef sc
    #undef sc
#endif // sc
}


#include <QDateTime>
#include <memory>
#include "Chat/chatid.h"
/**
 * @namespace ns
 * @brief the set of struct
 */
namespace ns{
    /**
     * @struct InfoHistory
     * @brief 历史消息的记录
     */
    struct History{
        QDateTime date;
        QString content;
        ChatId id;//对方的id
        bool isSelf;//是否是自己发送的
        History(){}
        History(QDateTime& t, QString& c, ChatId& id, bool isSelf) : date(t), content(c), id(id), isSelf(isSelf) {}
    };
    /**
     * @struct Member
     * @brief 群成员
     */
    struct Member{
        ChatId id;
        QString name;
        QPixmap pix;
        Type::Role role;
        Member(){}
        Member(ChatId& id, QString& name, QPixmap& pix, Type::Role role) : id(id), name(name), pix(pix), role(role) {}
    };
}

#endif // __CONFIG_H__