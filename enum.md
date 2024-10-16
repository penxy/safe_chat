
```cpp
enum class E_Type{
    Request,
    Response
};

/* Send */
/*
    E_Send
        E_Message
            E_Identity
        E_Action
            E_Status
            E_Identity
            E_ChangeInfo
        E_Info
*/
{
    // send type
    enum class E_Send{
        Message,
        Action,
        File,             // 文件传输, Up/Down/Send[E_File]
    }
    // message type
    enum class E_Message{
        Text,
    };
    // action type
    enum class E_Action{
        Regiest,
        Add,
        Delete,
        Accept,
        Reject, 
        Find, 
        Status,           //[E_Status]
        ChangeInfo,
    };
    // status
    enum class E_Status{
        Online,
        Busy,
        Leave,
        Hide
    };
    // identity type
    enum class E_Identity{
        Friend,
        Group,
    };
    enum class E_File{
        Up,
        Down,
        Send            // 发送文件
    };
    enum class E_Info{
        Name,
        Password
    };
    enum class E_ChangeInfo{
        Name,
        Password
    };
}

```