C_Sql               [2个线程，执行SQL]
C_Ini               [读配置文件]

C_Python            [单例模式，双锁], python接口, [包括表情包、ini写]<内部接口>

C_ID
    C_GroupID
    C_UserID
C_Msg               [解析消息, 包括字体, 表情包]
    C_GroupMsg
    C_UserMsg
C_Action
    C_GroupAction
    C_UserAction
C_File              [文件操作]

C_Timer             定时器，执行任务, 包括心跳

C_Protocol          解析、生成Json
C_Net               网络通信

C_IPC               进程间通信[单例模式，双锁]
C_Shm               掌握所有共享内存[单例模式，双锁]
C_Sem               所有线程内的通信[单例模式，双锁]

tool_global             工具类[namespace]
    tool_global_string  
    tool_global_time
    tool_global_file
