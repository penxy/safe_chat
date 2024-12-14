# 界面[未完成]
## 文件结构
```
src
├── args.cpp
├── args.h
├── Chat
│   ├── chat.cpp
│   ├── chat.h
│   ├── chatid.cpp
│   ├── chatid.h
│   ├── friend.cpp
│   ├── friend.h
│   ├── group.cpp
│   └── group.h
├── config.h
├── config_ui.h
├── Core
│   ├── core.cpp
│   ├── core_fd.h
│   ├── core_ftp.h
│   ├── core_gp.h
│   ├── core.h
│   ├── core_history.h
│   ├── core_self.h
│   └── readme.md
├── Data
│   ├── core_sql.cpp
│   └── core_sql.h
├── Main
│   ├── main_wid.cpp
│   ├── main_wid.h
│   ├── widget.cpp
│   └── widget.h
├── main.cpp
├── Model
│   ├── Add
│   │   ├── add_fd_page.cpp
│   │   └── add_fd_page.h
│   ├── Base
│   │   ├── btn_base.h
│   │   ├── label_photo.cpp
│   │   ├── label_photo.h
│   │   ├── label_role.cpp
│   │   ├── label_role.h
│   │   ├── Layout.cpp
│   │   ├── Layout.h
│   │   ├── Line.cpp
│   │   ├── Line.h
│   │   ├── my_frame.h
│   │   ├── wid_base.cpp
│   │   ├── wid_base.h
│   │   ├── widget_blank.cpp
│   │   └── widget_blank.h
│   ├── Card
│   │   ├── fd_card.cpp
│   │   └── fd_card.h
│   ├── ChatBar
│   │   ├── bubble
│   │   │   ├── bubble_msg.cpp
│   │   │   └── bubble_msg.h
│   │   ├── chat_btm.cpp
│   │   ├── chat_btm.h
│   │   ├── chat_default.h
│   │   ├── chat_mid.cpp
│   │   ├── chat_mid.h
│   │   ├── chat_page.cpp
│   │   ├── chat_page.h
│   │   ├── chat_top.cpp
│   │   └── chat_top.h
│   ├── Ftp
│   │   ├── ftp_page.cpp
│   │   └── ftp_page.h
│   ├── Group
│   │   ├── gp_member.cpp
│   │   └── gp_member.h
│   ├── ListBar
│   │   ├── core_list.cpp
│   │   ├── core_list.h
│   │   ├── fd_list.cpp
│   │   ├── fd_list.h
│   │   ├── gp_list.cpp
│   │   ├── gp_list.h
│   │   ├── Item
│   │   │   ├── core_list_item.cpp
│   │   │   ├── core_list_item.h
│   │   │   ├── fd_list_item.cpp
│   │   │   ├── fd_list_item.h
│   │   │   ├── gp_list_item.cpp
│   │   │   └── gp_list_item.h
│   │   ├── list_page.cpp
│   │   └── list_page.h
│   ├── test
│   │   ├── wid_test.cpp
│   │   └── wid_test.h
│   ├── TitleBar
│   │   ├── title_bar.cpp
│   │   ├── title_bar.h
│   │   └── title_btn.h
│   └── ToolBar
│       ├── tool_btn.cpp
│       ├── tool_btn.h
│       ├── tool_page.cpp
│       └── tool_page.h
├── Service
│   ├── base_service.h
│   ├── const_json.h
│   ├── core_protocol.cpp
│   ├── core_protocol.h
│   └── Net
│       ├── httpmanager.cpp
│       ├── httpmanager.h
│       ├── test.cpp
│       └── test.h
├── Setting
│   ├── core_setting.cpp
│   ├── core_setting.h
│   └── isystem_setting.h
├── utils
│   ├── interface.h
│   ├── single_model.h
│   ├── thread_pool.h
│   ├── tool.cpp
│   └── tool.h
└── widget
    └── form
        ├── addfrienddialog.cpp
        ├── addfrienddialog.h
        ├── addfrienddialog.ui
        ├── rmchatdialog.cpp
        ├── rmchatdialog.h
        └── rmchatdialog.ui
CMakeLists.txt
doc.dot
icons.qrc
readme.md

23 directories, 109 files
```